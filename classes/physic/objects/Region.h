#ifndef regionH
#define regionH

#include "../PhysicQuad.h"

class MRegion: public MPhysicQuad {
protected:
	void OnBeginCollide(b2Fixture* MainFixture, b2Fixture* ObjectFixture);
	void OnEndCollide(b2Fixture* MainFixture, b2Fixture* ObjectFixture);
	void OnBeginWallCollide();
	void OnEndWallCollide();
public:
	MRegion();
	bool Set(glm::vec2 Position, glm::vec2 Size, glm::vec3 Color, uint16 Mask);
	void OnUpdate();
};

#endif
