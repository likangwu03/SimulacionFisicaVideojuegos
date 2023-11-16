#include "ForceGenerator.h"
#include <unordered_map>
#include <unordered_set>

class ParticleForceRegistry {
public:
	void updateForces(double duration) {
		for (auto& fg : mapForceGenerator) {
			for (auto p : fg.second) {
				fg.first->updateForce(p, duration);
			}
		}
	}

	void addRegistry(ForceGenerator* fg, Particle* p) {
		mapForceGenerator[fg].insert(p);
		mapParticles[p].insert(fg);
	}

	void deletePArticleRegistry(Particle* p) {
		auto it=mapParticles.find(p);
		if (it != mapParticles.end()) {
			for (auto f : it->second) {
				auto it2=mapForceGenerator.find(f);
				if (it2 != mapForceGenerator.end()) {
					it2->second.erase(it->first);
				}
			}
			it->second.clear();
			mapParticles.erase(it);
		}

	}

	void deleteForcesRegistry(ForceGenerator* fg) {
		auto it = mapForceGenerator.find(fg);
		if (it != mapForceGenerator.end()) {
			for (auto p : it->second) {
				auto it2 = mapParticles.find(p);
				if (it2 != mapParticles.end()) {
					it2->second.erase(it->first);
				}
			}
			it->second.clear();
			mapForceGenerator.erase(it);
		}
	}

protected:
	std::unordered_map< Particle*, std::unordered_set<ForceGenerator*>> mapParticles;
	std::unordered_map< ForceGenerator*, std::unordered_set< Particle*>> mapForceGenerator;

};
