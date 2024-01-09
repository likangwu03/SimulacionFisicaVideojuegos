
#pragma once
#include "StaticObject.h"
class HoleCollision :public StaticObject
{
public:
	HoleCollision(ObjectInfor infor);

protected:
	virtual void create() override;

};


