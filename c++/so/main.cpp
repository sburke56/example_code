//
// Invoke a Shared Library
//

#include "Testclass.hpp"
#include <cassert>
#include <iostream> 

using namespace std; 

int main(int argc,char ** argv)
{
    Testclass t(20, 10);
    assert(t.multiply() == 200);
    assert(t.divide() == 2);
    assert(t.add() == 30);
    assert(t.subtract() == 10);
    cout << "All asserts passed" << endl; 
    return 0;
}
