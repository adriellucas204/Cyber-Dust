#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteAnimado.hpp"
#include "ASCII_Engine/core/SpriteBase.hpp"
#include <string>
#pragma once

class Car : public ObjetoDeJogo {
private:
  int life;

public:
  Car(std::string name, const SpriteBase &spr, int y, int x, int life = 5)
      : ObjetoDeJogo(name, spr, y, x), life(life) {}
  virtual ~Car() = default;

  bool isAlive() const { return life > 0; };
  int getLife() const { return life; };
  void setLife(int l) { this->life = l; };
  void gotHit() {
    if (--life <= 0) {
      this->desativarObj();
    }
  };
  // bool canCollideBullet() const { return true; }
};