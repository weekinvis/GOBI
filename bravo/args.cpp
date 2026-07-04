#include "args.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <bitset>

tipo_arq_t args::obter_extensao() const 
{
    return this->arquivo_extensao;
}

const std::string& args::obter_diretorio_testes() const
{
    return this->diretorio_res_caminho;
}

void args::marcar_bit(const int pos)
{
    if(pos >= 0 && pos < 8) this->flags.set(pos);
}

const std::bitset<N_PERMS>& args::obter_bits() const
{
    return this->flags;
}

args::args(std::string& arq, std::string& dir, tipo_arq_t tipo) \
: arquivo_caminho(arq), diretorio_res_caminho(dir), arquivo_extensao(tipo)
{}

static bool termina_com(const std::string& alvo, const std::string& sufixo)
{
    if(alvo.length() < sufixo.length()) return false;

    return alvo.compare(alvo.length() - sufixo.length(), sufixo.length(), sufixo) == 0;
}

const std::string& args::obter_arquivo_caminho() const
{
    return this->arquivo_caminho;
}

static std::pair<int, tipo_arq_t> info_arquivo(const std::vector<std::string>& sArgs)
{
    int res = -1;
    tipo_arq_t ext_arq;

    std::vector<std::pair<std::string, tipo_arq_t>> arq_aceitos \
    = { {".py", PY_ARQ}, {".c", C_ARQ}, {".cpp", CPP_ARQ}, {".java", JAVA_ARQ}};

    for(size_t i = 0; i < sArgs.size(); i++)
    {
        if(sArgs.at(i)[0] == '-') continue;
        if(sArgs.at(i)[sArgs.at(i).length()-1] == '/') continue;

        for(size_t j = 0; j < arq_aceitos.size(); j++)
        {
            if(termina_com(sArgs.at(i), arq_aceitos.at(j).first))
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

static int info_diretorio(const std::vector<std::string>& sArgs) 
{
    int res = -1;

    for(size_t i = 0; i < sArgs.size(); i++)
    {
        if(sArgs.at(i)[sArgs.at(i).length() - 1] != '/') continue;

        if(res != -1) throw std::runtime_error("Erro: Multiplos diretorios passados para a linha de comando!");

        res = i;
    }

    return (res != -1) ? (res) : \
    throw std::runtime_error("Erro: Nenhum diretorio foi encontrado! Passe um diretorio passando seu nome terminado em /");

}

static void set_flags(const std::vector<std::string>& sArgs, args& args_g)
{
    for(int i = 0; i < sArgs.size(); i++)
    {
        if(sArgs.at(i)[0] != '-') continue;

        for(int j = 1; j < sArgs.at(i).length(); j++)
        {
            switch(sArgs.at(i)[j])
            {
                case V_FLAG_C:
                    args_g.marcar_bit(V_FLAG_P);
                    break;
                case C_FLAG_C:
                    args_g.marcar_bit(C_FLAG_P);
                    break;
            }
        }

    }

}

args obter_args(const std::vector<std::string>& sArgs)
{
    std::pair<int, tipo_arq_t> par_arquivo_tipo = info_arquivo(sArgs); 

    std::string arq = sArgs.at(par_arquivo_tipo.first);
    std::string dir = sArgs.at(info_diretorio(sArgs));

    args args_g(arq, dir, par_arquivo_tipo.second);

    set_flags(sArgs, args_g);

    if(args_g.obter_bits().test(V_FLAG_P)) a_print("Argumentos criados com str: ", args_g.obter_bits());

    return args_g;
}