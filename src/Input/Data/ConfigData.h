#ifndef POSITIONRECONSTRUCTION_SRC_INPUT_DATA_CONFIGDATA_H
#define POSITIONRECONSTRUCTION_SRC_INPUT_DATA_CONFIGDATA_H

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

class ConfigData
{
public:
    std::string detSpecInputFile;
    std::string detPosInputFile;
    std::string panelPosInputFile;
    std::string panelSpecOutputFile;
    std::string srcDataOutputFile;
    int numCores;
    float minEnergy;
    float maxEnergy;

    void setDetSpecInputFile(const std::string& input){detSpecInputFile = input; setDetSpecInputFile_ = true;}
    void setDetPosInputFile(const std::string& input){detPosInputFile = input; setDetPosInputFile_ = true;}
    void setPanelPosInputFile(const std::string& input){panelPosInputFile = input; setPanelPosInputFile_ = true;}
    void setPanelSpecOutputFile(const std::string& input){panelSpecOutputFile = input; setPanelSpecOutputFile_ = true;}
    void setSrcDataOutputFile(const std::string& input){srcDataOutputFile = input; setSrcDataOutputFile_ = true;}
    void setSetNumCores(int input){numCores = input; setNumCores_ = true;}
    void setMinEnergy(float input){minEnergy = input; setMinEnergy_ = true;}
    void setMaxEnergy(float input){maxEnergy = input; setMaxEnergy_ = true;}
    
    bool validate();
    void printValidationErrors(std::ostream& os);

    friend std::ostream& operator<<(std::ostream& os, const ConfigData& cd);
private:
    bool setDetSpecInputFile_;
    bool setDetPosInputFile_;
    bool setPanelPosInputFile_;
    bool setPanelSpecOutputFile_;
    bool setSrcDataOutputFile_;
    bool setNumCores_;
    bool setMinEnergy_;
    bool setMaxEnergy_;
};

}

}
#endif //POSITIONRECONSTRUCTION_SRC_INPUT_DATA_CONFIGDATA_H
