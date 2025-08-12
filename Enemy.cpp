#include "Enemy.hpp"
#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteAnimado.hpp"
#include "ASCII_Engine/SpriteBuffer.hpp"
#include "ASCII_Engine/core/SpriteBase.hpp"
#include "EnemyBulletHandler.hpp"
#include <random>

// 1 -> se move para direita
// 2 -> se move para esquerda
// 3 -> se move para cima
// 4 -> se move para baixo

std::random_device seed;
std::uniform_int_distribution<int> positionNum(1, 10);

void Enemy::driveSystem(SpriteBuffer &screen) {
  int spawnNum{positionNum(seed)};
  if (this->getActive()) {
    if (spawnNum == 1 && this->getPosC() < screen.getWidth() - 24)
      this->moveRight(4);
    else if (spawnNum == 2 && this->getPosC() > screen.getWidth() - 46)
      this->moveLeft(4);
    else if (spawnNum >= 3 && spawnNum <= 6 && this->getPosL() > 16)
      this->moveUp(2);
    else if (spawnNum >= 7 && spawnNum <= 10 && this->getPosL() < 31)
      this->moveDown(2);
  }
}

void Enemy::shootSystem(EnemyBulletHandler &bulletHandler) {
  if (this->getActive()) {
    bulletHandler.addBullet();
  }
};
