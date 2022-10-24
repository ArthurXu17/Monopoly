#include <iostream>
#include "game.h"


Game::Game() {}

Game::~Game() {}

void Game::print_tile_edge() const {
    for (int i = 1; i <= tile_size; i++) {
        std::cout<<"_";
    }
}

void Game::print_inner_border() const {
    std::cout<<"|";
    for (int i = 1; i <= 11; i++) {  
        print_tile_edge();
        std::cout<<"|";
    }
    std::cout<<std::endl;
}

void Game::print_outer_border() const {
    std::cout<<"_";
    for (int i = 1; i <= 11; i++) {  
        print_tile_edge();
        std::cout<<"_";
    }
    std::cout<<std::endl;
}

void Game::print_blank_tile() const {
    for (int i = 1; i <= tile_size; i++) {
        std::cout<<" ";
    }
    std::cout<<"|";
}


void Game::print_str_tile(std::string str) const {
    std::cout<<str;
    int len = str.length();
    for (int i = 1; i <= tile_size - len; i++) {
        std::cout<<" ";
    }
    std::cout<<"|";
}

void Game::print_property_edge(std::string colour) const {
    std::cout<<colour;
    for (int i = 1; i <= tile_size; i++) {
        std::cout<<"-";
    }
    std::cout<<RESET<<"|";
}

void Game::print_empty_tile_row() const {
    std::cout<<"|";
    for (int i = 1; i <= 11; i++) {
        print_blank_tile();
    }
    std::cout<<std::endl;
}


void Game::print_middle() const {
    for (int i = 1; i < 9 * (tile_size + 1); i++) {
        std::cout<<" ";
    }
    std::cout<<"|";
}

void Game::print_empty_center_row() const {
    std::cout<<"|";
    print_blank_tile();
    print_middle();
    print_blank_tile();
    std::cout<<std::endl;
}

void Game::print_tile_center_row() const {
    std::cout<<"|";
    print_tile_edge();
    std::cout<<"|";
    print_middle();
    print_tile_edge();
    std::cout<<"|"<<std::endl;
}

void Game::print_board() const {
    print_outer_border();
    std::cout<<"|";
    print_str_tile("FREE"); 
    print_blank_tile();
    print_str_tile("CHANCE"); 
    print_blank_tile();
    print_blank_tile();
    print_str_tile("B&O");
    print_blank_tile();
    print_blank_tile();
    print_str_tile("WATER");
    print_blank_tile();
    print_str_tile("GO TO");
    std::cout<<std::endl<<"|";
    print_str_tile("PARKING");
    print_property_edge(RED);
    print_blank_tile();
    print_property_edge(RED);
    print_property_edge(RED);
    print_str_tile("RAILROAD");
    print_property_edge(YELLOW);
    print_property_edge(YELLOW);
    print_str_tile("WORKS");
    print_property_edge(YELLOW);
    print_str_tile("JAIL");
    std::cout<<std::endl<<"|";
    print_blank_tile();
    print_str_tile("KENTUCKY");
    print_blank_tile();
    print_str_tile("INDIANA");
    print_str_tile("ILLINOIS");
    print_blank_tile();
    print_str_tile("ATLANTIC");
    print_str_tile("VENTNOR");
    print_blank_tile();
    print_str_tile("MARVIN");
    print_blank_tile();
    std::cout<<std::endl<<"|";
    print_blank_tile();
    print_str_tile("AVENUE");
    print_blank_tile();
    print_str_tile("AVENUE");
    print_str_tile("AVENUE");
    print_blank_tile();
    print_str_tile("AVENUE");
    print_str_tile("AVENUE");
    print_blank_tile();
    print_str_tile("GARDENS");
    print_blank_tile();
    std::cout<<std::endl;
    print_empty_tile_row();
    print_inner_border();
    print_empty_center_row();
    std::cout<<"|";
    print_property_edge(ORANGE);
    print_middle();
    print_property_edge(GREEN);
    std::cout<<std::endl<<"|";
    print_str_tile("NEW YORK");
    print_middle();
    print_str_tile("PACIFIC");
    std::cout<<std::endl<<"|";
    print_str_tile("AVENUE");
    print_middle();
    print_str_tile("AVENUE");
    std::cout<<std::endl;
    print_empty_center_row();
    print_tile_center_row();
    print_empty_center_row();
    std::cout<<"|";
    print_property_edge(ORANGE);
    print_middle();
    print_property_edge(GREEN);
    std::cout<<std::endl<<"|";
    print_str_tile("TENNESEE");
    print_middle();
    print_str_tile("NORTH CAR.");
    std::cout<<std::endl<<"|";
    print_str_tile("AVENUE");
    print_middle();
    print_str_tile("AVENUE");
    std::cout<<std::endl;
    print_empty_center_row();
    print_tile_center_row();
    std::cout<<"|";
    print_str_tile("COMMUNITY");
    print_middle();
    print_str_tile("COMMUNITY");
    std::cout<<std::endl;
    std::cout<<"|";
    print_str_tile("CHEST");
    print_middle();
    print_str_tile("CHEST");
    std::cout<<std::endl;
    print_empty_center_row();
    print_empty_center_row();
    print_empty_center_row();
    print_tile_center_row();
    print_empty_center_row();
    std::cout<<"|";
    print_property_edge(ORANGE);
    print_middle();
    print_property_edge(GREEN);
    std::cout<<std::endl<<"|";
    print_str_tile("ST. JAMES");
    print_middle();
    print_str_tile("PENN.");
    std::cout<<std::endl<<"|";
    print_str_tile("PLACE");
    print_middle();
    print_str_tile("AVENUE");
    std::cout<<std::endl;
    print_empty_center_row();
    print_tile_center_row();
    std::cout<<"|";
    print_str_tile("PENN.");
    print_middle();
    print_str_tile("SHORT");
    std::cout<<std::endl;
    std::cout<<"|";
    print_str_tile("RAILROAD");
    print_middle();
    print_str_tile("LINE");
    std::cout<<std::endl;
    print_empty_center_row();
    print_empty_center_row();
    print_empty_center_row();
    print_tile_center_row();
    std::cout<<"|";
    print_blank_tile();
    print_middle();
    print_str_tile("CHANCE");
    std::cout<<std::endl;
    std::cout<<"|";
    print_property_edge(PINK);
    print_middle();
    print_blank_tile();
    std::cout<<std::endl;
    std::cout<<"|";
    print_str_tile("VIRGINIA");
    print_middle();
    print_blank_tile();
    std::cout<<std::endl;
    std::cout<<"|";
    print_str_tile("AVENUE");
    print_middle();
    print_blank_tile();
    std::cout<<std::endl;
    print_empty_center_row();
    print_tile_center_row();
    print_empty_center_row();
    std::cout<<"|";
    print_property_edge(PINK);
    print_middle();
    print_property_edge(BLUE);
    std::cout<<std::endl<<"|";
    print_str_tile("STATES");
    print_middle();
    print_str_tile("PARK");
    std::cout<<std::endl<<"|";
    print_str_tile("AVENUE");
    print_middle();
    print_str_tile("PLACE");
    std::cout<<std::endl;
    print_empty_center_row();
    print_tile_center_row();
    std::cout<<"|";
    print_str_tile("ELECTRIC");
    print_middle();
    print_str_tile("LUXARY");
    std::cout<<std::endl;
    std::cout<<"|";
    print_str_tile("COMPANY");
    print_middle();
    print_str_tile("TAX");
    std::cout<<std::endl;
    print_empty_center_row();
    print_empty_center_row();
    print_empty_center_row();
    print_tile_center_row();
    print_empty_center_row();
    std::cout<<"|";
    print_property_edge(PINK);
    print_middle();
    print_property_edge(BLUE);
    std::cout<<std::endl<<"|";
    print_str_tile("ST CHARLES");
    print_middle();
    print_str_tile("BOARDWALK");
    std::cout<<std::endl<<"|";
    print_str_tile("PLACE");
    print_middle();
    print_blank_tile();
    std::cout<<std::endl;
    print_empty_center_row();
    std::cout<<"|";
    print_tile_edge();
    std::cout<<"|";
    for (int i = 1; i < 9 * (tile_size + 1); i++) {
        std::cout<<"_";
    }
    std::cout<<"|";
    print_tile_edge();
    std::cout<<"|"<<std::endl;
    std::cout<<"|";
    print_str_tile("FREE"); 
    print_blank_tile();
    print_str_tile("CHANCE"); 
    print_blank_tile();
    print_blank_tile();
    print_str_tile("B&O");
    print_blank_tile();
    print_blank_tile();
    print_str_tile("WATER");
    print_blank_tile();
    print_str_tile("GO TO");
    std::cout<<std::endl<<"|";
    print_str_tile("PARKING");
    print_property_edge(RED);
    print_blank_tile();
    print_property_edge(RED);
    print_property_edge(RED);
    print_str_tile("RAILROAD");
    print_property_edge(YELLOW);
    print_property_edge(YELLOW);
    print_str_tile("WORKS");
    print_property_edge(YELLOW);
    print_str_tile("JAIL");
    std::cout<<std::endl<<"|";
    print_blank_tile();
    print_str_tile("KENTUCKY");
    print_blank_tile();
    print_str_tile("INDIANA");
    print_str_tile("ILLINOIS");
    print_blank_tile();
    print_str_tile("ATLANTIC");
    print_str_tile("VENTNOR");
    print_blank_tile();
    print_str_tile("MARVIN");
    print_blank_tile();
    std::cout<<std::endl<<"|";
    print_blank_tile();
    print_str_tile("AVENUE");
    print_blank_tile();
    print_str_tile("AVENUE");
    print_str_tile("AVENUE");
    print_blank_tile();
    print_str_tile("AVENUE");
    print_str_tile("AVENUE");
    print_blank_tile();
    print_str_tile("GARDENS");
    print_blank_tile();
    std::cout<<std::endl;
    print_empty_tile_row();
    print_inner_border();
}