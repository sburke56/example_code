#ifndef TEST_EXCEPTION_HPP 
#define TEST_EXCEPTION_HPP

class testException : std::exception
{
  public: 
    virtual const char* what() const throw()
    {
	return "test exception"; 
    }
};

#endif 
