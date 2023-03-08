#include "InputManager.h"

#include "SDL.h"

//==========================================================
//==========================================================

InputState::InputState() : mInput(0)
{
	keys[0].push_back(SDL_SCANCODE_LCTRL);
	keys[0].push_back(SDL_SCANCODE_SPACE);
	keys[0].push_back(SDL_SCANCODE_LSHIFT);
	keys[0].push_back(SDL_SCANCODE_UP);
	keys[0].push_back(SDL_SCANCODE_DOWN);
	keys[0].push_back(SDL_SCANCODE_E);
	keys[0].push_back(SDL_SCANCODE_BACKSPACE);

	keys[1].push_back(1);
	keys[1].push_back(2);
	keys[1].push_back(4);
	keys[1].push_back(8);
	keys[1].push_back(16);
	keys[1].push_back(32);
	keys[1].push_back(64);
}

InputState::~InputState()
{
}

int InputState::IsAction(int index) const
{
	return (mInput & index) != 0;
}

//==========================================================
//==========================================================

void InputManager::Update()
{
	for (int i = 0; i < mState.keys.size() - 1; ++i)
	{
		mState.mInput = (mState.mInput & ~(1 << i)) | (IsButtonDown(mState.keys[0][i]) << i);
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