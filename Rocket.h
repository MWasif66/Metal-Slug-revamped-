#pragma once
#include "Projectile.h"
class Rocket :
    public Projectile
{
public:
    Rocket(int x, int y, int width, int height, Texture& texture, float velocityX, float velocityY, float maxSpeed, mString owner, int damage, int explosionRadius);
    virtual ~Rocket();
    Rocket(const Rocket& r);

    void move(float dt);
    bool onHit() override;
    void update(float dt) override;
    void render(RenderWindow& window) override;
    void reset(int x, int y, float vX, float vY);
};

