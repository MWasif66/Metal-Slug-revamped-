#pragma once
#include "Rocket.h"

const int MAX_ROCKETS = 20;
class RocketPool
{
    Rocket* pool[MAX_ROCKETS];
    int count;

public:
    RocketPool();
    ~RocketPool();

    bool fire(int x, int y, float vX, float vY,
        Texture& tex, float maxSpeed,
        const char* owner, int damage, int explosionRadius);

    void update(float dt);
    void render(RenderWindow& window);
};

