
#include "MenuState.hpp"
#include "Core.hpp"

#include "Menu.hpp"
#include "World.hpp"
#include "Level.hpp"

MenuState::MenuState()
{
    rm.LoadTexture("atlas", "atlas.png");
    rm.LoadFont("font", "gamefont.ttf");
    rm.LoadSoundBuffer("menumove", "menumove.wav");
    rm.LoadSoundBuffer("menuselect", "menuselect.wav");
    
    menu = new Menu();
    world = new World();
    level = new Level();
    
    level->SetReady(true);
    level->SetUpdateScore(false);
}

MenuState::~MenuState()
{
    delete menu;
    delete world;
    delete level;
    
    rm.UnloadAll();
}

void MenuState::PoolEvents()
{
    //Events
    Event ev;
    while (win.pollEvent(ev)) {
        switch (ev.type) {
                
                //Close window
            case Event::Closed:
                win.close();
                break;
                
            case Event::KeyPressed:
                switch (ev.key.code)
                {
                    case Keyboard::Up: menu->OptionUp(); break;
                    case Keyboard::W: menu->OptionUp(); break;
                    case Keyboard::Down: menu->OptionDown(); break;
                    case Keyboard::S: menu->OptionDown(); break;
                    case Keyboard::Return: menu->OptionSelected(); break;
                    default: break;
                }
                break;
                
            default:
                break;
        }
    }
}

void MenuState::Update()
{
    world->Update();
    level->Update();
    menu->Update();
    
    world->SetBarColor(level->GetLastColor());
    menu->SetTitleColor(level->GetLastColor());
}

void MenuState::Draw()
{
    world->Draw();
    level->Draw();
    menu->Draw();
}