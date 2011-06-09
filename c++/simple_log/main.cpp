// 
// Two compilation flags are used to set up 
// this logging scheme.  
// 
// LOGGING_ENABLED allows logging to occur, otherwise 
// the logging code is never executed
// 
// FILELOG_MAX_LEVEL=[1-4] sets the logging level to 
// the specified number.  Any log calls with levels lower 
// than the number specied are not output. 
// 
#include "log.h"

int main(int argc, char* argv[])
{
  try
    {
      // levels: logERROR, logWARNING, logINFO, logDEBUG, 
      // logDEBUG1, logDEBUG2, logDEBUG3, logDEBUG4
      
      //
      // Set a reporting level
      //
      FILELog::ReportingLevel() = FILELog::FromString("DEBUG4");

      //
      // Set an output file
      //
      FILE* pFile = fopen("application.log", "a");
      Output2FILE::Stream() = pFile;

      const int count = 3;
      FILE_LOG(logDEBUG) << "A loop with " << count << " iterations";
      for (int i = 0; i != count; ++i)
        {
	  FILE_LOG(logDEBUG1) << "the counter i = " << i;
        }
      return 0;
    }
  catch(const std::exception& e)
    {
      FILE_LOG(logERROR) << e.what();
    }
  return -1;
}
