#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteBuffer.hpp"
#include "ASCII_Engine/core/SpriteBase.hpp"
#include "Enemy.hpp"
#include "Hero.hpp"
#include <vector>
#pragma once

class EnemyBulletHandler : public ObjetoDeJogo {
private:
  int bulletCount{0};
  std::vector<ObjetoDeJogo *> bulletVector;
  Enemy &enemy;
  SpriteBuffer &screen;

public:
  EnemyBulletHandler(Enemy &obj, SpriteBuffer &scr)
      : ObjetoDeJogo("BulletHandler", Sprite("rsc/bullet.txt"), 0, 0),
        enemy(obj), screen(scr) {}
  void addBullet();
  void update();
  void draw(SpriteBase &screen, int x, int y);
  int getBulletCount() const { return this->bulletCount; };
  //   void setEnemy(Enemy &obj) { this->enemy = obj; };

  ~EnemyBulletHandler();

  bool collided(Hero &);
};