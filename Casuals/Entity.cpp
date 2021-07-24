#include "Entity.h"
#include "EntityManager.h"

Entity::Entity()
{
	EntityManager::Push(this);
}

Entity::~Entity()
{
	EntityManager::Delete(this);
}
