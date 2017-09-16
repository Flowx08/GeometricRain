
#include "Game.hpp"
#include "Core.hpp"

#include "World.hpp"
#include "Player.hpp"
#include "Level.hpp"
#include "GameUI.hpp"

Game::Game()
{
    
    //Randomize
    srand((int)time(NULL));
    rand();
    
    //Load contents
    rm.LoadTexture("atlas", "atlas.png");
    rm.LoadFont("font", "gamefont.ttf");
    rm.LoadSoundBuffer("menumove", "menumove.wav");
    rm.LoadSoundBuffer("menuselect", "menuselect.wav");
    rm.LoadSoundBuffer("menudenied", "menudenied.wav");
    rm.LoadSoundBuffer("dead", "dead.wav");
    
    world = new World();
    player = new Player();
    level = new Level();
    gameui = new GameUI();
}

Game::~Game()
{
    
    delete world;
    delete player;
    delete level;
    delete gameui;
    
    rm.UnloadAll();
}

void Game::PoolEvents()
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
                    case sf::Keyboard::W:
                        player->Sprint();
                        gameui->MenuMoveUp();
                        break;
                    case sf::Keyboard::S: gameui->MenuMoveDown(); break;
                    case sf::Keyboard::Up:
                        player->Sprint();
                        gameui->MenuMoveUp();
                        break;
                    case sf::Keyboard::Down: gameui->MenuMoveDown(); break;
                    case sf::Keyboard::Return: gameui->MenuSelect(); break;
                        
                    case sf::Keyboard::Right: gameui->MenuMoveRight(); break;
                    case sf::Keyboard::D: gameui->MenuMoveRight(); break;
                    case sf::Keyboard::Left: gameui->MenuMoveLeft(); break;
                    case sf::Keyboard::A: gameui->MenuMoveLeft(); break;
                    default: break;
                }
                break;
                
            default:
                break;
        }
    }
}

void Game::Update()
{
    //Update
    world->Update();
    player->Update();
    level->Update();
    gameui->Update();
    
    //Check collisions
    player->CheckEnemysCollision(*level);
    
    //Set bar color
    world->SetBarColor(level->GetLastColor());
    
    //Show dead menu
    if (player->EventDeath()) {
        gameui->ShowDeadMenu();
        level->SaveMaxScore();
    }
    
    //Can play only if there is no menu
    player->SetPlay(gameui->NoMenu());
    
    //Set UI title color
    gameui->SetTitleColor(level->GetLastColor());
    
    //Set UI Text scores
    gameui->SetScore(level->GetScore());
    gameui->SetBestScore(level->GetBestScore());
    
    //Set world light power
    world->SetLightPower(level->GetLightPower());
    
    //Set if the player is ready
    gameui->ShowInstructions(player->isReady());
    level->SetReady(player->isReady());
    
    //Set if update or not the score
    level->SetUpdateScore(player->isAlive() && player->isPlayable());
    
    //Update player pos
    level->SetPlayerPos(player->GetPosition());
    
    //Restart the levels
    if (gameui->EventRestartLevel()) {
        level->Restart();
        player->Reset();
        gameui->Hide();
    }
}

void Game::Draw()
{
    //Draw
    world->Draw();
    player->Draw();
    level->Draw();
    gameui->Draw();
}