#pragma once
#include "ParticleSystem.h"
class ParticleSystemP2:public ParticleSystem
{
public:
	ParticleSystemP2(Scene* scene, const Vector3& g = SFV::GRAVITY);
	void update(double t) override;
	virtual void keyPress(unsigned char key);
protected:
	std::vector<bool> activas;
};

