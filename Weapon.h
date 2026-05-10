#pragma once
#include"Entity.h"
class Weapon
{
protected:
    float fireRate;      // seconds between shots
    float baseFireRate;
    Timer fireTimer;     // timer to manage fire rate 
    int ammo;            // -1 for infinite ammo 
    int magazineSize;       
    mString projectileType;
    int damage;

public:
    Weapon(const char* projType, float fireRate, int mangazine, int damage):fireTimer(fireRate),fireRate(fireRate),projectileType(projType),magazineSize(mangazine),ammo(mangazine),damage(damage)
    {
        baseFireRate = fireRate;
    }
    Weapon(const Weapon& w) : fireTimer(w.fireRate), fireRate(w.fireRate), projectileType(w.projectileType), magazineSize(w.magazineSize), ammo(w.magazineSize),baseFireRate(fireRate), damage(damage)
    {
        baseFireRate = w.fireRate;
    }

    void reload()
    {
        ammo = magazineSize;
    }

    // check timer and issue shoot command
    bool virtual shoot();
    float getBaseFireRate();
    int getAmmo();
    int getDamage();
    void updateFireTimer(int dt);
    void setFireRate(float f);
    mString getProjectileType();
};



