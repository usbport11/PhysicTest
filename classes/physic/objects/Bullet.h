#ifndef bulletH
#define bulletH

#include "Living.h"

class MBullet: public MPhysicQuad {
private:
	int Damage;
	int PenetrateLimit;
	int PenetrateCount;
protected:
	void OnBeginCollide(b2Fixture* MainFixture, b2Fixture* ObjectFixture);
	void OnEndCollide(b2Fixture* MainFixture, b2Fixture* ObjectFixture);
	void OnBeginWallCollide();
	void OnEndWallCollide();
public:
	MBullet();
	bool Set(glm::vec2 Position, glm::vec2 Size, glm::vec3 Color, uint16 Mask);
	void SetDamage(int Value);
	void SetPenetrating(int inPenetrateLimit);
	void OnUpdate();
};

#endif
