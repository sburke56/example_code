#include "shoe.hpp"

using namespace std; 

Shoe::Shoe(const string& name) : name_(name)
{
}

Shoe::~Shoe()
{
}

Shoe::Shoe(const Shoe& rhs)
{
    this->name_ = rhs.name(); 
} 

Shoe& Shoe::operator=(const Shoe& rhs)
{
    if (this != &rhs) 
    {
        this->name_ = rhs.name(); 
    }
    
    return *this; 
}

string Shoe::name() const 
{
    return name_; 
}
