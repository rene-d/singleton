#include "toto.h"
#include <iostream>
using namespace std;

extern const char *a1();
extern const char *a2();
extern int init_a2;

int main_use = 0;


int main(int argc, char *argv[])
{
    cout << __FUNCTION__ << endl;

    cout << "appel " << a1() << endl;
#ifdef USE_FUNC_A2
    // appelle une fonction du fichier a2.cpp
    cout << "appel " << a2() << endl;
#endif
#ifdef USE_VAR_A2
    // sollicite une variable du fichier a2.cpp
    init_a2 = 0;
#endif

    // affiche 0 si on n'est pas initialisé le singleton de a2.cpp
    cout << "main_use " << main_use << endl;

    if (argc < 2)
        return 0;

    return std::stoi(argv[1]) == main_use ? 0 : 2;
}
