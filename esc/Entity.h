#pragma once
#include <vector>
#include <array>
#include "Component.h"
#include "../game/ecs_def.h"
namespace ecs {
class Manager;
class State;
	class Entity {
	private:
		bool alive_;
		Manager* mngr_;
		std::vector<Component*> currCmps_;
		std::array<Component*, ecs::maxComponentId> cmps_;
	public:
		Entity();
		virtual ~Entity();
		inline void setContext(Manager* mngr) { mngr_ = mngr; };
		inline bool isAlive() { return alive_; }
		inline void setAlive(bool alive) { alive_ = alive; }


		template<typename T, typename ...Ts>
		inline T* addComponent(Ts&&... args) {
			T* c = new T(std::forward<Ts>(args)...);
			constexpr cmpId_type cId = T::id;
			removeComponent<T>();
			currCmps_.push_back(c);
			cmps_[cId] = c;
			c->setContext(this, mngr_);
			c->initComponent();
			return c;
		}
		
		template<typename T>
		inline void removeComponent() {
			constexpr cmpId_type cId = T::id;
			if (cmps_[cId] != nullptr) {
				auto iter = std::find(currCmps_.begin(),
					currCmps_.end(),
					cmps_[cId]);
				currCmps_.erase(iter);
				delete cmps_[cId];
				cmps_[cId] = nullptr;
			}
		}

		template<typename T>
		inline T* getComponent() {
			constexpr cmpId_type cId = T::id;
			return static_cast<T*>(cmps_[cId]);
		}

		template<typename T>
		inline bool hasComponent() {
			constexpr cmpId_type cId = T::id;
			return cmps_[cId] != nullptr;
		}

#ifdef P1
		 void update(uint32_t frameTime);
		 void render();
		 void handleEvents();
#endif // P1

	};
}