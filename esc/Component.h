#pragma once
#include "../game/ecs_def.h"
#include <stdint.h>
namespace ecs {
class Entity;
class Manager;
	struct Component {
	public:
		virtual ~Component() { }
		inline void setContext(Entity* ent, Manager* mngr) {
			ent_ = ent;
			mngr_ = mngr;
		}
		virtual void initComponent() { }
#ifdef P1
		virtual void update(uint32_t frameTime) { }
		virtual void render() { }
		virtual void handleEvents(){}
#endif // P1

	protected:
		Component() : ent_(nullptr), mngr_(nullptr){}
		Entity* ent_;
		Manager* mngr_;

	};
}


