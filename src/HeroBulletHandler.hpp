#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteBuffer.hpp"
#include "ASCII_Engine/core/SpriteBase.hpp"
#include "Enemy.hpp"
#include "Hero.hpp"
#include <vector>
#pragma once

class HeroBulletHandler : public ObjetoDeJogo {
private:
  int bulletCount{0};
  std::vector<ObjetoDeJogo *> bulletVector;
  Hero &hero;

public:
  HeroBulletHandler(Hero &obj)
      : ObjetoDeJogo("BulletHandler", Sprite("rsc/bullet.txt"), 0, 0),
        hero(obj) {}
  void addBullet();
  void update();
  void draw(SpriteBase &screen, int x, int y);
  int getBulletCount() const { return this->bulletCount; };
  ~HeroBulletHandler();

  bool collided(Enemy *enemyList[], int size);
};