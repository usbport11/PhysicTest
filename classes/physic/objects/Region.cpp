#include "../../../stdafx.h"
#include "Region.h"

MRegion::MRegion():MPhysicQuad() {
}

bool MRegion::Set(glm::vec2 Position, glm::vec2 Size, glm::vec3 Color, uint16 Mask) {
	return MPhysicQuad::Set(Position, Size, Color, b2_dynamicBody, OT_REGION, OT_WALL | Mask, true);
}

void MRegion::OnUpdate() {
}

void MRegion::OnBeginCollide(b2Fixture* MainFixture, b2Fixture* ObjectFixture) {
	MPhysicQuad* pObject = (MPhysicQuad*)ObjectFixture->GetBody()->GetUserData();
	switch(MainFixture->GetFilterData().categoryBits | ObjectFixture->GetFilterData().categoryBits) {
		case CT_REGION_ENEMY:
			cout<<"Region start collide!"<<endl;
			break;
	}
}

void MRegion::OnEndCollide(b2Fixture* MainFixture, b2Fixture* ObjectFixture) {
	MPhysicQuad* pObject = (MPhysicQuad*)ObjectFixture->GetBody()->GetUserData();
	switch(MainFixture->GetFilterData().categoryBits | ObjectFixture->GetFilterData().categoryBits) {
		case CT_REGION_ENEMY:
			cout<<"Region end collide!"<<endl;
			break;
	}
}

void MRegion::OnBeginWallCollide() {
}

void MRegion::OnEndWallCollide() {
}
