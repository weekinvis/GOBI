#include <iostream>
#include <stdexcept>
#include "erro.h"
#include "args.h"

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
    try {
        args_t * args = obtem_args(argc, argv);
    } catch(std::exception& exc)
    {
        std::cerr << exc.what() << std::endl;
        imprime_tutorial();
        return ERRO_COMUM;
    } 

    return SUCESSO;
}