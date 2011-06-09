#ifndef _CONFIG_FILE_H
#define _CONFIG_FILE_H

#include <string> 
#include <exception>
#include "SimpleIni.h"

class CConfigFile 
{
public: 
    CConfigFile(const std::string & file); 
    ~CConfigFile(); 

    int GetNumber(); 
    std::string GetString(); 
    void SetNumber(int num); 
    void SetString(const std::string & str);
    void Save(); 

private: 
    std::string _file; 
    bool _tainted; 
    bool _utf8; 
    bool _multi_key; 
    bool _use_multi_line; 
    CSimpleIniA _cfg; 
};

class CfgException : public std::exception
{
    virtual const char* what() const throw()
    {
	return "config file exception"; 
    }
};

#endif 
