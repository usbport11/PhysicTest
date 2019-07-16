#ifndef enemyH
#define enemyH

#include "Living.h"

class MEnemy: public MLiving {
private:
	MLiving* pTarget;
	//additional fixtures
	float VisionScale;
	b2Fixture* VisionSensor;
	float BodyScale;
	b2Fixture* BodySensor;
	//stuck control
	int WallsCollided;
	b2Vec2 PrevPosition;
	bool StuckFixing;
	//velocities
	float FollowVelocity;
	float IdleVelocity;
	//distances
	float FollowDistance;
	
	void Move();
protected:
	void OnBeginCollide(b2Fixture* MainFixture, b2Fixture* ObjectFixture);
	void OnEndCollide(b2Fixture* MainFixture, b2Fixture* ObjectFixture);
	void OnBeginWallCollide();
	void OnEndWallCollide();
public:
	MEnemy();
	bool Set(glm::vec2 Position, glm::vec2 Size, glm::vec3 Color);
	bool SetVisionScale(float inVisionScale);
	bool SetBodyScale(float inBodyScale);
	void OnUpdate();
};

#endif
