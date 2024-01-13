#include "ParticleSystemPF.h"
#include "Scene.h"
ParticleSystemPF::ParticleSystemPF(Scene* scene) :ParticleSystem(scene)
{
	create();
	fogs = std::vector< FogGenerator*>(4,nullptr);
}

void ParticleSystemPF::keyPress(unsigned char key)
{

}

void ParticleSystemPF::create()
{
	//Line
	Particle::ParticleInfor i;
	LineParticle* p = new LineParticle(i,1);
	p->removeRenderItem();
	line = new LineGenerator(this, 1,Vector3(0), Vector3(0),0.3 , p);
	line->setActive(false);
	_particle_generators.push_back(line);

	//fuego
	Particle::ParticleInfor infor;
	infor.Vel = Vector3(0, 20, 0);
	infor.duration = 1;
	infor.type = _particle_F1;
	//infor.accel = Vector3(0);
	Fireword* fire = new Fireword(12, 1, 1, infor);
	fire->removeRenderItem();

	firework = new FireworkGenerator(this, 3, Vector3(350,200,100), Vector3(700, 25, 700), 0.5, fire);
	addGenerator(firework);

	firework->setActive(false);


}

void ParticleSystemPF::createWinds(Vector3 p, Vector3 a,float k1,Vector3 v)
{
	WindForceGenerator* wind=new WindForceGenerator(k1*500,v, a, p);
	addForce(wind);
}

void ParticleSystemPF::createFog(Vector3 p, Vector3 a, float f,int num,int save)
{
	Particle::ParticleInfor info;
	info.color=Vector4(1, 1, 1, 0.2);
	info.r = 1;
	info.duration = 5;
	info.masa = 2;
	BoxParticle* pr = new BoxParticle(info, info.r, info.r, info.r);
	pr->removeRenderItem();
	FogGenerator* fog = new FogGenerator("fog"+save,this, num, p, a, 0, f, pr);
	addGenerator(fog);

	if (save != -1 && save < 4) {
		fogs[save] = fog;
		fog->setActive(false);
	}
}

void ParticleSystemPF::activeFog(int level)
{
	if (level > -1 && level < 4 && fogs[level] != nullptr) {
		fogs[level]->setActive(! fogs[level]->getActive());
	}
}

void ParticleSystemPF::offFog(int level)
{
	if (level > -1 && level < 4 && fogs[level] != nullptr) {
		fogs[level]->setActive(false);
	}
}

void ParticleSystemPF::createWhirlwinds(double K, double Y, double k1, Vector3 area, Vector3 pos)
{
	WhirlwindsForceGenerator* whirlwinds = new WhirlwindsForceGenerator(K, Y, k1, { 0,0,0 }, area, pos);
	addForce(whirlwinds);
}

void ParticleSystemPF::createMuelle(Vector3 pos)
{
	Particle::ParticleInfor infor2;
	infor2.duration = -1;
	infor2.Vel = { 0,0,0 };
	infor2.Pos = pos +Vector3(0,75,0);
	infor2.r = 2;
	infor2.color = Vector4(1, 1, 0, 1);
	//infor2.masa = 0;
	Particle* p3 = new Particle(infor2);

	AnchoredSpringFG* anchored = new AnchoredSpringFG(5, 40, pos + Vector3(0,100, 0), true);
	anchored->setAdd(false);

	_forceGenerators.push_back(anchored);

	particleForceRegistry.addRegistry(anchored, p3);
	//_particles.push_back(p3);
	_scene->addObject(p3);
}
