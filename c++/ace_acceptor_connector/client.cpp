#include <stdlib.h> 
#include <iostream>
#include "ace/INET_Addr.h" 
#include "ace/SOCK_Connector.h" 
#include "ace/SOCK_Stream.h" 
#include "ace/Log_Msg.h" 

using namespace std;

int main(int argc, char *argv[])
{
    const char* server_hostname = 
            argc > 1 ? argv[1] : "localhost"; 
    const size_t server_port = 
            argc > 2 ? atoi(argv[2]) : 30000; 

    ACE_SOCK_Connector connector; 
    ACE_SOCK_Stream peer; 
    ACE_INET_Addr peer_addr; 

    // Blocks until a connection is established. 
    if (peer_addr.set(server_port, server_hostname) == -1)
        return 1; 
    else if (connector.connect(peer, peer_addr) == -1)
        ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "connect()"), 1);

    string client_msg("hello world from client"); 
    if (peer.send_n(client_msg.c_str(), client_msg.size()) == -1)
        return 1; 

    char buf[BUFSIZ]; 
    // Receive a response from server. 
    size_t count = peer.recv(buf, sizeof buf); 
    cout << "Received " << count << " bytes from server: " << buf << endl; 
    
    return peer.close() == -1 ? 1 : 0; 
}
