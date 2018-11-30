#include "highScoreTable.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include "raylib/raylib.h"

bool HighScoreTable::hsTableSave(std::string fileName)
{
	std::ofstream fout(fileName.c_str(), std::ios::out);

	if (fout.fail())
	{
		std::cout << "File failed to create.\n" << std::endl;
		return false;
	}

	fout << hsn;
	//fout.write(std::to_string(hsn).c_str(), 1);

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

	std::string buffer;

	std::ifstream fin(fileName.c_str(), std::ios::in);

	if (fin.fail())
	{
		std::cerr << "File not found." << std::endl;
	}

	if (!fin.eof() && fin.peek() != EOF)
	{

		while (std::getline(fin, buffer))
		{
			hsn = std::stoi(buffer);
		}
	}
	fin.close();
}

HighScoreTable::~HighScoreTable()
{
}
