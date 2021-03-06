#ifndef POSITIONRECONSTRUCTION_SRC_INPUT_DATA_DETECTORPOSITIONDATA_H
#define POSITIONRECONSTRUCTION_SRC_INPUT_DATA_DETECTORPOSITIONDATA_H

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

class DetectorPositionData
{
public:
    std::vector<int> detectorNumber;
    std::vector<int> runNumber;
    std::vector<float> xPosition;
    std::vector<float> yPosition;
    std::vector<float> zPosition;

    void addDetectorNumber(int input){detectorNumber.push_back(input);}
    void addRunNumber(int input){runNumber.push_back(input);}
    void addXPosition(float input){xPosition.push_back(input);}
    void addYPosition(float input){yPosition.push_back(input);}
    void addZPosition(float input){zPosition.push_back(input);}

    bool validate();
    void printValidationErrors(std::ostream& os);

    friend std::ostream& operator<<(std::ostream& os, const DetectorPositionData& dpd);
private:

};

}
}
#endif //POSITIONRECONSTRUCTION_SRC_INPUT_DATA_DETECTORPOSITIONDATA_H
