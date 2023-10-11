#include "Scene.h"


Scene::Scene() : hdlrs_(), objsByGroup_() {
	cam = GetCamera();
	for (auto& groupEntities : objsByGroup_) {
		groupEntities.reserve(100);
	}
}
Scene::~Scene() {
	for (auto& ents : objsByGroup_) {
		for (auto e : ents)
			delete e;
	}
}

void Scene::addObject(Object* obj, SFV::grpId_type gId) {
	obj->setAlive(true);
	obj->setContext(this);
	objsByGroup_[gId].push_back(obj);
}

const auto& Scene::getObjects(SFV::grpId_type gId) {
	return objsByGroup_[gId];
}

void Scene::refresh() {
	for (SFV::grpId_type gId = 0; gId < SFV::maxGroupId; gId++) {
		auto& grpEnts = objsByGroup_[gId];
		grpEnts.erase(
			std::remove_if(grpEnts.begin(), grpEnts.end(),
				[](Object* e) {
					if (e->isAlive()) {
						return false;
					}
					else {
						delete e;
						return true;
					}
				}),
			grpEnts.end());
	}
}


void Scene::update(double t) {
	for (auto& ents : objsByGroup_) {
		for (auto& ent : ents) {
			ent->integrate(t);
		}
	}
}

void Scene::keyPress(unsigned char key) {
	for (auto& ents : objsByGroup_) {
		for (auto& ent : ents) {
			ent->keyPress(key);
		}
	}
}