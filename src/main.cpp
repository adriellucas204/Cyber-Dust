#include "Game.hpp"
#include <iostream>

// std::random_device rd;
// std::random_device directRate;

// std::uniform_int_distribution<int> distx(130, 166);
// std::uniform_int_distribution<int> disty(16, 33);
// std::uniform_int_distribution<int> direcChance(1, 100);
// std::uniform_int_distribution<int> shootRate(1, 100);

int main() {
  Game::run();
  // Keyboard::setMode(Keyboard::NONBLOCKING);
  // SpriteBuffer screen(200, 40); // coluna(x) e linha(y)

  // Enemy enemy1("enemy1", SpriteAnimado("rsc/enemyCar.txt", 3, COR::CINZA),
  // 16,
  //              175, 3);

  // std::vector<Enemy> enemyList;
  // enemyList.push_back(enemy1);

  // ObjetoDeJogo bg("bg", Sprite("rsc/levelScenery.txt"), 0, 0);
  // Hero hero("Hero", SpriteAnimado("rsc/mainCar.txt", 3, COR::VERMELHA), 16,
  // 0,
  //           3); // linha(y) e coluna (x)

  // RoadBlock barrier1("smallRB", Sprite("rsc/roadBlock4x4.txt", COR::AMARELA),
  //                    disty(rd), distx(rd));
  // HeroBulletHandler heroBullet(hero, screen);
  // EnemyBulletHandler enemyBullet(enemyList.at(0), screen);

  // // std::vector<ObjetoDeJogo *> bulletVector;

  // while (true) {
  //   heroBullet.update();
  //   enemyBullet.update();

  //   heroBullet.collided(enemyList);
  //   enemyBullet.collided(hero);

  //   char c = Keyboard::read();

  //   c = std::tolower(c);

  //   if (c == 'w' && hero.getPosL() > 16) {
  //     hero.moveUp(2);
  //   } else if (c == 's' && hero.getPosL() < 34) {
  //     hero.moveDown(2);
  //   } else if (c == 'a' && hero.getPosC() > 0) {
  //     hero.moveLeft(4);
  //   } else if (c == 'd' && hero.getPosC() < 121) {
  //     hero.moveRight(4);
  //   } else if (c == 32) {
  //     heroBullet.addBullet();
  //     // ObjetoDeJogo *bullet = new ObjetoDeJogo(
  //     //     "bulletTrace", Sprite("rsc/bullet.txt", COR::CINZA_ESCURA),
  //     //     hero.getPosL(), hero.getPosC() + 18);
  //     // bulletVector.push_back(bullet);
  //   }

  //   if (direcChance(directRate) <= 30) {
  //     for (Enemy &enemy : enemyList) {
  //       enemy.driveSystem(screen);
  //     }
  //   }

  //   if (shootRate(directRate) <= 30) {
  //     for (Enemy &enemy : enemyList) {
  //       enemy.shootSystem(enemyBullet);
  //     }
  //   }

  //   screen.clear();

  //   barrier1.moveLeft(4);
  //   hero.update();

  //   if (bg.getPosC() > -1400) {
  //     bg.moveLeft(4);
  //   } else {
  //     bg.moveTo(0, 0);
  //   }

  //   if (!barrier1.getActive()) {
  //     barrier1.ativarObj();
  //     barrier1.moveTo(disty(rd), distx(rd));

  //   } else if (barrier1.getPosC() > 0) {
  //     barrier1.moveLeft(4);
  //   } else {
  //     barrier1.desativarObj();
  //   }

  //   bg.draw(screen, bg.getPosL(), bg.getPosC());
  //   hero.draw(screen, hero.getPosL(), hero.getPosC());
  //   for (Enemy &enemy : enemyList) {
  //     if (enemy.getActive()) {
  //       enemy.update();
  //       enemy.draw(screen, enemy.getPosL(), enemy.getPosC());
  //     }
  //   }
  //   barrier1.draw(screen, barrier1.getPosL(), barrier1.getPosC());
  //   heroBullet.draw(screen, 0, 0);
  //   enemyBullet.draw(screen, 0, 0);

  //   // for (ObjetoDeJogo *bullet : bulletVector) {
  //   //   bullet->draw(screen, bullet->getPosL(), bullet->getPosC());
  //   // }

  //   system("clear");
  //   std::cout << screen << std::endl;
  //   // std::cout << hero.getPosL() << std::endl;
  //   // std::cout << hero.getPosC() << std::endl;

  //   if (hero.colideComBordas(barrier1)) {
  //     hero.gotHit();
  //     barrier1.desativarObj();
  //   }

  //   if (!hero.isAlive()) {
  //     std::cout << "GAME OVER." << std::endl;
  //     break;
  //   }

  //   std::cout << hero.getLife() << std::endl;

  //   // for (auto it = bulletVector.begin(); it != bulletVector.end();) {
  //   //   ObjetoDeJogo *bullet = *it;
  //   //   if (bullet->getPosC() < 197) {
  //   //     bullet->moveRight(8);
  //   //     ++it;
  //   //   } else {
  //   //     delete bullet;
  //   //     it = bulletVector.erase(it);
  //   //   }
  //   // }

  //   std::this_thread::sleep_for(std::chrono::milliseconds(64));
  // }

  return 0;
}
