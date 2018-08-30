#include "Variables.h"


//::::::::::::::::::::::::Menu Image Initialization::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
void MenuLoadFunc(){
	Menuimage[0] = iLoadImage("Menu//Menu.png");
	Menuimage[1] = iLoadImage("Menu//MenuPlay.PNG");
	Menuimage[2] = iLoadImage("Menu//MenuScore.PNG");
	Menuimage[3] = iLoadImage("Menu//MenuInstructions.PNG");
	Menuimage[4] = iLoadImage("Menu//MenuCredits.PNG");
	Menuimage[5] = iLoadImage("Menu//MenuExit.PNG");

	Menuimage[6] = iLoadImage("Menu//Instructions.png");
	Menuimage[7] = iLoadImage("Menu//Credits.png");
	Menuimage[8] = iLoadImage("Menu//HighScoreBackground.png");
	
	StartGameBackground = iLoadImage("Menu//StartGameBackground.png");
	GameOverimage = iLoadImage("Menu//GameOver.png");

	BackButtonImage = iLoadImage("Menu//BackButton.png");
	HomeButton = iLoadImage("Menu//Home.png");
	NewGameButton = iLoadImage("Menu//NewGame.PNG");
	LoadGameButton = iLoadImage("Menu//LoadGame.PNG"); 

	CharacterImage[0] = iLoadImage("Menu//Character1.png");
	CharacterImage[1] = iLoadImage("Menu//Character2.png");

	Story[0] = iLoadImage("Story//Story1.png");									
	Story[1] = iLoadImage("Story//Story2.png");
	Story[2] = iLoadImage("Story//Story3.png");
	Story[3] = iLoadImage("Story//Story4.png");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MenuDraw(){
	iShowImage(0, 0, ScreenWidth, ScreenHeight, Menuimage[0]);
	iShowImage(300, 320, 300, 65, Menuimage[1]);
	iShowImage(300, 250, 300, 65, Menuimage[2]);
	iShowImage(300, 180, 300, 65, Menuimage[3]);
	iShowImage(300, 110, 300, 65, Menuimage[4]);
	iShowImage(300, 40, 300, 65, Menuimage[5]);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void StartGame(){
	if (StartChoice == 0)			//new/load game
	{
		iShowImage(0, 0, 1000, 600, StartGameBackground);
		iShowImage(380, 240, 270, 50, NewGameButton);
		if (CharacterChoice != 0){
			iShowImage(380, 150, 270, 50, LoadGameButton);
			iSetColor(255, 255, 255);
			iText(350, 125, "[ Wait 5 Seconds After Pressing 'Load Game' ]");
		}
		iShowImage(ScreenWidth - 120, ScreenHeight - 100, 100, 100, BackButtonImage);
	}
	if (StartChoice == 1){			//choose character
		iShowImage(0, 0, 1000, 600, StartGameBackground);
		iSetColor(255, 255, 255);
		iText(ScreenWidth - 620, ScreenHeight - 120, "Choose Your Character:", GLUT_BITMAP_TIMES_ROMAN_24);
		iShowImage(200, 100, 180, 300, CharacterImage[0]);
		iText(250, 70, "Ironman", GLUT_BITMAP_TIMES_ROMAN_24);
		iShowImage(ScreenWidth - 380, 100, 180, 300, CharacterImage[1]);
		iText(ScreenWidth - 320, 70, "Ultron", GLUT_BITMAP_TIMES_ROMAN_24);
		iShowImage(ScreenWidth - 120, ScreenHeight - 100, 100, 100, BackButtonImage);
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Instructions(){
	iShowImage(0, 0, 1000, 600, Menuimage[6]);
	iSetColor(0, 255, 0);
	iShowImage(ScreenWidth - 120, ScreenHeight - 100, 100, 100, BackButtonImage);
}

////////////////////////////////////////////////////////////////////////////////////
void Credits(){
	iShowImage(0, 0, 1000, 600, Menuimage[7]);
	iSetColor(0, 255, 0);
	iShowImage(ScreenWidth - 120, ScreenHeight - 100, 100, 100, BackButtonImage);
}

////////////////////////////////////////////////////////////////////////////////////
void HighScoreImage(){
	iShowImage(0, 0, 1000, 600, Menuimage[8]);
	iSetColor(0, 255, 0);
	iShowImage(ScreenWidth - 120, ScreenHeight - 100, 100, 100, BackButtonImage);
}

////////////////////////////////////////////////////////////////////////////////////
void GameOverImage(){
	iShowImage(0, 0, 1000, 600, GameOverimage);
	//score
	iText(ScreenWidth - 170, ScreenHeight - 150, "Score:", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(ScreenWidth - 105, ScreenHeight - 150, Scoress, GLUT_BITMAP_TIMES_ROMAN_24);
	//return button
	if (GameOverTime >= 100){
		iSetColor(255, 255, 255);
		iShowImage(ScreenWidth - 170, ScreenHeight - 150, 150, 150, HomeButton);
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void StoryDraw(){
	if (IsStoryShowing == true){														
		iShowImage(0, 0, ScreenWidth, ScreenHeight, Story[StoryCount - 1]);
		iSetColor(255, 0, 255);
		iText(ScreenWidth - 140, 10, "Press 'Space'", GLUT_BITMAP_HELVETICA_18);
	}

}

void CurrentState(){
	//this is for saving current state in file(load game function)

	if (HeroHealthBar <= 0){		//when game over
		FILE *fp = fopen("save_game.txt", "w");
		fprintf(fp, "0\n300\n0\n0\n0\n30\n0\n800\n0\n0\n1\n1100\n200\n0\n0");
		fclose(fp);
	}

	else {
		FILE *fp = fopen("save_game.txt", "w");
		fprintf(fp, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d", GameOverTime, HeroHealthBar, HeroLaserBar, HeroDeadIndex, HeroCordinateX, HeroCordinateY, Score, ZombieCordinateX, DeadZombieCount, IsBossComing, IsZombieComing, BossCordinateX, BossHealthBar, CharacterChoice, Level);
		fclose(fp);
	}
}
