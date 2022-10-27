#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_
#include <vector>
#include <string>

const std::vector<int> HOUSE_COSTS = {50, 100, 150, 200};

const std::vector<std::vector<int>> RENT_COSTS = {
    {2, 10, 30, 90, 160, 250}, // Meditteranean Avenue
    {4, 20, 60, 180, 320, 450}, // Baltic Avenue
    {6, 30, 90, 270, 400, 550}, // Oriental Avenue
    {6, 30, 90, 270, 400, 550}, // Vermont Avenue
    {8, 40, 100, 300, 450, 600}, // Connecticut Avenue
    {10, 50, 150, 450, 625, 750}, // St Charles Place
    {10, 50, 150, 450, 625, 750}, // States Avenue
    {12, 60, 180, 500, 700, 900}, // Virginia Avenue
    {14, 70, 200, 550, 750, 950}, // St James Place
    {14, 70, 200, 550, 750, 950}, // Tennesee Avenue
    {16, 80, 220, 600, 800, 1000}, // New York Avenue
    {18, 90, 250, 700, 875, 1050}, // Kentucky Avenue
    {18, 90, 250, 700, 875, 1050}, // Indiana Avenue
    {20, 100, 300, 750, 925, 1100}, // Illinois Avenue
    {22, 110, 330, 800, 975, 1150}, // Atlantic Avenue
    {22, 110, 330, 800, 975, 1150}, // Ventmor Avenue
    {24, 120, 360, 850, 1025, 1200}, // Marvin Gardens
    {26, 130, 390, 900, 1100, 1275}, // Pacific Avenue
    {26, 130, 390, 900, 1100, 1275}, // North Carolina Avenue
    {28, 150, 450, 1000, 1200, 1400}, // Pennsylvania Avenue
    {35, 175, 500, 1100, 1300, 1500}, // Park Place
    {50, 200, 600, 1400, 1700, 2000}, // Boardwalk
};

const std::vector<int> PURCHASE_COSTS = {
    40, // Meditteranean Avenue
    60, // Baltic Avenue
    100, // Oriental Avenue
    100, // Vermont Avenue
    120, // Connecticut Avenue
    140, // St Charles Place
    140, // States Avenue
    160, // Virginia Avenue
    180, // St James Place
    180, // Tennesee Avenue
    200, // New York Avenue
    220, // Kentucky Avenue
    220, // Indiana Avenue
    240, // Illinois Avenue
    260, // Atlantic Avenue
    260, // Ventmor Avenue
    280, // Marvin Gardens
    300, // Pacific Avenue
    300, // North Carolina Avenue
    320, // Pennsylvania Avenue
    350, // Park Place
    400 // Boardwalk
};

const std::vector<std::string> NAMES = {
    "Meditteranean Avenue",
    "Baltic Avenue",
    "Oriental Avenue",
    "Vermont Avenue",
    "Connecticut Avenue",
    "St Charles Place",
    "States Avenue",
    "Virginia Avenue",
    "St James Place",
    "Tennesee Avenue",
    "New York Avenue",
    "Kentucky Avenue",
    "Indiana Avenue",
    "Illinois Avenue",
    "Atlantic Avenue",
    "Ventmor Avenue",
    "Marvin Gardens",
    "Pacific Avenue",
    "North Carolina Avenue",
    "Pennsylvania Avenue",
    "Park Place",
    "Boardwalk"
};

// colours
// taken from: https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
const std::string BROWN = "\033[38;5;94m";
const std::string LIGHT_BLUE = "\033[38;5;14m";
const std::string PINK = "\033[38;5;199m";
const std::string ORANGE = "\033[38;5;202m";
const std::string RED = "\033[38;5;196m";
const std::string YELLOW = "\033[38;5;226m";
const std::string GREEN = "\033[38;5;22m";
const std::string BLUE = "\033[34m";
const std::string RESET = "\033[0m";

#endif