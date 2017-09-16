#ifndef WORLD_HPP
#define WORLD_HPP

#include <SFML/Graphics/Sprite.hpp>

class World
{
public:
    World();
    void Update();
    void Draw();
    
    void SetBarColor(sf::Color barcolor);
    void SetLightPower(const float power);
    
private:
    
    sf::Sprite background;
    sf::Sprite bar;
};

#endif