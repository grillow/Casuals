#pragma once
#include "Entity.h"

class Bullet : public Entity
{
private:
	double speed;
public:
	Bullet(Vector2<double> Position, double speed, Vector2<double> Direction);
	void Update(float elapsed) override;
	void Draw() override;
};
