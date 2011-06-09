#ifndef _DLL_BASE_CLASS_HPP_
#define _DLL_BASE_CLASS_HPP_

#ifdef EXPAND_DLLEXPORT
#define DLLEXPORT(x) __declspec(dllexport)x
#else
#define DLLEXPORT(x) x
#endif

class Hiddenclass;

class DLLEXPORT(DllBaseClass)
{
public:
    DllBaseClass();
    ~DllBaseClass();

    // public interface
    virtual void DoSomething();

private:
    Hiddenclass *phc;
};

#endif
