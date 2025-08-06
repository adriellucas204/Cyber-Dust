#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteAnimado.hpp"
#include "ASCII_Engine/core/SpriteBase.hpp"
#include <string>
#pragma once

class RoadBlock : public ObjetoDeJogo {
public:
  RoadBlock(std::string name, const SpriteBase &spr, int y, int x)
      : ObjetoDeJogo(name, spr, y, x) {}
};