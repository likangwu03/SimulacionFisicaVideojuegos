#include "SceneJuego.h"
SceneJuego::SceneJuego(PxData data) :Scene(data)
{
	state = INI;
	create();
	createSys();
	createLevels();

	ctrl->setCamaraIniPos();
}

void SceneJuego::NextLevel()
{
	if (state != GAME) return;

	level++;
	if (level > MAX_LEVEL) {
		gameOver();
	}
	else {
		//ctrl->NextLevel(Ball_pos_vector[level], Areas[level].p, Areas[level].w, Areas[level].h);
		next_level = true;
		//ctrl->NextLevel(Ball_pos_vector[level], Areas[level].p, Areas[level].w, Areas[level].h);
	}
#ifdef DEBUG
	cout << "next level\n";
#endif // DEBUG

}

void SceneJuego::update(double t)
{
	if (next_level) {
		next_level = false;
		particle->offFog(level-1);
		ctrl->NextLevel(Ball_pos_vector[level], Areas[level].p, Areas[level].w, Areas[level].h);
	}
	Scene::update(t);
}

void SceneJuego::keyPress(unsigned char key)
{


	if (state == GAME) {
		switch (toupper(key))
		{
		case 'N':
			particle->activeFog(level);
			break;
		case 'M':
			NextLevel();
			break;
		}
		for (System* sys : systems) {
			sys->keyPress(key);
		}
	}

	if (state == INI) {
		switch (toupper(key))
		{
		case ' ':
			gameStart();
			break;
		}
	}

	if (state == OVER) {
		switch (toupper(key))
		{
		case ' ':
			reset();
			break;
		}
	}
	
}

void SceneJuego::createSys()
{
	solid = new SolidSystemPF(this);
	addSystem(solid);
	setSystemHandler(solid, "SolidSystem");

	particle = new ParticleSystemPF(this);
	addSystem(particle);
	setSystemHandler(particle, "ParticleSystem");

	ctrl = new ControllerSystem(this);
	addSystem(ctrl);
	setSystemHandler(ctrl, "ControllerSystem");
	//ctrl->NextLevel(Ball_pos_vector[level], Areas[level].p, Areas[level].w, Areas[level].h);
}

void SceneJuego::create()
{
	Ball_pos_vector.push_back(PxVec3(0, 20, 150));
	Area a;
	a.p = Vector3(0, 0, 70);
	a.w = 80;
	a.h = 150;
	Areas.push_back(a);

	Ball_pos_vector.push_back(PxVec3(500, 20, 300));
	a.p = Vector3(350, 0, 125);
	a.w = 250;
	a.h = 250;
	Areas.push_back(a);

	Ball_pos_vector.push_back(PxVec3(0, 20, -300));
	a.p = Vector3(300, 0, -300);
	a.w = 400;
	a.h = 180;
	Areas.push_back(a);

	Ball_pos_vector.push_back(PxVec3(1150, 20, 300));
	//Ball_pos_vector.push_back(PxVec3(750, 20, -200));
	a.p = Vector3(1000, 0, 50);
	a.w = 350;
	a.h = 350;
	Areas.push_back(a);


	
	//Ball
	DynamicObject::ObjectInfor infor2;
	infor2.gPhysics = _data.gPhysics;
	infor2.gScene = _data.gScene;
	infor2.pos = Vector3(0, 15, 150);
	infor2.masa = 0.1;
	infor2.tam.x = 2;
	infor2.densidad = -1;
	Ball* b=new Ball(infor2);
	setHandler(_hdlr_BALL, b);
	addObject(b, SFV::_grp_SOLID);

	//new Floor(this, Vector3(0, 50, 50), PxQuat(0, PxVec3(0, 0, 1)), 25, 30, 50, Floor::WallInfor(),{1,1,1,0.3});
	//new Floor(this, { 0,0,0 }, PxQuat(0, PxVec3(0, 0, 1)), 80, 20, 50);
	
}

void SceneJuego::createLevels()
{
	level1();
	level2();
	level3();
	level4();
}

void SceneJuego::level1()
{
	Vector3 level_pos = Vector3(0, 0, 0);
	particle->createMuelle(level_pos);

	particle->createFog(level_pos+Vector3(0,50,50), Vector3(80,0.1,150),0.1,5,0);
	
	//creatFan(level_pos+Vector3(0, 50, 50), Vector3(25, 30, 50), 5, Vector3(0, 0, 0.5));


	//particle->createWhirlwinds(2,10,100,Vector3(40,50,40), level_pos+Vector3(0, 50, 50))

	Floor::WallInfor i;
	i.down = false;
	Floor* floor=new Floor(this, level_pos+Vector3(0,0,120), PxQuat(0, PxVec3(0, 0, 1)), 50, 20, 80,i);

	addObject(floor, _grp_STATIC);

	Hole::WallInfor i2;
	i2.top = false;
	Hole* hole = new Hole(this, level_pos, PxQuat(0, PxVec3(0, 0, 1)), 50, 20, 50,i2);

	addObject(hole, _grp_STATIC);

}

void SceneJuego::level2()
{
	Vector3 level_pos = Vector3(350, 0, 0);

	particle->createFog(level_pos + Vector3(0, 50, 150), Vector3(175, 0.1, 175), 0.1, 10, 1);

	creatFan(level_pos + Vector3(150, 50, 50), Vector3(25, 30, 100), 5, Vector3(0, 0, 0.5));
	creatFan(level_pos + Vector3(-150, 50, 250), Vector3(25, 30, 100), 5, Vector3(0, 0, -0.5));

	createBox(level_pos + Vector3(150, 30, 0), Vector3(15), 45);
	createBox(level_pos + Vector3(150, 30, 100), Vector3(10), 0);
	createBox(level_pos + Vector3(150, 30, 200), Vector3(15), 45);

	createBox(level_pos + Vector3(-150, 30, 100), Vector3(15), 45);
	createBox(level_pos + Vector3(-150, 30, 200), Vector3(10), 0);
	createBox(level_pos + Vector3(-150, 30, 300), Vector3(15), 45);

	// level_pos = Vector3(0, 0, 0);
	Hole::WallInfor i;
	i.left = false;
	i.top = false;
	Hole* hole=new Hole(this, level_pos + Vector3(-150, 0, 0), PxQuat(0, PxVec3(0, 0, 1)), 50, 20, 50, i);

	particle->createMuelle(level_pos + Vector3(-150, 0, 0));

	addObject(hole, _grp_STATIC);

	Floor::WallInfor f1;
	f1.right = false;
	f1.left = false;

	Floor* floor = new Floor(this, level_pos, PxQuat(0, PxVec3(0, 0, 1)), 100, 20, 50, f1);
	addObject(floor, _grp_STATIC);


	floor = new Floor(this, level_pos + Vector3(0, 0, 300), PxQuat(0, PxVec3(0, 0, 1)), 100, 20, 50, f1);
	addObject(floor, _grp_STATIC);

	Floor::WallInfor f2;
	f2.top = false;
	f2.down = false;

	floor = new Floor(this, level_pos+Vector3(-150, 0, 150), PxQuat(0, PxVec3(0, 0, 1)), 50, 20, 108, f2);
	addObject(floor, _grp_STATIC);

	floor = new Floor(this, level_pos + Vector3(150, 0, 150), PxQuat(0, PxVec3(0, 0, 1)), 50, 20, 108, f2);
	addObject(floor, _grp_STATIC);


	Floor::WallInfor f3;
	f3.right = false;
	f3.down = false;

	floor = new Floor(this, level_pos + Vector3(150, 0, 300), PxQuat(0, PxVec3(0, 0, 1)), 50, 20, 50, f3);
	addObject(floor, _grp_STATIC);

	Floor::WallInfor f4;
	f4.left = false;
	f4.down = false;

	floor = new Floor(this, level_pos + Vector3(-150, 0, 300), PxQuat(0, PxVec3(0, 0, 1)), 50, 20, 50, f4);
	addObject(floor, _grp_STATIC);

	Floor::WallInfor f5;
	f5.right = false;
	f5.top = false;

	floor = new Floor(this, level_pos + Vector3(150, 0, 0), PxQuat(0, PxVec3(0, 0, 1)), 50, 20, 50, f5);
	addObject(floor, _grp_STATIC);

}

void SceneJuego::level3()
{
	Vector3 level_pos = Vector3(0, 0, -400);

	particle->createFog(level_pos + Vector3(350, 50, 100), Vector3(400, 0.1, 150), 0.1, 10, 2);

	Hole::WallInfor info;
	info.down = false;
	Hole* hole = new Hole(this, level_pos + Vector3(100 * 6, 0, 200), PxQuat(0, PxVec3(0, 0, 1)), 50, 20, 58, info);
	addObject(hole, _grp_STATIC);

	particle->createMuelle(level_pos + Vector3(100 * 6, 0, 200));


	Floor::WallInfor f0;
	f0.left = false;
	f0.top = false;
	Floor* floor = new Floor(this, level_pos + Vector3(0, 0, 100), PxQuat(0, PxVec3(0, 0, 1)), 50, 20, 58, f0);
	addObject(floor, _grp_STATIC);

	Floor::WallInfor f7;
	f7.right = false;
	f7.top = false;
	floor = new Floor(this, level_pos + Vector3(600, 0, 100), PxQuat(0, PxVec3(0, 0, 1)), 50, 20, 50, f7);
	addObject(floor, _grp_STATIC);

	for (int i = 1; i < 6; ++i) {
		Floor::WallInfor f1;
		f1.right = false;
		f1.left = false;

		if (i % 2 == 0) {
			f1.top = false;
		}
		else {
			f1.down = false;

		}

		floor = new Floor(this, level_pos + Vector3(100*i, 0, 100), PxQuat(0, PxVec3(0, 0, 1)), 50, 20, 50,f1);
		addObject(floor, _grp_STATIC);

	}

	for (int i = 0; i < 6; ++i) {
		Floor::WallInfor f1;
		
		if (i % 2 == 0) {
			creatFan(level_pos + Vector3(100 * i, 50, 175), Vector3(25, 30, 75), 5, Vector3(0, 0, -0.5));
			f1.down = false;
			floor = new Floor(this, level_pos + Vector3(100 * i, 0, 200), PxQuat(0, PxVec3(0, 0, 1)), 50, 20, 50,f1);
			addObject(floor, _grp_STATIC);

		}
		else {
			creatFan(level_pos + Vector3(100 * i, 50, 25), Vector3(25, 30, 100), 5, Vector3(0, 0, 0.5));

			f1.top = false;
			floor = new Floor(this, level_pos + Vector3(100 * i, 0, 0), PxQuat(0, PxVec3(0, 0, 1)), 50, 20, 50,f1);
			addObject(floor, _grp_STATIC);
		}
	}
	//Floor::WallInfor i;
//	i.right = false;
	/*new Floor(this, level_pos, PxQuat(0, PxVec3(0, 0, 1)), 300, 20, 70);
	new Floor(this, level_pos+Vector3(370,0,0), PxQuat(0, PxVec3(0, 0, 1)), 300, 20, 70);

	new Floor(this, level_pos, PxQuat(0, PxVec3(0, 0, 1)), 70, 20, 300);
	new Floor(this, level_pos + Vector3(370, 0, 0), PxQuat(0, PxVec3(0, 0, 1)), 70, 20, 300);

	new Floor(this, level_pos, PxQuat(0, PxVec3(0, 0, 1)), 70, 20, 70);*/


}

void SceneJuego::level4()
{
	Vector3 level_pos = Vector3(750, 0,-200);


	particle->createFog(level_pos+ Vector3(250, 50, 250), Vector3(150, 0.1, 150), 0.1,10, 3);

	particle->createWhirlwinds(2, 10, 5, Vector3(100, 50, 100), level_pos + Vector3(250, 50, 250));
	solid->createWhirlwinds(0.01, 100, 0.005, Vector3(100, 50, 100), level_pos + Vector3(250, 50, 250));

	Floor::WallInfor i;
	i.down = false;
	i.left = false;
	new Floor(this, level_pos + Vector3(0, 0, 292), PxQuat(0, PxVec3(0, 0, 1)), 50, 20, 258, i);

	Floor::WallInfor i0;
	i0.right = false;
	new Floor(this, level_pos + Vector3(250, 0, 250), PxQuat(0, PxVec3(0, 0, 1)), 200, 20, 300, i0);


	Hole::WallInfor i2;
	i2.top = false;
	i2.left = false;
	new Hole(this, level_pos, PxQuat(0, PxVec3(0, 0, 1)), 50, 20, 50, i2);

	particle->createMuelle(level_pos);

	createBox(level_pos + Vector3(200, 30, 0), Vector3(15,15,60), 45);
	createBox(level_pos + Vector3(200, 30, 400), Vector3(15,15,60), 45);
	createBox(level_pos + Vector3(0, 30, 400), Vector3(15,15,60), 45);

	createBox(level_pos + Vector3(200, 30, 200), Vector3(15,15,60), -45);
	createBox(level_pos + Vector3(0, 30, 200), Vector3(15,15,60), -45);

	createBox(level_pos + Vector3(400, 30, 0), Vector3(20), 70);
	createBox(level_pos + Vector3(300, 30, 200), Vector3(20), 50);
	createBox(level_pos + Vector3(350, 30, 400), Vector3(20), 20);
	

}

void SceneJuego::reset()
{
	level = -1;
	particle->setActiveFirework(false);
	state = INI;
	next_level = false;
	//ctrl->setCamaraIniPos();

}

void SceneJuego::gameOver()
{
	particle->offFog(level-1);
	state = OVER;
	particle->setActiveFirework(true);
	ctrl->gameOver();
	ctrl->setCamaraIniPos();
}

void SceneJuego::gameStart()
{
	if (state == GAME)return;
	state = GAME;
	ctrl->gameStart();
	level = -1;
	NextLevel();

}

void SceneJuego::creatFan(Vector3 p, Vector3 area,float k,Vector3 v)
{
	int aux = 1;
	if (v.z > 0) aux = -1;
	Fan* fan = new Fan(this, p+Vector3(0,0, aux*area.z));
	addObject(fan);

	particle->createWinds(p, area, k, v);
	solid->createWinds(p, area, k, v);
}

void SceneJuego::createBox(Vector3 p, Vector3 area, float r)
{
	StaticObject::ObjectInfor obj_i;
	obj_i.color = color;
	obj_i.scene = this;
	obj_i.gPhysics = getPhysics();
	obj_i.gScene = getGScene();
	obj_i.pos = p;
	obj_i.tam = area;
	obj_i.q = PxQuat(r*M_PI/180,Vector3(0,1,0));
	addObject(new StaticObject(obj_i) , _grp_STATIC);
}


