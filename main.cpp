#include <SFML/Graphics.hpp>
#include "board.h"


int main()
{
    board game;
    int boardSize = game.getSize();
    const int SPRITE_SIZE = 12;
    sf::RenderWindow window(sf::VideoMode(SPRITE_SIZE * boardSize, SPRITE_SIZE * boardSize), "SFML works!");
    sf::Texture livingPic;
    sf::Texture deadPic;
    sf::Sprite live;
    sf::Sprite dead;
    sf::Vector2i mPosition;

    livingPic.loadFromFile("flower.png");
    deadPic.loadFromFile("grass.png");
    live.setTexture(livingPic);
    dead.setTexture(deadPic);
    int clickedX, clickedY;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                mPosition = sf::Mouse::getPosition(window);
                clickedX = mPosition.x / SPRITE_SIZE;
                clickedY = mPosition.y / SPRITE_SIZE;
                game.toggleLife(clickedX, clickedY);
            }
            if(event.type == sf::Event::KeyPressed)
            {
                game.update();
            }
        }

        window.clear();

        for (int x = 0; x < boardSize; x++)
        {
            for (int y = 0; y < boardSize; y++)
            {
                if (!game.isAlive(x, y))
                {
                    dead.setPosition(sf::Vector2f((float)x * SPRITE_SIZE, (float)y * SPRITE_SIZE));
                    window.draw(dead);
                }
                else
                {
                    live.setPosition(sf::Vector2f((float)x * SPRITE_SIZE, (float)y * SPRITE_SIZE));
                    window.draw(live);
                }
            }
        }

        window.display();
    }


    return 0;
}
