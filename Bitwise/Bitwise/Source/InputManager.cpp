#include "InputManager.h"
#include <iostream>
#include "SDL.h"

//==========================================================
//==========================================================

InputState::InputState() : mInput(0)
{
	//assigns all the bits and all the keys and all the text in one vector thingy (idk i missed that class)
	keys =
	{
		{1, 2, 4, 8, 16, 32, 64},
		{SDL_SCANCODE_LCTRL, SDL_SCANCODE_SPACE, SDL_SCANCODE_LSHIFT, SDL_SCANCODE_UP, SDL_SCANCODE_DOWN, SDL_SCANCODE_E, SDL_SCANCODE_BACKSPACE },
		{"Attack", "Jump", "Duck", "Forawrd", "Back", "Use", "Cancel"}
	};
}

InputState::~InputState()
{
}

//returns the state of the bit
int InputState::IsAction(int index) const
{
	//		and always takes the zero so using and will only return the one your looking for
	return (mInput & index) != 0;
}

//==========================================================
//==========================================================

void InputManager::Update()
{
	//checks all inputs and assigns them to their bit inside of mInput
	for (int i = 0; i < mState.keys[1].size(); ++i)
	{
		//				this part is to turn off		this part checks to see if the button is down
		//				any bits that need to be		IsButtonDown() returns a bool (1 is true 0 is false)
		//				turned off by checking the		the or operator always takes the ones from a statment
		//				the and of the inverse of 		so if IsButtonDown is true than using bit shifting the 
		//				one shifted across all the 		correct bit turns to 1	
		//				bits i wanna check
		mState.mInput = (mState.mInput & ~(1 << i)) | (IsButtonDown(std::get<int>(mState.keys[1][i])) << i);
	}
}

bool InputManager::IsButtonDown(int nScancode) const
{
	int nKeys = 0;
	const Uint8* pKeys = SDL_GetKeyboardState(&nKeys);

	if (pKeys == nullptr)
	{
		return false;
	}

	if (nScancode >= nKeys)
	{
		return false;
	}

	return pKeys[nScancode];
}