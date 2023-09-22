#include "Particle.h"


Particle::Particle(Vector3 Pos, Vector3 Vel)
{
	pos = physx::PxTransform(Pos);
	vel = Vel;
	PxSphereGeometry a; a.radius = 5;
	PxShape* shape = CreateShape(a);
	renderItem = new RenderItem(shape,&pos,Vector4(0.1,1,1,1));
	RegisterRenderItem(renderItem);

}

Particle::~Particle()
{
	renderItem->release();
}

void Particle::integrate(double t)
{
	pos.p += vel*t;
}