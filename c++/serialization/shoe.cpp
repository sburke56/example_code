#include "shoe.hpp"

using std::ostream;
using std::istream;
using std::cout;
using std::endl;

Shoe::Shoe()
{
}

Shoe::Shoe(const std::string& brand,
           const std::string& type,
           float size,
           const std::string& color)
        : _brand(brand),
          _type(type),
          _size(size),
          _color(color)
{
}

Shoe::~Shoe()
{
}

ostream& operator<<(ostream& out, const Shoe& shoe)
{
    out << shoe._brand << ":";
    out << shoe._type << ":";
    out << shoe._size << ":";
    out << shoe._color << ":";

    return out;
}

istream& operator>>(istream& in, Shoe& shoe)
{
    in >> shoe._brand;
    in >> shoe._type;
    in >> shoe._size;
    in >> shoe._color;

    return in;
}
