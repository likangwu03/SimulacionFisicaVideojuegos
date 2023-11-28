#include "ParticleSystemP4.h"
#include "Scene.h";
ParticleSystemP4::ParticleSystemP4(Scene* scene, const Vector3& g) :ParticleSystem(scene, g)
{
	MuelleDemo();

	GravityForceGenerator* gravity = new GravityForceGenerator();
	addForce(gravity);
}

void ParticleSystemP4::MuelleDemo()
{
	Particle::ParticleInfor infor;
	infor.duration = -1;
	infor.Vel = { 0,0,5 };
	Particle* p1 = new Particle(infor);
	infor.Pos = { 0,0,10 };
	infor.Vel = { 0,0,-5 };
	Particle* p2 = new Particle(infor);

	_particles.push_back(p1);
	_particles.push_back(p2);

	_scene->addObject(p1);
	_scene->addObject(p2);

	SpringForceGenerator* f1 = new SpringForceGenerator(1, 15, p2);
	SpringForceGenerator* f2 = new SpringForceGenerator(1, 15, p1);

	_forceGenerators.push_back(f1);
	_forceGenerators.push_back(f2);

	particleForceRegistry.addRegistry(f1, p1);
	particleForceRegistry.addRegistry(f2, p2);
}
