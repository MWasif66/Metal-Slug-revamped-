#pragma once
#include "Projectile.h"
#include "Gravity.h"
class Grenade :
    public Projectile
{
    Gravity gravity;
    
public:
    Grenade(int x, int y, int width, int height, Texture& texture, float velocityX, float velocityY, float maxSpeed, mString owner, int damage, int explosionRadius);
    virtual ~Grenade();
    Grenade(const Grenade& g);

    void move(float dt);
    bool onHit() override;
    void update(float dt) override;
    void render(RenderWindow& window) override;
    void reset(int x, int y, float vX, float vY);
};

