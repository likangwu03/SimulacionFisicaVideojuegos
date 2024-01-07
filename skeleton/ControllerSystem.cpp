#include "ControllerSystem.h"
#include "Scene.h"
#include "ParticleSystemPF.h"
ControllerSystem::ControllerSystem(Scene* scene) :System(scene, SFV::SystemId::_sys_CTRL)
{
	iniObj();
	ball_pos = ball->getRigid()->getGlobalPose().p;
}

void ControllerSystem::iniObj()
{
	ball = (Ball*)_scene->getHandler(SFV::hdlrId::_hdlr_BALL);
	camera = GetCamera();
	line = ((ParticleSystemPF*)_scene->getSystem("ParticleSystem"))->getLine();
}

void ControllerSystem::update(double t)
{
	canHit = ball->noMove();

	if (!canHit) {
		//std::cout << ball->getRigid()->getGlobalPose().p.x << " " << ball->getRigid()->getGlobalPose().p.y << " " << ball->getRigid()->getGlobalPose().p.z << "\n";
		PxVec3 diff = ball->getRigid()->getGlobalPose().p - ball_pos;
		camera->addPos(diff);

		ball_pos = ball->getRigid()->getGlobalPose().p;
		PxVec3 dir = camera->getTransform().p - ball_pos;
		camera->setDir(-dir.getNormalized());
		
	}
	else if(!hasHit) {
		line->setActive(true);
		line->setDuration(p_ini+ p_d*force/maxForce);
		line->setOrigin(ball->getRigid()->getGlobalPose().p);
		double angleInRadians = angleInDegrees * M_PI / 180.0;
		double x = std::cos(angleInRadians);
		double z = std::sin(angleInRadians);
		dir = PxVec3( x,0,z );
		line->setMeanVelocity(dir*v);
	}
	if (hasHit) {
		cont += t;
	}

	if (ball->getRigid()->getLinearVelocity().normalize() < minVel && hasHit && cont>cont_t) {
		cont = 0;
		hasHit = false;
		ball->getRigid()->setLinearVelocity(Vector3(0, 0, 0));
		ball->getRigid()->setAngularVelocity(Vector3(0, 0, 0));
		cout << "aaaaaahit\n";
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
			angleInDegrees = 0;
			hasHit = true;
			cout << "hit\n";
			break;
		case '2':
			if (force < maxForce)force += 1000;
			cout << force << "\n";
			break;
		case '5':
			if (force > minForce)force -= 1000;
			cout << force << "\n";
			break;
		case '1':
			angleInDegrees-=_d;
			cout << angleInDegrees << "\n";
			break;
		case '3':
			angleInDegrees+=_d;
			cout << angleInDegrees << "\n";
			break;
		}
	}
	
}

void ControllerSystem::handleMouse(int button, int state, int x, int y)
{
	if (button == 1) {
		cout <<x<<"  "<<y<< "\n";
	}
}

void ControllerSystem::handleMotion(int x, int y)
{
}

void ControllerSystem::adjustsCameraPos()
{
	
}
