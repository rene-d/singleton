#include "toto.h"

#include <iostream>
using namespace std;


// un truc qui ne sert à rien

static const char *dummy = "EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE" \
                           "EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE" \
                           "EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE";

// si on décommente ceci, le test 2 (et uniquement ce test) affichera dummy
//void b() __attribute__((constructor));

void b()
{
    cout << __FUNCTION__ << dummy << endl;
}
