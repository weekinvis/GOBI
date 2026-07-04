#pragma once
#ifndef _juiz_h__
#define _juiz_h__

#include "args.h"

enum class veredito 
{
    AC,
    WA,
    RE,
    TLE
};

int j_main(const args& args);

#endif