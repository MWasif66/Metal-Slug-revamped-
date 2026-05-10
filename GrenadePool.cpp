#include "GrenadePool.h"


GrenadePool::GrenadePool()
{
    count = MAX_GRENADES;
    Texture dummyTex;

    for (int i = 0; i < count; i++)
    {
        pool[i] = new Grenade(0, 0, 16, 16, dummyTex, 0, 0, 200, "player", 10, 80);
        pool[i]->setIsExpired(true);
    }
}

GrenadePool::~GrenadePool()
{
    for (int i = 0; i < count; i++)
        delete pool[i];
}

bool GrenadePool::fire(int x, int y, float vX, float vY,
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

void GrenadePool::update(float dt)
{
    for (int i = 0; i < count; i++)
    {
        if (!pool[i]->getIsExpired())
            pool[i]->update(dt);
    }
}

void GrenadePool::render(RenderWindow& window)
{
    for (int i = 0; i < count; i++)
    {
        if (!pool[i]->getIsExpired())
            pool[i]->render(window);
    }
}