// c'est le fichier embêtant...
// il contient un singleton qu'il faut à tout prix initialiser

#include "toto.h"
#include <iostream>
using namespace std;

extern int main_use;            // déclaré dans z.cpp (exécutable)
extern int internal_use;        // déclaré dans a1.cpp (ce module)


// la classe du singleton
class A
{
public:
    A()
    {
        ++main_use;
        ++internal_use;
        cout << __FUNCTION__ << endl;
    }
};

// le singleton pourri
static A a;


// une fonction quelconque
const char *a2()
{
    return __FUNCTION__;
}

// une variable quelconque
int init_a2;
