#pragma once
#include "Object.h"
#include "def.h"
#include <array>
#include <vector>
#include "System.h"
#include "RenderUtils.hpp"
using namespace std;

class Scene
{
protected:
	array<Object*, SFV::maxHdlrId> hdlrs_;
	array<vector<Object*>, SFV::maxGroupId> objsByGroup_;
	array<vector<Object*>, SFV::maxGroupId> objsAux_;
	Camera* cam;
	vector<System*> systems= vector<System*>(SFV::maxSystemId,nullptr);
	

public:
	Scene();
	virtual ~Scene();

	inline void removeAllObjects() {
		for (auto& ents : objsByGroup_) {
			for (auto e : ents)
				e->setAlive(false);
		}
	}

	System* getSystem(int type) {
		return systems[type];
	}

	void addObject(Object* obj,SFV::grpId_type gId = SFV::_grp_GENERAL);


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

	void addSystem(System* s);
};


