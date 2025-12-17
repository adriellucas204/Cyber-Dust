#include "FaseLevel1.hpp"
#include "ASCII_Engine/Fase.hpp"
#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "ASCII_Engine/SpriteBuffer.hpp"
#include "ASCII_Engine/core/SpriteBase.hpp"
#include "ASCII_Engine/input/Keyboard.hpp"
#include "Enemy.hpp"
#include "EnemyBulletHandler.hpp"
#include "Hero.hpp"
#include "HeroBulletHandler.hpp"
#include "roadBlock.hpp"
#include <cctype>
#include <chrono>
#include <iostream>
#include <random>
#include <thread>

std::random_device rd;
std::uniform_int_distribution<int> shootAndDirec(1, 100);
std::uniform_int_distribution<int> rbSelect(0, 2);
std::uniform_int_distribution<int> itemSelect(0, 1);
std::uniform_int_distribution<int> distx(130, 166);
std::uniform_int_distribution<int> disty(16, 33);
std::uniform_int_distribution<int> enemyY(17, 30);
std::uniform_int_distribution<int> enemyX(154, 165);

void FaseLevel1::init() {
  hero = new Hero("hero", SpriteAnimado("rsc/mainCar.txt", 3, COR::VERMELHA),
                  16, 0, 5);
  objs.push_back(hero);

  enemies[0] = new Enemy(
      "enemy1", SpriteAnimado("rsc/enemyCar.txt", 3, COR::MAGENTA), 16, 175, 3);
  objs.push_back(enemies[0]);
  enemies[0]->desativarObj();

  enemies[1] =
      new Enemy("boss", SpriteAnimado("rsc/bossCar.txt", 3, COR::CINZA_ESCURA),
                16, 175, 3);
  enemies[1]->setLife(20);
  objs.push_back(enemies[1]);
  enemies[1]->desativarObj();

  roadBs[0] =
      new RoadBlock("6x2", Sprite("rsc/roadBlock6x2.txt", COR::AMARELA), 0, 0);
  objs.push_back(roadBs[0]);
  roadBs[0]->desativarObj();

  roadBs[1] =
      new RoadBlock("4x4", Sprite("rsc/roadBlock4x4.txt", COR::AMARELA), 0, 0);
  objs.push_back(roadBs[1]);
  roadBs[1]->desativarObj();

  roadBs[2] =
      new RoadBlock("2x6", Sprite("rsc/roadBlock2x6.txt", COR::AMARELA), 0, 0);
  objs.push_back(roadBs[2]);
  roadBs[2]->desativarObj();

  enemyBullet[0] = new EnemyBulletHandler(*enemies[0]);
  objs.push_back(enemyBullet[0]);

  enemyBullet[1] = new EnemyBulletHandler(*enemies[1]);
  objs.push_back(enemyBullet[1]);

  heroBullet = new HeroBulletHandler(*hero);
  objs.push_back(heroBullet);

  items[0] = new ObjetoDeJogo("magField",
                              Sprite("rsc/magField.txt", COR::CINZA), 0, 0);
  objs.push_back(items[0]);
  items[0]->desativarObj();

  items[1] = new ObjetoDeJogo(
      "techBattery", SpriteAnimado("rsc/techBattery.txt", 3, COR::AZUL), 0, 0);
  objs.push_back(items[1]);
  items[1]->desativarObj();

  bg = new ObjetoDeJogo("bg", Sprite("rsc/levelScenery.txt"), 0, 0);
  objs.push_front(bg);
}

unsigned FaseLevel1::run(SpriteBuffer &screen) {
  Keyboard::setMode(Keyboard::NONBLOCKING);
  char c;
  bool roadBlockActive;
  bool enemyActive;
  int enemiesLeft{20};

  // padrao
  screen.clear();
  system("clear");
  draw(screen);
  show(screen);

  while (true) {
    roadBlockActive = false;
    enemyActive = false;
    // testar se balas colidiram com algo.
    // heroBullet.update();
    // enemyBullet.update();

    // atualizar o background
    if (bg->getPosC() > -1400) {
      bg->moveLeft(4);
    } else {
      bg->moveTo(0, 0);
    }

    if (heroBullet->collided(enemies, 2)) {
      enemiesLeft--;
    }

    for (int i{0}; i < 2; i++) {
      enemyBullet[i]->collided(*hero);
    }

    c = Keyboard::read();
    c = std::tolower(c);

    // entrada do usuario para o jogador se mover
    if (c == 'w' && hero->getPosL() > 16) {
      hero->moveUp(2);
    } else if (c == 's' && hero->getPosL() < 34) {
      hero->moveDown(2);
    } else if (c == 'a' && hero->getPosC() > 0) {
      hero->moveLeft(4);
    } else if (c == 'd' && hero->getPosC() < 121) {
      hero->moveRight(4);
    } else if (c == 32) {
      heroBullet->addBullet();
    } else if (c == 13) {
      return Fase::PAUSED;
    }

    // se ha inimigos na tela
    for (int i = 0; i < 2; i++) {
      if (enemies[i]->getActive()) {
        enemyActive = true;
        break;
      }
    }

    if (!enemyActive && enemiesLeft > 0) {
      int index{itemSelect(rd)};
      enemies[index]->ativarObj();
      enemies[index]->setLife(5);
      enemies[index]->moveTo(enemyY(rd), enemyX(rd));
    }

    // inimigos se mover e atirar
    if (shootAndDirec(rd) <= 30) {
      for (int i{0}; i < 2; i++) {
        if (enemies[i]->getActive()) {
          enemies[i]->driveSystem(screen);
        }
      }
    }

    if (shootAndDirec(rd) <= 20) {
      for (int i{0}; i < 2; i++) {
        if (enemies[i]->getActive()) {
          enemies[i]->shootSystem(*enemyBullet[i]);
        }
      }
    }

    // gelo bahiano randomico
    for (int i{0}; i < 3; i++) {
      if (roadBs[i]->getActive()) {
        roadBlockActive = true;
        break;
      }
    }

    if (!roadBlockActive) {
      int index{rbSelect(rd)};
      roadBs[index]->ativarObj();
      roadBs[index]->moveTo(disty(rd), distx(rd));
    }

    for (int i = 0; i < 3; i++) {
      if (roadBs[i]->getActive()) {
        if (roadBs[i]->getPosC() > 0) {
          roadBs[i]->moveLeft(4);
        } else {
          roadBs[i]->desativarObj();
        }
        break;
      }
    }

    for (int i = 0; i < 3; i++) {
      if (hero->colideComBordas(*roadBs[i])) {
        hero->gotHit();
      }
    }

    // if (rbSelect(rd)) {
    //   barrier1.ativarObj();
    //   barrier1.moveTo(disty(rd), distx(rd));

    // } else if (barrier1.getPosC() > 0) {
    //   barrier1.moveLeft(4);
    // } else {
    //   barrier1.desativarObj();
    // }

    std::this_thread::sleep_for(std::chrono::milliseconds(64));
    update();
    screen.clear();
    std::cout << "\x1b[H";

    draw(screen);
    show(screen);

    if (!hero->isAlive()) {
      return Fase::GAME_OVER;
    }

    if (enemiesLeft <= 0) {
      return Fase::LEVEL_COMPLETE;
    }
    std::cout << "LIFE: " << hero->getLife() << std::endl;
    std::cout << "ENEMIES REMAINING: " << enemiesLeft << std::endl;
  }
}