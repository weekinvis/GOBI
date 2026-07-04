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
                 "║               digite `./bravo -h` para obter ajuda                ║\n" \
                 "╚═══════════════════════════════════════════════════════════════════╝\n" << \
                 std::endl;
}

static inline void imprime_ajuda()
{
    std::cout << "./bravo" << std::endl;
    std::cout << "Todos os diretorios devem ser encerrados em `/`." << std::endl;
    std::cout << "teste/, respostas/, /algo/ <- Esses sao exemplos de argumentos reconhecidos como diretorio." << std::endl;
    std::cout << "Todas as flags devem ser indicadas por `-`." << std::endl;
    std::cout << "-h (ajuda), -v (imprimir mensagens de execucao), -hv ou -vh (ambas as funcionalidades)." << std::endl;
    std::cout << "As flags disponiveis sao: -h (ajuda), -v (imprimir mensagens de execucao), -c (nao recompilar o programa a ser testado), -d (apenas recompilar o programa e nao testar)." << std::endl;
    std::cout << "Os arquivos de teste devem ser passados com sua extensao (programa.c), (programa.py), etc... " << std::endl;
    std::cout << "Atualmente, o programa aceita python, java, c++ e c." << std::endl;
}

int main(const int argc, const char * argv[])
{
    std::vector<std::string> s_args;
    s_args.reserve(argc - 1);
    
    for(int i = 1; i < argc; i++) s_args.push_back(argv[i]);

    try {
        args j_args = obter_args(s_args);

        if(!j_args.obter_bits().test(H_FLAG_P)) j_main(j_args);
        else imprime_ajuda();

    } catch(std::exception& exc)
    {
        std::cerr << exc.what() << std::endl;
        imprime_tutorial();
        return ERRO_COMUM;
    }

    return SUCESSO;
}