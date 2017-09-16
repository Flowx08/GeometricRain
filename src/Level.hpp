#ifndef ENEMYMANAGER_HPP
#define ENEMYMANAGER_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <vector>
#include "Enemy.hpp"

class Level
{
public:
    Level();
    void Update();
    void Draw();
    
    bool CollideWithEnemys(sf::FloatRect rect);
    sf::Color GetLastColor() const;
    int GetScore() const;
    int GetBestScore() const;
    float GetLightPower() const;
    void SetPlayerPos(sf::Vector2f pos);
    void SetUpdateScore(const bool update);
    void Restart();
    void SetReady(const bool ready);
    void LoadMaxScore();
    void SaveMaxScore();
    
private:
    
    std::vector<Enemy> m_enemys;
    sf::Color m_lastcolor = sf::Color::White;
    sf::Vector2f m_playerpos;
    int m_level = 0;
    bool m_TrapeziumRain = false;
    const unsigned int m_max_enemy = 150;
    unsigned int m_current_enemy = 0;
    float m_spawnspeed = 0.4f;
    float m_spawntime = 0.f;
    float m_gamespeed = 1.f;
    float m_lightpower = 1.f;
    bool m_enemypassbar = false;
    int m_score = 0;
    int m_best_score = 0;
    bool m_updatescore = true;
    bool m_isplayerread = false;
    
};

#endif
