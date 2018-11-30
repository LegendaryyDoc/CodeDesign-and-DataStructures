#pragma once
#include "highScoreEntry.h"
#include <vector>

class HighScoreTable
{
public:
	int hsn = 0;

	bool hsTableSave(std::string fileName);
	HighScoreTable();
	HighScoreTable(std::string fileName);
	~HighScoreTable();
};