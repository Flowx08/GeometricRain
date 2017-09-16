
#include "UIList.hpp"
#include "Core.hpp"

UIList::UIList()
{
    m_move.setBuffer(rm.GetSoundBuffer("menumove"));
    m_select.setBuffer(rm.GetSoundBuffer("menuselect"));
}

UIList::~UIList()
{
    m_move.stop();
    m_select.stop();
}

UIList::UIList(sf::Vector2f position, const int linespace)
{
    listposition = position;
    listlinespace = linespace;
}

void UIList::AddItem(sf::Text item)
{
    texts.push_back(item);
}

void UIList::AdjustItemsPosition()
{
    for (int i = 0; i < texts.size(); i++){
        texts[i].setPosition(listposition.x - texts[i].getLocalBounds().width/2.f,
                             listposition.y + listlinespace * i);
    }
}

int UIList::GetSelectedItemID() const
{
    return selecteditem;
}

sf::Text& UIList::GetSelectedItem()
{
    return texts[selecteditem];
}

sf::Text& UIList::GetItem(const int index)
{
    return texts[index];
}

void UIList::MoveUp()
{
    selecteditem--;
    if (selecteditem < 0) selecteditem = static_cast<int>(texts.size() -1);
    for (int i = 0; i < texts.size(); i++) {
        if (i == selecteditem) texts[i].setScale(1, 1.1);
        else texts[i].setScale(1.f, 1.f);
    }
    m_move.play();
}

void UIList::MoveDown()
{
    selecteditem++;
    if (selecteditem >= static_cast<int>(texts.size())) selecteditem = 0;
    for (int i = 0; i < texts.size(); i++) {
        if (i == selecteditem) texts[i].setScale(1, 1.1);
        else texts[i].setScale(1.f, 1.f);
    }
    m_move.play();
}

void UIList::Select()
{
    m_select.play();
}

void UIList::SelectItem(const int index)
{
    selecteditem = index;
}

void UIList::Update()
{
    for (int i = 0; i < texts.size(); i++) {
        if (i == selecteditem) texts[i].setColor(Color::Red);
        else texts[i].setColor(Color::White);
    }
}

void UIList::Draw()
{
    for (auto &t : texts) win.draw(t);
}
