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
	switch (state)
	{
	case 0 :
		std::cout << "0" << std::endl;
		break;
		
	case 1 :
		std::cout << "1" << std::endl;
		break;

	case 2 : 
		std::cout << "2" << std::endl;
		break;

	case 3 :
		std::cout << "3" << std::endl;
		break;

	default :
		break;
	}
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
