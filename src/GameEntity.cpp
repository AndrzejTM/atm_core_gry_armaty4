#include "GameEntity.h"
#include <SFML/Graphics.hpp>
#include <cmath>

GameEntity::GameEntity()
{
    shape.setSize(sf::Vector2f(50, 50));
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(sf::Vector2f(100, 300));

    line[0].position = sf::Vector2f(125, 325);
    line[1].position = sf::Vector2f(175, 325);
    line[0].color = sf::Color::Red;
    line[1].color = sf::Color::Red;

    pocisk.setSize(sf::Vector2f(10, 10));
    pocisk.setFillColor(sf::Color::Blue);
    pocisk.setPosition(sf::Vector2f(line[1].position.x, line[1].position.y));
    kat = 0;
    moc = 0;
}

GameEntity::GameEntity(float x, float y)
{
    shape.setSize(sf::Vector2f(50, 50));
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(sf::Vector2f(x, y));

    line[0].position = sf::Vector2f(x+25, y+25);
    line[1].position = sf::Vector2f(x+75, y+25);
    line[0].color = sf::Color::Red;
    line[1].color = sf::Color::Red;

    pocisk.setSize(sf::Vector2f(10, 10));
    pocisk.setFillColor(sf::Color::Blue);
    pocisk.setPosition(sf::Vector2f(line[1].position.x, line[1].position.y));
    kat = 0;
    moc = 0;
}

GameEntity::~GameEntity()
{
    //dtor
}

void GameEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(shape);
    target.draw(line, 2, sf::Lines);
    target.draw(pocisk);
}

void GameEntity::ruchArmata(double& kat, sf::Vertex& punkt1, sf::Vertex& punkt2)
{
    punkt2.position = sf::Vector2f( float(punkt1.position.x+cos(kat)*50),
                                   float(punkt1.position.y+sin(kat)*50));
    this->pocisk.setPosition(punkt2.position.x, punkt2.position.y);
}
