#include"ParseFunctions.h"

#include<fstream>

#include"Data/ConfigData.h"
#include"Parsers/ConfigParser.h"

typedef boost::spirit::istream_iterator It;

bool parseInputFile(ConfigData* inParams, const std::string& inputFileName)
{
    //make the parser, this line will make the compiler slow down a lot
    ConfigParser<It> configParser(inParams);
    //set up the file
    std::ifstream input(inputFileName);
    //unset the skip whitespace
    input.unsetf(std::ios::skipws);
    //set up the iterators
    It start(input), stop;
    //parse the input
    return boost::spirit::qi::parse(start, stop, configParser);
}
