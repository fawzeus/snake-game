#include "snake.hpp"

using namespace std;

Snake::Snake(int x=28,int y=116,sf::Color color=sf::Color::Blue,Direction dir=Direction::DOWN){
    x=28;
    y=116;
    body.push_back(make_pair(x,y));
    body.push_back(make_pair(17,116));
    body.push_back(make_pair(6,116));
}
Snake::Snake():x(28),y(116),color(sf::Color::Blue),dir(Direction::DOWN){
    body.push_back(make_pair(x,y));
    body.push_back(make_pair(17,116));
    body.push_back(make_pair(6,116));
}
void Snake::draw(sf::RenderWindow &window){
    for(unsigned long i=0;i<body.size();i++){
        int scale = ceil(1.0*SNAKE_SIZE/2);
        sf::RectangleShape rectangle(sf::Vector2f(11, 11));
        sf::RectangleShape contour(sf::Vector2f(11,11));
        contour.setOutlineThickness(2); // Set outline thickness
        contour.setOutlineColor(sf::Color::Cyan); // Set outline color
        rectangle.setFillColor(color);

        rectangle.setPosition(body[i].first-scale,body[i].second-scale);
        contour.setPosition(body[i].first-scale,body[i].second-scale);
        window.draw(rectangle);
        window.draw(contour);
    }
}
void Snake::move(){
    cout<<"dir "<<static_cast<int>(dir)<<endl;
    pair <int,int> direction = direction_values[static_cast<int>(dir)];
    int curx=x,cury=y;
    x+=direction.first*SNAKE_SIZE;
    y+=direction.second*SNAKE_SIZE;
    body[0].first=x;
    body[0].second=y;
    for(unsigned long i=1;i<body.size();i++){
        int tempx,tempy;
        tempx=body[i].first;
        tempy=body[i].second;
        body[i].first=curx;
        body[i].second=cury;
        curx=tempx;
        cury=tempy;
    }
}


void Snake::set_direction(Direction dir){
    this->dir=dir;
}