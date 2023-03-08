#pragma once
#include <iostream>
#include <vector>
//==========================================================
//==========================================================

enum Action
{
	ATTACK = 1,
	JUMP = 2,
	DUCK = 4,
	FORWARD = 8,
	BACK = 16,
	USE = 32,
	CANCEL = 64
};

class InputState
{
public:

	// the "friend" keyword allows you to bypass encapsulation
	// in this case, it allows InputManager to reach into my private variables
	friend class InputManager;

	InputState();
	~InputState();

	int IsAction(int index) const;

	std::vector<int> GetActions() const { return keys[1]; };																																																																														
	
private:

	int mInput;
	std::vector<std::vector<int> > keys;
};


//=============================================================
//=============================================================

class InputManager
{
public:

	// this gets called each frame to query the system for the button states
	void Update();

	bool IsButtonDown(int nScancode) const;

	const InputState& GetState() const { return mState; }

private:

	InputState mState;

};