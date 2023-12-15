#pragma once
#include "SolidForceGenerator.h"
#include <unordered_map>
#include <unordered_set>
class SolidForceRegistry {
public:
	void updateForces(double duration) {
		for (auto& fg : mapForceGenerator) {
			for (auto p : fg.second) {
				fg.first->updateForce(p, duration);
			}
		}
	}

	void addRegistry(SolidForceGenerator* fg, DynamicObject* p) {
		mapForceGenerator[fg].insert(p);
		mapObjs[p].insert(fg);
	}

	void deleteObjRegistry(DynamicObject* p) {
		auto it = mapObjs.find(p);
		if (it != mapObjs.end()) {
			for (auto f : it->second) {
				auto it2 = mapForceGenerator.find(f);
				if (it2 != mapForceGenerator.end()) {
					it2->second.erase(it->first);
				}
			}
			it->second.clear();
			mapObjs.erase(it);
		}

	}

	void deleteForcesRegistry(SolidForceGenerator* fg) {
		auto it = mapForceGenerator.find(fg);
		if (it != mapForceGenerator.end()) {
			for (auto p : it->second) {
				auto it2 = mapObjs.find(p);
				if (it2 != mapObjs.end()) {
					it2->second.erase(it->first);
				}
			}
			it->second.clear();
			mapForceGenerator.erase(it);
		}
	}

	void clear() {
		for (auto& fg : mapForceGenerator) {
			fg.second.clear();
		}
		mapForceGenerator.clear();

		for (auto& p : mapObjs) {
			p.second.clear();
		}
		mapObjs.clear();
	}

protected:
	std::unordered_map< DynamicObject*, std::unordered_set<SolidForceGenerator*>> mapObjs;
	std::unordered_map< SolidForceGenerator*, std::unordered_set< DynamicObject*>> mapForceGenerator;

};

