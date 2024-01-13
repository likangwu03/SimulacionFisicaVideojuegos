#pragma once
#include "Particle.h"
class BoxParticle :public Particle
{
public:
	BoxParticle(ParticleInfor infor,float w=1, float h=1,float p=1);


protected:
	virtual void createRender();
public:
	float _width=1;
	float _height=1;
	float _depth = 1;
	Vector4 _color;

	void createRender2() {
		createRender();
	}
	inline float getVolume() {
		return _width * _height * _depth;
	}


	Particle* clone();
};

