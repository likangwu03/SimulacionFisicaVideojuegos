#pragma once
#include "Particle.h"
#include <list>
#include <random>
class ParticleSystem;
class ParticleGenerator
{
public:
	ParticleGenerator(ParticleSystem* system,int n_particles = 3,Vector3 pos= { 0.0f, 0.0f, 0.0f }, Vector3 velocity= { 0.0f, 0.0f, 0.0f },double frequency=0.1f,Vector3 gravity=SFV::GRAVITY);
	virtual std::list<Particle*> generateParticles() = 0;


	inline void setOrigin(const Vector3& p) { _origin = p; }
	inline void setFrequency(double f) { _frequency = f; }

	inline void setMeanVelocity(const Vector3& v) {
		_velocity = v;
	}
	inline Vector3 getMeanVelocity() const {
		return _velocity;
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

	virtual void update(double t) = 0;

protected:
	int _n_particles = 3; // Number of particles for each generateParticles call(TODO: add randomness ? ? )
	Particle* _model_particle = nullptr; // Has the attributes of the particle that will be generated!(damping, lifetime, etc.)
	Vector3 _origin, _velocity;

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
	//std::normal_distribution<> d;


	std::string _name;
	Vector3 _gravity;
	double _frequency;
	double _cont;

	ParticleSystem* _system;
};

