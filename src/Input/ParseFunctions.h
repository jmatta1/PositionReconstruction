#ifndef POSITIONRECONSTRUCTION_SRC_INPUT_PARSEFUNCTIONS_H
#define POSITIONRECONSTRUCTION_SRC_INPUT_PARSEFUNCTIONS_H


// includes for C system headers
// includes for C++ system headers
#include<string>
#include<ostream>
// includes from other libraries
// includes from this code

namespace Input
{

namespace Data
{
class ConfigData;
class DetectorPositionData;
class PanelPositionData;
}

bool parseConfigFile(Data::ConfigData* inParams, const std::string& inputFileName);

bool parseValAndPrintConfigFile(Data::ConfigData* inParams,
                                const std::string& inputFileName, std::ostream& os);

bool parseDetectorPositionFile(Data::DetectorPositionData* inParams, const std::string& inputFileName);

bool parseValAndPrintDetectorPositionFile(Data::DetectorPositionData* inParams,
                                          const std::string& inputFileName, std::ostream& os);

bool parsePanelPositionFile(Data::PanelPositionData* inParams, const std::string& inputFileName);

bool parseValAndPrintPanelPositionFile(Data::PanelPositionData* inParams,
                                       const std::string& inputFileName, std::ostream& os);

}
#endif //POSITIONRECONSTRUCTION_SRC_INPUT_PARSEFUNCTIONS_H
