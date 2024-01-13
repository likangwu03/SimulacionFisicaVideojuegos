#pragma once
#include "Object.h"
#include "def.h"
#include <array>
#include <vector>
#include "System.h"
#include "RenderUtils.hpp"
#include <unordered_map>
#include "checkML.h"
using namespace physx;
using namespace std;

class Scene
{
public:
	struct PxData {
		PxPhysics* gPhysics=nullptr;
		PxScene* gScene= nullptr;
	};
protected:
	array<Object*, SFV::maxHdlrId> hdlrs_;
	array<vector<Object*>, SFV::maxGroupId> objsByGroup_;
	array<vector<Object*>, SFV::maxGroupId> objsAux_;
	Camera* cam;
	unordered_map<string,System*> systemsHdlrs;
	vector<System*> systems;

	PxData _data;

public:
	Scene(PxData data=PxData());
	virtual ~Scene();

	inline void removeAllObjects() {
		for (auto& ents : objsByGroup_) {
			for (auto e : ents)
				e->setAlive(false);
		}
	}

	System* getSystem(string id);

	void addSystem(System* s);

	inline void setSystemHandler(System* s, string id) {
		if (systemsHdlrs.count(id)) delete systemsHdlrs[id];
		systemsHdlrs[id] = s;
	}

	void addObject(Object* obj,SFV::grpId_type gId = SFV::_grp_GENERAL);

	void addObject2(Object* obj,SFV::grpId_type gId = SFV::_grp_GENERAL);

	const auto& getObjects(SFV::grpId_type gId = SFV::_grp_GENERAL);

	virtual void init() {};

	void refresh();

	virtual void update(double t);

	void addAux();

	virtual void keyPress(unsigned char key);


	inline void setHandler(SFV::hdlrId_type hId, Object* e) {
		hdlrs_[hId] = e;
	}
	inline Object* getHandler(SFV::hdlrId_type hId) {
		return hdlrs_[hId];
	}
	inline std::vector<Object*>* getGroup(SFV::grpId grp) { return &objsByGroup_[grp]; }


	virtual void handleMouse(int button, int state, int x, int y);
	virtual void handleMotion(int x, int y);


	PxPhysics* getPhysics() { return _data.gPhysics; }
	PxScene* getGScene() { return _data.gScene; }
};


