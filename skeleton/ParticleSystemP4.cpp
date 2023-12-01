#include "ParticleSystemP4.h"
#include "Scene.h";
ParticleSystemP4::ParticleSystemP4(Scene* scene, const Vector3& g) :ParticleSystem(scene, g)
{
	//MuelleDemo();
	//comaElastica();
	bateria(5);
	//flotacion();
	whirlwinds = new WhirlwindsForceGenerator(1, 10, 30, { 0,0,0 }, { 100,200,100 }, { 0,-50,0 });
	addForce(whirlwinds);
	whirlwinds->setActive(false);
	gravity = new GravityForceGenerator();
	addForce(gravity);
	gravity->setActive(false);
	wind = new WindForceGenerator(30, { 0,0,10 }, { 100,100,100 }, { 0,-50,0 });
	addForce(wind);
	wind->setActive(false);
	drag = new ParticleDragGenerator();
	drag->setDrag(0.1, 0);
	drag->setActive(false);
	addForce(drag);

	drag2 = new ParticleDragGenerator();
	drag2->setDrag(0.1, 0.1);
	drag2->setActive(false);
	addForce(drag2);
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


	Particle::ParticleInfor infor2;
	infor2.duration = -1;
	infor2.Vel = { 0,0,-5 };
	infor2.Pos = { 10,0,10 };

	Particle* p3 = new Particle(infor2);

	f3 = new AnchoredSpringFG(1, 15, { 10,0,0 });

	_forceGenerators.push_back(f3);

	particleForceRegistry.addRegistry(f3, p3);
	_particles.push_back(p3);
	_scene->addObject(p3);
}

void ParticleSystemP4::comaElastica()
{
	Particle::ParticleInfor infor;
	infor.duration = -1;
	infor.Vel = { 0,20,5 };
	Particle* p1 = new Particle(infor);
	infor.Pos = { 0,20,10 };
	infor.Vel = { 0,0,-5 };
	Particle* p2 = new Particle(infor);

	_particles.push_back(p1);
	_particles.push_back(p2);

	_scene->addObject(p1);
	_scene->addObject(p2);

	ElasticWireFG* f1 = new ElasticWireFG(1, 15, p2);
	ElasticWireFG* f2 = new ElasticWireFG(1, 15, p1);

	_forceGenerators.push_back(f1);
	_forceGenerators.push_back(f2);

	particleForceRegistry.addRegistry(f1, p1);
	particleForceRegistry.addRegistry(f2, p2);

}

void ParticleSystemP4::bateria(int n)
{
	Particle::ParticleInfor infor2;
	infor2.duration = -1;
	infor2.Vel = { 0,0,0 };
	infor2.Pos = { -10,0,15 };

	Particle* p3 = new Particle(infor2);

	AnchoredSpringFG* f = new AnchoredSpringFG(k, 15, { -10,0,0 });

	_forceGenerators.push_back(f);

	particleForceRegistry.addRegistry(f, p3);
	_particles.push_back(p3);
	_scene->addObject(p3);

	Particle::ParticleInfor infor;
	infor.duration = -1;
	infor.Vel = { 0,0,0 };
	infor.Pos = { -10,0,30 };
	Particle* p1 = p3;

	for (int i = 0; i < n; ++i) {

		Particle* p2 = new Particle(infor);

		_particles.push_back(p2);

		_scene->addObject(p2);

		SpringForceGenerator* f1 = new SpringForceGenerator(k, 15, p2);
		SpringForceGenerator* f2 = new SpringForceGenerator(k, 15, p1);

		_forceGenerators.push_back(f1);
		_forceGenerators.push_back(f2);

		particleForceRegistry.addRegistry(f1, p1);
		particleForceRegistry.addRegistry(f2, p2);

		p1 = p2;

		infor.Pos += Vector3(0, 0, 15);
	}

}

void ParticleSystemP4::flotacion()
{
	Particle::ParticleInfor infor;
	infor.Pos = { 0,100,0 };
	infor.Vel = { 0,0,0 };
	infor.masa = 2000000;
	infor.accel = { 0,0,0 };
	infor.duration = -1;
	infor.damping = 0.7;
	p = new BoxParticle(infor, 10, 30, 10, Vector4(1, 1, 0, 1));

	_particles.push_back(p);

	_scene->addObject(p);


	Buoyancy = new BuoyancyForceGenerator(p->_height, p->getVolume(), 1000);
	addForce(Buoyancy);
}


void ParticleSystemP4::keyPress(unsigned char key)
{
	switch (toupper(key))
	{
	case '1':
		gravity->setActive(!gravity->getActive());
		std::cout << "gravity: " << gravity->getActive() << "\n";
		break;
	case '2':
		drag->setActive(!drag->getActive());
		std::cout << "drag: " << drag->getActive() << "\n";
		break;
	case '3':
		wind->setActive(!wind->getActive());
		std::cout << "wind: " << wind->getActive() << "\n";
		break;
	case '4':
		whirlwinds->setActive(!whirlwinds->getActive());
		std::cout << "whirlwinds: " << whirlwinds->getActive() << "\n";
		break;
	case '5':
		createExplosion();
		break;
	case '6':
		drag2->setActive(!drag2->getActive());
		std::cout << "drag2: " << drag2->getActive() << "\n";
		break;
	case '+':
		f3->setK(f3->getK() + 20);
		std::cout << "k: " << f3->getK() << "\n";
		break;
	case '-':
		f3->setK(f3->getK() - 20);
		std::cout << "k: " << f3->getK() << "\n";
		break;

	case 'Z': 
		p->_width += d;
		p->_depth += d;
		Buoyancy->setVolume(p->getVolume());
		p->removeRenderItem();
		p->createRender2();
		std::cout << "Particle volume: " << p->getVolume() << "\n";
		break;
	case 'X':
		if (p->_width - d > 0) {
			p->_width -= d;
			p->_depth -= d;
			Buoyancy->setVolume(p->getVolume());
			p->removeRenderItem();
			p->createRender2();
		}
		std::cout << "Particle volume: " << p->getVolume() << "\n";
		break;
	case 'C':
		p->_height += d;
		Buoyancy->setVolume(p->getVolume());
		p->removeRenderItem();
		p->createRender2();
		std::cout << "Particle volume: " << p->getVolume() << "\n";
		break;
	case 'V':
		if (p->_height - d > 0) {
			p->_height -= d;
			Buoyancy->setVolume(p->getVolume());
			p->removeRenderItem();
			p->createRender2();
		}
		std::cout << "Particle volume: " << p->getVolume() << "\n";
		break;
	case 'B':
		p->setMass(p->getMass() + 100000);
		std::cout << "Particle mass: " << p->getMass() << "\n";
		break;
	case 'N':
		p->setMass(p->getMass() - 100000);
		std::cout << "Particle mass: " << p->getMass() << "\n";
		break;
	case 'M':
		p->setPos(Vector3(0, 100, 0));
		std::cout << "Particle pos: " << p->getPosition().x <<" ; "<< p->getPosition().y<<" ; "<< p->getPosition().z << "\n";
		break;
	case ',':
		Buoyancy->setDensity(Buoyancy->getDensity() + 100);
		std::cout << "Density: " << Buoyancy->getDensity() << "\n";
		break;
	case '.':
		Buoyancy->setDensity(Buoyancy->getDensity() - 100);
		std::cout << "Density: " << Buoyancy->getDensity() << "\n";
		break;
	}



}

void ParticleSystemP4::createExplosion()
{
	ExplosionForceGenerator* explosion = new ExplosionForceGenerator({ 0,0,0 }, 100, 900000, 1);
	addForce(explosion);
}


