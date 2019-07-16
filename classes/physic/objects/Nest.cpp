#include "../../../stdafx.h"
#include "Nest.h"

MNest::MNest():MLiving() {
	SpawnLimit = 0;
	SpawnTime = 0;
}
bool MNest::Set(glm::vec2 Position, glm::vec2 Size, glm::vec3 Color, int inSpawnTime, int inSpawnLimit, MPhysicWorld* inpPhysicWorld) {
	if(inSpawnTime <= 0) return false;
	if(inSpawnLimit <= 0) return false;
	if(!inpPhysicWorld) return false;
	
	pPhysicWorld = inpPhysicWorld;
	SpawnLimit = inSpawnLimit;
	SpawnTime = inSpawnTime;
	SpawnTimer.SetTimeLimit(SpawnTime);
	SpawnTimer.Start();
	return MPhysicQuad::Set(Position, Size, Color, b2_dynamicBody, OT_ENEMY, OT_HERO, true);
}

void MNest::Spawn() {
	//clear null objects
	vector<MEnemy*>::iterator it = Enemies.begin();
	while(it != Enemies.end()) {
		if(!*it) it = Enemies.erase(it);
		else it++;
	}
	//check spawnrate
	if(SpawnTimer.Time()) {
		//check that new object can be spawned
		if(SpawnLimit >= Enemies.size()) return;
		//create new enemy
		MEnemy* Enemy = new MEnemy;
		Enemy->Set(GetCenter(), glm::vec2(20, 20), glm::vec3(0, 0, 1));
		Enemy->SetAddress((MPhysicQuad**)&Enemy);
		//create and allocate in physic world
		pPhysicWorld->AddPhysicQuad(Enemy);
	}
}
	
void MNest::OnUpdate() {
	Spawn();
	MLiving::OnUpdate();
}
