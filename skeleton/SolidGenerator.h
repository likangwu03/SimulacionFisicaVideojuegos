#pragma once
#include "DynamicObject.h"
#include <list>
#include <random>
class SolidSystem;
class SolidGenerator
{
public:
	SolidGenerator(SolidSystem* system, Vector3 pos,int n,double f);
	~SolidGenerator();

	virtual void generateSolids() = 0;
	virtual void update(double t) = 0;
protected:

	void addNormalDistribution(float mean, float deviation);

	void addUniformDistribution(float ini, float fin);


	std::string _name;
	SolidSystem* _system;
	Scene* _scene;
	DynamicObject* _model = nullptr;

	std::random_device rd;
	std::mt19937 gen;
	std::vector< std::normal_distribution<float>> normal_distributions;
	std::vector< std::uniform_real_distribution<float>> uniform_distributions;


	int _nObject;
	double _frequency;
	double _cont;
	Vector3 _pos;

};

