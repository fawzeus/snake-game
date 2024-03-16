#include "food.hpp"

Food::Food(int size,int value,sf::Color color):size(size),value(value),color(color){
    change_position();
    //cout<<"FOOD ("<<x<<","<<y<<")"<<endl;
}
void Food::draw(sf::RenderWindow &window){
    sf::CircleShape shape(size);
    shape.setPosition(x,y);
    shape.setFillColor(color);
    window.draw(shape);
}
void Food::change_position(){
    srand(time(0));
    x = (rand()%(WIDTH/SNAKE_SIZE))*SNAKE_SIZE;
    srand(time(0));
    y = (rand()%(HEIGHT/SNAKE_SIZE))*SNAKE_SIZE;
}

int Food::get_x()const{
    return x;
}
int Food::get_y()const{
    return y;
}