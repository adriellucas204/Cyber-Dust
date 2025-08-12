#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteAnimado.hpp"
#include "ASCII_Engine/core/SpriteBase.hpp"
#include "Car.hpp"
#include <string>
#pragma once

class Hero : public Car {

public:
  Hero(std::string name, const SpriteBase &spr, int y, int x, int life = 5)
      : Car(name, spr, y, x, life) {};
  virtual ~Hero() = default;
};