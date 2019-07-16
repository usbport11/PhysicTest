#ifndef colorquadH
#define colorquadH

struct stColorQuad {
	glm::vec2 v[4];
	glm::vec3 c[4];
	stColorQuad() {
		v[0] = v[1] = v[2] = v[3] = glm::vec2(0, 0);
		c[0] = c[1] = c[2] = c[3] = glm::vec3(1, 1, 1);
	}
	stColorQuad(glm::vec2 Position, glm::vec2 Size, glm::vec3 Color) {
		if(Size.x <= 0 || Size.y <= 0) return;
		v[0] = glm::vec2(Position.x, Position.y);
		v[1] = glm::vec2(Position.x + Size.x, Position.y);
		v[2] = glm::vec2(Position.x + Size.x, Position.y + Size.y);
		v[3] = glm::vec2(Position.x, Position.y + Size.y);
		c[0] = c[1] = c[2] = c[3] = Color;
	}
	stColorQuad(float CenterX, float CenterY, float Width, float Height, glm::vec3 Color) {
		if(Width <= 0 || Height <= 0) return;
		glm::vec2 pos = glm::vec2(CenterX - Width / 2, CenterY - Height / 2);
		v[0] = glm::vec2(pos.x, pos.y);
		v[1] = glm::vec2(pos.x + Width, pos.y);
		v[2] = glm::vec2(pos.x + Width, pos.y + Height);
		v[3] = glm::vec2(pos.x, pos.y + Height);
		c[0] = c[1] = c[2] = c[3] = Color;
	}
};

#endif
