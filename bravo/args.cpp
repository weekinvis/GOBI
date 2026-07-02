#include "args.h"
#include <stdexcept>
#include <string>

tipo_arq_t args::obter_extensao() const 
{
    return this->arquivo_extensao;
}

args::args(std::string& arq, byte_t flags_, std::string& dir, tipo_arq_t tipo) \
: arquivo_caminho(arq), flags(flags_), diretorio_res_caminho(dir), arquivo_extensao(tipo)
{}

static bool termina_com(const std::string& alvo, const std::string& sufixo)
{
    if(alvo.length() < sufixo.length()) return false;

    return alvo.compare(alvo.length() - sufixo.length(), sufixo.length(), sufixo) == 0;
}

static std::pair<int, tipo_arq_t> info_arquivo(const std::vector<std::string>& sArgs)
{
    int res = -1;
    tipo_arq_t ext_arq;

    std::vector<std::string> arq_aceitos = {".py", ".c", ".cpp", ".java"};

    for(size_t i = 0; i < sArgs.size(); i++)
    {
        if(sArgs.at(i)[0] == '-') continue;
        if(sArgs.at(i)[sArgs.at(i).length()-1] == '/') continue;

        for(const std::string& ext_aceita : arq_aceitos)
        {
            if(termina_com(sArgs.at(i), ext_aceita))
            {
                if(res != -1)
                {
                    throw std::runtime_error("Erro: Multiplos arquivos passados para a linha de comando!");
                }
                res = i;

                if(sArgs.at(i) == ".py") ext_arq = PY_ARQ;
                if(sArgs.at(i) == ".c") ext_arq = C_ARQ;
                if(sArgs.at(i) == ".cpp") ext_arq = CPP_ARQ;
                if(sArgs.at(i) == ".java") ext_arq = JAVA_ARQ;

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

byte_t info_flags(const std::vector<std::string> sArgs)
{
    return 1;
}

args obter_args(const std::vector<std::string>& sArgs)
{
    std::pair<int, tipo_arq_t> par_arquivo_tipo = info_arquivo(sArgs); 

    std::string vr = sArgs.at(par_arquivo_tipo.first);
    std::string vi = sArgs.at(info_diretorio(sArgs));
    
    return args(vr, info_flags(sArgs), vi, par_arquivo_tipo.second);
}