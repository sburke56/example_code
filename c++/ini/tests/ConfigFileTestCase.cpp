#include <cppunit/config/SourcePrefix.h>
#include "ConfigFileTestCase.h"
#include <memory> 
#include <fstream> 

CPPUNIT_TEST_SUITE_REGISTRATION( CConfigFileTestCase ); 

using namespace std; 

// void CConfigFileTestCase::example()
// {
//   CPPUNIT_ASSERT_DOUBLES_EQUAL( 1.0, 1.1, 0.05 );
//   CPPUNIT_ASSERT( 1 == 0 );
//   CPPUNIT_ASSERT( 1 == 1 );
// }


void CConfigFileTestCase::setUp()
{
    try 
    {
	m_ConfigFile = auto_ptr<CConfigFile>(new CConfigFile("options.cfg")); 
    }
    catch (const CfgException & e)
    {
	CPPUNIT_ASSERT(0); 
    }
    
}

void CConfigFileTestCase::tearDown()
{
}

void CConfigFileTestCase::getNumber()
{
    int num = m_ConfigFile->GetNumber(); 
    CPPUNIT_ASSERT(num == 5); 
}

void CConfigFileTestCase::getString()
{
    string str = m_ConfigFile->GetString(); 
    CPPUNIT_ASSERT(str == "hello world"); 
}

void CConfigFileTestCase::setNumber()
{
    int num = 25; 
    m_ConfigFile->SetNumber(num); 
    CPPUNIT_ASSERT(m_ConfigFile->GetNumber() == num); 
}

void CConfigFileTestCase::setString()
{
    string test = "test"; 
    m_ConfigFile->SetString(test); 
    CPPUNIT_ASSERT(m_ConfigFile->GetString() == test);
}

void CConfigFileTestCase::saveCfg()
{
    int num = 25; 
    string test = "test"; 

    ofstream ofs("test_file.cfg", ios::out);
    CConfigFile test_file("test_file.cfg"); 
    test_file.SetNumber(num); 
    test_file.SetString(test); 
    test_file.Save(); 

    CConfigFile new_file("test_file.cfg");
    //cout << endl << "num = " << new_file.GetNumber() << endl; 
    //cout << endl << "str = " << new_file.GetString() << endl; 
    CPPUNIT_ASSERT(new_file.GetNumber() == num); 
    CPPUNIT_ASSERT(new_file.GetString() == test);
}

