
//======================
#include "GameState.hpp"


// ================================
// ====>> GAMESTATE
// ================================

//////////////////////////////////////////
GameState::~GameState() {}

//////////////////////////////////////////
void GameState::PoolEvents() {}

//////////////////////////////////////////
void GameState::Update() {}

//////////////////////////////////////////
void GameState::Draw() {}


// ================================
// ====>> STATEMANAGER
// ================================

////////////////////////////////////////////////
StateManager::StateManager() :
    m_State(nullptr)
{}

////////////////////////////////////////////////
StateManager::~StateManager()
{
    StateUnload();
}

//////////////////////////////////////////
void StateManager::SetStateID(const unsigned int ID)
{
    m_StateID = ID;
    m_StateIDChanged = true;
}

//////////////////////////////////////////
const unsigned int StateManager::GetStateID() const
{
    return m_StateID;
}

//////////////////////////////////////////
const bool StateManager::isStateIDChanged()
{
    bool tmp = m_StateIDChanged;
    m_StateIDChanged = false;
    return tmp;
}

//////////////////////////////////////////
void StateManager::StateLoad(GameState* state)
{
    if (m_State == nullptr) m_State = state;
}

//////////////////////////////////////////
void StateManager::StateUnload()
{
    if (m_State) {
        delete m_State;
        m_State = nullptr;
    }
}

//////////////////////////////////////////
void StateManager::StatePoolEvents()
{
    if (m_State) m_State->PoolEvents();
}

//////////////////////////////////////////
void StateManager::StateDraw()
{
	if (m_State)  m_State->Draw();
}

//////////////////////////////////////////
void StateManager::StateUpdate()
{
	if (m_State) m_State->Update();
}