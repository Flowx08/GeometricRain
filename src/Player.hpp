#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Audio/Sound.hpp>
#include "Animation.hpp"
#include "ParticleEmitter.hpp"

class Level;

class Player
{
public:
    Player();
    ~Player();
    void Update();
    void Draw();
    
    bool isAlive() const;
    bool isPlayable() const;
    void CheckEnemysCollision(Level& em);
    void SetPlay(const bool value);
    void Killed();
    void Sprint();
    void Reset();
    bool isReady();
    bool EventDeath();
    sf::Vector2f GetPosition();
    
private:
    
    bool alive = false;
    bool playable = false;
    bool ev_death = false;
    bool isready = false;
    float sprint = 1.f;
    const float sprint_delay = 6.f;
    float sprint_wait = 0.f;
    sf::Sprite player;
    sf::Vector2f direction;
    
    sfu::Animation Stay;
    sfu::Animation RunRight;
    sfu::Animation RunLeft;
    sfu::Animation* AnimCurrent;
    
    sf::Sound deadsound;
    sfu::ParticleEmitter bodyparticles;
};

#endif