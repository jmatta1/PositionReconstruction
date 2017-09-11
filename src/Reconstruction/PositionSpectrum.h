#ifndef POSITIONRECONSTRUCTION_SRC_RECONSTRUCTION_POSITIONSPECTRUM_H
#define POSITIONRECONSTRUCTION_SRC_RECONSTRUCTION_POSITIONSPECTRUM_H

namespace Reconstruction
{

struct PositionSpectrum
{
public:
    PositionSpectrum(int numPos, double en):positionCount(numPos), centerEnergy(en) {spectrum = new double[numPos];}
    ~PositionSpectrum(){delete[] spectrum;}
    

    int positionCount;
    double centerEnergy;
    double* spectrum;
};

}

#endif //POSITIONRECONSTRUCTION_SRC_RECONSTRUCTION_POSITIONSPECTRUM_H
