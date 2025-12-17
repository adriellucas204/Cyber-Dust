#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteAnimado.hpp"
#include "ASCII_Engine/SpriteBuffer.hpp"
#include "ASCII_Engine/SpriteView.hpp"
#include "Enemy.hpp"
#include "Hero.hpp"
#include "roadBlock.hpp"
#include <cstdlib>
#include <iostream>
#include <random>
#include <string>

std::random_device rd;
std::uniform_int_distribution<int> range();

int main() {
  SpriteBuffer screen(200, 40); // coluna(x) e linha(y)

  ObjetoDeJogo bg("bg", Sprite("rsc/levelScenery.txt"), 0, 0);
  Hero hero("Hero", SpriteAnimado("rsc/mainCar.txt", 1, COR::VERMELHA), 16, 0,
            3); // linha(y) e coluna (x)
  ObjetoDeJogo bulletTrace("bulletTrace",
                           Sprite("rsc/bullet.txt", COR::CINZA_ESCURA), 18, 18);

  Enemy enemy1("enemy1", SpriteAnimado("rsc/enemyCar.txt", 1, COR::CINZA), 16,
               175, 3);
  RoadBlock barrier1("smallRB", Sprite("rsc/roadBlock4x4", COR::AMARELA), )

      std::string input;

  while (true) {
    std::getline(std::cin, input);

    if (input == "w" && hero.getPosL() > 16) {
      hero.moveUp(2);
      enemy1.moveUp(1);
    } else if (input == "s" && hero.getPosL() < 34) {
      hero.moveDown(2);
      enemy1.moveDown(1);
    } else if (input == "a" && hero.getPosC() > 0) {
      hero.moveLeft(4);
    } else if (input == "d" && hero.getPosC() < 121) {
      hero.moveRight(4);
    }

    screen.clear();

    hero.update();
    enemy1.update();

    if (bg.getPosC() > -1400) {
      bg.moveLeft(4);
    } else {
      bg.moveTo(0, 0);
    }

    bg.draw(screen, bg.getPosL(), bg.getPosC());
    hero.draw(screen, hero.getPosL(), hero.getPosC());
    bulletTrace.draw(screen, bulletTrace.getPosL(), bulletTrace.getPosC());
    enemy1.draw(screen, enemy1.getPosL(), enemy1.getPosC());

    system("clear");
    std::cout << screen << std::endl;
    std::cout << hero.getPosL() << std::endl;
    std::cout << hero.getPosC() << std::endl;

    if (bulletTrace.getPosC() < 197) {
      bulletTrace.moveRight(8);
    } else {
      bulletTrace.desativarObj();
    }
  }

  // Sprite background("rsc/scene.txt");

  // background.draw(screen, 0, 0);
  // std::cout << screen << std::endl;
  return 0;
}
