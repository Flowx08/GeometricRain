
#include "ParticleEmitter.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

using namespace sf;

// ================================
// ====>> PARTICLE
// ================================

namespace sfu
{
    
    ////////////////////////////////////////////////////////////
    Particle::Particle()
    {}
    
    ////////////////////////////////////////////////////////////
    Particle::Particle(const sf::Vector2f pos, const sf::Vector2f dir,
                       const sf::Color color, const unsigned int size, const float lifetime) :
        m_position(pos),
        m_direction(dir),
        m_color(color),
        m_size(size),
        m_lifetime(lifetime),
        m_maxlifetime(lifetime)
    {}

    ////////////////////////////////////////////////////////////
    void Particle::SetPosition(const float x, const float y)
    {
        m_position.x = x;
        m_position.y = y;
    }

    ////////////////////////////////////////////////////////////
    void Particle::SetPosition(const sf::Vector2f pos)
    {
        m_position = pos;
    }

    ////////////////////////////////////////////////////////////
    void Particle::SetDirection(const float x, const float y)
    {
        m_direction.x = x;
        m_direction.y = y;
    }

    ////////////////////////////////////////////////////////////
    void Particle::SetDirection(const sf::Vector2f dir)
    {
        m_direction = dir;
    }

    ////////////////////////////////////////////////////////////
    void Particle::SetColor(const sf::Color color)
    {
        m_color = color;
    }

    ////////////////////////////////////////////////////////////
    void Particle::SetSize(const unsigned int size)
    {
        m_size = size;
    }

    ////////////////////////////////////////////////////////////
    void Particle::SetLifetime(const float lifetime)
    {
        m_lifetime = lifetime;
        m_maxlifetime = lifetime;
    }

    ////////////////////////////////////////////////////////////
    sf::Vector2f Particle::GetPosition() const
    {
        return m_position;
    }

    ////////////////////////////////////////////////////////////
    sf::Vector2f Particle::GetDirection() const
    {
        return m_direction;
    }

    ////////////////////////////////////////////////////////////
    sf::Color Particle::GetColor() const
    {
        return m_color;
    }

    ////////////////////////////////////////////////////////////
    const float Particle::GetLifetime() const
    {
        return m_lifetime;
    }
    
    
    // ================================
    // ====>> PARTICLEEMITTER
    // ================================
    
    
    ////////////////////////////////////////////////////////////
    ParticleEmitter::ParticleEmitter()
    {
        vertices.setPrimitiveType(sf::Quads);
    }
    
    ////////////////////////////////////////////////////////////
    void ParticleEmitter::Update(const float etime)
    {
        vertices.clear();
        for (auto p = particles.begin(); p != particles.end();)
        {
            p->m_lifetime -= etime;
            p->m_position += p->m_direction * etime;
            float a = 255.f*(p->m_lifetime/p->m_maxlifetime);
            p->m_color.a = a < 0 ? 0 : a;
            
            vertices.append(Vertex({p->m_position.x - p->m_size/2.f,
                                    p->m_position.y - p->m_size/2.f},
                                    p->m_color));
            
            vertices.append(Vertex({p->m_position.x + p->m_size/2.f,
                                    p->m_position.y - p->m_size/2.f},
                                    p->m_color));
            
            vertices.append(Vertex({p->m_position.x + p->m_size/2.f,
                                    p->m_position.y + p->m_size/2.f},
                                    p->m_color));
            
            vertices.append(Vertex({p->m_position.x - p->m_size/2.f,
                                    p->m_position.y + p->m_size/2.f},
                                    p->m_color));
            
            if (p->m_lifetime <= 0) {
                particles.erase(p);
                continue;
            }
            
            //Increment
            ++p;
        }
    }
    
    ////////////////////////////////////////////////////////////
    void ParticleEmitter::AddParticle(Particle part)
    {
        particles.push_back(part);
    }
    
    ////////////////////////////////////////////////////////////
    void ParticleEmitter::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // apply the transform
        states.transform *= getTransform();
        
        // our particles don't use a texture
        states.texture = NULL;
        
        // draw the vertex array
        target.draw(vertices, states);
    }
    
}
