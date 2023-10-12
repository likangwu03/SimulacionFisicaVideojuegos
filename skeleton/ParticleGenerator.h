#pragma once
#include "Particle.h"
#include <list>
#include <random>
class ParticleGenerator
{
public:
	virtual std::list<Particle*> generateParticles() = 0;


	inline void setOrigin(const Vector3& p) { _origin = p; }
	inline void setFrequency(double f) { _frequency = f; }

	inline void setMeanVelocity(const Vector3& v) {
		_mean_velocity = v;
	}
	inline Vector3 getMeanVelocity() const {
		return _mean_velocity;
	}
	inline void setMeanDuration(double new_duration) {
		_model_particle->setDuration(new_duration);
	}

	inline void setParticle(Particle* p) {
		delete _model_particle;
		_model_particle = p->clone();
		_model_particle->removeRenderItem();
	}
	inline void setNParticles(int n_p) { _n_particles = n_p; }
protected:
	int _n_particles = 3; // Number of particles for each generateParticles call(TODO: add randomness ? ? )
	double _generation_prob = 1.0; // IF 1.0 --> always produces particles
	Particle* _model_particle = nullptr; // Has the attributes of the particle that will be generated!(damping, lifetime, etc.)
	Vector3 _origin, _mean_velocity;

	/*
	std::mt19937 _mt;
	std::uniform_real_distribution<double> _u{ 0,1 };
	*/

	/*
	std::random_device rd;  // Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<> dis(1.0, 2.0);
	*/

	//generar números aleatorios con media 5 y desviación estándar 2:
	//std::random_device rd;
    //std::mt19937 gen(rd());
    //std::normal_distribution<> d(5, 2);

	//dis(gen) para conseguir numero 


	std::random_device rd;
	std::mt19937 gen;
	std::normal_distribution<> d;


	std::string _name;
	Vector3 _gravity;
	double _frequency;
};

