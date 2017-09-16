
#include "GameUI.hpp"
#include "Core.hpp"
#include "States.hpp"

GameUI::GameUI()
{
    //Shortcut
    sf::Font& font = rm.GetFont("font");
    sf::Texture& atlas = rm.GetTexture("atlas");
    
    m_scoretext.setFont(font);
    m_scoretext.setCharacterSize(24);
    m_scoretext.setColor(Color::White);
    m_scoretext.setPosition(8, view.getSize().y - 24 - 8);
    m_scoretext.setString("Score : " + std::to_string(0));
    
    m_deadmenutitle.setFont(font);
    m_deadmenutitle.setCharacterSize(48);
    m_deadmenutitle.setString(m_deadmenu_titlestring);
    m_deadmenutitle.setColor(Color::White);
    m_deadmenutitle.setPosition(view.getCenter().x, view.getCenter().y - 150);
    m_deadmenutitle.setOrigin(m_deadmenutitle.getLocalBounds().width/2,
                            m_deadmenutitle.getLocalBounds().height/2);

    
    m_deadmenuscore.setFont(font);
    m_deadmenuscore.setCharacterSize(32);
    m_deadmenuscore.setColor(Color::Green);
    m_deadmenuscore.setPosition(view.getCenter().x, view.getCenter().y - 70);
    m_deadmenuscore.setOrigin(m_deadmenuscore.getLocalBounds().width/2,
                              m_deadmenuscore.getLocalBounds().height/2);
    
    m_deadmenubestscore.setFont(font);
    m_deadmenubestscore.setCharacterSize(32);
    m_deadmenubestscore.setColor(Color::Green);
    m_deadmenubestscore.setPosition(view.getCenter().x, view.getCenter().y - 30);
    m_deadmenubestscore.setOrigin(m_deadmenubestscore.getLocalBounds().width/2,
                                  m_deadmenubestscore.getLocalBounds().height/2);
    
    m_deadmenuoptions = UIList({view.getCenter().x, view.getCenter().y + 20}, 50);
    m_deadmenuoptions.AddItem(Text("Try again", font));
    m_deadmenuoptions.AddItem(Text("Back", font));
    m_deadmenuoptions.AdjustItemsPosition();
    
    m_instructions.setFont(font);
    m_instructions.setString("Press A - D or Left - Right to move.\n"
                             "     Press W or Up to sprint.");
    m_instructions.setCharacterSize(32);
    m_instructions.setColor(Color::White);
    m_instructions.setPosition(view.getCenter().x, view.getCenter().y);
    m_instructions.setOrigin(m_instructions.getLocalBounds().width/2,
                             m_instructions.getLocalBounds().height/2);
    
    m_board.setTexture(atlas);
    m_board.setTextureRect(IntRect(176, 0, 32, 32));
    m_board.setPosition(view.getCenter());
    m_board.setColor(Color::White);
    m_board.setOrigin(16, 16);
    m_board.setScale(13, 13);
    
}

GameUI::~GameUI()
{
}

void GameUI::Update()
{
    switch (m_gamemenu) {
            
        case None:
            if (m_showinstruction > 0) m_showinstruction -= etime;
            else m_showinstruction = 0;
            m_instructions.setColor(Color(255, 255, 255, 255 * m_showinstruction));
            break;
            
        case Dead:
            m_deadmenuoptions.Update();
            break;
            
        default:
            break;
    }
}

void GameUI::Draw()
{
    switch (m_gamemenu) {
            
        case None:
            win.draw(m_scoretext);
            if (m_showinstruction > 0)
                win.draw(m_instructions);
            break;
            
        case Dead:
            win.draw(m_board);
            win.draw(m_deadmenutitle);
            win.draw(m_deadmenuscore);
            win.draw(m_deadmenubestscore);
            m_deadmenuoptions.Draw();
            break;
            
        default:
            break;
    }
}

void GameUI::ShowDeadMenu()
{
    m_gamemenu = Dead;

    m_deadmenuscore.setString("Score: " + std::to_string(m_score));
    m_deadmenuscore.setOrigin(m_deadmenuscore.getLocalBounds().width/2,
                              m_deadmenuscore.getLocalBounds().height/2);
    
    m_deadmenubestscore.setString("Best Score: " + std::to_string(m_bestscore));
    m_deadmenubestscore.setOrigin(m_deadmenubestscore.getLocalBounds().width/2,
                                  m_deadmenubestscore.getLocalBounds().height/2);
    
}

void GameUI::MenuMoveUp()
{
    switch (m_gamemenu) {
        case Dead:
            m_deadmenuoptions.MoveUp();
            break;
            
        default:
            break;
    }

}

void GameUI::MenuMoveDown()
{
    switch (m_gamemenu) {
        case Dead:
            m_deadmenuoptions.MoveDown();
            break;
            
        default:
            break;
    }
}

void GameUI::MenuSelect()
{
    switch (m_gamemenu) {
        case Dead:
            m_deadmenuoptions.Select();
            switch (m_deadmenuoptions.GetSelectedItemID()) {
                case Tryagain:
                    m_restartlevel = true;
                    break;
                    
                case Backmainmenu:
                    sm.SetStateID(States::Menu);
                    return;
                    break;
                    
                default:
                    break;
            }
            break;
            
        default:
            break;
    }
}

void GameUI::SetScore(int score)
{
    m_score = score;
    m_scoretext.setString("Score : " + std::to_string(score));
}

void GameUI::SetBestScore(int score)
{
    m_bestscore = score;
}

bool GameUI::EventRestartLevel()
{
    bool tmp = m_restartlevel;
    m_restartlevel = false;
    return tmp;
}

void GameUI::Hide()
{
    m_gamemenu = None;
}

void GameUI::MenuMoveRight()
{
    
}

void GameUI::MenuMoveLeft()
{

}

bool GameUI::NoMenu()
{
    return m_gamemenu == None;
}

void GameUI::ShowInstructions(bool value)
{
    if (!value) m_showinstruction = 1.f;
}

void GameUI::SetTitleColor(sf::Color color)
{
    m_deadmenutitle.setColor(color);
}
