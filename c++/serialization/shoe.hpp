#ifndef _SHOE_H
#define _SHOE_H

#include <iostream>
#include <string>

class Shoe
{
  public:
    Shoe();
    Shoe(const std::string& brand,
         const std::string& type,
         float size,
         const std::string& _color);
    virtual ~Shoe();

  private:
    friend std::ostream& operator<<(std::ostream& out, const Shoe& shoe);
    friend std::istream& operator>>(std::istream& in, Shoe& shoe);


    Shoe(const Shoe&);
    Shoe& operator=(const Shoe&);

    std::string _brand;
    std::string _type;
    float _size;
    std::string _color;
};
#endif                                          \

