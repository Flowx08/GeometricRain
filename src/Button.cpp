
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Window/Mouse.hpp>

#include "Button.hpp"

Button::Button()
{}

Button::Button(const sf::Font& font, const char* buttontext,
       const unsigned int size, const sf::Color& color,
       float x, float y)
{
    text.setFont(font);
    text.setString(buttontext);
    text.setCharacterSize(size);
    text.setColor(color);
    text.setPosition(x, y);
}

void Button::SetText(const char* buttontext)
{
    text.setString(buttontext);
}

void Button::SetFont(const sf::Font& font)
{
    text.setFont(font);
}

void Button::SetColor(const sf::Color &color)
{
    text.setColor(color);
}

void Button::SetCharacterSize(const unsigned int size)
{
    text.setCharacterSize(size);
}

void Button::SetPosition(float x, float y)
{
    text.setPosition(x, y);
}

const sf::Text& Button::Get()
{
    return text;
}

void Button::Update(sf::RenderWindow& win)
{
    sf::Vector2i mouse = sf::Mouse::getPosition(win);
    if (text.getLocalBounds().intersects(sf::FloatRect(mouse.x, mouse.y, 2, 2))) {
        isHold = true;
        text.scale(1.1, 1.1);
    }
    else
    {
        isHold = false;
        isClicked = false;
        text.scale(1, 1);
    }
}

void Button::Draw(sf::RenderWindow& win)
{
    win.draw(text);
}