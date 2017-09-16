
#include "Level.hpp"
#include "Core.hpp"
#include <fstream>
#include "WrapperOSX.h"

Level::Level()
{
    LoadMaxScore();
}

void Level::Update()
{
    
    if (!m_isplayerread) return;
    
    m_spawntime += etime;
    m_enemypassbar = false;
    
    if (m_spawntime >= m_spawnspeed)
    {
        float esize = 1 + (rand() % 1000)/1000.f;
        int rtype = rand() % 100;
        Enemy::Type type = Enemy::Quad;
        sf::Vector2f pos = {(float)(rand() % (int)view.getSize().x), -32};
        
        if (m_TrapeziumRain)
        {
            type = Enemy::Trapezium;
            esize = 1.f;
            pos = {m_playerpos.x - 400 + rand() % 800, -32};
        }
        else
        {
            if (rtype < 50) type = Enemy::Quad;
            else if (rtype < 85) type = Enemy::Triangle;
            else if (rtype < 95) type = Enemy::Star;
            else type = Enemy::Circle;
        }
        
        Enemy enemy = Enemy(type, pos, {esize, esize}, m_gamespeed);
        
        if (m_enemys.size() == 150)
        {
            m_current_enemy++;
            if (m_current_enemy >= m_max_enemy)
                m_current_enemy = 0;
            m_enemys[m_current_enemy] = enemy;
        }
        else
        {
            m_enemys.push_back(enemy);
        }
        
        m_spawntime -= m_spawnspeed;
    }
    
    bool abovebar = false;
    for (auto &e : m_enemys) {
        abovebar = false;
        if (e.isAlive()) {
            if ( e.GetPosition().y < 650) abovebar = true;
            e.Update();
            if (abovebar && e.GetPosition().y >= 650) {
                m_lastcolor = e.GetColor();
                m_enemypassbar = true;
                if (m_updatescore) m_score++;
            }
        }
    }
    
    
    if (m_score > 1000 && m_score % 1000 < 100) m_TrapeziumRain = true;
    else m_TrapeziumRain = false;
    
    if (m_score > m_best_score)
        m_best_score = m_score;
    
    if (m_score < 600)
    {
        m_lightpower = 0.5f + 0.5f * (1.f - m_score/600.f);
        m_spawnspeed = 0.15f + 0.25f * (1.f - m_score/500.f);
    }
    else
    {
        m_lightpower = 0.5f;
        m_spawnspeed = 0.15;
    }
    
    if (m_score < 1000)
    {
        m_gamespeed = 1.f + 2.f * (m_score/1000.f);
    }
    else
    {
        m_gamespeed = 3.f;
    }
    
    //if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) m_score++;
    
}

void Level::Draw()
{
    for (auto &e : m_enemys)
        if (e.isAlive())
            e.Draw();
}

bool Level::CollideWithEnemys(const sf::FloatRect rect)
{
    for (auto &e : m_enemys) {
        if (!e.isAlive()) continue;
        if (!(e.GetPosition().y > 500)) continue;
        if (e.GetRect().intersects(rect)) return true;
    }
    return false;
}

sf::Color Level::GetLastColor() const
{
    return m_lastcolor;
}

int Level::GetScore() const
{
    return m_score;
}

int Level::GetBestScore() const
{
    return m_best_score;
}

void Level::SetUpdateScore(const bool update)
{
    m_updatescore = update;
}

void Level::Restart()
{
    m_enemys.clear();
    m_lastcolor = Color::White;
    m_current_enemy = 0;
    m_score = 0;
    m_lightpower = 1.f;
    m_isplayerread = false;
}

void Level::SetReady(const bool ready)
{
    m_isplayerread = ready;
}

float Level::GetLightPower() const
{
    return m_lightpower;
}

void Level::LoadMaxScore()
{
    /*
    //Open the file
    std::ifstream file(rm.GetResourcePath() + "data.txt", std::ios::binary);
    
    //Check for errors
    if (!file) {
        file.close();
        return;
    }
    
    //Read data
    file.read(reinterpret_cast<char*>(&m_best_score), sizeof(int));
    
    //Close file
    file.close();
    */
}

void Level::SaveMaxScore()
{
    /*
    //Open the file
    std::ofstream file(rm.GetResourcePath() + "data.txt", std::ios::binary);
    
    //Check for errors
    if (!file) {
        file.close();
        return;
    }
    
    //Write data
    file.write(reinterpret_cast<char*>(&m_best_score), sizeof(int));
    
    //Close file
    file.close();
     */
}

void Level::SetPlayerPos(sf::Vector2f pos)
{
    m_playerpos = pos;
}
