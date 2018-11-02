#pragma once
#include "raylib.h"

class GameState
{
private:
	GameState();
	GameState(GameState const&);  // prevents external use
	void operator=(GameState const&); // prevents external use
	int state;

public:
	int getState();
	void setState(int newState);
	static GameState& GetInstance();
	~GameState();
};