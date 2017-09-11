#include"ParseFunctions.h"
// includes for C system headers
// includes for C++ system headers
#include<fstream>
// includes from other libraries
// includes from this code
#include"Data/ConfigData.h"
#include"Data/DetectorPositionData.h"
#include"Data/PanelPositionData.h"
#include"Parsers/ConfigParser.h"
#include"Parsers/DetectorPositionParser.h"
#include"Parsers/PanelPositionParser.h"

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
        inParams->printValidationErrors(os);
        return false;
    }
    return true;
}

bool parseDetectorPositionFile(Data::DetectorPositionData* inParams, const std::string& inputFileName)
{
    //make the parser, this line will make the compiler slow down a lot
    Parsers::DetectorPositionParser<It> detectorPositionParser(inParams);
    //set up the file
    std::ifstream input(inputFileName);
    //unset the skip whitespace
    input.unsetf(std::ios::skipws);
    //set up the iterators
    It start(input), stop;
    //parse the input
    return boost::spirit::qi::parse(start, stop, detectorPositionParser);
}

bool parseValAndPrintDetectorPositionFile(Data::DetectorPositionData* inParams,
                                          const std::string& inputFileName, std::ostream& os)
{
    os << "Reading Configuration Data from: " << inputFileName << std::endl;
    bool parseSuccess = parseDetectorPositionFile(inParams, inputFileName);
    if(!parseSuccess)
    {
        os<<"Could not parse "<<inputFileName<<std::endl;
        return false;
    }
    
    if(!inParams->validate())
    {
        os << "Could not validate configuration data" << std::endl;
        inParams->printValidationErrors(os);
        return false;
    }
    return true;
}

bool parsePanelPositionFile(Data::PanelPositionData* inParams, const std::string& inputFileName)
{
    //make the parser, this line will make the compiler slow down a lot
    Parsers::PanelPositionParser<It> detectorPositionParser(inParams);
    //set up the file
    std::ifstream input(inputFileName);
    //unset the skip whitespace
    input.unsetf(std::ios::skipws);
    //set up the iterators
    It start(input), stop;
    //parse the input
    return boost::spirit::qi::parse(start, stop, detectorPositionParser);
}

bool parseValAndPrintPanelPositionFile(Data::PanelPositionData* inParams,
                                       const std::string& inputFileName, std::ostream& os)
{
    os << "Reading Configuration Data from: " << inputFileName << std::endl;
    bool parseSuccess = parsePanelPositionFile(inParams, inputFileName);
    if(!parseSuccess)
    {
        os<<"Could not parse "<<inputFileName<<std::endl;
        return false;
    }
    
    if(!inParams->validate())
    {
        os << "Could not validate configuration data" << std::endl;
        inParams->printValidationErrors(os);
        return false;
    }
    return true;
}


}
