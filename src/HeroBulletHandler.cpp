#include "HeroBulletHandler.hpp"
#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteBuffer.hpp"
#include "Car.hpp"
#include "Enemy.hpp"
#include <string>
#include <vector>

void HeroBulletHandler::addBullet() {
  if (this->getBulletCount() < 3) {
    ObjetoDeJogo *bullet = new ObjetoDeJogo(
        "bulletTrace", Sprite("rsc/bullet.txt", COR::CINZA_ESCURA),
        this->hero.getPosL(), this->hero.getPosC() + 18);
    this->bulletVector.push_back(bullet);
    this->bulletCount++;
  }
}

void HeroBulletHandler::update() {
  for (auto it = this->bulletVector.begin(); it != this->bulletVector.end();) {
    ObjetoDeJogo *bullet = *it;
    if (!(bullet->getActive()) || bullet->getPosC() > 197) {
      delete bullet;
      it = bulletVector.erase(it);
      this->bulletCount--;
    } else {
      bullet->moveRight(8);
      ++it;
    }
  }
} // chamar o update caso a bala colida, pois vai verificar no loop se a bala
  // esta desativada para liberar espaco

void HeroBulletHandler::draw(SpriteBase &screen, int x, int y) {
  (void)x;
  (void)y;
  for (ObjetoDeJogo *bullet : this->bulletVector) {
    bullet->draw(screen, bullet->getPosL(), bullet->getPosC());
  }
}

bool HeroBulletHandler::collided(Enemy *enemyList[], int size) {
  for (ObjetoDeJogo *bullet : this->bulletVector) {
    for (int i = 0; i < size; i++) {
      Enemy *enemy = enemyList[i];
      if (enemy->getActive() && bullet->colideComBordas(*enemy)) {
        bullet->desativarObj();
        enemy->gotHit();
        return true;
      }
    }
  }
  return false;
}

HeroBulletHandler::~HeroBulletHandler() {
  for (ObjetoDeJogo *bullet : this->bulletVector) {
    delete bullet;
  }
  this->bulletVector.clear();
}
// enemy : getC() + 2
// hero : getC() + 18