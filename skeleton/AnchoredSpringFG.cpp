#include "AnchoredSpringFG.h"

AnchoredSpringFG::AnchoredSpringFG(double k, double resting, const Vector3& anchor_pos, bool visible):
	SpringForceGenerator(k,resting,nullptr)
{
	Particle::ParticleInfor infor;
	infor.Pos = anchor_pos;
	infor.Vel = { 0,0,0 };
	infor.masa = 0;
	infor.accel = { 0,0,0 };
	_other = new BoxParticle(infor);
	if (!visible) {
		_other->removeRenderItem();
	}
}

AnchoredSpringFG::~AnchoredSpringFG()
{
	delete _other;
}
