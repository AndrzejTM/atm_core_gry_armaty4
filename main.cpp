#include <SFML/Graphics.hpp>
#include <GameEntity.h>
#include <cmath>
#include <iostream>

int main()
{
    int width = 500;
    int height = 350;

    sf::RenderWindow window(sf::VideoMode(width, height), "atm_core_gry_armaty4");
    sf::Event event;
    GameEntity* player = new GameEntity();
    GameEntity* wrog = new GameEntity(400, 300);
    float dx;
    float dy;
    float grawitacja = 0.1;
    bool tryb_automatyczny = false;


    while (window.isOpen())
    {
        window.setFramerateLimit(60);
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Right)
                {
                    player->kat += 0.1;
                    player->ruchArmata(player->kat, player->line[0], player->line[1]);
                    std::cout << "Kat = " << player->kat << std::endl;
                }
                if (event.key.code == sf::Keyboard::Left)
                {
                    player->kat -= 0.1;
                    player->ruchArmata(player->kat, player->line[0], player->line[1]);
                    std::cout << "Kat = " << player->kat << std::endl;
                }
                if (event.key.code == sf::Keyboard::M)
                {
                    player->moc += 1;
                    std::cout << "Moc = " << player->moc << std:: endl;
                }
                if (event.key.code == sf::Keyboard::Z)
                {
                    player->moc = 0;
                    player->kat = 0;
                    player->pocisk.setPosition(player->line[1].position.x,
                                               player->line[1].position.y);
                }

                if (event.key.code == sf::Keyboard::U)
                {
                    dx = cos(player->kat)*player->moc;
                    dy = sin(player->kat)*player->moc;
                }
                if (event.key.code == sf::Keyboard::S)
                {
                    tryb_automatyczny = !tryb_automatyczny;
                }
            }
        }

        if ( (player->pocisk.getPosition().y) > 350)
        {
            tryb_automatyczny = false;
        }
        window.clear(sf::Color::White);
        if (tryb_automatyczny == true)
        {
            dy += grawitacja;
            player->pocisk.setPosition( (player->pocisk.getPosition().x+dx),
                                        (player->pocisk.getPosition().y+dy) );
            std::cout << "dx = " << dx << std::endl;
            std::cout << "dy = " << dy << std::endl;
            std::cout << "kat = " << player->kat << std::endl;
            std::cout << "grawitacja = " << grawitacja << std::endl;
            std::cout << "tryb automatyczny = " << tryb_automatyczny << std:: endl;
            std::cout << "Pocisk y = " << player->pocisk.getPosition().y << std::endl;
        }
        window.draw(*player);
        window.draw(*wrog);
        window.display();
    }
    return 0;
    }


