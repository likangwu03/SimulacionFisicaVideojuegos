#include "ParticleSystemP2.h"
#include "checkML.h"
ParticleSystemP2::ParticleSystemP2(Scene* scene, const Vector3& g):ParticleSystem(scene,g)
{
	Vector3 p_aux = Vector3(0);
	ParticleGenerator* generator_aux = new CircleGenerator("cicle", this, 3, p_aux, Vector3(0, 5, 0), 0.01, nullptr, Vector3(0));
	_particle_generators.push_back(generator_aux);
	activas.push_back(false);
	
	Vector3 p_aux2 = Vector3(50, 0, 0);
	ParticleGenerator* generator_aux2 = new Fountain("fountain", this, 3, p_aux2, Vector3(0, 10, 0), 0.01);
	_particle_generators.push_back(generator_aux2);
	activas.push_back(false);

	Vector3 p_aux3 = Vector3(50, 0, 0);
	ParticleGenerator* generator_aux3 = new TornadoSystem("tornado", this, 3, p_aux3, Vector3(0, 10, 0), 0.1);
	_particle_generators.push_back(generator_aux3);
	activas.push_back(false);

	
}

void ParticleSystemP2::update(double t)
{
	for (int i = 0; i < activas.size(); ++i) {
		if (activas[i]) {
			_particle_generators[i]->update(t);
		}
	}
	refresh();
}

void ParticleSystemP2::keyPress(unsigned char key)
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

	}
}


