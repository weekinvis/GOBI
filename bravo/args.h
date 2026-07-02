#pragma once
#ifndef _args_h_
#define _args_h_

#include <cstdio>
#include <vector>
#include <string>

typedef unsigned char byte_t;

typedef enum tipo_arq_e 
{
    C_ARQ,
    CPP_ARQ,
    PY_ARQ,
    JAVA_ARQ
} tipo_arq_t;

class args 
{
    private:
        std::string arquivo_caminho;
        tipo_arq_t arquivo_extensao;
        byte_t flags;
        std::string diretorio_res_caminho;
    public:
        args(std::string& arq, byte_t flags, std::string& dir, tipo_arq_t tipo);

        tipo_arq_t obter_extensao() const;

};

args obter_args(const std::vector<std::string>& sArgs);

#endif