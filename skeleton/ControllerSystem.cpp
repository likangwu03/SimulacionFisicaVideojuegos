#include "ControllerSystem.h"
#include "Scene.h"
#include "ParticleSystemPF.h"
ControllerSystem::ControllerSystem(Scene* scene) :System(scene, SFV::SystemId::_sys_CTRL)
{
	iniObj();
	ball_pos = ball->getRigid()->getGlobalPose().p;
	pos = Vector3(0);
	inGame = false;
}

void ControllerSystem::iniObj()
{
	ball = (Ball*)_scene->getHandler(SFV::hdlrId::_hdlr_BALL);
	camera = GetCamera();
	line = ((ParticleSystemPF*)_scene->getSystem("ParticleSystem"))->getLine();
}

void ControllerSystem::update(double t)
{
	if (!inGame)return;

	checkIsOutSide();
	//canHit = ball->noMove();
	canHit = ball->getRigid()->getLinearVelocity().normalize() < minVel;

	if (!canHit) {
		//std::cout << ball->getRigid()->getGlobalPose().p.x << " " << ball->getRigid()->getGlobalPose().p.y << " " << ball->getRigid()->getGlobalPose().p.z << "\n";
		PxVec3 diff = ball->getRigid()->getGlobalPose().p - ball_pos;
		camera->addPos(diff);

		ball_pos = ball->getRigid()->getGlobalPose().p;
		PxVec3 dir = camera->getTransform().p - ball_pos;
		camera->setDir(-dir.getNormalized());
		
	}

	if(!hasHit && canHit) {
		line->setActive(true);
		line->setDuration(p_ini+ p_d*force/maxForce);
		line->setOrigin(ball->getRigid()->getGlobalPose().p);
		double angleInRadians = angleInDegrees * M_PI / 180.0;
		double x = std::cos(angleInRadians);
		double z = std::sin(angleInRadians);
		dir = PxVec3( x,0,z );
		line->setMeanVelocity(dir*v);
	}
	else {
		line->setActive(false);
	}


	if (hasHit) {
		cont += t;
	}

	if (ball->getRigid()->getLinearVelocity().normalize() < minVel && hasHit && cont>cont_t) {
		cont = 0;
		hasHit = false;
		ball->getRigid()->setLinearVelocity(Vector3(0, 0, 0));
		ball->getRigid()->setAngularVelocity(Vector3(0, 0, 0));
#ifdef DEBUG
		cout << "aaaaaahit\n";
#endif // DEBUG
	}
	
}

void ControllerSystem::keyPress(unsigned char key)
{
	if (canHit) {
		switch (toupper(key))
		{
		case ' ':
			ball_pos_hit= ball->getRigid()->getGlobalPose().p;
			ball->getRigid()->addForce(dir * force);
			line->setActive(false);
			//angleInDegrees = 0;
 			hasHit = true;
			cont = 0;
#ifdef DEBUG
			cout << "hit\n";
#endif // DEBUG
			break;
		case 'Z':
			if (force < maxForce)force += 1000;
#ifdef DEBUG
			cout << force << "\n";
#endif // DEBUG
			break;
		case 'X':
			if (force > minForce)force -= 1000;
#ifdef DEBUG
			cout << force << "\n";
#endif // DEBUG
			break;
		case 'C':
			angleInDegrees-=_d;
#ifdef DEBUG
			cout << angleInDegrees << "\n";
#endif // DEBUG
			break;
		case 'V':
			angleInDegrees+=_d;
#ifdef DEBUG
			cout << angleInDegrees << "\n";
#endif // DEBUG
			break;
		}
	}

	switch (toupper(key))
	{
	case 'B':
		ball_pos = ball->getRigid()->getGlobalPose().p;
		PxVec3 dir = camera->getTransform().p - ball_pos;
		camera->setDir(-dir.getNormalized());
		break;
	}
}

void ControllerSystem::NextLevel(PxVec3 ball_p, Vector3 p, float w, float h)
{
	ball_pos_hit = PxVec3(ball_p);
	pos = p;
	_w = w;
	_h = h;
	SetPosToNextLevel();
}

void ControllerSystem::gameOver()
{
	inGame = false;
	line->setActive(false);
}

void ControllerSystem::gameStart()
{
	inGame = true;
}

void ControllerSystem::setCamaraIniPos()
{
	
		camera->setPos(Vector3(200,1000,400));

		camera->setDir(Vector3(0.2, -1, -0.4));
}

void ControllerSystem::SetPosToNextLevel()
{
	PxTransform t(ball_pos_hit);
	ball->getRigid()->setGlobalPose(t);
	//ball->SetPos(ball_pos_hit);


	ball->getRigid()->setLinearVelocity(Vector3(0, 0, 0));
	ball->getRigid()->setAngularVelocity(Vector3(0, 0, 0));
	cont = 0;
	hasHit = false;

	PxVec3 diff = ball->getRigid()->getGlobalPose().p +Vector3(0,100,100);
	camera->setPos(diff);

	ball_pos = ball->getRigid()->getGlobalPose().p;
	//PxVec3 dir = camera->getTransform().p - ball_pos;
	//camera->setDir(-dir.getNormalized());

	PxVec3 dir = camera->getTransform().p - ball_pos;
	camera->setDir(Vector3(0,-1,-1));
}

void ControllerSystem::checkIsOutSide()
{
	PxVec3 p = ball->getRigid()->getGlobalPose().p;

	if (p.x > pos.x - _w && p.x< pos.x + _w && p.z>pos.z - _h && p.z < pos.z + _h && p.y> _y) return;

	PxTransform t(ball_pos_hit);
	ball->getRigid()->setGlobalPose(t);

	PxVec3 diff = ball->getRigid()->getGlobalPose().p - ball_pos;
	camera->addPos(diff);

	ball_pos = ball->getRigid()->getGlobalPose().p;
	PxVec3 dir = camera->getTransform().p - ball_pos;
	camera->setDir(-dir.getNormalized());


	ball->getRigid()->setLinearVelocity(Vector3(0, 0, 0));
	ball->getRigid()->setAngularVelocity(Vector3(0, 0, 0));
	cont = 0;
	hasHit = false;
#ifdef DEBUG
	cout << "aaaaffffffffaahit\n";
#endif // DEBUG
}

