#include "ASCII_Engine/Fase.hpp"
#include "ASCII_Engine/SpriteBuffer.hpp"
#include "ASCII_Engine/core/SpriteBase.hpp"
#include "Enemy.hpp"
#include "EnemyBulletHandler.hpp"
#include "Hero.hpp"
#include "HeroBulletHandler.hpp"
#include "roadBlock.hpp"

#pragma once

class FaseLevel1 : public Fase {
private:
  Enemy *enemies[2];
  Hero *hero;
  RoadBlock *roadBs[3];
  EnemyBulletHandler *enemyBullet[2];
  //   EnemyBulletHandler *bossBullet;
  HeroBulletHandler *heroBullet;
  ObjetoDeJogo *items[2];
  SpriteBuffer &screen;

public:
  FaseLevel1(std::string name, const SpriteBase &bkg, SpriteBuffer &scr)
      : Fase(name, bkg), screen(scr) {}
  virtual ~FaseLevel1() {}

  SpriteBuffer &getScreen() { return this->screen; }

  virtual void init();
  virtual unsigned run(SpriteBuffer &screen);
};