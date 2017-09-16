
#include "Player.hpp"
#include "Core.hpp"

#include "Level.hpp"

Player::Player()
{
    player = Sprite(rm.GetTexture("atlas"), IntRect(0, 0, 16, 16));
    player.setOrigin(8, 8);
    player.setPosition(view.getCenter().x, 650 - 16 + 4);
    player.setScale(2, 2);
    player.setColor(Color::White);
    
    deadsound.setBuffer(rm.GetSoundBuffer("dead"));
    
    alive = true;
    isready = false;
    
    Stay = sfu::Animation({0, 0}, {16, 16}, 2, 1);
    RunRight = sfu::Animation({0, 16}, {16, 16}, 2, 0.15);
    RunLeft = sfu::Animation({0, 32}, {16, 16}, 2, 0.15);
    AnimCurrent = &Stay;
    
}

Player::~Player()
{
    deadsound.stop();
}

void Player::Update()
{
    if (alive && playable)
    {
        
        //Reset
        direction.x = 0;
        
        //Controlls
        if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) {
            direction.x += 200 * sprint * etime;
            isready = true;
        }
        
        if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) {
            direction.x += -200 * sprint * etime;
            isready = true;
        }
        
        //Animation
        if ((direction.x == 0 && direction.y == 0) ||
            (direction.x < 0.05 && direction.x > -0.05))
        {
            AnimCurrent = &Stay;
        }
        else if (direction.x > 0)
        {
            AnimCurrent = &RunRight;
        }
        else if (direction.x < 0)
        {
            AnimCurrent = &RunLeft;
        }
        
        //Animation update texture
        AnimCurrent->Update(etime);
        player.setTextureRect(AnimCurrent->GetFrame());
        
        //Reduce sprint power
        if (sprint >= 1.f) sprint -= etime;
        else sprint = 1.f;
        
        //Sprint wait
        if (sprint_wait > 0.f) sprint_wait -= etime;
        else sprint_wait = 0.f;
        
        //Move player
        player.move(direction);
        
        //Wall collision
        if (player.getPosition().x < 0)
            player.setPosition(0, player.getPosition().y);
        
        if (player.getPosition().x > view.getSize().x)
            player.setPosition(view.getSize().x, player.getPosition().y);
    }
    
    bodyparticles.Update(etime);
    
}

void Player::Draw()
{
    if (alive && playable) win.draw(player);
    win.draw(bodyparticles);
}

void Player::CheckEnemysCollision(Level& lvl)
{
    if (!alive || !playable) return;
    if (lvl.CollideWithEnemys(player.getGlobalBounds())) {
        Killed();
    }
}

void Player::Killed()
{
    if (alive) {
        ev_death = true;
        deadsound.play();
        for (int i = 0; i < 20; i++)
        {
            sfu::Particle p;
            p.SetPosition(player.getPosition());
            p.SetDirection({static_cast<float>((rand() % 200)-100), static_cast<float>((rand() % 200)-100)});
            p.SetColor(sf::Color(100, 100, 100));
            p.SetLifetime((1000 + rand() % 1000)/1000.f);
            p.SetSize(4 + rand() % 3);
            bodyparticles.AddParticle(p);
        }
    }
    alive = false;
}

bool Player::isAlive() const
{
    return alive;
}

void Player::Sprint()
{
    if (!alive || !playable) return;
    if (direction.x == 0) return;
    if (!sprint_wait) {
        sprint = 2.f;
        sprint_wait = sprint_delay;
        for (int i = 0; i < 6; i++)
        {
            sfu::Particle p;
            p.SetPosition(player.getPosition());
            p.SetDirection(-direction.x * (20.f + rand() % 20), static_cast<float>((rand() % 100)-50));
            p.SetColor(sf::Color(100, 100, 250));
            p.SetLifetime((1000 + rand() % 1000)/1000.f);
            p.SetSize(4 + rand() % 3);
            bodyparticles.AddParticle(p);
        }
    }
}

void Player::SetPlay(const bool value)
{
    playable = value;
}

bool Player::isPlayable() const
{
    return playable;
}

bool Player::EventDeath()
{
    bool tmp = ev_death;
    ev_death = false;
    return tmp;
}

void Player::Reset()
{
    player.setPosition(view.getCenter().x, 650 - 16 + 4);
    alive = true;
    isready = false;
    AnimCurrent = &Stay;
}

bool Player::isReady()
{
    return isready;
}

sf::Vector2f Player::GetPosition()
{
    return player.getPosition();
}