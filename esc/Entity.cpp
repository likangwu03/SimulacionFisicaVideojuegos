#include "Entity.h"

namespace ecs {

	Entity::Entity() :
		mngr_(nullptr), cmps_(), currCmps_(), alive_() {
		currCmps_.reserve(ecs::maxComponentId);
	}
	Entity::~Entity() {
		for (auto c : currCmps_) {
			delete c;
		}
	}
#ifdef P1
	void Entity::update(uint32_t frameTime) {
		auto n = currCmps_.size();
		for (auto i = 0u; i < n; i++)
			currCmps_[i]->update(frameTime);
	}
	void Entity::render() {
		auto n = currCmps_.size();
		for (auto i = 0u; i < n; i++)
			currCmps_[i]->render();
	}
	void Entity::handleEvents() {
		auto n = currCmps_.size();
		for (auto i = 0u; i < n; i++)
			currCmps_[i]->handleEvents();
	}
#endif // P1

}