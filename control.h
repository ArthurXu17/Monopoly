#ifndef _CONTROL_H_
#define _CONTROL_H_
#include <memory>
#include "game.h"
#include "player.h"

class Controller {
    std::unique_ptr<Game> game;
    std::vector<std::shared_ptr<Player>> players;
    public:
        Controller();
        void play();
        ~Controller();
};

#endif