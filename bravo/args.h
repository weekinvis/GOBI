#pragma once
#ifndef _args_h_
#define _args_h_

#include <cstdio>
#include <vector>
#include <string>

typedef unsigned char byte_t;

typedef enum tipo_arg_e 
{
    RESP_ARG,
    PROG_ARG,
    FLAG_ARG
} tipo_arg_t;

typedef enum tipo_arq_e 
{
    C_ARQ,
    CPP_ARQ,
    PY_ARQ,
    JAVA_ARQ
} tipo_arq_t;

typedef struct arg_s 
{
    std::string valor;
    tipo_arg_t tipo;

} arg_t;

typedef struct args_s 
{
    std::vector<arg_t> valores;
    byte_t flags;
    tipo_arq_t extensao;
} args_t;

args_t * obtem_args(const int argc, const char * argv[]);

#endif