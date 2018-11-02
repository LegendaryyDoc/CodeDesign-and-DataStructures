#include "state.h"
#include "raylib.h"
#include <iostream>

GameState::GameState()
{
}

void GameState::operator=(GameState const &)
{
}

int GameState::getState()
{
	return state;
}

void GameState::setState(int newState)
{
	state = newState;
}

GameState & GameState::GetInstance()
{
	// TODO: insert return statement here
	static GameState* GetInstance = new GameState();
	return *GetInstance;
}

GameState::~GameState()
{
}
