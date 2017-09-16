#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "GameState.hpp"

class World;
class Player;
class Level;
class GameUI;

class Game : public GameState
{
public:
    
    Game();
    ~Game();
    void PoolEvents();
    void Update();
    void Draw();
    
private:
    
    World* world;
    Player* player;
    Level* level;
    GameUI* gameui;
    
    sf::Clock clock;
    float etime;
};

#endif