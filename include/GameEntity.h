#ifndef OBIEKTGRY_H
#define OBIEKTGRY_H
#include <SFML/Graphics.hpp>


class GameEntity : public sf::Drawable
{
    public:
        GameEntity();
        GameEntity(float x, float y);
        virtual ~GameEntity();
        sf::RectangleShape shape;
        sf::RectangleShape pocisk;
        sf::Vertex line[2];
        double kat;
        int moc;
        void ruchArmata(double& kat, sf::Vertex&, sf::Vertex&);
    protected:

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // OBIEKTGRY_H
