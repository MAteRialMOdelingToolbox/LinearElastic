#pragma once
#include <string>

class BftUel{

    public:

        double* stateVars;

        enum StateTypes{
            Sigma11,
            Sigma22,
            Sigma33,
            HydrostaticStress,
            GeostaticStress,
            UmatStateVars
        };

        enum DistributedLoadTypes{
            Pressure, 
        };

        BftUel(){};

        virtual ~BftUel(){};

        virtual int getNumberOfRequiredStateVars() = 0;

        virtual void assignStateVars(double *stateVars, int nStateVars, int nStateVarsMaterial) = 0;

        virtual void initializeYourself() = 0;

        virtual void computeYourself( const double* QTotal,
                                            const double* dQ,
                                            double* Pe,
                                            double* Ke,
                                            const double* time,
                                            double dT,
                                            double& pNewdT) = 0;

        virtual void setInitialConditions(StateTypes state, const double* values) = 0;

        virtual void computeDistributedLoad(
                                    DistributedLoadTypes loadType,
                                    double* P, 
                                    int elementFace, 
                                    const double* load,
                                    const double* time,
                                    double dT) = 0;

        virtual double* getPermanentResultPointer(const std::string& resultName, int gaussPt, int& resultLength) = 0;
};
