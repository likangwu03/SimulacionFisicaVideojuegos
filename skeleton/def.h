#pragma once
#define P1

#include "RenderUtils.hpp"

namespace SFV {

#ifdef P1
	using system_type = unsigned int;
	enum SystemId : system_type
	{
		_sys_DEFAULT,
		_sys_PARTICLE,
		_sys_SOLID,
		_LAST_SYS_ID
	};
	constexpr system_type maxSystemId = _LAST_SYS_ID;
	
	using hdlrId_type = unsigned int;
	enum hdlrId : hdlrId_type
	{
		_hdlr_NAME,
		_hdlr_TEXT,
		_LAST_HDLR_ID
	};
	constexpr hdlrId_type maxHdlrId = _LAST_HDLR_ID;

	using grpId_type = unsigned int;
	enum grpId : grpId_type {
		_grp_GENERAL,
		_grp_TEXTS,
		_grp_SOLID,
		_grp_STATIC,
		_LAST_GRP_ID
	};
	constexpr grpId_type maxGroupId = _LAST_GRP_ID;

	using particle_type = unsigned int;
	enum ParticleType : particle_type
	{
		_particle_default,
		_particle_P1,
		_particle_F1,
		_particle_F2,
		_particle_mass,
		_LAST_PARTUCLE_TYPE
	};
	constexpr particle_type maxParticleType = _LAST_PARTUCLE_TYPE;

#pragma region parameter
	const Vector3 GRAVITY = { 0.0f, -9.8f, 0.0f };
	const double DAMPING = 0.998;
	const double DEFAULT_DURATION = 3;

	const float M_PI = 3.14159;
#pragma endregion

#endif // P1
}