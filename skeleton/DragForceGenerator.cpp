#include "DragForceGenerator.h"

DragForceGenerator::DragForceGenerator():SolidForceGenerator(),_k1(0),_k2(0)
{
}

void DragForceGenerator::updateForce(DynamicObject* obj, double t)
{
	if (!_active)return;
	if (fabs(obj->getRigid()->getInvMass()) < 1e-10) return;
	Vector3 v = obj->getRigid()->getLinearVelocity();
	float drag_coef = v.normalize();
	if (drag_coef > 0.007) {
		
		drag_coef = _k1 * drag_coef + _k2 * drag_coef * drag_coef;
		Vector3 dragF = -v * drag_coef;
		obj->getRigid()->addForce(dragF);
	}

	/*
	v = obj->getRigid()->getAngularVelocity();
	drag_coef = v.normalize();
	drag_coef = _k1 * drag_coef + _k2 * drag_coef * drag_coef;
	dragF = -v * drag_coef;
	obj->getRigid()->setAngularVelocity(obj->getRigid()->getAngularVelocity() + dragF);*/
}
