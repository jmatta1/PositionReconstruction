#include"ConfigData.h"

// includes for C system headers
// includes for C++ system headers
// includes from other libraries
// includes from this code

namespace Input
{
namespace Data
{

void ConfigData::printValidationErrors(std::ostream& os)
{
    if(setDetSpecInputFile_)
    {
        os << "The detector spectrum input file was not set" << std::endl;
    }
    if(setDetPosInputFile_)
    {
        os << "The detector position input file was not set" << std::endl;
    }
    if(setPanelPosInputFile_)
    {
        os << "The AD panel input file was not set" << std::endl;
    }
    if(setPanelSpecOutputFile_)
    {
        os << "The panel spectrum output file was not set" << std::endl;
    }
    if(setSrcDataOutputFile_)
    {
        os << "The source data output file was not set." << std::endl;
    }
    if(setNumCores_)
    {
        os << "The number of cores was not set." << std::endl;
    }
}


std::ostream& operator<<(std::ostream& os, const ConfigData& cd)
{
    os << "[Start Configuration Input]\n"
       << "    Detector Spectrum Input File  = " << cd.detSpecInputFile    << "\n"
       << "    Detector Position Input File  = " << cd.detPosInputFile     << "\n"
       << "    AD Panel Input File           = " << cd.panelPosInputFile   << "\n"
       << "    Panel Spectrum Output File    = " << cd.panelSpecOutputFile << "\n"
       << "    Source Data Ouput File        = " << cd.srcDataOutputFile   << "\n"
       << "    Number of Cores               = " << cd.numCores            << "\n";
    return os << "[End Configuration Input]";
}

}
}
