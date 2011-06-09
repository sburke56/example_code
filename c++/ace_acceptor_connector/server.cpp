#include <iostream>
#include "ace/INET_Addr.h" 
#include "ace/SOCK_Acceptor.h" 
#include "ace/SOCK_Stream.h"

using namespace std;

int main(int argc, char *argv[])
{
    ACE_INET_Addr server_addr; 
    ACE_SOCK_Acceptor acceptor; 
    ACE_SOCK_Stream peer; 

    if (server_addr.set(30000, "localhost") == -1) return 1; 
    if (acceptor.open(server_addr) == -1) return 1; 

    while(1)
    {
        if (acceptor.accept(peer) == -1) return 1; 
        peer.disable(ACE_NONBLOCK); 
        
        char buf[BUFSIZ]; 
        size_t count = peer.recv(buf, sizeof buf); 
        cout << "Received " << count << " bytes from client: " << buf << endl; 
               
        // Send response back to the client. 
        string server_msg("hello world from server"); 
        if (peer.send_n(server_msg.c_str(), server_msg.size()) == -1)
            return 1; 
    }

    return acceptor.close() == -1 ? 1 : 0; 
}
