#include "AnchoredSpringFG.h"

AnchoredSpringFG::AnchoredSpringFG(double k, double resting, const Vector3& anchor_pos):
	SpringForceGenerator(k,resting,nullptr)
{
	Particle::ParticleInfor infor;
	infor.Pos = anchor_pos;
	infor.Vel = { 0,0,0 };
	infor.masa = 0;
	infor.accel = { 0,0,0 };
	_other = new Particle(infor);
}

AnchoredSpringFG::~AnchoredSpringFG()
{
	delete _other;
}
