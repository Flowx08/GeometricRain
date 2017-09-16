#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics/Sprite.hpp>

class Enemy
{
public:
    
    enum Type
    {
        Quad,
        Triangle,
        Star,
        TriangleLeft,
        TriangleRight,
        Circle,
        Trapezium,
    };
    
    Enemy();
    Enemy(Enemy::Type type, sf::Vector2f pos, sf::Vector2f scale, float speed);
    void Update();
    void Draw();
    
    bool isAlive() const;
    sf::Vector2f GetPosition() const;
    sf::FloatRect GetRect() const;
    sf::Color GetColor() const;
    
private:
    
    Type m_type;
    bool m_alive = true;
    bool m_jumped = false;
    float m_weight = 80;
    sf::Sprite m_enemy;
    sf::Vector2f m_direction;
    
};

#endif
