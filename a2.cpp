#include <iostream>
using namespace std;

extern int main_use;

class A
{
    public:
        A()
        {
            ++main_use;
            cout << __FUNCTION__ << endl;
        }
};


static A a;


const char * a2()
{
    return __FUNCTION__;
}
