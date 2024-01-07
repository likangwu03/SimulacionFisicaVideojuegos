#pragma once
#include "DynamicObject.h"
class Ball:public DynamicObject
{
public:
	Ball(ObjectInfor infor);

	inline bool const noMove() {
		return  _rb->getAngularVelocity() == PxVec3(0) && _rb->getLinearVelocity() == PxVec3(0);
	}

protected:
	virtual void create() override;

};

