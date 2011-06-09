#include <iostream>
#include <string>
#include <exception> 
#include "test_exception.hpp" 
#include "db_conn.hpp" 
#include <boost/shared_ptr.hpp> 
#include <boost/make_shared.hpp> 

using std::cout;
using std::endl;
using std::string;

typedef boost::shared_ptr<DbConn> dbPtr;

int main(int argc, char *argv[])
{
    try
    {        
#ifdef USE_AUTO_PTR
        dbPtr amazon_s3;
        // Using make_shared factory function which is same as 
        // amazon_s3 = boost::shared_ptr<DbConn>(new DbConn); 
        amazon_s3 = boost::make_shared<DbConn>(); 
#else 
        DbConn* amazon_s3 = new DbConn(); 
#endif 
        cout << "About to throw an exception." << endl; 
        throw testException(); 
        amazon_s3->useConnection();
        amazon_s3->closeConnectionNicely(); 
    }
    catch (const testException & e)
    {
        cout << e.what() << endl; 
    }
    catch (...)
    {
        cout << "Caught exception, all bets are off." << endl;
    }

    return 0;
}
