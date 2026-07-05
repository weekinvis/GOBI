#pragma once
#ifndef _juiz_h__
#define _juiz_h__

#include "args.h"

#define UNZIP_COMANDO "unzip"
#define ANO_INICIO     1999
#define QNT_NIVEIS      4
#define QNT_FASES       3

enum class veredito 
{
    AC,
    WA,
    RE,
    TLE
};

int j_main(const args& args);

#endif