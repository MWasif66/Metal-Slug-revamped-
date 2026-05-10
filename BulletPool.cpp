#include "BulletPool.h"

BulletPool::BulletPool()
{
    count = BULLET_COUNT;

    Texture dummyTex; // temporary — texture set properly on fire()

    for (int i = 0; i < count; i++)
    {
        // Pre-allocate all bullets at position 0,0 — they're inactive
        pool[i] = new Bullet(0, 0, 16, 8, dummyTex, 0, 0, 300, "player", 0);
        pool[i]->setIsExpired(true);
    }
}

BulletPool::~BulletPool()
{
    for (int i = 0; i < count; i++)
        delete pool[i];
}

bool BulletPool::fire(int x, int y, float vX, float vY,
    Texture& tex, float maxSpeed,
    const char* owner, int explosionRadius)
{
    for (int i = 0; i < count; i++)
    {
        if (pool[i]->getIsExpired())          // find first free slot
        {
            pool[i]->reset(x, y, vX, vY);
            pool[i]->setTexture(tex);
            pool[i]->setIsExpired(false);
            pool[i]->setOwner(owner);
            return true;         // fired successfully
        }
    }
    return false;                // pool full, shot skipped
}

void BulletPool::update(float dt)
{
    for (int i = 0; i < count; i++)
    {
        if (!pool[i]->getIsExpired())
        {
            pool[i]->update(dt);
        }
    }
}

void BulletPool::render(RenderWindow& window)
{
    for (int i = 0; i < count; i++)
    {
        if (!pool[i]->getIsExpired())
            pool[i]->render(window);
    }
}
