#ifndef GLOBAL_HPP
#define GLOBAL_HPP

//==================
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Listener.hpp>
#include <SFML/Window/Event.hpp>

//==================
#include "ResourcesManager.hpp"
#include "GameState.hpp"

using namespace sf;

extern sf::RenderWindow win;
extern sf::Listener listener;
extern sf::View view;
extern ResourcesManager rm;
extern StateManager sm;
extern double etime;

#endif