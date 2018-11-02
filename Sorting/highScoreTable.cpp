#include "highScoreTable.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>


// Bubble sorting version
/*std::vector<HighScoreEntry> HighScoreTable::topNNScores(int topRows)
{
	// prints off top scores	
	if (hsVector.size() < topRows)
	{
		for (int i = 0; i < hsVector.size(); i++)
		{
			std::cout << "Name: " << hsVector[i].name << " Score: " << hsVector[i].score << " Level: " << hsVector[i].level << std::endl;
		}
	}
	else
	{
		for (int i = 0; i < topRows; i++)
		{
			std::cout << "Name: " << hsVector[i].name << " Score: " << hsVector[i].score << " Level: " << hsVector[i].level << std::endl;
		}
	}
	return std::vector<HighScoreEntry>();
}

bool HighScoreTable::pruneBottomNNScores(int bottomRows)
{
	// removes the bottom score
	for (int i = 0; i < bottomRows; i++)
	{
		hsVector.pop_back();
	}

	return false;
}

std::vector<std::string> HighScoreTable::split(std::string & line)
{
	// splits file up with ,
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

bool HighScoreTable::hsTableSave(std::string fileName)
{
	std::ofstream fout(fileName.c_str(), std::ios::out);

	if (fout.fail())
	{
		std::cout << "File failed to create.\n" << std::endl;
		return false;
	}

	for (int i = 0; i < hsVector.size(); i++)
	{
		fout.write(hsVector.at(i).name.c_str(), hsVector.at(i).name.size());
		fout.write(",", 1);
		fout.write(std::to_string(hsVector.at(i).score).c_str(), std::to_string(hsVector.at(i).score).size());
		fout.write(",", 1);
		fout.write(std::to_string(hsVector.at(i).level).c_str(), std::to_string(hsVector.at(i).level).size());
		fout.write("\n", 1);
	}

	fout.flush();
	fout.close();

	return true;
}

HighScoreTable::HighScoreTable()
{
}

HighScoreTable::HighScoreTable(std::string fileName)
{
	// reads the file
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

	// sorting
	HighScoreEntry tmp;

	for (int i = 0; i < hsVector.size(); i++)
	{
		for (int j = 0; j < hsVector.size(); j++)
		{
			if (hsVector[i].score > hsVector[j].score) // if one is less than other
			{
				tmp = hsVector[i];

				hsVector[i] = hsVector[j];

				hsVector[j] = tmp;

			}
		}
	}
	fin.close();
}

HighScoreTable::~HighScoreTable()
{
}*/

// Insertion sorting

std::vector<HighScoreEntry> HighScoreTable::topNNScores(int topRows)
{
	// prints off top scores	
	if (hsVector.size() < topRows)
	{
		for (int i = 0; i < hsVector.size(); i++)
		{
			std::cout << "Name: " << hsVector[i].name << " Score: " << hsVector[i].score << " Level: " << hsVector[i].level << std::endl;
		}
	}
	else
	{
		for (int i = 0; i < topRows; i++)
		{
			std::cout << "Name: " << hsVector[i].name << " Score: " << hsVector[i].score << " Level: " << hsVector[i].level << std::endl;
		}
	}

	return std::vector<HighScoreEntry>();
}

bool HighScoreTable::pruneBottomNNScores(int bottomRows)
{
	// removes the bottom score
	for (int i = 0; i < bottomRows; i++)
	{
		hsVector.pop_back();
	}

	return false;
}

std::vector<std::string> HighScoreTable::split(std::string & line)
{
	// splits file up with ,
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

bool HighScoreTable::hsTableSave(std::string fileName)
{
	std::ofstream fout(fileName.c_str(), std::ios::out);

	if (fout.fail())
	{
		std::cout << "File failed to create.\n" << std::endl;
		return false;
	}

	for (int i = 0; i < hsVector.size(); i++)
	{
		fout.write(hsVector.at(i).name.c_str(), hsVector.at(i).name.size());
		fout.write(",", 1);
		fout.write(std::to_string(hsVector.at(i).score).c_str(), std::to_string(hsVector.at(i).score).size());
		fout.write(",", 1);
		fout.write(std::to_string(hsVector.at(i).level).c_str(), std::to_string(hsVector.at(i).level).size());
		fout.write("\n", 1);
	}

	fout.flush();
	fout.close();

	return true;
}

HighScoreTable::HighScoreTable()
{
}

HighScoreTable::HighScoreTable(std::string fileName)
{
	// reads the file
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

	// sorting
	HighScoreEntry tmp;

	for (int i = 1; i < hsVector.size(); i++)
	{
		for (int j = 1; j < hsVector.size(); j++)
		{
			if (hsVector[i].score > hsVector[j - 1].score) // if one is less than other
			{
				tmp = hsVector[i];

				hsVector[i] = hsVector[j - 1];

				hsVector[j - 1] = tmp;

			}
		}
	}
	fin.close();
}

HighScoreTable::~HighScoreTable()
{
}
