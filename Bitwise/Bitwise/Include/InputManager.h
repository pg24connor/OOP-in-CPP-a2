#pragma once
#include <vector>
#include <variant>
#include <string>

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

	int IsAction(int index) const;

	//returns a vector of ints 
	std::vector<std::variant<int, std::string>> GetActions() const { return keys[0]; };
	std::vector<std::variant<int, std::string>> GetActionWords() const { return keys[2]; };
	
private:

	int mInput;
	std::vector<std::vector<std::variant<int, std::string>>> keys;
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