#include "SolidGenerator.h"
#include "SolidSystem.h"
SolidGenerator::SolidGenerator(SolidSystem* system, Vector3 pos, int n, double f):
	_system(system),_pos(pos),_nObject(n),_frequency(f),_cont(0)
{
	gen = std::mt19937(rd());
	_scene = system->getScene();
}

SolidGenerator::~SolidGenerator()
{
	delete _model;
	normal_distributions.clear();
	uniform_distributions.clear();
}

void SolidGenerator::addNormalDistribution(float mean, float deviation)
{
	std::normal_distribution<float> aux(mean, deviation);
	normal_distributions.push_back(aux);
}



void SolidGenerator::addUniformDistribution(float ini, float fin)
{
	std::uniform_real_distribution<float> aux(ini, fin);

	uniform_distributions.push_back(aux);

}