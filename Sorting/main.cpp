#include <iostream>
#include "HighScoreTable.h"
#include <vector>


int main() {
	//Instantiate and initialize the whole highscore table
	HighScoreTable hst("highScores.txt");

	int scoreSize = 10;

	//retrieve the top 10 scores
	std::vector<HighScoreEntry> topScores = hst.topNNScores(scoreSize);

	//todo: cycle through the scores and output them

	//prune the bottom 3 scores from the table
	hst.pruneBottomNNScores(3);

	std::cout << "\n\n\n\n";

	topScores = hst.topNNScores(10);

	//hst.hsTableSave("highScores.txt");

	system("pause");

	return 0;
}