#pragma once

#include "Entity.h"
#include "System.h"
using namespace std;
namespace ecs {
	class Manager {
	private:
		array<Entity*, ecs::maxHdlrId> hdlrs_;
		std::vector<Message> msgs_;
		std::vector<Message> aux_msgs_;//al borrar los mensajes	enviados no se desplaza nada
		array<System*, ecs::maxSystemId> sys_;
		array<vector<Entity*>, ecs::maxGroupId> entsByGroup_;
	public:
		Manager();
		virtual ~Manager();
#pragma region COMPONENT
		template<typename T, typename ...Ts>
		inline T* addComponent(Entity* e, Ts&&...args) {
			T* c = new T(std::forward<Ts>(args)...);
			constexpr cmpId_type cId = T::id;
			removeComponent<T>();
			e->currCmps_.push_back(c);
			e->cmps_[cId] = c;
			c->setContext(e, this);
			c->initComponent();
			return c;
		}
		template<typename T>
		inline void removeComponent(Entity* e) {
			constexpr cmpId_type cId = T::id;
			if (e->cmps_[cId] != nullptr) {
				auto iter = std::find(e->currCmps_.begin(),
					e->currCmps_.end(),
					e->cmps_[cId]);
				e->currCmps_.erase(iter);
				delete e->cmps_[cId];
				e->cmps_[cId] = nullptr;
			}
		}
#pragma endregion

#pragma region ENTIDAD
		inline void removeAllEntities() {
			for (auto& ents : entsByGroup_) {
				for (auto e : ents)
					e->setAlive(false);
			}
		}
		Entity* addEntity(ecs::grpId_type gId = ecs::_grp_GENERAL);
		const auto& getEntities(grpId_type gId = ecs::_grp_GENERAL);
		void refresh();
#ifdef P1
		void update(uint32_t frameTime);
		void render();
		void handleEvents();
#endif // P1

		inline void setHandler(hdlrId_type hId, Entity* e) {
			hdlrs_[hId] = e;
		}
		inline Entity* getHandler(hdlrId_type hId) {
			return hdlrs_[hId];
		}
		inline std::vector<Entity*>* getGroup(grpId grp) { return &entsByGroup_[grp]; }
#pragma endregion

#pragma region SISTEMA
		template<typename T, typename ...Ts>
		inline T* addSystem(Ts &&... args) {
			constexpr sysId_type sId = T::id;
			removeSystem<T>();
			System* s = new T(std::forward<Ts>(args)...);
			s->setContext(this);
			s->initSystem();
			sys_[sId] = s;
			return static_cast<T*>(s);
		}
		template<typename T>
		inline T* getSystem() {
			constexpr sysId_type sId = T::id;
			return static_cast<T*>(sys_[sId]);
		}
		template<typename T>
		inline void removeSystem() {
			constexpr sysId_type sId = T::id;
			if (sys_[sId] != nullptr) {
				delete sys_[sId];
				sys_[sId] = nullptr;
			}
		}

#pragma endregion

#pragma region MENSAJE
		inline void send(const Message& m, bool delay = true) {
			if (!delay) {
				for (System* s : sys_) {
					if (s != nullptr)
						s->receive(m);
				}
			}
			else {
				msgs_.emplace_back(m);
			}
		}
		inline void flushMessages() {
			std::swap(msgs_, aux_msgs_);
			for (auto& m : aux_msgs_) {
				for (System* s : sys_) {  //env¨ªa todos los mensajes de aux_msgs_.Los nuevos mensajes que entran como reacci¨®n van a msgs_
					if (s != nullptr)
						s->receive(m);
				}
			}
			aux_msgs_.clear(); //Borrar los mensajes enviados, sin la necesidad de desplazar los nuevos
		}
#pragma endregion

	};
}