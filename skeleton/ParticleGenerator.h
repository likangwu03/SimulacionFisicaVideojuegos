#pragma once
#include "Particle.h"
#include <list>
#include <random>
class ParticleSystem;
class ParticleGenerator
{
public:
	ParticleGenerator(ParticleSystem* system,int n_particles = 3,Vector3 pos= { 0.0f, 0.0f, 0.0f }, Vector3 velocity= { 0.0f, 0.0f, 0.0f },double frequency=0.1f, Particle* p=nullptr);
	
	virtual void generateParticles() = 0;

	~ParticleGenerator();

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

	void setActive(bool a) { active = a; }
	bool getActive() { return active; }

protected:
	int _n_particles = 3; // Number of particles for each generateParticles call(TODO: add randomness ? ? )
	Particle* _model_particle = nullptr; // Has the attributes of the particle that will be generated!(damping, lifetime, etc.)
	Vector3 _origin, _velocity;

	std::random_device rd;
	std::mt19937 gen;
	std::string _name;
	double _frequency;
	double _cont;

	ParticleSystem* _system;

	Scene* _scene;

	bool active = true;
};

