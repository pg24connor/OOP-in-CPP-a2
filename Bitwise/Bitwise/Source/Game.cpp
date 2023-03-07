#include "Game.h"

#include "Constants.h"
#include "EngineInterface.h"
#include "SDL.h"

#include "InputManager.h"

#include <iostream>

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
    color.g = 255;
    color.b = 255;
}

void Game::OnEvent(SDL_Event* event)
{}

void Game::OnEventsConsumed()
{
    mInputManager.Update();
}

void Game::Run(float deltaTime)
{
    if (mInputManager.GetState().IsAttack())
    {
        mEngine->DrawText(mFontID, exVector2(10, 10), "Attack", exColor(0, 0, 0), 0);
    }

    if (mInputManager.GetState().IsJump())
    {
        mEngine->DrawText(mFontID, exVector2(10, 45), "Jump", exColor(0, 0, 0), 0);
    }

    if (mInputManager.GetState().IsDuck())
    {
        mEngine->DrawText(mFontID, exVector2(10, 80), "Duck", exColor(0, 0, 0), 0);
    }

    if (mInputManager.GetState().IsForward())
    {
        mEngine->DrawText(mFontID, exVector2(10, 115), "Forward", exColor(0, 0, 0), 0);
    }

    if (mInputManager.GetState().IsBack())
    {
        mEngine->DrawText(mFontID, exVector2(10, 150), "Back", exColor(0, 0, 0), 0);
    }

    if (mInputManager.GetState().IsUse())
    {
        mEngine->DrawText(mFontID, exVector2(10, 185), "Use", exColor(0, 0, 0), 0);
    }

    if (mInputManager.GetState().IsCancel())
    {
        mEngine->DrawText(mFontID, exVector2(10, 220), "Cancel", exColor(0, 0, 0), 0);
    }   
}