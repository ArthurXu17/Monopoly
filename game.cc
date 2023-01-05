#include <iostream>
#include "game.h"

void Game::add_street_property(int &i) {
    int j = 0; // house index
    if (6 <= i && i <= 11) {
        j = 1;
    } else if (12 <= i && i <= 16) {
        j = 2;
    } else if (17 <= i && i <= 20) {
        j = 3;
    }
    tiles.emplace_back(std::make_shared<Street_Property>(
        NAMES[i], PURCHASE_COSTS[i], HOUSE_COSTS[j], RENT_COSTS[i]));
    i++;
}

Game::Game(std::vector<std::shared_ptr<Player>> players_in): players{players_in} {
    tiles.emplace_back(std::make_shared<NothingTile>("GO"));
    int street_property_counter = 0;
    add_street_property(street_property_counter);
    tiles.emplace_back(std::make_shared<NothingTile>("Community Chest"));
    add_street_property(street_property_counter);
    tiles.emplace_back(std::make_shared<TaxTile>("Income Tax", 200));
    tiles.emplace_back(std::make_shared<Railroad>("Reading Railroad", 200));
    add_street_property(street_property_counter);
    tiles.emplace_back(std::make_shared<NothingTile>("Chance"));
    add_street_property(street_property_counter);
    add_street_property(street_property_counter);
    tiles.emplace_back(std::make_shared<NothingTile>("Jail"));
    add_street_property(street_property_counter);
    tiles.emplace_back(std::make_shared<Utility>("Electric Company", 120));
    add_street_property(street_property_counter);
    add_street_property(street_property_counter);
    tiles.emplace_back(std::make_shared<Railroad>("Pennsylvania Railroad", 200));
    add_street_property(street_property_counter);
    tiles.emplace_back(std::make_shared<NothingTile>("Community Chest"));
    add_street_property(street_property_counter);
    add_street_property(street_property_counter);
    tiles.emplace_back(std::make_shared<NothingTile>("Free Parking"));
    add_street_property(street_property_counter);
    tiles.emplace_back(std::make_shared<NothingTile>("Chance"));
    add_street_property(street_property_counter);
    add_street_property(street_property_counter);
    tiles.emplace_back(std::make_shared<Railroad>("B&O Railroad", 200));
    add_street_property(street_property_counter);
    add_street_property(street_property_counter);
    tiles.emplace_back(std::make_shared<Utility>("Water Works", 120));
    add_street_property(street_property_counter);
    tiles.emplace_back(std::make_shared<NothingTile>("Go To Jail"));
    add_street_property(street_property_counter);
    add_street_property(street_property_counter);
    tiles.emplace_back(std::make_shared<NothingTile>("Community Chest"));
    add_street_property(street_property_counter);
    tiles.emplace_back(std::make_shared<Railroad>("Short Line", 200));
    tiles.emplace_back(std::make_shared<NothingTile>("Chance"));
    add_street_property(street_property_counter);
    tiles.emplace_back(std::make_shared<TaxTile>("Luxury Tax", 100));
    add_street_property(street_property_counter);
}

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

void Game::print_player_on_tile(int pos) const {
    // assumes 10 is visiting 30 is in jail
    int count = 0;
    for (auto p : players) {
        if (p->get_position() == pos) {
            std::cout<<*p<<" ";
            count++;
        }
    }
    for (int i = 1; i <= tile_size - 2 * count; i++) {
        std::cout<<" ";
    }
    std::cout<<"|";
}

void Game::print_houses(std::shared_ptr<Tile> property) const {
    std::shared_ptr<Street_Property> street_property = std::static_pointer_cast<Street_Property>(property);
    int num_houses = street_property->get_num_houses();
    if (1 <= num_houses && num_houses <= 4) {
        std::cout<<GREEN;
        for (int i = 1; i <= num_houses; i++) {
            std::cout<<"h";
        }
        for (int i = 1; i <= tile_size - num_houses; i++) {
            std::cout<<" ";
        }
        std::cout<<RESET<<"|";
    } else if (num_houses == 5) {
        std::cout<<RED<<"H";
        for (int i = 1; i <= tile_size - 1; i++) {
            std::cout<<" ";
        }
        std::cout<<RESET<<"|";
    } else {
        print_blank_tile();
    }
}

void Game::print_board() const {
    print_outer_border();
    std::cout<<"|";
    print_str_tile("FREE"); 
    print_houses(tiles[21]); // Kentucky
    print_str_tile("CHANCE"); 
    print_houses(tiles[23]); // Indiana
    print_houses(tiles[24]); // Illinois
    print_str_tile("B&O");
    print_houses(tiles[26]); // Atlantic
    print_houses(tiles[27]); // Ventnor
    print_str_tile("WATER");
    print_houses(tiles[29]); // Marvin Gardens
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
    std::cout<<std::endl<<"|";
    for (int i = 20; i <= 29; i++) {
        print_player_on_tile(i);
    }
    print_blank_tile();
    std::cout<<std::endl;
    print_inner_border();
    std::cout<<"|";
    print_houses(tiles[19]); // New York
    print_middle();
    print_houses(tiles[31]); // Pacific
    std::cout<<std::endl;
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
    std::cout<<"|";
    print_player_on_tile(19); // new york players
    print_middle();
    print_player_on_tile(31); // pacific players
    std::cout<<std::endl;
    print_tile_center_row();
    std::cout<<"|";
    print_houses(tiles[18]); // Tennesee
    print_middle();
    print_houses(tiles[32]); // North Carolina
    std::cout<<std::endl;
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
    std::cout<<"|";
    print_player_on_tile(18); // tennessee players
    print_middle();
    print_player_on_tile(32); // north carolina players
    std::cout<<std::endl;
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
    std::cout<<"|";
    print_player_on_tile(17); // cc
    print_middle();
    print_player_on_tile(33); // cc
    std::cout<<std::endl;
    print_tile_center_row();
    std::cout<<"|";
    print_houses(tiles[16]); // St james
    print_middle();
    print_houses(tiles[34]); // Pennsylvania
    std::cout<<std::endl;
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
    std::cout<<"|";
    print_player_on_tile(16); // st james players
    print_middle();
    print_player_on_tile(34); // pennsylvania players
    std::cout<<std::endl;
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
    std::cout<<"|";
    print_player_on_tile(15); // penn railroad
    print_middle();
    print_player_on_tile(35); // short line
    std::cout<<std::endl;
    print_tile_center_row();
    std::cout<<"|";
    print_houses(tiles[14]); // virginia
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
    std::cout<<"|";
    print_player_on_tile(14); // virginia
    print_middle();
    print_player_on_tile(36); // chance
    std::cout<<std::endl;
    print_tile_center_row();
    std::cout<<"|";
    print_houses(tiles[13]); // States
    print_middle();
    print_houses(tiles[37]); // Park place
    std::cout<<std::endl;
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
    std::cout<<"|";
    print_player_on_tile(13); // states
    print_middle();
    print_player_on_tile(37); // park place
    std::cout<<std::endl;
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
    std::cout<<"|";
    print_player_on_tile(12); // electric company
    print_middle();
    print_player_on_tile(38); // luxary tax
    std::cout<<std::endl;
    print_tile_center_row();
    std::cout<<"|";
    print_houses(tiles[11]); // st charles
    print_middle();
    print_houses(tiles[39]); // Boardwalk
    std::cout<<std::endl;
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
    std::cout<<"|";
    print_player_on_tile(11); // st charles
    print_middle();
    print_player_on_tile(39); // boardwalk
    std::cout<<std::endl;
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
    print_str_tile("JAIL"); 
    print_houses(tiles[9]); // connecticut
    print_houses(tiles[8]); // vermont
    print_str_tile("CHANCE"); 
    print_houses(tiles[6]); // oriental
    print_str_tile("READING");
    print_str_tile("INCOME");
    print_houses(tiles[3]); // baltic
    print_str_tile("COMMUNITY");
    print_houses(tiles[1]); // medditeranean
    print_str_tile("GO");
    std::cout<<std::endl<<"|";
    print_player_on_tile(30); // in jail
    print_property_edge(LIGHT_BLUE);
    print_property_edge(LIGHT_BLUE);
    print_blank_tile();
    print_property_edge(LIGHT_BLUE);
    print_str_tile("RAILROAD");
    print_str_tile("TAX");
    print_property_edge(BROWN);
    print_str_tile("CHEST");
    print_property_edge(BROWN);
    print_str_tile("COLLECT");
    std::cout<<std::endl<<"|";
    print_tile_edge();
    std::cout<<"|";
    print_str_tile("CONN.");
    print_str_tile("VERMONT");
    print_blank_tile();
    print_str_tile("ORIENTAL");
    print_blank_tile();
    print_blank_tile();
    print_str_tile("BALTIC");
    print_blank_tile();
    print_str_tile("MEDD.");
    print_str_tile("200$");
    std::cout<<std::endl<<"|";
    print_str_tile("VISITNG");
    print_str_tile("AVENUE");
    print_str_tile("AVENUE");
    print_blank_tile();
    print_str_tile("AVENUE");
    print_blank_tile();
    print_blank_tile();
    print_str_tile("AVENUE");
    print_blank_tile();
    print_str_tile("AVENUE");
    print_blank_tile();
    std::cout<<std::endl<<"|";
    for (int i = 10; i >= 0; i--) {
        print_player_on_tile(i);
    }
    std::cout<<std::endl;
    print_inner_border();
}

void Game::playerLandOnTile(std::shared_ptr<Player> landed) {
    int pos = landed->get_position();
    tiles.at(pos)->perform_turn(landed, players);
}