#include "db_conn.hpp"
#include <iostream> 

using std::cout; 
using std::endl; 

DbConn::DbConn()
{
    cout << "DbConn::DbConn()" << endl; 
}

DbConn::~DbConn()
{
    cout << "DbConn::~DbConn()" << endl; 
    finalCleanup(); 
}

void DbConn::useConnection()
{
    cout << "Using database connection." << endl; 
}

void DbConn::closeConnectionNicely()
{
    cout << "Closing connection nicely." << endl; 
}

void DbConn::finalCleanup()
{
    cout << "Doing final cleanup of connection." << endl; 
}
