#ifndef _CONTROL_H_
#define _CONTROL_H_
#include <memory>
//for random
#include <chrono>
#include <random>
#include <algorithm>

#include "game.h"
#include "player.h"

class Controller {
    std::unique_ptr<Game> game;
    std::vector<std::shared_ptr<Player>> players;
    std::mt19937 gen;
    std::default_random_engine rng;
    std::pair<int,int> roll_dice(bool loaded, std::mt19937& game_gen) const;
    public:
        Controller();
        void play();
        ~Controller();
};

#endif