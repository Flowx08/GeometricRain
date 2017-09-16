#ifndef CREDITSTATE_HPP
#define CREDITSTATE_HPP

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "GameState.hpp"

class CreditState : public GameState
{
public:
    
    CreditState();
    ~CreditState();
    void PoolEvents();
    void Update();
    void Draw();
    
private:
    
    float _alphain = 1;
    float _alphaout = 1;
    const float _maxalphain = 1;
    const float _maxalphaout = 1;
    float _scale = 2.f;
    float _alpha = 0;
    float _fullalphadelay = 0.5f;
    
    sf::Sprite background;
    sf::Sprite logo;
    
    sf::Clock clock;
    float etime;
};

#endif