#include "Hiddenclass.hpp"

//using namespace std;

Hiddenclass::Hiddenclass(int a, int b) : hca(a), hcb(b) {;}
Hiddenclass::~Hiddenclass() {;}
int Hiddenclass::multiply() const { return hca * hcb; }
int Hiddenclass::divide() const { return hcb ? hca / hcb : 0; }
int Hiddenclass::add() const { return hca + hcb; }
int Hiddenclass::subtract() const { return hca - hcb; }

