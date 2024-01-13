#include "Fan.h"
#include "Scene.h"
Fan::Fan(Scene* s, Vector3 pos, float speed, float w, float h, float d, Vector4 c):Object(),_pos(pos),color(c),width(w),height(h),depth(d),_speed(speed),_degree(0)
{
	setContext(s);
	

	Particle::ParticleInfor i;
	i.color = color;
	i.Pos = pos;
	
	obj1 = new BoxParticle(i,w,h,d);
	obj2 = new BoxParticle(i, w, h, d);

}

Fan::~Fan()
{
	delete obj1;
	delete obj2;
}

void Fan::integrate(double t)
{
	_degree = _degree + _speed * t;
	
	PxTransform tr;
	tr.p = _pos;
	tr.q = PxQuat(_degree * M_PI / 180, PxVec3(0, 0, 1));

	//obj1->setPos(_pos)
	obj1->setRotation(tr.q);

	tr.q = PxQuat((_degree+90) * M_PI / 180, PxVec3(0, 0, 1));

	obj2->setRotation(tr.q);

}
