#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics/Text.hpp>

namespace sf
{
    class RenderWindow;
}

class Button
{
public:
    
    Button();
    Button(const sf::Font& font, const char* buttontext,
           const unsigned int size, const sf::Color& color,
           float x, float y);
    void SetText(const char* buttontext);
    void SetFont(const sf::Font& font);
    void SetCharacterSize(const unsigned int size);
    void SetColor(const sf::Color& color);
    const sf::Text& Get();
    void SetPosition(float x, float y);
    void Update(sf::RenderWindow& win);
    void Draw(sf::RenderWindow& win);
    
private:
    bool isHold;
    bool isClicked;
    sf::Text text;
};

#endif