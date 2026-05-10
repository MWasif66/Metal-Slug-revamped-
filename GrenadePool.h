#pragma once
#include "Grenade.h"

const int MAX_GRENADES = 30;

class GrenadePool
{
    Grenade* pool[MAX_GRENADES];
    int count;

public:
    GrenadePool();
    ~GrenadePool();

    bool fire(int x, int y, float vX, float vY,
        Texture& tex, float maxSpeed,
        const char* owner, int damage, int explosionRadius);

    void update(float dt);
    void render(RenderWindow& window);
};

