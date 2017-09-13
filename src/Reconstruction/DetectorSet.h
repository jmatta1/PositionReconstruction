#ifndef POSITIONRECONSTRUCTION_SRC_RECONSTRUCTION_DETECTORSET_H
#define POSITIONRECONSTRUCTION_SRC_RECONSTRUCTION_DETECTORSET_H

// includes for C system headers
// includes for C++ system headers
// includes from other libraries
// includes from this code

namespace Reconstruction
{

static const int CoordSize = 4;//not 3 due to alignment needs

class DetectorSet
{
public:
    DetectorSet(int numEnBin, int numPos);
    ~DetectorSet();

    float calculateWeights(int posNum, float* srcPt, float intensity) const;
    void setPosition(int ind, float xpos, float ypos, float zpos)
    {
        detCoords[CoordSize*ind]=xpos;detCoords[CoordSize*ind+1]=ypos;detCoords[CoordSize*ind+2]=zpos;
    }
    void setEnergy(int enInd, float en){centerEn[enInd] = en;}
    void setPosBin(int posInd, int enInd, float value){posSpectra[enInd][posInd] = value;}
    
    float* getSpectrum(int index){return posSpectra[index];}
    float getEnergy(int index){return centerEn[index];}
    int getPosCount(){return posCount;}
    int getEnBinCount(){return enBinCount;}
private:
    int posCount;
    float* detCoords; //array of coordinates, will have dim = 4*posCount,
    //only 3 floats are needed per coordinate, but the 4 gives memory alignment for 4byte floats
    
    int enBinCount;
    float* centerEn;
    
    float** posSpectra;
};

}
#endif //POSITIONRECONSTRUCTION_SRC_RECONSTRUCTION_DETECTORSET_H
