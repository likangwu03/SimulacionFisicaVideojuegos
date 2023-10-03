#pragma once
#include "Message.h"

namespace ecs {
	class Manager;
	class System
	{
	public:
		virtual ~System() { }
		void setContext(Manager* mngr) {
			mngr_ = mngr;
		}
		virtual void initSystem() { }
		virtual void update(uint32_t frameTime) { }
		virtual void receive(const Message& m) { }
		System():mngr_(nullptr) {}
	protected:
		Manager* mngr_;
	};
}

