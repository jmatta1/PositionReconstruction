#include"ParseFunctions.h"

#include<fstream>

#include"Data/ConfigData.h"
#include"Parsers/ConfigParser.h"

namespace Input
{

typedef boost::spirit::istream_iterator It;

bool parseConfigFile(Data::ConfigData* inParams, const std::string& inputFileName)
{
    //make the parser, this line will make the compiler slow down a lot
    Parsers::ConfigParser<It> configParser(inParams);
    //set up the file
    std::ifstream input(inputFileName);
    //unset the skip whitespace
    input.unsetf(std::ios::skipws);
    //set up the iterators
    It start(input), stop;
    //parse the input
    return boost::spirit::qi::parse(start, stop, configParser);
}

bool parseValAndPrintConfigFile(Data::ConfigData* inParams,
                                const std::string& inputFileName, std::ostream& os)
{
    os << "Reading Configuration Data from: " << inputFileName << std::endl;
    bool parseSuccess = parseConfigFile(inParams, inputFileName);
    if(!parseSuccess)
    {
        os<<"Could not parse "<<inputFileName<<std::endl;
        return false;
    }
    
    if(!inParams->validate())
    {
        os << "Could not validate configuration data" << std::endl;
        inParams->printValidationErrors();
        return false;
    }
    
    os << "Input configuration is:"<<std::endl;
    os << *inParams << std::endl;
    return true;
}

}
