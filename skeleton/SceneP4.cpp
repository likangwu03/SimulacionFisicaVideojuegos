#include "SceneP4.h"
SceneP4::SceneP4() :Scene()
{
	ParticleSystemP4* s = new ParticleSystemP4(this);
	addSystem(s);
	setSystemHandler(s, "ParticleSystem");
}