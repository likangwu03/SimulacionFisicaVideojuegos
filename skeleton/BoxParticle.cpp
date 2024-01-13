#include "BoxParticle.h"

BoxParticle::BoxParticle(ParticleInfor infor, float w, float h, float p)
	:Particle(infor), 
	_width(w), _height(h), _depth(p), _color(infor.color)
{
	removeRenderItem();
	createRender();
}

void BoxParticle::createRender()
{
	PxBoxGeometry a;
	a.halfExtents = PxVec3(_width, _height, _depth);
	PxShape* shape = CreateShape(a);
	renderItem = new RenderItem(shape, &_pos, _color);
}

Particle* BoxParticle::clone()
{
	return new BoxParticle(my_info, _width, _height, _depth);
}
