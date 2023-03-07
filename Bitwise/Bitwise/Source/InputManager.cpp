#include "InputManager.h"

#include "SDL.h"

//==========================================================
//==========================================================

InputState::InputState()
	: mAttack(false)
	, mJump(false)
	, mDuck(false)
	, mForward(false)
	, mBack(false)
	, mUse(false)
	, mCancel(false)
{
}

InputState::~InputState()
{
}

bool InputState::IsAttack() const
{
	return mAttack;
}

bool InputState::IsJump() const
{
	return mJump;
}

bool InputState::IsDuck() const
{
	return mDuck;
}

bool InputState::IsForward() const
{
	return mForward;
}

bool InputState::IsBack() const
{
	return mBack;
}

bool InputState::IsUse() const
{
	return mUse;
}

bool InputState::IsCancel() const
{
	return mCancel;
}

//==========================================================
//==========================================================

void InputManager::Update()
{
	mState.mAttack = IsButtonDown(SDL_SCANCODE_LCTRL);
	mState.mJump = IsButtonDown(SDL_SCANCODE_SPACE);
	mState.mDuck = IsButtonDown(SDL_SCANCODE_LSHIFT);
	mState.mForward = IsButtonDown(SDL_SCANCODE_UP);
	mState.mBack = IsButtonDown(SDL_SCANCODE_DOWN);
	mState.mUse = IsButtonDown(SDL_SCANCODE_E);
	mState.mCancel = IsButtonDown(SDL_SCANCODE_BACKSPACE);
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