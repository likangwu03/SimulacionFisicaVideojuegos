#include "Particle.h"


Particle::Particle(Vector3 Pos, Vector3 Vel, Vector3 ace,double damping):Object()
{
	pos = physx::PxTransform(Pos);
	vel = Vel;
	a = ace;
	damping_ = damping;
	PxSphereGeometry a; 
	a.radius = 5;
	PxShape* shape = CreateShape(a);
	renderItem = new RenderItem(shape,&pos,Vector4(0.1,1,1,1));
	RegisterRenderItem(renderItem);

}

Particle::~Particle()
{
	DeregisterRenderItem(renderItem);
	renderItem->release();
}

void Particle::integrate(double t)
{
	// Update position
	pos.p += vel*t;

	vel += a * t;
	// Impose drag (damping)
	vel *= powf(damping_, t);
}