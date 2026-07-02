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
    std::vector<std::string> s_args;
    s_args.reserve(argc - 1);
    
    for(int i = 1; i < argc; i++) s_args.push_back(argv[i]);

    std::optional<args> j_args;

    try {
        j_args = obter_args(s_args);
    
    } catch(std::exception& exc)
    {
        std::cerr << exc.what() << std::endl;
        imprime_tutorial();
        return ERRO_COMUM;
    }

    j_main(j_args.value());

    return SUCESSO;
}