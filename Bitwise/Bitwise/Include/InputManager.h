#pragma once

//==========================================================
//==========================================================

class InputState
{
public:

	// the "friend" keyword allows you to bypass encapsulation
	// in this case, it allows InputManager to reach into my private variables
	friend class InputManager;

	InputState();
	~InputState();

	bool IsAttack() const;
	bool IsJump() const;
	bool IsDuck() const;
	bool IsForward() const;
	bool IsBack() const;
	bool IsUse() const;
	bool IsCancel() const;

private:

	bool mAttack;
	bool mJump;
	bool mDuck;
	bool mForward;
	bool mBack;
	bool mUse;
	bool mCancel;

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

