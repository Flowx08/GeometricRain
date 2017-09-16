
//========================
#include "CreditState.hpp"
#include "Core.hpp"

CreditState::CreditState()
{
    //Setup view
    
    view = View((Vector2f)win.getSize()/2.f, (Vector2f)win.getSize());
    
    //Load logo texture
    rm.LoadTexture("credits", "credits.png");
    rm.GetTexture("credits").setSmooth(false);
    
    //Setup background
    background = Sprite(Texture(), IntRect(0, 0, win.getSize().x, win.getSize().y));
    background.setPosition(0, 0);
    background.setColor(Color(220, 220, 220));
    
    //Setup logo
    logo = Sprite(rm.GetTexture("credits"));
    logo.setOrigin(logo.getGlobalBounds().width/2, logo.getGlobalBounds().height/2);
    logo.setPosition(win.getSize().x/2, win.getSize().y/2);
    logo.setColor(Color(255, 255, 255, _alpha));
    logo.setScale(2, 2);
}

CreditState::~CreditState()
{
    rm.UnloadAll();
}

void CreditState::PoolEvents()
{
    //Events
    Event ev;
    while (win.pollEvent(ev)) {
        switch (ev.type) {
                
                //Close window
            case Event::Closed:
                win.close();
                break;
                
            default:
                break;
        }
    }
}

void CreditState::Update()
{
    //Calculate elapsed time
    etime = clock.restart().asMicroseconds() / 1000000.f;
    
    logo.setColor(Color(255, 255, 255, _alpha));
    
    if (_alphain > 0){
        _alpha = 255*(_maxalphain - _alphain);
        _alphain -= etime;
    }
    else if (_fullalphadelay > 0)
    {
        _fullalphadelay -= etime;
    }
    else if (_alphaout > 0)
    {
        _alpha = 255 * (_alphaout / _maxalphaout);
        _alphaout -= etime;
    }
    else
    {
        sm.SetStateID(1);
        return;
    }
}

void CreditState::Draw()
{
    win.draw(background);
    win.draw(logo);
}
