#ifndef _GAME_H_
#define _GAME_H_
#include "player.h"
#include "constants.h"
#include "street_property.h"
#include "railroad.h"
#include "utility.h"


class Game {
    int tile_size = 10;
    std::vector<std::shared_ptr<Player>> players;
    std::vector<std::shared_ptr<Tile>> tiles;
    // property intialization helper funciton
    void add_street_property(int &i);
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
    void print_player_on_tile(int pos) const;
    void print_houses(std::shared_ptr<Tile> property) const;
    public:
        Game(std::vector<std::shared_ptr<Player>> players_in);
        void print_board() const;
        void playerLandOnTile(std::shared_ptr<Player> landed);
        ~Game();
};

#endif