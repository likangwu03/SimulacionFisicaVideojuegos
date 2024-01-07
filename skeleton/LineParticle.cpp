#include "LineParticle.h"

LineParticle::LineParticle(ParticleInfor infor,float r) :Particle(infor),r(r),i(infor)
{
	removeRenderItem();
	createRender();
}


//solo para ver y no va se afectado por fuerzas 
void LineParticle::integrate(double t)
{
	_cont += t;
	_pos.p += _vel * t;

	clearForce();
}

Particle* LineParticle::clone()
{
	return new LineParticle(i,r);
}

void LineParticle::createRender()
{
	PxSphereGeometry a;
	a.radius = r;
	PxShape* shape = CreateShape(a);
	renderItem = new RenderItem(shape, &_pos, color);
}
