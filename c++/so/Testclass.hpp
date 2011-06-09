#ifndef _TESTCLASS_HPP_
#define _TESTCLASS_HPP_

#ifdef EXPAND_DLLEXPORT
#define DLLEXPORT(x) __declspec(dllexport)x
#else
#define DLLEXPORT(x) x
#endif

class Hiddenclass;

class DLLEXPORT(Testclass)
{
private:
    Hiddenclass *phc;
public:
    Testclass(int a, int b);
    ~Testclass();
    int multiply() const;
    int divide() const;
    int add() const;
    int subtract() const;
};

#endif
