#include <SFML/Graphics.hpp>
#include "food.hpp"
#include "snake.hpp"
#include <unistd.h>
using namespace std;

int main(){

    Food f;
    Snake s;
    Direction current_dir = Direction::RIGHT;
    sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT),"Snake Game");
    while(window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    if(current_dir!=Direction::DOWN)
                        current_dir=Direction::UP;
                    break;
                case sf::Keyboard::Down:
                    if(current_dir!=Direction::UP)
                        current_dir=Direction::DOWN;
                    break;
                case sf::Keyboard::Left:
                    if(current_dir!=Direction::RIGHT)
                        current_dir=Direction::LEFT;
                    break;
                case sf::Keyboard::Right:
                    if(current_dir!=Direction::LEFT)
                        current_dir=Direction::RIGHT;
                    break;
                default:
                    break;
                }
            }
        }
        s.set_direction(current_dir);
        s.move();
        
        // Draw the game objects
        window.clear();
        f.draw(window);
        s.draw(window);
        window.display();
        usleep(500000);
        
    }
    return 0;
}