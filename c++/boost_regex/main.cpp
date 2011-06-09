#include <iostream>
#include <string>
#include <boost/regex.hpp> 

using namespace std; 
using boost::regex; 

int main(int argc, char *argv[])
{
    // In order to match the entire name with a space use tick marks around it.
    regex regex_name("Stephen Burke");
    regex regex_date("\\d\\d/\\d\\d/\\d\\d\\d\\d"); 

    if (argc < 2)
    {
        cout << "Enter string to match regex against.\n"; 
        cout << "Regex1: " << regex_name.str() << endl; 
        cout << "Regex2: " << regex_date.str() << endl; 
        return 1; 
    }
    
    string input_str(argv[1]); 

    cout << "Name regex matches: " << boolalpha << regex_match(input_str, regex_name) << endl; 
    cout << "Date regex matches: " << boolalpha << regex_match(input_str, regex_date) << endl; 

    // The algorithms regex_search and regex_match make use of
    // match_results to report what matched; the difference between
    // these algorithms is that regex_match will only find matches
    // that consume all of the input text, where as regex_search will
    // search for a match anywhere within the text being matched.
    return 0;
}
