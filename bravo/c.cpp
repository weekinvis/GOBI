#include "c.h"
#include "args.h"

#include <vector>
#include <string>
#include <unistd.h>

void c_modulo(args_t * args)
{
    std::vector<std::string> strArgs = {"gcc", "-O2", "-static"};
    
    [args](std::vector<std::string>& strArgs) -> void {
        for(arg_t arg : args->valores) 
        {
            if(arg.tipo == PROG_ARG)
            {
                strArgs.push_back(arg.valor);
                return;
            }
        }
    }(strArgs);

    std::vector<char*> cArgs;
    cArgs.reserve(strArgs.size() + 1); 

    for (std::string& str : strArgs) {
        cArgs.push_back(const_cast<char*>(str.c_str())); 
    }

    cArgs.push_back(nullptr); 

    execvp(cArgs[0], cArgs.data());

    std::perror("execvp failed");

}