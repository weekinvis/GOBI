#include <iostream>
#include <stdexcept>
#include <optional>
#include "erro.h"
#include "args.h"
#include "juiz.h"

static inline void imprime_tutorial()
{
    std::cerr << "╔═══════════════════════════════════════════════════════════════════╗\n" \
                 "║ Funcionamento:                                                    ║\n" \
                 "║═══════════════════════════════════════════════════════════════════║\n" \
                 "║   ./bravo programa.[extensao] pasta_com_testes/ -flags (opcional) ║\n" \
                 "║           exemplo: ./bravo main.c 2024PMTestes/ -av               ║\n" \
                 "╚═══════════════════════════════════════════════════════════════════╝\n" << \
                 std::endl;
}

int main(const int argc, const char * argv[])
{
    std::vector<std::string> sArgs;
    sArgs.reserve(argc - 1);
    
    for(int i = 1; i < argc; i++) sArgs.push_back(argv[i]);

    std::optional<args> jArgs;

    try {
        jArgs = obter_args(sArgs);
    
    } catch(std::exception& exc)
    {
        std::cerr << exc.what() << std::endl;
        imprime_tutorial();
        return ERRO_COMUM;
    }

    return SUCESSO;
}