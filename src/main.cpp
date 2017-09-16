
//====================
#include "GameState.hpp"
#include "Core.hpp"
#include "States.hpp"
#include "WrapperOSX.h"

//====================
#include "CreditState.hpp"
#include "MenuState.hpp"
#include "Game.hpp"

//====================
#include <SFML/System/Sleep.hpp>


//====================
using namespace sf;

int main()
{
    //Context settings
    sf::ContextSettings cs;
    cs.depthBits = 8;
    cs.stencilBits = 0;
    cs.antialiasingLevel = 0;
    
    //Create window
    win.create(VideoMode(1100, 700), "Geometric Rain", sf::Style::Close, cs);
    win.setVerticalSyncEnabled(true);
    win.setFramerateLimit(80);
    win.setMouseCursorVisible(false);
    
    //Set credit screen
    sm.SetStateID(States::Credits);
    
    //Clock for elapsed time calculation
    sf::Clock etime_tracker;
    
    //Game loop
    while (win.isOpen()) {
        
        //Update state
        if (sm.isStateIDChanged()) {
            sm.StateUnload();
            switch (sm.GetStateID()) {
                case States::Credits:
                    sm.StateLoad(new CreditState());
                    break;
                    
                case States::Menu:
                    sm.StateLoad(new MenuState());
                    break;
                    
                case States::Game:
                    sm.StateLoad(new Game());
                    break;
                    
                default:
                    break;
            }
        }
        
        
        //Pool events
        sm.StatePoolEvents();
        
        //Clear everything
        win.clear();
        
        //Update current game state
        sm.StateDraw();
        sm.StateUpdate();
        
        //Display everything on the window
        win.display();
        
        //Calculate elapsed time
        etime = etime_tracker.restart().asMilliseconds() / 1000.f;
    }
    
    return 0;
}