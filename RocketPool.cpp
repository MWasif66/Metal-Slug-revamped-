#include "RocketPool.h"

RocketPool::RocketPool()
{
    count = MAX_ROCKETS;
    Texture dummyTex;

    for (int i = 0; i < count; i++)
    {
        pool[i] = new Rocket(0, 0, 32, 16, dummyTex, 0, 0, 500, "player", 20, 100);
        pool[i]->setIsExpired(true);
    }
}

RocketPool::~RocketPool()
{
    for (int i = 0; i < count; i++)
        delete pool[i];
}

bool RocketPool::fire(int x, int y, float vX, float vY,
    Texture& tex, float maxSpeed,
    const char* owner, int damage, int explosionRadius)
{
    for (int i = 0; i < count; i++)
    {
        if (pool[i]->getIsExpired())
        {
            pool[i]->reset(x, y, vX, vY);
            pool[i]->setTexture(tex);
            pool[i]->setIsExpired(false);
            pool[i]->setOwner(owner);
            return true;
        }
    }
    return false;
}

void RocketPool::update(float dt)
{
    for (int i = 0; i < count; i++)
    {
        if (!pool[i]->getIsExpired())
            pool[i]->update(dt);
    }
}

void RocketPool::render(RenderWindow& window)
{
    for (int i = 0; i < count; i++)
    {
        if (!pool[i]->getIsExpired())
            pool[i]->render(window);
    }
}
