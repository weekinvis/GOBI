#include "cpp.h"
#include "args.h"

#include <string>
#include <unistd.h>
#include <filesystem>
#include <sys/wait.h>

#define QNT_ARGS_GPP_CPP 7

static void cpp_compilar_programa(const args& args)
{
    
    pid_t pid = fork();
    
    if(pid < 0) exit(-1);
    else if(pid == 0)
    {
        std::vector<std::string> cpp_comp_args;
        cpp_comp_args.reserve(QNT_ARGS_GPP_CPP);

        std::filesystem::path p(args.obter_arquivo_caminho());
        std::string nome_exct = p.stem().string();

        cpp_comp_args.push_back("g++");
        cpp_comp_args.push_back("-std=c++20");
        cpp_comp_args.push_back("-static");
        cpp_comp_args.push_back("-O2");
        cpp_comp_args.push_back("-o");
        cpp_comp_args.push_back(nome_exct + ".out");
        cpp_comp_args.push_back(args.obter_arquivo_caminho());
        std::vector<char*> cpp_args;

        cpp_args.reserve(cpp_comp_args.size() + 1); 

        for (std::string& str : cpp_comp_args) 
        {
            cpp_args.push_back(const_cast<char*>(str.c_str())); 
        }

        cpp_args.push_back(nullptr); 

        execvp(cpp_args[0], cpp_args.data());

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

void cpp_modulo(const args& args)
{
    if(args.obter_bits().test(C_FLAG_P))
    {
        std::cout << "Pulando etapa de compilacao..." << std::endl;
    } else
    {
        std::cout << "Compilando..." << std::endl;
        cpp_compilar_programa(args);
    }

    std::cout << "Pronto." << std::endl << std::endl;

    if(args.obter_bits().test(V_FLAG_P))
    {
        a_print("Compilacao encerrada com Sucesso!");
        a_print("Usando testes com arquivo de dados local...");
    }

}