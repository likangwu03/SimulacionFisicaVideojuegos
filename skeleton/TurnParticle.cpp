#include "TurnParticle.h"

TurnParticle::TurnParticle(float r, float g,float v, ParticleInfor infor):Particle(infor)
{
	radios = r;
	grados = g;
	vel_g = v;
	C = 2 * SFV::M_PI * r;
	origen = infor.Pos;
}

TurnParticle::~TurnParticle()
{
}

void TurnParticle::integrate(double t)
{
	_vel += _accel * t;
	_vel *= powf(_damping, t);

	radios += t * _vel.z;

	float aux_y = _vel.y * t;
	_pos.p.y += aux_y;


	//float distance = _vel.x * t;
	//grados += getResult(distance);
	grados += vel_g * t;

	float result =DegreeToRadian(grados);
	float aux_x= cosf(result) * radios + origen.x;
	_pos.p.x = aux_x;
	float aux_z= sinf(result) * radios + origen.z;

	_pos.p.z = aux_z;

	_cont += t;
	if (_cont > _duration) {
		setAlive(false);
	}

}

float TurnParticle::DegreeToRadian(float d)
{
    return d * SFV::M_PI / 180;
}
