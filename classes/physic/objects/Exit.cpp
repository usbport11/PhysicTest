#include "../../../stdafx.h"
#include "Exit.h"

MExit::MExit():MLevelObject() {
	Type = LOT_EXIT;
	ExitType = LET_NONE;
}

bool MExit::Set(glm::vec2 Position, glm::vec2 Size, glm::vec3 Color, unsigned char inExitType) {
	ExitType = inExitType;
	return MLevelObject::Set(Position, Size, Color, true);
}

unsigned char MExit::GetExitType() {
	return ExitType;
}
