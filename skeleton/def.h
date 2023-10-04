#pragma once
#define P1

namespace SFV {

#ifdef P1
	using hdlrId_type = unsigned int;
	enum hdlrId : hdlrId_type
	{
		_hdlr_FIGHTER,
		_hdlr_FIGHTER2,
		_hdlr_IP,
		_hdlr_PORT,
		_hdlr_NAME,
		_hdlr_TEXT,
		_LAST_HDLR_ID
	};
	constexpr hdlrId_type maxHdlrId = _LAST_HDLR_ID;

	using grpId_type = unsigned int;
	enum grpId : grpId_type {
		_grp_GENERAL,
		_grp_TEXTS,
		_LAST_GRP_ID
	};
	constexpr grpId_type maxGroupId = _LAST_GRP_ID;
#endif // P1


}