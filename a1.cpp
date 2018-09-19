#include "toto.h"

#include <iostream>
using namespace std;

// un fichier contenant une fonction utilisée

int internal_use = 0;

const char *a1()
{
    ++internal_use;
    return __FUNCTION__;
}