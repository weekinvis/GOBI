#pragma once
#ifndef _args_h_
#define _args_h_

#include <cstdio>
#include <vector>
#include <string>
#include <bitset>

#define N_PERMS 8

#define V_FLAG_C 'v'
#define V_FLAG_P  0

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
        std::bitset<N_PERMS> flags;
        std::string diretorio_res_caminho;
    public:
        args(std::string& arq, std::string& dir, tipo_arq_t tipo);

        tipo_arq_t obter_extensao() const;

        void marcar_bit(const int pos);
        const std::bitset<N_PERMS>& obter_bits() const;

};

args obter_args(const std::vector<std::string>& sArgs);
void marcar_bit(const int pos);

#endif