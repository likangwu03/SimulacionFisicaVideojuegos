#pragma once
#include "Particle.h"
#include <cmath>
#include "checkML.h"
class TurnParticle :public Particle
{
public:
	TurnParticle(float r, float g, float v, ParticleInfor infor);
	~TurnParticle();
	void integrate(double t) override;
	void setRadius(float r);
protected:
	float C;//perimetro
	float radios;
	float grados;
	float vel_g;
	Vector3 origen;

	float DegreeToRadian(float d);

	float getResult(float distance) {
		float aux = C / 360;
		float d = distance / aux;
		return DegreeToRadian(d);
	}
};


