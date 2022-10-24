#ifndef _GAME_H_
#define _GAME_H_
#include "player.h"
#include "constants.h"


class Game {
    int tile_size = 10;
    // print board helper functions
    void print_tile_edge() const;
    void print_blank_tile() const;
    void print_str_tile(std::string str) const;
    void print_property_edge(std::string colour) const;
    void print_empty_tile_row() const;
    void print_middle() const;
    void print_empty_center_row() const;
    void print_tile_center_row() const;
    void print_inner_border() const;
    void print_outer_border() const;
    public:
        Game();
        void print_board() const;
        ~Game();
};

#endif