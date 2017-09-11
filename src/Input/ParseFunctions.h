#ifndef POSITIONRECONSTRUCTION_SRC_INPUT_PARSEFUNCTIONS_H
#define POSITIONRECONSTRUCTION_SRC_INPUT_PARSEFUNCTIONS_H

#include<string>
#include<ostream>

namespace Input
{

namespace Data
{
class ConfigData;
}

bool parseConfigFile(Data::ConfigData* inParams, const std::string& inputFileName);

bool parseValAndPrintConfigFile(Data::ConfigData* inParams,
                                const std::string& inputFileName, std::ostream& os);

}
#endif //POSITIONRECONSTRUCTION_SRC_INPUT_PARSEFUNCTIONS_H
