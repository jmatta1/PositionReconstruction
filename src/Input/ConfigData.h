#ifndef POSITIONRECONSTRUCTION_SRC_INPUT_CONFIGDATA_H
#define POSITIONRECONSTRUCTION_SRC_INPUT_CONFIGDATA_H

// includes for C system headers
// includes for C++ system headers
#include<string>
// includes from other libraries
// includes from this code



class ConfigData
{
public:
    std::string detSpecInputFile;
    std::string detPosInputFile;
    std::string panelPosInputFile;
    std::string panelSpecOutputFile;
    std::string srcDataOutputFile;
    int numCores;

    void setDetSpecInputFile(const std::string& input){detSpecInputFile = input; setDetSpecInputFile_ = true;}
    void setDetPosInputFile(const std::string& input){detPosInputFile = input; setDetPosInputFile_ = true;}
    void setPanelPosInputFile(const std::string& input){panelPosInputFile = input; setPanelPosInputFile_ = true;}
    void setPanelSpecOutputFile(const std::string& input){panelSpecOutputFile = input; setPanelSpecOutputFile_ = true;}
    void setSrcDataOutputFile(const std::string& input){srcDataOutputFile = input; setSrcDataOutputFile_ = true;}
    void setSetNumCores(int input){numCores = input; setNumCores_ = true;}
    
    bool validate(){return (setDetSpecInputFile_ && setDetPosInputFile_ && setPanelPosInputFile_ &&
                            setPanelSpecOutputFile_ && setSrcDataOutputFile_ && setSetNumCores_);}
    void printValidationErrors();

    friend std::ostream& operator<<(std::ostream& os, const ConfigData& cd);
private:
    bool setDetSpecInputFile_;
    bool setDetPosInputFile_;
    bool setPanelPosInputFile_;
    bool setPanelSpecOutputFile_;
    bool setSrcDataOutputFile_;
    bool setSetNumCores_;
};

#endif //POSITIONRECONSTRUCTION_SRC_INPUT_CONFIGDATA_H
