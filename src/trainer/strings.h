#ifndef _STRINGS_H
#define _STRINGS_H

#include "types.h"

extern char *D_80799E20[];

enum {
#define DEFINE_STRING(name, str) name
#include "_strings.h"
#undef DEFINE_STRING
};

#endif