#include"ConfigData.h"

// includes for C system headers
// includes for C++ system headers
// includes from other libraries
// includes from this code

namespace Input
{
namespace Data
{

bool ConfigData::validate()
{
    bool allSet =  (setDetSpecInputFile_ && setDetPosInputFile_ &&
                    setPanelPosInputFile_ && setPanelSpecOutputFile_ &&
                    setSrcDataOutputFile_ && setNumCores_ &&
                    setMinEnergy_ && setMaxEnergy_);
    
    bool goodParams = ((minEnergy >= 0.0) && (minEnergy < maxEnergy));
    
    return (allSet && goodParams);
}

void ConfigData::printValidationErrors(std::ostream& os)
{
    if(!setDetSpecInputFile_)
    {
        os << "The detector spectrum input file was not set" << std::endl;
    }
    if(!setDetPosInputFile_)
    {
        os << "The detector position input file was not set" << std::endl;
    }
    if(!setPanelPosInputFile_)
    {
        os << "The AD panel input file was not set" << std::endl;
    }
    if(!setPanelSpecOutputFile_)
    {
        os << "The panel spectrum output file was not set" << std::endl;
    }
    if(!setSrcDataOutputFile_)
    {
        os << "The source data output file was not set." << std::endl;
    }
    if(!setNumCores_)
    {
        os << "The number of cores was not set." << std::endl;
    }
    if(!setMinEnergy_)
    {
        os << "The minimum energy was not set." << std::endl;
    }
    if(!setMaxEnergy_)
    {
        os << "The maximum energy was not set." << std::endl;
    }
    if(minEnergy < 0.0)
    {
        os << "The minimum energy must be greater than or equal to 0.0" << std::endl;
    }
    if(minEnergy >= maxEnergy)
    {
        os << "The minimum energy less than the maximum energy" << std::endl;
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
       << "    Number of Cores               = " << cd.numCores            << "\n"
       << "    Minimum Energy (MeV)          = " << cd.minEnergy           << "\n"
       << "    Maximum Energy (MeV)          = " << cd.maxEnergy           << "\n";
    return os << "[End Configuration Input]";
}

}
}
