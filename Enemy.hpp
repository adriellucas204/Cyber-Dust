#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteAnimado.hpp"
#include "ASCII_Engine/core/SpriteBase.hpp"
#include "Car.hpp"
#pragma once

class Enemy : public Car {
public:
  Enemy(std::string name, const SpriteBase &spr, int y, int x, int life = 5)
      : Car(name, spr, y, x, life) {};
  virtual ~Enemy() = default;

  // int atacar(); fazer n sei como
};