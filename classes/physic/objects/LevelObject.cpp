#include "../../../stdafx.h"
#include "LevelObject.h"

MLevelObject::MLevelObject():MPhysicQuad() {
	Type = LOT_NONE;
}

bool MLevelObject::Set(glm::vec2 Position, glm::vec2 Size, glm::vec3 Color, bool Sensor) {
	return MPhysicQuad::Set(Position, Size, Color, b2_kinematicBody, OT_OBJECT, OT_HERO, Sensor);
}

void MLevelObject::OnBeginCollide(b2Fixture* MainFixture, b2Fixture* ObjectFixture) {}
void MLevelObject::OnEndCollide(b2Fixture* MainFixture, b2Fixture* ObjectFixture) {}
void MLevelObject::OnBeginWallCollide() {}
void MLevelObject::OnEndWallCollide() {}

unsigned char MLevelObject::GetType() {
	return Type;
}
