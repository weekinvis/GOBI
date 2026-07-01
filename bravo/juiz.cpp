#include <iostream>
#include "args.h"
#include "java.h"
#include "c.h"
#include "cpp.h"
#include "py.h"
#include "erro.h"

int juiz(args_t * args)
{
    try 
    {
        switch(args->extensao)
        {
            case PY_ARQ:
                py_modulo(args);
                break;
            case C_ARQ:
                c_modulo(args);
                break;
            case CPP_ARQ:
                cpp_modulo(args);
                break;
            case JAVA_ARQ:
                java_modulo(args);
                break;
        }
        return SUCESSO;

    } catch(std::exception& exp)
    {
        std::cerr << exp.what() << std::endl;
        return ERRO_COMUM;
    }

}