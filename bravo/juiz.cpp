#include <iostream>
#include "args.h"
#include "java.h"
#include "c.h"
#include "cpp.h"
#include "py.h"
#include "erro.h"

int j_main(const args& args)
{
    try 
    {
        switch(args.obter_extensao())
        {
            case PY_ARQ:
                if(args.obter_bits().test(V_FLAG_P)) a_print("Entrando em modulo Python");
                py_modulo(args);
                break;
            case C_ARQ:
                if(args.obter_bits().test(V_FLAG_P)) a_print("Entrando em modulo C");
                c_modulo(args);
                break;
            case CPP_ARQ:
                if(args.obter_bits().test(V_FLAG_P)) a_print("Entrando em modulo CPP");
                cpp_modulo(args);
                break;
            case JAVA_ARQ:
                if(args.obter_bits().test(V_FLAG_P)) a_print("Entrando em modulo Java");
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