#ifndef nestH
#define nestH

#include "Enemy.h"
#include "../PhysicWorld.h"
#include "../../system/Timer4.h"

class MNest: public MLiving {
private:
	vector<MEnemy*> Enemies;
	int SpawnLimit;
	double SpawnTime;
	MTimer4 SpawnTimer;
	MPhysicWorld* pPhysicWorld;
	void Spawn();
public:
	MNest();
	bool Set(glm::vec2 Position, glm::vec2 Size, glm::vec3 Color, int inSpawnTime, int inSpawnLimit, MPhysicWorld* inpPhysicWorld);
	void OnUpdate();
};

#endif
