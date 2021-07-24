#pragma once
#include <vector>
#include "Entity.h"

class Entity;

class EntityManager
{
private:
	static void ProcessCollision(Entity* entity);
public:
	static std::vector<Entity*> EntityList;
	static void Push(Entity* entity);
	static void Delete(Entity* entity);
	static void Update(float elapsed);
	static void Draw();
};
