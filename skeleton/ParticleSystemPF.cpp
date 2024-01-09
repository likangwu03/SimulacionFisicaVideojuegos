#include "ParticleSystemPF.h"

ParticleSystemPF::ParticleSystemPF(Scene* scene) :ParticleSystem(scene)
{
	create();
}

void ParticleSystemPF::keyPress(unsigned char key)
{

}

void ParticleSystemPF::create()
{
	//Line
	Particle::ParticleInfor i;
	LineParticle* p = new LineParticle(i,1);
	p->removeRenderItem();
	line = new LineGenerator(this, 1,Vector3(0), Vector3(0),0.3 , p);
	line->setActive(false);
	_particle_generators.push_back(line);


}

void ParticleSystemPF::createWinds(Vector3 p, Vector3 a,float k1,Vector3 v)
{
	WindForceGenerator* wind=new WindForceGenerator(k1,v, a, p);
	addForce(wind);
}

void ParticleSystemPF::createFog(Vector3 p, Vector3 a, float f)
{

}
