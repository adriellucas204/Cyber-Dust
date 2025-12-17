#include "EnemyBulletHandler.hpp"
#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteBuffer.hpp"
#include "Car.hpp"
#include "Enemy.hpp"
#include "Hero.hpp"
#include <string>
#include <vector>

void EnemyBulletHandler::addBullet() {
  if (this->getBulletCount() < 3) {
    ObjetoDeJogo *bullet = new ObjetoDeJogo(
        "bulletTrace", Sprite("rsc/bullet.txt", COR::MARROM_ESCURA),
        this->enemy.getPosL(), this->enemy.getPosC() + 2);
    this->bulletVector.push_back(bullet);
    this->bulletCount++;
  }
}

void EnemyBulletHandler::update() {
  for (auto it = this->bulletVector.begin(); it != this->bulletVector.end();) {
    ObjetoDeJogo *bullet = *it;
    if (!(bullet->getActive()) || bullet->getPosC() < 0) {
      delete bullet;
      it = bulletVector.erase(it);
      this->bulletCount--;
    } else {
      bullet->moveLeft(8);
      ++it;
    }
  }
} // chamar o update caso a bala colida, pois vai verificar no loop se a bala
  // esta desativada para liberar espaco

void EnemyBulletHandler::draw(SpriteBase &screen, int x, int y) {
  (void)x;
  (void)y;
  for (ObjetoDeJogo *bullet : this->bulletVector) {
    bullet->draw(screen, bullet->getPosL(), bullet->getPosC());
  }
}

bool EnemyBulletHandler::collided(Hero &hero) {
  for (ObjetoDeJogo *bullet : this->bulletVector) {
    if (bullet->colideComBordas(hero)) {
      bullet->desativarObj();
      hero.gotHit();
      return true;
    }
  }
  return false;
}

EnemyBulletHandler::~EnemyBulletHandler() {
  for (ObjetoDeJogo *bullet : this->bulletVector) {
    delete bullet;
  }
  this->bulletVector.clear();
}
// enemy : getC() + 2
// hero : getC() + 18