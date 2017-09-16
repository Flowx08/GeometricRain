
#include "World.hpp"
#include "Core.hpp"

World::World()
{
    Texture& atlas = rm.GetTexture("atlas");
    background = Sprite(atlas, IntRect(atlas.getSize().x-16, 0, 16, 16));
    background.setPosition(view.getSize().x/2, view.getSize().y/2);
    background.setOrigin(8, 8);
    background.setScale(1100/16 +1, 700/16 +1);
    background.setColor(Color(100, 100, 100));
    
    bar = Sprite(atlas, IntRect(atlas.getSize().x-16, 16, 16, 16));
    bar.setPosition(view.getSize().x/2, 650);
    bar.setOrigin(8, 0);
    bar.setScale(1100/16 +1, 1);
    bar.setColor(Color::White);
    
}

void World::Update()
{
    
}

void World::Draw()
{
    win.draw(background);
    win.draw(bar);
}

void World::SetBarColor(sf::Color barcolor)
{
    bar.setColor(barcolor);
}

void World::SetLightPower(const float power)
{
    background.setColor(Color(100 * power, 100 * power, 100 * power));
}