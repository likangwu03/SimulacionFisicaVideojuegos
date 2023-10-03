#include "Manager.h"
namespace ecs {

	Manager::Manager() : hdlrs_(), entsByGroup_() {
		for (auto& groupEntities : entsByGroup_) {
			groupEntities.reserve(100);
		}
		for (int i = 0; i < sys_.size(); ++i) {
			sys_[i] = nullptr;
		}
	}
	Manager::~Manager() {
		for (auto& ents : entsByGroup_) {
			for (auto e : ents)
				delete e;
		}

		for (auto s : sys_) delete s;
	}

Entity* Manager::addEntity(ecs::grpId_type gId) {
	Entity* e = new Entity();
	e->setAlive(true);
	e->setContext(this);
	entsByGroup_[gId].push_back(e);
	return e;
}

const auto& Manager::getEntities(grpId_type gId) {
	return entsByGroup_[gId];
}
void Manager::refresh() {
	for (ecs::grpId_type gId = 0; gId < ecs::maxGroupId; gId++) {
		auto& grpEnts = entsByGroup_[gId];
		grpEnts.erase(
			std::remove_if(grpEnts.begin(), grpEnts.end(),
				[](Entity* e) {
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
#ifdef P1

void Manager::update(uint32_t frameTime) {
	for (auto& ents : entsByGroup_) {
		for (auto& ent : ents) {
			ent->update(frameTime);
		}
	}
}
void Manager::render() {
	for (auto& ents : entsByGroup_) {
		for (auto& ent : ents) {
			ent->render();
		}
	}
}
void Manager::handleEvents() {
	for (auto& ents : entsByGroup_) {
		for (auto& ent : ents) {
			ent->handleEvents();
		}
	}
}
#endif // P1
}