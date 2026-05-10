#include "Weapon.h"



bool Weapon::shoot()
{
    if (fireTimer.isReady())
    {
        fireTimer.use();
        if (magazineSize != -1)
            ammo--;
        return true;
    }
    else
        return false;
}

// Note: call timer upddate in player and set it in player update


float Weapon::getBaseFireRate()
{
    return baseFireRate;
}

int Weapon::getAmmo()   // for weapon switching
{
    return ammo;
}

int Weapon::getDamage()
{
    return damage;
}

void Weapon::updateFireTimer(int dt)
{
    fireTimer.update(dt);
}

void Weapon::setFireRate(float f)
{
    fireRate = f;
    // must update timer too
    fireTimer.maxTime = f;
}

mString Weapon::getProjectileType()
{
    return projectileType;
}
