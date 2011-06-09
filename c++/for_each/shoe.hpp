#ifndef SHOE_H
#define SHOE_H

#include <string> 

class Shoe
{
  public:
    Shoe(const std::string & name);
    virtual ~Shoe();

    Shoe(const Shoe&); 
    Shoe& operator=(const Shoe&); 

    std::string name() const; 

  private: 
    std::string name_; 
};
#endif

