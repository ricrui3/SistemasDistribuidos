#ifndef POLIGONOREG_H_
#define POLIGONOREG_H_ 

class PoligonoReg:public PoligonoIrreg{
	private:
		double angle;
	public:
		PoligonoReg();
		PoligonoReg(double x, double y);
		obtieneArea();
};

#endif