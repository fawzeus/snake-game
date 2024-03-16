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
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        cout<<"can\'t load font"<<endl;
        exit(-1);
    }
    sf::Text text;

    // select the font
    text.setFont(font); // font is a sf::Font

    // set the string to display
    text.setString("Score :"+std::to_string(get_score()));

    // set the character size
    text.setCharacterSize(24); // in pixels, not points!
    text.setPosition(10,10);

    // set the color
    text.setFillColor(sf::Color::White);

    // set the text style
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    window.draw(text);
    for(unsigned long i=0;i<body.size();i++){
        //scale x and y coordinates to the center
        int scale = ceil(SNAKE_SIZE/2.0);
        sf::RectangleShape rectangle(sf::Vector2f(10, 10));
        sf::RectangleShape contour(sf::Vector2f(10,10));
        contour.setOutlineThickness(2); // Set outline thickness
        contour.setOutlineColor(sf::Color::Cyan); // Set outline color
        rectangle.setFillColor(color);

        rectangle.setPosition(body[i].first-scale,body[i].second-scale);
        contour.setPosition(body[i].first-scale,body[i].second-scale);
        window.draw(rectangle);
        window.draw(contour);
    }
}
// move snake one step in the given direction 
void Snake::move(){
    //scale x and y coordinates to the center
    int scale = ceil(SNAKE_SIZE/2.0);
    pair <int,int> direction = direction_values[static_cast<int>(dir)];
    int curx=x,cury=y;
    //update the position of the head
    x+=direction.first*SNAKE_SIZE;
    y+=direction.second*SNAKE_SIZE;
    
    if (x>WIDTH-scale)x=scale;
    else if(x<scale) x=WIDTH-scale;
    if (y>HEIGHT-scale)y=scale;
    else if(y<-scale) y=HEIGHT-scale;
    //cout<<"SNAKE ("<<x<<","<<y<<")"<<endl;
    //update position of the head
    body[0].first=x;
    body[0].second=y;
    //update position of each cell and make it the same position as the previous cell
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
//check for a collusion between sanke and food;
void Snake::check_food_eat(Food &f){
    if(abs(f.get_x()-x)<=6 and abs(f.get_y()-y)<=6){
        body.push_back(make_pair(x,y));
        f.change_position();
    }
}
//check if the snake hit his body
bool Snake::check_for_death(){
    for(unsigned long i=1;i<body.size();i++){
        if(body[i].first==body[0].first and body[i].second==body[0].second){
            return true;
        }
    }
    return false;
}
//score of game
int Snake::get_score(){
    return body.size()-3;
}