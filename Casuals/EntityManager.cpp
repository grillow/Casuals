#include "EntityManager.h"
#include "CollidableRectangle.h"
#include "Block.h"
#include "SPlayer.h"
#include "Bullet.h"

std::vector<Entity*> EntityManager::EntityList;

void EntityManager::ProcessCollision(Entity* entity)
{
	if (entity == nullptr)
		return;

	const Block* asBlock = dynamic_cast<const Block*>(entity);
	
	if (asBlock != nullptr)
		if (!asBlock->Movable)
			return;
	
	CollidableRectangle e1(entity->Position, entity->Width, entity->Height);

	for (unsigned int i = 0; i < EntityList.size(); i++)
	{
		if (EntityList[i] == entity)
			continue;

		asBlock = dynamic_cast<const Block*>(EntityList[i]);
		if (asBlock != nullptr)
			if (asBlock->Movable)
				continue;
		if (dynamic_cast<const SPlayer*>(entity) != nullptr && dynamic_cast<const Bullet*>(EntityList[i]) != nullptr)
			continue;

		CollidableRectangle e2(EntityList[i]->Position, EntityList[i]->Width, EntityList[i]->Height);
		Vector2<double> bias = e1.Collide(e2);
		entity->Position += bias;

		bias.Normalize();
		if (bias.X != 0)
			entity->Velocity.X *= -1;
		if (bias.Y != 0)
			entity->Velocity.Y *= -1;
	}

}

void EntityManager::Push(Entity* entity)
{
	EntityList.push_back(entity);
}

void EntityManager::Delete(Entity* entity)
{
	for (unsigned int i = 0; i < EntityList.size(); i++)
	{
		if (EntityList[i] == entity)
		{
			EntityList.erase(EntityList.begin() + i);
			break;
		}
	}
}

void EntityManager::Update(float elapsed)
{
	for (unsigned int i = 0; i < EntityList.size(); i++)
	{
		EntityList[i]->Update(elapsed);
		ProcessCollision(EntityList[i]);
	}
}

void EntityManager::Draw()
{
	for (unsigned int i = 0; i < EntityList.size(); i++)
	{
		EntityList[i]->Draw();
	}
}
