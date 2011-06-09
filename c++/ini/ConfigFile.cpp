#include "ConfigFile.hpp" 
#include <iostream> 
#include <cassert> 
#include <sstream> 

using namespace std; 

// sections
const string section = ""; 
// keys 
const string key_number = "number"; 
const string key_string = "string"; 
const string key_monitors = "monitors"; 
const string key_resolution = "resolution"; 

CConfigFile::CConfigFile(const string & file) :
    _file(file),
    _tainted(false), 
    _utf8(false),
    _multi_key(false),
    _use_multi_line(false)
{
    _cfg.SetUnicode(_utf8); 
    _cfg.SetMultiKey(_multi_key); 
    _cfg.SetMultiLine(_use_multi_line);
    
    SI_Error rc = _cfg.LoadFile(_file.c_str()); 

    if (rc < 0)
    {
	_tainted = true; 
	throw CfgException(); 
    }
}

CConfigFile::~CConfigFile()
{

}

int CConfigFile::GetNumber()
{
    assert(!_tainted); 
    return _cfg.GetLongValue(section.c_str(), key_number.c_str());
}

string CConfigFile::GetString()
{
    assert(!_tainted); 
    return string(_cfg.GetValue(section.c_str(), key_string.c_str()));
}

void CConfigFile::SetNumber(int num)
{
    assert(!_tainted);
    
    stringstream mystr; 
    mystr << num; 

    _cfg.SetValue(section.c_str(), key_number.c_str(), mystr.str().c_str()); 
}

void CConfigFile::SetString(const string & str)
{
    assert(!_tainted); 
    _cfg.SetValue(section.c_str(), key_string.c_str(), str.c_str()); 
}

void CConfigFile::Save()
{
    assert(!_tainted); 
    int rc = _cfg.SaveFile(_file.c_str()); 

    if (rc < 0)
    {
	_tainted = true; 
	throw new CfgException(); 
    }
}
