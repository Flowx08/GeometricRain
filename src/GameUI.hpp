#ifndef SCOREMANAGER_HPP
#define SCOREMANAGER_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include "UIList.hpp"

class ScoresInfo;

class GameUI
{
public:
    GameUI();
    ~GameUI();
    void Update();
    void Draw();
    
    void SetScore(int score);
    void SetBestScore(int score);
    void MenuMoveUp();
    void MenuMoveDown();
    void MenuMoveRight();
    void MenuMoveLeft();
    void MenuSelect();
    void ShowDeadMenu();
    void Hide();
    bool EventRestartLevel();
    bool NoMenu();
    void ShowInstructions(bool value);
    void SetTitleColor(sf::Color color);
    
private:
    
    sf::Text m_scoretext;
    
    enum GameMenu
    {
        None,
        Dead,
    };
    
    enum deadmenu
    {
        Tryagain,
        Backmainmenu
    };
    
    const char* m_deadmenu_titlestring = "Game over";
    int m_gamemenu = None;
    sf::Text m_deadmenutitle;
    sf::Text m_deadmenuscore;
    sf::Text m_deadmenubestscore;
    sf::Text m_instructions;
    sf::Sprite m_board;
    UIList m_deadmenuoptions;
    bool m_restartlevel = false;
    float m_showinstruction = 1.f;
    int m_score = 0;
    int m_bestscore = 0;
    
};

#endif
