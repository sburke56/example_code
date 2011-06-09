#ifndef _DB_CONN_H
#define _DB_CONN_H

class DbConn
{
  public:
    DbConn();
    virtual ~DbConn();
    void useConnection(); 
    void closeConnectionNicely(); 
    
  private:
    DbConn(const DbConn&); 
    DbConn& operator=(const DbConn&); 
    void finalCleanup(); 
};
#endif

