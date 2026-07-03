#include "c.h"
#include "args.h"

#include <vector>
#include <string>
#include <unistd.h>
#include <filesystem>
#include <sys/wait.h>
#include <fcntl.h>
#include <fstream>

#define TAMANHO_EXT_C  2
#define QNT_ARGS_GCC_C 7

static void compilar_programa(const args& args)
{
    
    pid_t pid = fork();
    
    if(pid < 0) exit(-1);
    else if(pid == 0)
    {
        std::vector<std::string> c_comp_args;
        c_comp_args.reserve(QNT_ARGS_GCC_C);

        std::filesystem::path p(args.obter_arquivo_caminho());
        std::string nome_exct = p.stem().string();

        c_comp_args.push_back("gcc");
        c_comp_args.push_back("-lm");
        c_comp_args.push_back("-O2");
        c_comp_args.push_back("-static");
        c_comp_args.push_back("-o");
        c_comp_args.push_back(nome_exct + ".out");
        c_comp_args.push_back(args.obter_arquivo_caminho());
        std::vector<char*> c_args;

        c_args.reserve(c_comp_args.size() + 1); 

        for (std::string& str : c_comp_args) 
        {
            c_args.push_back(const_cast<char*>(str.c_str())); 
        }

        c_args.push_back(nullptr); 

        execvp(c_args[0], c_args.data());

        _exit(127);
        
    } 

    int status;

    if (waitpid(pid, &status, 0) == -1) 
    {
        throw std::runtime_error("Erro em waitpid().");
    }

    if (WIFSIGNALED(status))
    {
        throw std::runtime_error(
            "Compilador terminou por sinal " +
            std::to_string(WTERMSIG(status)));
    }

    if (!WIFEXITED(status))
    {
        throw std::runtime_error("Compilador não terminou normalmente.");
    }

    if (WEXITSTATUS(status) != 0)
    {
        throw std::runtime_error(
            "Erro de compilação (gcc retornou código " +
            std::to_string(WEXITSTATUS(status)) + ").");
    }

}

static bool comparar_arquivo(const std::filesystem::path& esperado, const std::filesystem::path& obtido)
{
    std::ifstream fe(esperado);
    std::ifstream fo(obtido);

    std::string a, b;

    while (true)
    {
        bool ea = bool(fe >> a);
        bool eb = bool(fo >> b);

        if (ea != eb)
            return false;

        if (!ea)
            return true;

        if (a != b)
            return false;
    }
}

veredito executar_caso(const std::string& executavel, const std::filesystem::path& entrada,\
                       const std::filesystem::path& resposta, double limiteTempo)
{
    namespace fs = std::filesystem;

    fs::path saida = fs::temp_directory_path() / "judge.out";

    pid_t pid = fork();

    if (pid < 0)
        throw std::runtime_error("fork falhou.");

    if (pid == 0)
    {
        int in = open(entrada.c_str(), O_RDONLY);
        int out = open(saida.c_str(),
                       O_WRONLY | O_CREAT | O_TRUNC,
                       0644);

        dup2(in, STDIN_FILENO);
        dup2(out, STDOUT_FILENO);

        close(in);
        close(out);

        execl(executavel.c_str(),
              executavel.c_str(),
              nullptr);

        _exit(127);
    }

    auto inicio = std::chrono::steady_clock::now();

    int status;

    while (true)
    {
        pid_t r = waitpid(pid, &status, WNOHANG);

        if (r == pid)
            break;

        auto agora = std::chrono::steady_clock::now();

        double tempo =
            std::chrono::duration<double>(agora - inicio).count();

        if (tempo > limiteTempo)
        {
            kill(pid, SIGKILL);
            waitpid(pid, nullptr, 0);

            fs::remove(saida);

            return veredito::TLE;
        }

        usleep(1000);
    }

    if (!WIFEXITED(status) || WEXITSTATUS(status) != 0)
    {
        fs::remove(saida);
        return veredito::RE;
    }

    bool iguais = comparar_arquivo(resposta, saida);

    fs::remove(saida);

    return iguais ? veredito::AC : veredito::WA;
}

static void executar_testes(const args& args)
{
    if(args.obter_bits().test(V_FLAG_P)) a_print("Recolhendo ultimos dados...");
    namespace fs = std::filesystem;

    fs::path pasta(args.obter_diretorio_testes());

    std::string executavel = fs::path(args.obter_arquivo_caminho()).stem().string() + ".out";
    
    if(args.obter_bits().test(V_FLAG_P)) a_print("Iniciando testes agora!");


    for (int i = 1;; ++i)
    {
        fs::path entrada = pasta / (std::to_string(i) + ".in");

        if (!fs::exists(entrada))
        {
            if(args.obter_bits().test(V_FLAG_P)) a_print("Pasta chegou ao fim! Sem mais testes!");
            break;
        }
        fs::path resposta = pasta / (std::to_string(i) + ".sol");

        veredito v = executar_caso(executavel, entrada, resposta, 1.0);

        switch (v)
        {
        case veredito::AC:
            std::cout << "Caso " << i << ": Resposta Correta\n";
            break;

        case veredito::WA:
            std::cout << "Caso " << i << ": Resposta Errada\n";
            break;

        case veredito::RE:
            std::cout << "Caso " << i << ": Erro de Execucao\n";
            break;

        case veredito::TLE:
            std::cout << "Caso " << i << ": Limite de Tempo\n";
            break;
        }
    }

}

void c_modulo(const args& args)
{
    if(args.obter_bits().test(V_FLAG_P)) a_print("Iniciando compilacao de " + args.obter_arquivo_caminho() + " agora.");

    compilar_programa(args);

    if(args.obter_bits().test(V_FLAG_P))
    {
        a_print("Compilacao encerrada com Sucesso!");
        a_print("Usando testes com arquivo de dados local...");
    }

    executar_testes(args);

}