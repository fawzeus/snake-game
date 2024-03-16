#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <vector>
#include<SFML/Graphics.hpp>
#include <utility>
#include <iostream>
#include <cmath>
#include "CONDTANTS.hpp"
#include "food.hpp"
using namespace std;

enum class Direction {
    UP =   0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3
};
constexpr pair<int,int> direction_values[] = {
    {0, -1},     // UP
    {0, 1},    // DOWN
    {-1, 0},    // LEFT
    {1, 0}      // RIGHT
};

class Snake{
private:
    int x,y;
    vector<pair<int,int>> body;
    sf::Color color;
    Direction dir;
public:
    Snake(int x,int y,sf::Color color,Direction dir);
    Snake();
    void move();
    void draw(sf::RenderWindow &window);
    void set_direction(Direction dir);
    void check_food_eat(Food &f);
    bool check_for_death();
};
#endif