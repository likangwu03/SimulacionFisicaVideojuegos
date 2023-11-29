#include "SceneP4.h"
SceneP4::SceneP4() :Scene()
{
	s = new ParticleSystemP4(this);
	addSystem(s);
	setSystemHandler(s, "ParticleSystem");
}

void SceneP4::keyPress(unsigned char key)
{
	s->keyPress(key);
}
