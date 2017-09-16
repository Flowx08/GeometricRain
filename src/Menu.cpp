
#include "Core.hpp"
#include "Menu.hpp"

#include "States.hpp"

Menu::Menu()
{
    Texture& atlas = rm.GetTexture("atlas");
    Font& font = rm.GetFont("font");
    
    title = Sprite(atlas, IntRect(0, 64,
                                  atlas.getSize().x, 32));
    title.setPosition(view.getSize().x/2, 100);
    title.setOrigin(atlas.getSize().x/2, 16);
    title.setScale(3, 3);
    
    current_option = 0;
    
    //Setup Main texts
    main = UIList({view.getCenter().x, 200}, 80);
    main.AddItem(Text("Play", font));
    main.GetItem(0).setCharacterSize(48);
    main.AddItem(Text("Options", font));
    main.GetItem(1).setCharacterSize(48);
    main.AddItem(Text("Credits", font));
    main.GetItem(2).setCharacterSize(48);
    main.AddItem(Text("Exit", font));
    main.GetItem(3).setCharacterSize(48);
    main.AdjustItemsPosition();
    
    //Setup Options texts
    options = UIList({view.getCenter().x, 200}, 80);
    options.AddItem(Text(OptionsStrings[0] + std::to_string((int)listener.getGlobalVolume()), font));
    options.GetItem(0).setCharacterSize(32);
    options.AddItem(Text(OptionsStrings[1], font));
    options.GetItem(1).setCharacterSize(32);
    options.AdjustItemsPosition();
    
    //Setup Credits texts
    creditstext = Text(creditsstring, font);
    creditstext.setCharacterSize(48);
    creditstext.setColor(Color::Green);
    creditstext.setPosition(view.getSize().x/2 - creditstext.getGlobalBounds().width/2, 300);
    credits = UIList({view.getCenter().x, 400}, 80);
    credits.AddItem(Text("Back", font));
    credits.GetItem(0).setCharacterSize(48);
    credits.AdjustItemsPosition();
    
    Instructions.setFont(font);
    Instructions.setString("Press W - S or Up - Down to navigate the menu");
    Instructions.setColor(Color::White);
    Instructions.setPosition(view.getCenter().x, view.getSize().y - 100);
    Instructions.setCharacterSize(20);
    Instructions.setOrigin(Instructions.getLocalBounds().width/2,
                           Instructions.getLocalBounds().height/2);
    
    Instructions2.setFont(font);
    Instructions2.setString("Press Enter to select an option");
    Instructions2.setColor(Color::White);
    Instructions2.setPosition(view.getCenter().x, view.getSize().y - 72);
    Instructions2.setCharacterSize(20);
    Instructions2.setOrigin(Instructions2.getLocalBounds().width/2,
                            Instructions2.getLocalBounds().height/2);
    
}

Menu::~Menu()
{
}

void Menu::Update()
{
    switch (current_screen) {
        case S_Main:
            main.Update();
            break;
            
        case S_Options:
            options.Update();
            break;
            
        case S_Credits:
            credits.Update();
            break;
            
        default:
            break;
    }
}

void Menu::Draw()
{
    win.draw(title);
    switch (current_screen)
    {
        case S_Main:
            main.Draw();
            break;
            
        case S_Options:
            options.Draw();
            break;
            
        case S_Credits:
            win.draw(creditstext);
            credits.Draw();
            break;
            
        default:
            break;
    }
    win.draw(Instructions);
    win.draw(Instructions2);
}

void Menu::SetTitleColor(sf::Color titlecolor)
{
    title.setColor(titlecolor);
}

void Menu::OptionSelected()
{
    
    switch (current_screen)
    {
        case S_Main:
            main.Select();
            switch (main.GetSelectedItemID())
            {
                case O_Play:
                    sm.SetStateID(States::Game);
                    return;
                case O_Exit: win.close(); return;
                case O_Options: SetScreen(S_Options); return;
                case O_Credits: SetScreen(S_Credits); return;
            }
            break;
            
        case S_Options:
            options.Select();
            switch (options.GetSelectedItemID())
            {
                static float volume = 100;
                case O_SFXVolume:
                    volume = listener.getGlobalVolume();
                    volume += 10;
                    if (volume > 100)
                        volume = 0;
                    options.GetItem(0).setString(OptionsStrings[0] + std::to_string((int)volume));
                    options.AdjustItemsPosition();
                    listener.setGlobalVolume(volume);
                    return;
                    break;
                    
                case O_Back: SetScreen(S_Main); return;
            }
            break;
            
        case S_Credits:
            credits.Select();
            current_screen = S_Main;
            break;
            
        default:
            break;
    }
}

void Menu::OptionUp()
{
    switch (current_screen)
    {
        case S_Main: main.MoveUp(); break;
        case S_Options: options.MoveUp(); break;
            
        default:
            break;
    }
}

void Menu::OptionDown()
{
    switch (current_screen)
    {
        case S_Main: main.MoveDown(); break;
        case S_Options: options.MoveDown(); break;
            
        default:
            break;
    }
}

void Menu::SetScreen(const Menu::Screen screen)
{
    current_screen = screen;
    current_option = 0;
}