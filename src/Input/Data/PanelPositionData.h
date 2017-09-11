#ifndef POSITIONRECONSTRUCTION_SRC_INPUT_DATA_PANELPOSITIONDATA_H
#define POSITIONRECONSTRUCTION_SRC_INPUT_DATA_PANELPOSITIONDATA_H

// includes for C system headers
// includes for C++ system headers
#include<vector>
#include<ostream>
// includes from other libraries
// includes from this code

namespace Input
{
namespace Data
{

class PanelPositionData
{
public:
    std::vector<int> panelNumber;
    
    std::vector<float> xPosition;
    std::vector<float> yPosition;
    std::vector<float> zPosition;

    std::vector<float> xHalfSize;
    std::vector<float> yHalfSize;
    std::vector<float> zHalfSize;
    
    std::vector<float> xNorm;
    std::vector<float> yNorm;
    std::vector<float> zNorm;
    
    void addPanelNumber(int input){panelNumber.push_back(input);}
    
    void addXPosition(float input){xPosition.push_back(input);}
    void addYPosition(float input){yPosition.push_back(input);}
    void addZPosition(float input){zPosition.push_back(input);}
    
    void addXHalfSize(float input){xHalfSize.push_back(input);}
    void addYHalfSize(float input){yHalfSize.push_back(input);}
    void addZHalfSize(float input){zHalfSize.push_back(input);}
    
    void addXNorm(float input){xNorm.push_back(input);}
    void addYNorm(float input){yNorm.push_back(input);}
    void addZNorm(float input){zNorm.push_back(input);}

    bool validate();
    void printValidationErrors(std::ostream& os);

    friend std::ostream& operator<<(std::ostream& os, const PanelPositionData& ppd);
private:

};

}
}
#endif //POSITIONRECONSTRUCTION_SRC_INPUT_DATA_PANELPOSITIONDATA_H
