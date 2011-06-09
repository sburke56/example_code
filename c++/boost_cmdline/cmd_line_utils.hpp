#include <string>
#include <boost/program_options.hpp>

using std::string;

namespace po = boost::program_options;

static po::variables_map g_vm;
static po::options_description g_desc;

struct CmdLineUtils
{
    static void parseCmdLine(int argc, char *argv[])
    {
        // Declare the supported options.
        g_desc.add_options()
                ("help", "produce help message")
                ("top-level-dir", po::value<string>(), "set top level directory to parse");

        //
        // Declare positional options which is
        // "argument" in the following line
        //  ./prog argument
        //
        po::positional_options_description p;
        p.add("top-level-dir", -1);

        //
        // Parse the command line & store the info
        //
        po::store(po::command_line_parser(argc, argv).options(g_desc).positional(p).run(), g_vm);
        //
        // Commit the info to the variable map
        //
        po::notify(g_vm);
    }
};
