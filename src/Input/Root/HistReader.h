#ifndef POSITIONRECONSTRUCTION_SRC_INPUT_ROOT_HISTREADER_H
#define POSITIONRECONSTRUCTION_SRC_INPUT_ROOT_HISTREADER_H
// includes for C system headers
// includes for C++ system headers
#include<string>
// includes from other libraries
// includes from this code

namespace Reconstruction
{
class DetectorSet;
}

namespace Input
{

namespace Data
{
class DetectorPositionData;
}

class HistReader
{
public:
    HistReader(const std::string& fName, Data::DetectorPositionData* detPosDat, float minEnergy, float maxEnergy):
        fileName(fName), detPosData(detPosDat), minEn(minEnergy), maxEn(maxEnergy){}
    
    Reconstruction::DetectorSet* readPositionSpectra();
    
private:
    
    void buildSpecName(int detNum, int runNum);
    std::string specName;
    
    std::string fileName;
    Data::DetectorPositionData* detPosData;
    float minEn;
    float maxEn;
};

}
#endif //POSITIONRECONSTRUCTION_SRC_INPUT_ROOT_HISTREADER_H
