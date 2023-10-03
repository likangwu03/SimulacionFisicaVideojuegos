#pragma once
#include "Entity.h"
#include "../utils/Vector2D.h"
#include <SDL_stdinc.h>
#include "../sdlutils/SDLNetUtils.h"
namespace ecs {
	using namespace std;
	using msgId_type = unsigned int;
	enum msgId : msgId_type {
		_m_MY_FIGHTER_SHOT,
		_m_ADD_BULLET,
		_m_COL_BULLETASTEROID,
		_m_COL_FIGHTERASTEROID,
		_m_Asteroids_Extinction,
		_m_1Player, //bot¨®n 1player
		_m_2Players, //bot¨®n multiplayer
		_m_To_Wait,
		_m_MULTI_PLAYER_START,
		//flujo del juego
		_m_GAME_START,
		_m_GAME_OVER,
		_m_ROUND_START,
		_m_ROUND_OVER,

		_m_OTHER_WIN, //para render msg
		_m_COL_FIGHTERBULLET, //col->fighter/bullet/(multi->net)
		_m_COL_OTHER_FIGHTERBULLET, //multi->net ___comunicar con el otro de que he colisionado con el bullet
		_m_OTHER_DECREASE_LIFE,//ctrl1->net->multi2  ___comunicar con el otro de que he reducido una vida
		_m_OTHER_FIGHTER_SHOT, //multi1->net->multi->(add)bullet ___comunicar con el otro de que he disparado
		_m_OTHER_FIGHTER_TRANSFORM,//multi1->net->multi2 ___comunicar con el otro de mi pos
		_m_OTHER_FIGHTER_NAME,//ctrl1->net->multi2
		_m_UPDATE_BULLETS_POS,//multi1->net->multi2___reposicionar los bullets del otro cuando en el mio ha hecho un delete de bullet

		_m_ME_WIN, //ctrl->net
		_m_LOST_CONNECTION, //net->ctrl
		_m_CONNECTED, //net->ctrl

		_m_NET_MESSAGE,//->net

		_m_CHAT_MESSAGE,

		_m_INVALID
	};
	struct Message {
		msgId_type id;
		msgId_type netId;

		//_m_MY_FIGHTER_SHOT
		struct {
			Vector2D pos;
			Vector2D vel;
			double width;
			double height;
			hdlrId_type owner;
		} fighter_shot_data;

		//_m_COL_BULLETASTEROID
		struct {
			Entity* bullet;
			Entity* asteroid;
		}col_bulletAsteroid_data;

		//_m_COL_BULLETFIGHTER
		struct {
			Entity* bullet;
		}col_bulletFighter_data;


		struct {
			Entity* bullet;
		}col_bullet_data;

		// _m_ROUND_OVER
		struct {
			WinnerEnum winner_;
		}round_over_data;

		//NET
		struct {
			bool server_;
		}server_data;
		struct {
			bool server;
			std::string ip;
			std::string port;
			std::string name;
		} network_data;

		struct {
			vector<pair<Vector2D, float>> pos;
		} data_transform_vector;

		struct {
			Uint8 lenght;
			char text[30];
		} data_text;
		struct {
			float pos_x;
			float pos_y;
			float rotation;
		} data_transform;
		struct {
			float pos_x;
			float pos_y;
			float vel_x;
			float vel_y;
			float width;
			float height;
		} data_move_transform;
	public:
		Uint8* serialize(Uint8* msg) {
			Uint8 a = netId;
			msg = SDLNetUtils::serialize(a, msg);
			switch (netId)
			{
			case _m_OTHER_FIGHTER_NAME:
				msg = serialize_text(msg);
				break;
			case _m_OTHER_FIGHTER_TRANSFORM:
				msg = serialize_transform(msg);
				break;
			case _m_OTHER_FIGHTER_SHOT:
				msg = serialize_move_transform(msg);
				break;
			case _m_COL_OTHER_FIGHTERBULLET:
				break;
			case _m_OTHER_DECREASE_LIFE:
				break;
			case _m_UPDATE_BULLETS_POS:
				msg = serialize_pos_vector(msg);
				break;
			case _m_CHAT_MESSAGE:
				msg = serialize_text(msg);
				break;
			}
			return msg;
		}

		Uint8* serialize_text(Uint8* msg) {

			msg = SDLNetUtils::serialize(data_text.lenght, msg);
			msg = SDLNetUtils::serialize_array<char>(data_text.text, data_text.lenght, msg);
			return msg;
		}

		Uint8* serialize_transform(Uint8* msg) {
			msg = SDLNetUtils::serialize(data_transform.pos_x, msg);
			msg = SDLNetUtils::serialize(data_transform.pos_y, msg);
			msg = SDLNetUtils::serialize(data_transform.rotation, msg);
			return msg;
		}

		Uint8* serialize_move_transform(Uint8* msg) {
			msg = SDLNetUtils::serialize(data_move_transform.pos_x, msg);
			msg = SDLNetUtils::serialize(data_move_transform.pos_y, msg);
			msg = SDLNetUtils::serialize(data_move_transform.vel_x, msg);
			msg = SDLNetUtils::serialize(data_move_transform.vel_y, msg);
			msg = SDLNetUtils::serialize(data_move_transform.width, msg);
			msg = SDLNetUtils::serialize(data_move_transform.height, msg);
			return msg;
		}
		Uint8* serialize_pos_vector(Uint8* msg) {
			int n = data_transform_vector.pos.size();
			msg = SDLNetUtils::serialize(n, msg);
			for (auto pos : data_transform_vector.pos) {
				float temp = pos.first.getX(); //pos
				msg = SDLNetUtils::serialize(temp, msg);
				temp = temp = pos.first.getY();
				msg = SDLNetUtils::serialize(temp, msg);
				temp = temp = pos.second; //rot
				msg = SDLNetUtils::serialize(temp, msg);
			}
			return msg;
		}

		Uint8* deserialize(Uint8* msg) {
			Uint8 aux;
			msg = SDLNetUtils::deserialize(aux, msg);
			id = (msgId_type)aux;
			netId = _m_INVALID;
			switch (id)
			{
			case _m_OTHER_FIGHTER_NAME:
				msg = deserialize_text(msg);
				break;
			case _m_OTHER_FIGHTER_TRANSFORM:
				msg = deserialize_transform(msg);

				break;
			case _m_OTHER_FIGHTER_SHOT:
				msg = deserialize_move_transform(msg);
				break;
			case _m_COL_OTHER_FIGHTERBULLET:
				break;
			case _m_OTHER_DECREASE_LIFE:
				break;
			case  _m_UPDATE_BULLETS_POS:
				msg = deserialize_pos_vector(msg);
				break;
			case _m_CHAT_MESSAGE:
				msg = deserialize_text(msg);
				break;
			}
			return msg;


		}

		Uint8* deserialize_text(Uint8* msg) {
			msg = SDLNetUtils::deserialize(data_text.lenght, msg);
			msg = SDLNetUtils::deserialize_array<char>(data_text.text, data_text.lenght, msg);
			return msg;
		}

		Uint8* deserialize_transform(Uint8* msg) {
			msg = SDLNetUtils::deserialize(data_transform.pos_x, msg);
			msg = SDLNetUtils::deserialize(data_transform.pos_y, msg);
			msg = SDLNetUtils::deserialize(data_transform.rotation, msg);
			return msg;
		}

		Uint8* deserialize_move_transform(Uint8* msg) {
			msg = SDLNetUtils::deserialize(data_move_transform.pos_x, msg);
			msg = SDLNetUtils::deserialize(data_move_transform.pos_y, msg);
			msg = SDLNetUtils::deserialize(data_move_transform.vel_x, msg);
			msg = SDLNetUtils::deserialize(data_move_transform.vel_y, msg);
			msg = SDLNetUtils::deserialize(data_move_transform.width, msg);
			msg = SDLNetUtils::deserialize(data_move_transform.height, msg);
			return msg;
		}

		Uint8* deserialize_pos_vector(Uint8* msg) {
			int n;
			msg = SDLNetUtils::deserialize(n, msg);
			data_transform_vector.pos = vector<pair<Vector2D, float>>(n);
			for (int i = 0; i < n; ++i) {
				float auxX, auxY;
				msg = SDLNetUtils::deserialize(auxX, msg); //pos
				msg = SDLNetUtils::deserialize(auxY, msg);
				data_transform_vector.pos[i].first = { auxX,auxY };
				msg = SDLNetUtils::deserialize(auxX, msg); //rot
				data_transform_vector.pos[i].second = auxX;
			}
			return msg;
		}
	};
}