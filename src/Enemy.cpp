
#include "Enemy.hpp"
#include "Core.hpp"

Enemy::Enemy()
{}

Enemy::Enemy(Enemy::Type type, sf::Vector2f pos, sf::Vector2f scale, float speed)
{
    
    //Texture shortcut
    sf::Texture& atlas = rm.GetTexture("atlas");
    
    //Setup sprite
    m_enemy.setTexture(atlas);
    m_enemy.setPosition(pos);
    m_enemy.setOrigin(16, 16);
    m_enemy.setScale(scale);
    m_enemy.setColor(Color(55 + rand() % 200, 55 + rand() % 200, 55 + rand() % 200));
    m_type = type;
    
    m_alive = true;
    
    //Type specific things
    switch (type) {
        case Quad:
            m_enemy.setTextureRect(IntRect(32, 0, 32, 32));
            m_direction = sf::Vector2f(0, 100 * speed);
            m_weight = 80.f * (2.f - scale.x);
            break;
            
        case Triangle:
            m_enemy.setTextureRect(IntRect(64, 0, 32, 32));
            m_direction = sf::Vector2f(0, 100 * speed);
            m_weight = 160.f;
            break;
            
        case Star:
            m_enemy.setTextureRect(IntRect(96, 0, 32, 32));
            m_direction = sf::Vector2f(-30 + rand() % 60, 200 * speed);
            m_weight = 0;
            break;
            
        case Circle:
            m_enemy.setTextureRect(IntRect(128, 0, 32, 32));
            m_direction = sf::Vector2f(0, 50 * speed);
            m_weight = 200.f;
            break;
            
        case Trapezium:
            m_enemy.setTextureRect(IntRect(32, 32, 32, 32));
            m_direction = sf::Vector2f(0, 200 * speed);
            m_weight = 0;
            break;
            
        default:
            break;
    }
}

void Enemy::Update()
{
    //Gravity
    m_direction.y += m_weight * (1.f - m_enemy.getLocalBounds().width/64.f) * etime;
    
    switch (m_type) {
        case Quad:
            break;
            
        case Triangle:
            
            break;
            
        case Star:
            
            break;
            
        case Circle:
            if (m_enemy.getPosition().y + (m_direction.y * (float)etime) > 650 - 16
                && !m_jumped) {
                m_direction.y = -m_direction.y;
                m_jumped = true;
            }
            break;
            
        case Trapezium:
            
            break;
            
        default:
            break;
    }
    
    //Move
    m_enemy.move(m_direction * (float)etime);

    //Check it is alive
    if (m_enemy.getPosition().y > view.getSize().y + 32)
        m_alive = false;
}

void Enemy::Draw()
{
    win.draw(m_enemy);
}

bool Enemy::isAlive() const
{
    return m_alive;
}

sf::Vector2f Enemy::GetPosition() const
{
    return m_enemy.getPosition();
}

sf::FloatRect Enemy::GetRect() const
{
    return m_enemy.getGlobalBounds();
}

sf::Color Enemy::GetColor() const
{
    return m_enemy.getColor();
}