#pragma once
#include "SpringForceGenerator.h"
#include "BoxParticle.h"
class AnchoredSpringFG :public SpringForceGenerator{
public:
	AnchoredSpringFG(double k, double resting, const Vector3& anchor_pos,bool visible=true);


	~AnchoredSpringFG();

};

