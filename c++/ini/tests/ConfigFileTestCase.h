#ifndef CONFIG_FILE_TEST_CASE_H
#define CONFIG_FILE_TEST_CASE_H

#include <cppunit/extensions/HelperMacros.h>
#include <memory> 
#include "ConfigFile.hpp" 

/* 
 * Test cases for the CConfigFile class 
 *
 */

class CConfigFileTestCase : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( CConfigFileTestCase );
    CPPUNIT_TEST( getNumber );
    CPPUNIT_TEST( getString );
    CPPUNIT_TEST( setNumber );
    CPPUNIT_TEST( setString );
    CPPUNIT_TEST( saveCfg );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown(); 

protected:
    void getNumber();
    void getString(); 
    void setNumber(); 
    void setString();
    void saveCfg(); 

    std::auto_ptr<CConfigFile> m_ConfigFile;
};


#endif
