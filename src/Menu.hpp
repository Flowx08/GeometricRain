#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Audio/Sound.hpp>

#include "UIList.hpp"

using namespace sf;

class Menu
{
public:
    Menu();
    ~Menu();
    void Update();
    void Draw();
    
    void SetTitleColor(sf::Color titlecolor);
    
    void OptionSelected();
    void OptionUp();
    void OptionDown();
    
private:
    
    sf::Sound menumove;
    sf::Sound menuselect;
    
    sf::Text Instructions;
    sf::Text Instructions2;
    
    enum Screen
    {
        S_Main,
        S_Options,
        S_Credits
    };
    
    void SetScreen(const Screen screen);
    
    Sprite title;
    Screen current_screen = S_Main;
    unsigned int current_option = O_Play;
    
    // ==== MAIN SCREEN ====
    
    enum MainOptions
    {
        O_Play,
        O_Options,
        O_Credits,
        O_Exit,
    };
    
    UIList main;
    
    enum OptionsOptions
    {
        O_SFXVolume,
        O_Back,
    };
    
    UIList options;
    
    const std::string OptionsStrings[2] =
    {
        "Sound FX Volume: ",
        "Back"
    };
    
    UIList credits;
    sf::Text creditstext;
    const char* creditsstring = "Game made by Carlo Meroni";
    
};

#endif