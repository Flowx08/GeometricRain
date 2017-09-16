//==================
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Listener.hpp>
#include <SFML/Window/Event.hpp>

//==================
#include "ResourcesManager.hpp"
#include "GameState.hpp"

sf::RenderWindow win;
sf::Listener listener;
sf::View view;
ResourcesManager rm;
StateManager sm;
double etime;