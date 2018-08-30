#include "Variables.h"
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
void ScoreDraw(){
	//this is for showing current score on the screen while playing 
	iShowImage(790, 525, 200, 75, ScoreBackground);
	sprintf(Levelss, "%d", Level + 1);
	sprintf(Scoress, "%d", Score);		// "Scoress", "Levelss" are character type array. And Score(which increses using increment) is integer type for storing current score... Score is turned from int to char everytime because, iText can only show character in the screen...

	iSetColor(255, 255, 255);

	iText(800, 570, "Score: ", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(880, 570, Scoress, GLUT_BITMAP_TIMES_ROMAN_24);

	iText(800, 540, "Level: ", GLUT_BITMAP_9_BY_15);
	iText(865, 540, Levelss, GLUT_BITMAP_9_BY_15);
}

////////////////////////////////////////////////////////////////////////////////////
void HighScoreShow(){
	//this is for showing highscore from main menu
	FILE *fp = fopen("high_score.txt", "r");
	fscanf(fp, "%d", &HighScore);

	sprintf(Scoress, "%d", HighScore);
	iSetColor(255, 255, 255);
	iText(550, 300, Scoress, GLUT_BITMAP_TIMES_ROMAN_24);

	iText(375, 300, "High score : ", GLUT_BITMAP_TIMES_ROMAN_24);
	fclose(fp);
}

////////////////////////////////////////////////////////////////////////////////////
void HighScoreCalculate(){
	//Final score is the score after gameover
	FinalScore = Score;
	FILE *fp = fopen("high_score.txt", "r");
	fscanf(fp, "%d", &HighScore);

	//if Final score is greater than high score, it will be replaced
	if (HighScore < FinalScore){
		HighScore = FinalScore;
		FILE *fp = fopen("high_score.txt", "w");
		fprintf(fp, "%d", HighScore);
		fclose(fp);
	}
	fclose(fp);
}

////////////////////////////////////////////////////////////////////////////////////