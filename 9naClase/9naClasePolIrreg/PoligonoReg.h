#ifndef POLIGONOREG_H_
#define POLIGONOREG_H_ 

class PoligonoReg:public PoligonoIrreg{
	private:
		double angle;
		int numVertices;
	public:
		PoligonoReg(int = 3);
		obtieneArea();
};

#endif