#ifndef _DECLARE_SINGLETON_H
#define _DECLARE_SINGLETON_H

#define DECLARE_SINGLETON(cls) \
protected: \
   static cls* pInst; \
   cls(); \
public: \
   static cls* instance(); \
private:

#define DEFINE_SINGLETON(cls) \
cls* cls::pInst=NULL; \
cls* cls::instance() { \
   if (pInst) return pInst; \
   else return pInst=new cls; }

#endif

#endif
