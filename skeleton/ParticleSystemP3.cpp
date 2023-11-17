#include "ParticleSystemP3.h"
#include "checkML.h"
ParticleSystemP3::ParticleSystemP3(Scene* scene, const Vector3& g) :ParticleSystem(scene, g)
{
	Particle::ParticleInfor p1_infor;
	p1_infor.duration = 15;
	p1_infor.masa = 70;
	Particle* p1 = new Particle(p1_infor);

	Vector3 p_aux = Vector3(0);
	ParticleGenerator* generator_aux = new CircleGenerator("cicle", this, 3, p_aux, Vector3(0, 5, 0), 0.01, p1, Vector3(0));
	_particle_generators.push_back(generator_aux);
	activas.push_back(false);

	/*
	p1_infor.Pos = Vector3(100, 0, 0);
	p1 = new Particle(p1_infor);

	p1_infor.Pos = Vector3(-100, 0, 0);
	p1 = new Particle(p1_infor);
	p1_infor.Pos = Vector3(0, 100, 0);
	p1 = new Particle(p1_infor);
	p1_infor.Pos = Vector3(0, -100, 0);
	p1 = new Particle(p1_infor);
	*/

	Particle::ParticleInfor p2_infor;
	p2_infor.duration = 15;
	p2_infor.Vel = { 0,0,0 };
	p2_infor.masa = 70;
	Particle* p2 = new Particle(p2_infor);


	Vector3 p_aux2 = Vector3(0, 0, 0);
	ParticleGenerator* generator_aux2 = new Fountain("fountain", this, 3, p_aux2, Vector3(0, 8, 0), 0.01, p2);
	_particle_generators.push_back(generator_aux2);
	activas.push_back(false);


	Particle::ParticleInfor p3_infor;
	p2_infor.duration = 15;
	p2_infor.Vel = { 0,0,0 };
	Particle* p3 = new Particle(p3_infor);


	Vector3 p_aux3 = Vector3(0, 0, 0);
	ParticleGenerator* generator_aux3 = new Fountain_mass("fountain_mass", this, 3, p_aux3, Vector3(0, 8, 0), 0.01, p3);
	_particle_generators.push_back(generator_aux3);
	activas.push_back(false);

	/*
	Vector3 p_aux3 = Vector3(50, 0, 0);
	ParticleGenerator* generator_aux3 = new TornadoSystem("tornado", this, 3, p_aux3, Vector3(0, 10, 0), 0.1);
	_particle_generators.push_back(generator_aux3);*/
	activas.push_back(false);

	whirlwinds = new WhirlwindsForceGenerator(10, 10, 30, { 0,0,0 }, { 100,200,100 }, { 0,0,0 });
	addForce(whirlwinds);

	gravity = new GravityForceGenerator();
	addForce(gravity);

	wind = new WindForceGenerator(30, { 0,0,10 }, { 100,100,100 }, { 0,0,0 });
	addForce(wind);
}

void ParticleSystemP3::update(double t)
{
	for (int i = 0; i < activas.size(); ++i) {
		if (activas[i]) {
			_particle_generators[i]->update(t);
		}
	}

	for (auto fg : _forceGenerators) {
		if (!fg->updateTime(t)) {
			fg->setAlive(false);
		}
	}

	particleForceRegistry.updateForces(t);


	refresh();
}

void ParticleSystemP3::keyPress(unsigned char key)
{
	switch (toupper(key))
	{
	case 'Z':
		activas[0] = !activas[0];
		break;
	case 'X':
		activas[1] = !activas[1];
		break;
	case 'C':
		activas[2] = !activas[2];
		break;

	case 'V':
		whirlwinds->setActive(!whirlwinds->getActive());
		break;

	case 'B':
		gravity->setActive(!gravity->getActive());
		break;
	case 'N':
		wind->setActive(!wind->getActive());
		break;
	case 'M':
		createExplosion();
		break;

	}
}

ParticleSystemP3::~ParticleSystemP3()
{
	
}

void ParticleSystemP3::createExplosion()
{
	ExplosionForceGenerator* explosion = new ExplosionForceGenerator({ 0,50,0 }, 100, 900000, 1);
	addForce(explosion);
}
