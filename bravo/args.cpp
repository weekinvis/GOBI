#include "args.h"
#include <cassert>
#include <cstdlib>
#include <stdexcept>

int obter_indice_arg_programa(const int argc, const char * argv[])
{
    for(int i = 1; i < argc; i++)
    {

    }

}

args_t * obtem_args(const int argc, const char * argv[])
{
    args_t * args = (args_t*)malloc(sizeof(args_t));

    assert(args != NULL);

    if(argc <= 2) throw std::runtime_error("Erro: Esperado numero menor de argumentos.");
    if(argc > 3)  throw std::runtime_error("Erro: Esperado numero maior de argumentos.");
    

}