#include "args.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <bitset>

tipo_arq_t args::obter_extensao() const noexcept
{
    return this->arquivo_extensao;
}

const std::string& args::obter_diretorio_testes() const noexcept
{
    return this->diretorio_res_caminho;
}

const std::bitset<N_PERMS>& args::obter_bits() const noexcept
{
    return this->flags;
}

const std::string& args::obter_arquivo_caminho() const noexcept
{
    return this->arquivo_caminho;
}


args::args(std::string& arq, std::string& dir, tipo_arq_t tipo, std::bitset<N_PERMS>& flags_) \
: arquivo_caminho(arq), diretorio_res_caminho(dir), arquivo_extensao(tipo), flags(flags_)
{}

static bool termina_com(const std::string& alvo, const std::string& sufixo)
{
    if(alvo.length() < sufixo.length()) return false;

    return alvo.compare(alvo.length() - sufixo.length(), sufixo.length(), sufixo) == 0;
}

static std::pair<int, tipo_arq_t> info_arquivo(const std::vector<std::string>& s_args)
{
    int res = -1;
    tipo_arq_t ext_arq;

    std::vector<std::pair<std::string, tipo_arq_t>> arq_aceitos \
    = { {".py", PY_ARQ}, {".c", C_ARQ}, {".cpp", CPP_ARQ}, {".java", JAVA_ARQ}};

    for(size_t i = 0; i < s_args.size(); i++)
    {
        if(s_args.at(i)[0] == '-') continue;
        if(s_args.at(i)[s_args.at(i).length()-1] == '/') continue;

        for(size_t j = 0; j < arq_aceitos.size(); j++)
        {
            if(termina_com(s_args.at(i), arq_aceitos.at(j).first))
            {
                if(res != -1)
                {
                    throw std::runtime_error("Erro: Mais de um arquivo de entrada.");
                }
                res = i;
                ext_arq = arq_aceitos.at(j).second;
            }

        }

    }
    return (res != -1) ? (std::make_pair(res, ext_arq)) : \
    throw std::runtime_error("Erro: Nao foi possivel localizar o arquivo na linha de comando.");
}

static int info_diretorio(const std::vector<std::string>& s_args) 
{
    int res = -1;

    for(size_t i = 0; i < s_args.size(); i++)
    {
        if(s_args.at(i)[s_args.at(i).length() - 1] != '/') continue;

        if(res != -1) throw std::runtime_error("Erro: Multiplos diretorios passados para a linha de comando!");

        res = i;
    }

    return (res != -1) ? (res) : \
    throw std::runtime_error("Erro: Nenhum diretorio foi encontrado! Passe um diretorio passando seu nome terminado em /");

}

static std::bitset<N_PERMS> set_flags(const std::vector<std::string>& s_args)
{
    std::bitset<N_PERMS> flags;
    for(int i = 0; i < s_args.size(); i++)
    {
        if(s_args.at(i)[0] != '-') continue;

        for(int j = 1; j < s_args.at(i).length(); j++)
        {
            switch(s_args.at(i)[j])
            {
                case V_FLAG_C:
                    flags.set(V_FLAG_P);
                    break;
                case C_FLAG_C:
                    flags.set(C_FLAG_P);
                    break;
                case H_FLAG_C:
                    flags.set(H_FLAG_P);
                    break;
                case D_FLAG_C:
                    flags.set(D_FLAG_P);
                    break;
                default:
                    throw std::runtime_error("Flag desconhecida passada!");
            }
        }

    }
    return flags;

}

args obter_args(const std::vector<std::string>& s_args)
{

    std::bitset<N_PERMS> flags = set_flags(s_args);

    if(flags.test(H_FLAG_P))
    {
        std::string dummy = ".";
        args args_g(dummy, dummy, C_ARQ, flags);
        return args_g;
    }

    std::pair<int, tipo_arq_t> par_arquivo_tipo = info_arquivo(s_args);
    std::string arq = s_args.at(par_arquivo_tipo.first);

    if(flags.test(D_FLAG_P))
    {
        std::string dummy = ".";
        args args_g(arq, dummy, par_arquivo_tipo.second, flags);
        return args_g;
    }

    std::string dir = s_args.at(info_diretorio(s_args));

    args args_g(arq, dir, par_arquivo_tipo.second, flags);

    if(args_g.obter_bits().test(V_FLAG_P)) a_print("Argumentos criados com str: ", args_g.obter_bits());

    return args_g;
}