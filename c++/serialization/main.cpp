#include <iostream>
#include <istream>
#include <fstream>
#include "shoe.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    Shoe my_shoe("Mizuno", "running", 10.5, "red");
    //cout << my_shoe << endl;

    ofstream out_file("shoes.txt");
    out_file << my_shoe << endl;
    out_file.close();

    ifstream in_file("shoes.txt");

    Shoe in_shoe;
    in_file >> in_shoe;
    in_file.close();

    cout << "Shoes" << endl;
    cout << in_shoe;

    return 0;
}
