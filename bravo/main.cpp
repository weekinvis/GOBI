#include <iostream>
#include <stdexcept>
#include "erro.h"
#include "args.h"
#include "juiz.h"

static inline void imprime_tutorial()
{
    std::cerr << "╔═══════════════════════════════════════════════════════════════════╗\n" \
                 "║ Funcionamento:                                                    ║\n" \
                 "║═══════════════════════════════════════════════════════════════════║\n" \
                 "║   ./bravo programa.[extensao] pasta_com_testes/ -flags (opcional) ║\n" \
                 "╚═══════════════════════════════════════════════════════════════════╝\n" << \
                 std::endl;
}

int main(const int argc, const char * argv[])
{
    args_t * args;
    try {
        args = obtem_args(argc, argv);
    } catch(std::exception& exc)
    {
        std::cerr << exc.what() << std::endl;
        imprime_tutorial();
        return ERRO_COMUM;
    } 

    if(juiz(args)) return ERRO_COMUM;

    free(args);

    return SUCESSO;
}