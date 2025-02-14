#include "../../../stdafx.h"
#include "Bullet.h"

MBullet::MBullet():MPhysicQuad() {
	Damage = 0;
	PenetrateCount = 0;
	PenetrateLimit = 0;
}

bool MBullet::Set(glm::vec2 Position, glm::vec2 Size, glm::vec3 Color, uint16 Mask) {
	if(!MPhysicQuad::Set(Position, Size, Color, b2_dynamicBody, OT_BULLET, OT_WALL | Mask, true)) return false;
}

void MBullet::OnBeginCollide(b2Fixture* MainFixture, b2Fixture* ObjectFixture) {
	MLiving* pLiving = (MLiving*)ObjectFixture->GetBody()->GetUserData();
	if(pLiving) {
		pLiving->ReciveDamage(Damage);
		if(PenetrateLimit) {
			PenetrateCount ++;
			if(PenetrateCount >= PenetrateLimit && PenetrateLimit > 0) NeedRemove = true;
			return;
		}
		NeedRemove = true;
	}
}

void MBullet::OnEndCollide(b2Fixture* MainFixture, b2Fixture* ObjectFixture) {
}

void MBullet::OnBeginWallCollide() {
	NeedRemove = true;
}

void MBullet::OnEndWallCollide() {
}

void MBullet::SetDamage(int Value) {
	Damage = Value;
}

void MBullet::SetPenetrating(int inPenetrateLimit) {
	PenetrateLimit = inPenetrateLimit;
}

void MBullet::OnUpdate() {
}
