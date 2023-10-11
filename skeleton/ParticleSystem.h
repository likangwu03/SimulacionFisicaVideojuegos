#pragma once
#include "Scene.h"

class ParticleSystem :public Scene {
public:
	// Creates a void system with a det. gravity
	ParticleSystem(const Vector3& g = { 0.0f, -9.8f, 0.0f });
	~ParticleSystem() {};


	Vector3 _gravity;
};