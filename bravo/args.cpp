#include "args.h"
#include <cassert>
#include <cstdlib>
#include <stdexcept>
#include <cstring>
#include <iostream>

bool termina_com(const char * alvo, const char * comp)
{
    if(strlen(comp) >= strlen(alvo)) return false;

    for(size_t i = strlen(alvo) - strlen(comp), j = 0; i < strlen(alvo); i++, j++)
    {
        if(alvo[i] != comp[j]) return false;
    }
    return true;
}

void obter_token_extensao(const std::string& extensao, tipo_arq_t& tok_extensao)
{
    if(extensao == ".py") tok_extensao = PY_ARQ;
    if(extensao == ".c") tok_extensao = C_ARQ;
    if(extensao == ".cpp") tok_extensao = CPP_ARQ;
    if(extensao == ".java") tok_extensao = JAVA_ARQ;
}

std::pair<tipo_arq_t, int> obter_programa(const int argc, const char * argv[])
{
    std::vector<std::string> extensoes = {".py", ".c", ".cpp", ".java"};
    tipo_arq_t tok_extensao;
    int indice = -1;

    for(int i = 1; i < argc; i++)
    {
        for(std::string extensao : extensoes)
        {
            if(termina_com(argv[i], extensao.c_str()))
            {
                if(indice != -1)
                {
                    throw std::runtime_error("Erro: Os argumentos passados contem mais de um arquivo. Envie apenas 1!");
                }
                indice = i;
                obter_token_extensao(extensao, tok_extensao);
            }

        }
    }

    return (indice != -1) ? (std::make_pair(tok_extensao, indice)) : \
    throw std::runtime_error("Erro: Nao foi possivel localizar nenhum programa!");
}

int obter_pasta(const int argc, const char * argv[])
{
    int indice = -1;
    for(int i = 1; i < argc; i++) 
    {
        if(argv[i][strlen(argv[i]) - 1] == '/')
        {
            if(indice != -1)
            {
                throw std::runtime_error("Erro: os argumentos passados contem mais de uma pasta. Envie apenas 1!");
            }
            indice = i;
        }
    }
    return (indice != -1) ? (indice) : \
    throw std::runtime_error("Erro: Nao foi possivel localizar nenhuma pasta!");
}

int obter_flags(const int argc, const char * argv[])
{
    int indice = -1;
    for(int i = 0; i < argc; i++)
    {
        if(argv[i][0] == '-')
        {
            if(indice != -1)
            {
                throw std::runtime_error("Erro: os argumentos passados contem mais de um demarcador de flag. Envie apenas 1!");
            }
            indice = i;
        }
    }
    return (indice != -1) ? (indice): \
    throw std::runtime_error("Erro: Nao foi possivel localizar nenhuma flag.");
}

args_t * obtem_args(const int argc, const char * argv[])
{
    args_t * args = (args_t*)malloc(sizeof(args_t));

    assert(args != NULL);

    if((argc - 1) < 2) throw std::runtime_error("Erro: Esperado numero maior de argumentos.");
    if((argc - 1) > 3) throw std::runtime_error("Erro: Esperado numero menor de argumentos.");
        
    {
        std::pair<tipo_arq_t, int> par_arquivo = obter_programa(argc, argv);

        std::string programa = argv[par_arquivo.second];
        std::string resposta = argv[obter_pasta(argc, argv)];

        arg_t flag_prog = {.valor = programa, .tipo = PROG_ARG};
        arg_t flag_resp = {.valor = resposta, .tipo = RESP_ARG};

        args->valores.push_back(flag_prog);
        args->valores.push_back(flag_resp);

        args->extensao = par_arquivo.first;
    }

    try {
        std::string flags = argv[obter_flags(argc, argv)];

        arg_t flag_arg = {.valor = flags, .tipo = FLAG_ARG};
        
        args->valores.push_back(flag_arg);

        // ajustar_byte();

    } catch(std::exception& exc)
    {} 

    return args;
}