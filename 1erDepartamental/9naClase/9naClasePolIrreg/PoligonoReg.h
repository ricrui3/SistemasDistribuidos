#ifndef POLIGONOREG_H_
#define POLIGONOREG_H_
#include "PoligonoIrreg.h"

class PoligonoReg : public PoligonoIrreg{
	private:
		double angle;
		int numVertices;
	public:
		PoligonoReg(int = 3);
		int obtieneArea();
};

#endif