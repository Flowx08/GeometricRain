#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "GameState.hpp"

class Menu;
class World;
class Level;

class MenuState : public GameState
{
public:
    
    MenuState();
    ~MenuState();
    void PoolEvents();
    void Update();
    void Draw();
    
private:
    
    Menu* menu;
    World* world;
    Level* level;
    
    
    sf::Clock clock;
    float etime;
};

#endif