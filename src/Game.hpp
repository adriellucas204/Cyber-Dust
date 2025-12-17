#include "ASCII_Engine/Fase.hpp"
#include "ASCII_Engine/Sprite.hpp"
#include "FaseLevel1.hpp"
#include <iostream>

class Game {
public:
  Game() {}
  ~Game() {}

  static void run() {
    SpriteBuffer buffer(200, 40);

    FaseLevel1 fase1("FaseLevel1", Sprite("rsc/levelScenery.txt"), buffer);
    fase1.init();
    int ret = fase1.run(buffer);

    if (ret != Fase::END_GAME && ret != Fase::GAME_OVER) {
      buffer.clear();
      std::cout << "Parabens por ter completado" << std::endl;
    } else {
      std::cout << "GAME OVER." << std::endl;
    }
    std::cout << "Saindo..." << std::endl;
  }
};