#ifndef UILIST_HPP
#define UILIST_HPP

#include <SFML/Graphics/Text.hpp>
#include <SFML/Audio/Sound.hpp>
#include <vector>

class UIList
{
public:
    UIList();
    ~UIList();
    UIList(sf::Vector2f position, const int linespace);
    void Update();
    void Draw();
    
    void AddItem(sf::Text item);
    void AdjustItemsPosition();
    int GetSelectedItemID() const;
    sf::Text& GetSelectedItem();
    sf::Text& GetItem(const int index);
    void MoveUp();
    void MoveDown();
    void Select();
    void SelectItem(const int index);
    
    
private:
    
    sf::Sound m_move;
    sf::Sound m_select;
    
    sf::Vector2f listposition;
    int listlinespace;
    
    std::vector<sf::Text> texts;
    int selecteditem = 0;
    
};

#endif
