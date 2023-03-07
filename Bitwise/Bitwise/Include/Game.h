#pragma once

#include "GameInterface.h"
#include "EngineTypes.h"
#include "InputManager.h"

class Game : public exGameInterface
{
public:
    static Game*        GetInstance();
        
    virtual             ~Game();

    virtual void        Initialize(exEngineInterface* engine);
    virtual const char* GetWindowName() const;
    virtual void        GetClearColor(exColor& color) const;

    virtual void        OnEvent(SDL_Event* event);
    virtual void        OnEventsConsumed();

    virtual void        Run(float deltaTime);
private:
    Game();
    static Game*        sInstance;
    
    exEngineInterface*  mEngine;

    InputManager        mInputManager;

    int                 mFontID;
    const char*         mWindowName;
};

