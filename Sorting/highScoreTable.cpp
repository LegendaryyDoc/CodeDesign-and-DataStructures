#include "highScoreTable.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>

std::vector<HighScoreEntry> HighScoreTable::topNNScores(int topRows)
{


	HighScoreEntry tmp;

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (hsVector[i].score < hsVector[j].score) // if one is less than other
			{
				tmp = hsVector[i];

				hsVector[i] = hsVector[j];

				hsVector[j] = tmp;
								
			}
		}
	}
	return std::vector<HighScoreEntry>();
}

bool HighScoreTable::pruneBottomNNScores(int bottomRows)
{
	return false;
}

std::vector<std::string> HighScoreTable::split(std::string & line)
{
	std::vector<std::string> result;
	std::stringstream lineStream(line);
	std::string cell;
	while (std::getline(lineStream, cell, ','))
	{
		result.push_back(cell);
		if (!lineStream && cell.empty())
		{
			result.push_back("");
		}
	}
	return result;
}

HighScoreTable::HighScoreTable()
{
}

HighScoreTable::HighScoreTable(std::string fileName)
{
	HighScoreEntry mySaveData;

	std::string buffer;
	std::vector <std::string> rtn;

	std::ifstream fin(fileName.c_str(), std::ios::in);

	if (fin.fail())
	{
		std::cerr << "File not found." << std::endl;
	}

	if (!fin.eof() && fin.peek() != EOF)
	{
		std::getline(fin, buffer);
		while (std::getline(fin, buffer)) 
		{
			rtn = split(buffer);
			mySaveData.level = std::stoi(rtn.back());
			rtn.pop_back();
			mySaveData.score = std::stoi(rtn.back());
			rtn.pop_back();
			mySaveData.name = rtn.back();
			rtn.pop_back();

			hsVector.push_back(mySaveData);
		}
	}
	fin.close();
}

HighScoreTable::~HighScoreTable()
{
}
