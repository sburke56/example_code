// include log4cxx header files.
#include "log4cxx/logger.h"
#include "log4cxx/basicconfigurator.h"
#include "log4cxx/propertyconfigurator.h"
#include "log4cxx/helpers/exception.h"

using namespace log4cxx;
using namespace log4cxx::helpers;

// Define a static logger variable so that it references the
// Logger instance named "MyApp".
LoggerPtr logger(Logger::getLogger("MyApp"));

int main(int argc, char **argv)
{
  int result = 0;
  try
    {
      if (argc > 1)
	{
	  //
	  // Used the config file passed into the program 
	  // to setup the logger & appenders & layouts
	  //
	  // BasicConfigurator replaced with PropertyConfigurator.
	  PropertyConfigurator::configure(argv[1]);
	}
      else
	{
	  BasicConfigurator::configure();
	}

      LOG4CXX_INFO(logger, "Entering application.");

      LOG4CXX_ERROR(logger, "Testing" << "an" << "Error message."); 
      LOG4CXX_FATAL(logger, "Testing" << "a" << "Fatal message."); 

      LOG4CXX_INFO(logger, "Exiting application.");
    }
  catch(Exception&)
    {
      result = 1;
    }

  return result;
}
