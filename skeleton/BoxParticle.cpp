#include "BoxParticle.h"

BoxParticle::BoxParticle(ParticleInfor infor, float w, float h, float p, Vector4 color)
	:Particle(infor), 
	_width(w), _height(h), _depth(p), _color(color)
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
