#pragma once
#include "bullet.h"

const int BULLET_COUNT=50;
class BulletPool
{
    Bullet* pool[BULLET_COUNT];  // pointers to pre-allocated bullets
    int count;
public:
    BulletPool();
    ~BulletPool();

    bool fire(int x, int y, float vX, float vY,
        Texture& tex, float maxSpeed,
        const char* owner, int explosionRadius);

    void update(float dt);
    void render(RenderWindow& window);
};

