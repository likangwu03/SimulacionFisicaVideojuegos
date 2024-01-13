#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"

#include <iostream>

#include "SceneP1.h"
#include "SceneP2.h"
#include "SceneP3.h"
#include "SceneP4.h"
#include "sceneP5.h"
#include "SceneJuego.h"


std::string display_text = "Press Space to Start";
std::string display_text1 = "Press Space to Return";
std::string display_text2 = "You win! :)";
std::string controls1 = "WASD: move camera";
std::string controls2 = "Right click: rotate camera";
std::string controls3 = "Z: increase force";
std::string controls4 = "X: decrease force";
std::string controls5 = "C: decrease angle";
std::string controls6 = "V: increase angle";
std::string controls7 = "B: camera looks at ball";
std::string controls8 = "N: turn on or off the fog";
std::string controls9 = "M: next level";
std::string controls10 = "SPACE: hit ball";
std::string controls11 = "Q: show controls";
std::string controls12 = "Q: hide controls";


enum GameState
{
	INI,GAME,OVER
};
int gameState = INI;
float angle = 0;
float force = 0;
bool showControls = true;



using namespace physx;

PxDefaultAllocator		gAllocator;
PxDefaultErrorCallback	gErrorCallback;

PxFoundation* gFoundation = NULL;
PxPhysics* gPhysics = NULL;


PxMaterial* gMaterial = NULL;

PxPvd* gPvd = NULL;

PxDefaultCpuDispatcher* gDispatcher = NULL;
PxScene* gScene = NULL;
ContactReportCallback gContactReportCallback;

SceneJuego* scene;
//Scene* scene;


void UpdateData() {

	gameState= scene->getState();
	if (gameState == GAME) {
		angle = scene->getAngle();
		force = scene->getForce();
	}
}


// Initialize physics engine
void initPhysics(bool interactive)
{
	PX_UNUSED(interactive);

	gFoundation = PxCreateFoundation(PX_FOUNDATION_VERSION, gAllocator, gErrorCallback);

	gPvd = PxCreatePvd(*gFoundation);
	PxPvdTransport* transport = PxDefaultPvdSocketTransportCreate(PVD_HOST, 5425, 10);
	gPvd->connect(*transport, PxPvdInstrumentationFlag::eALL);

	gPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *gFoundation, PxTolerancesScale(), true, gPvd);

	gMaterial = gPhysics->createMaterial(0.7, 0.7, 1);

	// For Solid Rigids +++++++++++++++++++++++++++++++++++++
	PxSceneDesc sceneDesc(gPhysics->getTolerancesScale());
	sceneDesc.gravity = PxVec3(0.0f, -9.8f, 0.0f);
	gDispatcher = PxDefaultCpuDispatcherCreate(2);
	sceneDesc.cpuDispatcher = gDispatcher;
	sceneDesc.filterShader = contactReportFilterShader;
	sceneDesc.simulationEventCallback = &gContactReportCallback;
	gScene = gPhysics->createScene(sceneDesc);

	Scene::PxData data = { gPhysics,gScene };
	//scene = new SceneP4();

	scene = new SceneJuego(data);


}


// Function to configure what happens in each step of physics
// interactive: true if the game is rendering, false if it offline
// t: time passed since last call in milliseconds
void stepPhysics(bool interactive, double t)
{
	PX_UNUSED(interactive);

	scene->update(t);
	scene->refresh();

	UpdateData();

	gScene->simulate(t);
	gScene->fetchResults(true);

}

// Function to clean data
// Add custom code to the begining of the function
void cleanupPhysics(bool interactive)
{
	PX_UNUSED(interactive);

	delete scene;
	// Rigid Body ++++++++++++++++++++++++++++++++++++++++++
	gScene->release();
	gDispatcher->release();
	// -----------------------------------------------------
	gPhysics->release();
	PxPvdTransport* transport = gPvd->getTransport();
	gPvd->release();
	transport->release();

	gFoundation->release();
}

// Function called when a key is pressed
void keyPress(unsigned char key, const PxTransform& camera)
{
	PX_UNUSED(camera);
	scene->keyPress(key);

	switch (toupper(key))
	{
	case 'Q':
		showControls = !showControls;
		break;

	}
}

void onCollision(physx::PxActor* actor1, physx::PxActor* actor2)
{
	PX_UNUSED(actor1);
	PX_UNUSED(actor2);

	const string name1 = actor1->getName();
	const string name2 = actor2->getName();
	if (name1 == "ball" && name2 == "hole") {
		PX_UNUSED(actor1);
		PX_UNUSED(actor2);
		//StaticRigidBody* p1 = static_cast<StaticRigidBody*>(actor1->userData);
		
		scene->NextLevel();
	}

}

void handleMouse(int button, int state, int x, int y)
{
	scene->handleMouse(button, state, x, y);
}

void handleMotion(int x, int y)
{
	scene->handleMotion(x, y);
}



int main(int, const char* const*)
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#ifndef OFFLINE_EXECUTION 
	extern void renderLoop();
	renderLoop();
#else
	static const PxU32 frameCount = 100;
	initPhysics(false);
	for (PxU32 i = 0; i < frameCount; i++)
		stepPhysics(false);
	cleanupPhysics(false);
#endif
	return 0;
}