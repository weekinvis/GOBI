#pragma once
#ifndef _args_h_
#define _args_h_

#include <cstdio>

typedef unsigned char byte_t;

typedef enum tipo_arg_e 
{
    RESP_ARG,
    PROG_ARG
} tipo_arg_t;

typedef struct arg_s 
{
    char * valor;
    tipo_arg_t tipo;

} arg_t;

typedef struct args_s 
{
    arg_t * valores;
    size_t num_arg;
    byte_t flags;
} args_t;

args_t * obtem_args(const int argc, const char * argv[]);

#endif