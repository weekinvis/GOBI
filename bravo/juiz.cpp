#include <vector>
#include <string>
#include <unistd.h>
#include <filesystem>
#include <sys/wait.h>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include "args.h"
#include "java.h"
#include "c.h"
#include "cpp.h"
#include "py.h"
#include "erro.h"
#include "juiz.h"

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

static veredito executar_caso(const std::pair<std::string, tipo_arq_t>& executavel, const std::filesystem::path& entrada,\
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

        if(executavel.second == C_ARQ || executavel.second == CPP_ARQ)
        {
            execl(executavel.first.c_str(),
                executavel.first.c_str(),
                nullptr);
        }
        else if(executavel.second == PY_ARQ)
        {
            execl(USR_PY_INT_CMD_LINE,
                PY_INT_CMD_LINE,
                executavel.first.c_str(),
                nullptr);
                perror("execl python");
        }
        else
        { 
            execl(USR_JAVA_INT_CMD_LINE,
                JAVA_INT_CMD_LINE,
                executavel.first.c_str(),
                nullptr);
                perror("execl java");

        }
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
    if(args.obter_bits().test(D_FLAG_P) || args.obter_bits().test(H_FLAG_P)) return;

    if(args.obter_bits().test(V_FLAG_P)) a_print("Recolhendo ultimos dados...");

    namespace fs = std::filesystem;
    fs::path pasta(args.obter_diretorio_testes());

    if(!fs::exists(pasta))
    {
        throw std::runtime_error("Pasta nao encontrada!");
    }

    std::pair<std::string, tipo_arq_t> executavel;

    if(args.obter_extensao() == C_ARQ || args.obter_extensao() == CPP_ARQ)
        executavel.first = fs::path(args.obter_arquivo_caminho()).stem().string() + ".out";
    else 
        executavel.first = fs::path(args.obter_arquivo_caminho()).string();

    executavel.second = args.obter_extensao();

    if(args.obter_bits().test(V_FLAG_P)) a_print("Iniciando testes agora!");

    int quantidade_respostas = 0, quantidade_respostas_certas = 0;

    for(int i = 1;; i++)
    {
        int resposta_atual_certa = 0;
        fs::path sub_pasta = pasta / std::to_string(i);

        if(!fs::exists(sub_pasta))
        {
            if(args.obter_bits().test(V_FLAG_P)) a_print("Sem mais subtestes!", i);
            break;
        } 

        if(args.obter_bits().test(V_FLAG_P)) a_print("Iniciando subtestes n", i);

        for (int j = 1;; j++)
        {
            bool erro = true;
            fs::path entrada = sub_pasta / (std::to_string(j) + ".in");
    
            if (!fs::exists(entrada))
            {
                if(args.obter_bits().test(V_FLAG_P)) a_print("Pasta chegou ao fim! Sem mais testes!");

                if(resposta_atual_certa == j - 1)
                {
                    std::cout << "Subteste n" << i << std::endl;
                    std::cout << resposta_atual_certa << '/' << j - 1 << " respostas corretas!" << std::endl;
                }

                break;
            }
            quantidade_respostas++;
            fs::path resposta = sub_pasta / (std::to_string(j) + ".sol");
    
            veredito v = executar_caso(executavel, entrada, resposta, 1.0);
    
            switch (v)
            {
                case veredito::AC:
                    if(args.obter_bits().test(V_FLAG_P))
                    {
                        std::cout << "Caso " << j << ": Resposta Correta\n";
                    }
                    resposta_atual_certa++;
                    quantidade_respostas_certas++;
                    erro = false;
                    break;
        
                case veredito::WA:
                    std::cout << "Encerrando Subteste " << i << std::endl << "Caso " << j <<": Resposta Errada" << std::endl;
                    break;
        
                case veredito::RE:
                    std::cout << "Encerrando Subteste " << i << std::endl << "Caso " << j <<": Erro de execucao" << std::endl;
                    break;
        
                case veredito::TLE:
                    std::cout << "Encerrando Subteste " << i << std::endl << "Caso " << j <<": Tempo limite de execucao" << std::endl;
                    break;

            }
            if(erro) break;
        }
        std::cout << std::endl;
    }

    if(quantidade_respostas == quantidade_respostas_certas) 
    {
        std::cout << "Essa submissao acertou todos os " << quantidade_respostas << " testes." << std::endl;
    }

}

int j_main(const args& args)
{
    try 
    {
        switch(args.obter_extensao())
        {
            case PY_ARQ:
                if(args.obter_bits().test(V_FLAG_P)) a_print("Python");

                executar_testes(args);
                
                break;

            case C_ARQ:
                if(args.obter_bits().test(V_FLAG_P)) a_print("C");
                    
                c_modulo(args);
                executar_testes(args);

                break;

            case CPP_ARQ:
                if(args.obter_bits().test(V_FLAG_P)) a_print("C++");
                
                cpp_modulo(args);   
                executar_testes(args);

                break;

            case JAVA_ARQ:
                if(args.obter_bits().test(V_FLAG_P)) a_print("Java");
                
                break;

        }
        return SUCESSO;

    } catch(std::exception& exp)
    {
        std::cerr << exp.what() << std::endl;
        return ERRO_COMUM;
    }

}