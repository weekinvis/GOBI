#pragma once
#ifndef _args_h_
#define _args_h_

#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <iostream>

#define N_PERMS 8

#define V_FLAG_C 'v' // para imprimir infos
#define C_FLAG_C 'c' // para nao recompilar
#define H_FLAG_C 'h' // ajuda
#define D_FLAG_C 'd' // para so recompilar

#define V_FLAG_P  0
#define C_FLAG_P  1
#define H_FLAG_P  2
#define D_FLAG_P  3

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
        args(std::string& arq, std::string& dir, tipo_arq_t tipo, std::bitset<N_PERMS>& flags_);

        tipo_arq_t obter_extensao() const;
        const std::string& obter_arquivo_caminho() const;
        const std::string& obter_diretorio_testes() const;

        const std::bitset<N_PERMS>& obter_bits() const;

};

args obter_args(const std::vector<std::string>& sArgs);
void marcar_bit(const int pos);

inline void rec_print()
{
}

template <typename T, typename... Args>
void rec_print(T first, Args... args)
{
    std::cout << first << " ";
    rec_print(args...);
}

template <typename T, typename... Args>
void a_print(T first, Args... args)
{
    std::cout << "[] " << first << " ";
    rec_print(args...);
    std::cout << std::endl;
}

#endif