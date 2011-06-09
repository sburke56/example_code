#include <iostream>
#include <algorithm> 
#include <vector> 
#include <string> 
#include "shoe.hpp" 

using namespace std;

struct lace : public unary_function<Shoe, void>
{
    lace() {}
    void operator()(Shoe x) const 
    { 
        cout << "operating on shoe" << x.name() << endl; 
    }
};

struct name : public binary_function<Shoe, string, void>
{
    name() {}
    void operator()(Shoe x, const string& extra_data) const 
    { 
        cout << "shoe name: " << x.name() << endl; 
        cout << "extra data: " << extra_data << endl; 
    }
};

int main(int argc, char *argv[])
{
    vector<Shoe> myShoes; 
    
    myShoes.push_back(Shoe("nike")); 
    myShoes.push_back(Shoe("reabok")); 
    myShoes.push_back(Shoe("new balance")); 


    for_each(myShoes.begin(), myShoes.end(), lace()); 
    for_each(myShoes.begin(), myShoes.end(), bind2nd(name(), "extra_data")); 

    return 0;
}
