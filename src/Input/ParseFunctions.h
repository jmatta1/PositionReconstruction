#ifndef POSITIONRECONSTRUCTION_SRC_INPUT_PARSEFUNCTIONS_H
#define POSITIONRECONSTRUCTION_SRC_INPUT_PARSEFUNCTIONS_H

#include<string>
class ConfigData;

bool parseInputFile(ConfigData* inParams, const std::string& inputFileName);

#endif //POSITIONRECONSTRUCTION_SRC_INPUT_PARSEFUNCTIONS_H
