#ifndef heroH
#define heroH

#include "Living.h"
#include "Chest.h"
#include "Exit.h"

class MHero: public MLiving {
private:
	MChest* pChest;
	MExit* pExit;
protected:
	void OnBeginCollide(b2Fixture* MainFixture, b2Fixture* ObjectFixture, MPhysicQuad* pObject);
	void OnEndCollide(b2Fixture* MainFixture, b2Fixture* ObjectFixture, MPhysicQuad* pObject);
	void OnBeginWallCollide();
	void OnEndWallCollide();
public:
	MHero();
	bool Set(glm::vec2 Position, glm::vec2 Size, glm::vec3 Color);
	void Update();
	void OpenChest();
	unsigned char GetExitType();
};

#endif
