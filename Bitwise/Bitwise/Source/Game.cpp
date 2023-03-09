#include "Game.h"

#include "Constants.h"
#include "EngineInterface.h"
#include "SDL.h"

#include "InputManager.h"

#include <iostream>
#include <string>

Game* Game::sInstance = nullptr;

Game* Game::GetInstance()
{
    if (sInstance == nullptr)
    {
        sInstance = new Game();
    }
    return sInstance;
}

Game::Game() 
    : mEngine(nullptr)
    , mFontID(-1)
    , mWindowName("Game")
{}

Game::~Game()
{
}

void Game::Initialize(exEngineInterface* engine)
{
    mEngine = engine;
    mFontID = mEngine->LoadFont("resources/Urusans.ttf", 32);
}

const char* Game::GetWindowName() const
{
    return mWindowName;
}

void Game::GetClearColor(exColor& color) const
{
    color.r = 255;
    color.g = 0;
    color.b = 0;
}

void Game::OnEvent(SDL_Event* event)
{}

void Game::OnEventsConsumed()
{
    mInputManager.Update();
}

void Game::Run(float deltaTime)
{
    //replace if chain with a for loop
    for (int i = 0; i < mInputManager.GetState().GetActions().size(); ++i)
    {
        if (mInputManager.GetState().IsAction(std::get<int>(mInputManager.GetState().GetActions()[i])))
        {
            mEngine->DrawText(mFontID, exVector2(10, i * 35), std::get<std::string>(mInputManager.GetState().GetActionWords()[i]).c_str(), exColor(0, 0, 0), 0);
        }
    }
}