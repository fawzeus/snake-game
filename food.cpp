#include "food.hpp"

Food::Food(int size,int value,sf::Color color):size(size),value(value),color(color){
    change_position();
}
void Food::draw(sf::RenderWindow &window){
    sf::CircleShape shape(size);
    shape.setPosition(x,y);
    shape.setFillColor(color);
    window.draw(shape);
}
void Food::change_position(){
    srand(time(0));
    x = (rand()%(WIDTH/SNAKE_SIZE));
    x = max(0,x-1)*SNAKE_SIZE+ceil(1.0*SNAKE_SIZE/2);
    srand(time(0));
    y = (rand()%(HEIGHT/SNAKE_SIZE));
    y= max(0,y-1)*SNAKE_SIZE+ceil(1.0/SNAKE_SIZE/2);
}