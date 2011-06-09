#include <iostream>
#include <string>

#include "cmd_line_utils.hpp"

using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[])
{
    try
    {
        CmdLineUtils::parseCmdLine(argc, argv);

        if (g_vm.count("help"))
        {
            cout << g_desc << "\n";
            return 1;
        }

        if (g_vm.count("top-level-dir"))
        {
            cout << "top-level-dir was set to "
                 << g_vm["top-level-dir"].as<string>() << ".\n";
        }
        else
        {
            cout << "top-level-dir was not set.\n";
        }
    }
    catch (...)
    {
        cout << "Caught exception, all bets are off for command arguments.\n";
    }

    return 0;
}
