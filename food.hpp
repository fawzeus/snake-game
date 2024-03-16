#ifndef FOOD_HPP
#define FOOD_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include<cmath>
#include "CONSTANTS.hpp"

using namespace std;

class Food {
    private:
        int x,y;
        int size;
        int value;
        sf::Color color;
    public:
        Food(int size = 5,int value=1,sf::Color color=sf::Color::Red);
        void draw(sf::RenderWindow &window);
        void change_position();
        int get_x()const;
        int get_y()const;


};

#endif