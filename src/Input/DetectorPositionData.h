#ifndef POSITIONRECONSTRUCTION_SRC_INPUT_DETECTORPOSITIONDATA_H
#define POSITIONRECONSTRUCTION_SRC_INPUT_DETECTORPOSITIONDATA_H

// includes for C system headers
// includes for C++ system headers
#include<vector>
// includes from other libraries
// includes from this code

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
    void printValidation();

    friend std::ostream& operator<<(std::ostream& os, const DetectorPositionData& dpd);
private:

};

#endif //POSITIONRECONSTRUCTION_SRC_INPUT_DETECTORPOSITIONDATA_H
