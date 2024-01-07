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
