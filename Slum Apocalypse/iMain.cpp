#include "iGraphics.h"
#include "bitmap_loader.h"
#include "Hero.h"
#include "Background.h"
#include "Zombie.h"
#include "Variables.h"
#include "Menu.h"
#include "iDrawFunc.h"
#include "Score.h"
#include "ControlKeys.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////          iDraw         /////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void iDraw()
{
	iClear();
	//MainMenu appear
	if (MenuChoice == 0){
		MenuDraw();
	}

	//Story Appear
	if (IsStoryShowing == true){
		StoryDraw();
	}

	//New,Load game screen appear
	if (StartChoice >= 0){
		StartGame();
	}

	//Gamescreen Appear
	if (MenuChoice == 1)
	{
		SkyDraw();
		MiddleBuildingDraw();
		RoadDraw();
		BossDraw();
		HeroDraw();
		ZombieDraw();
		BarsDraw();
		ScoreDraw();
		CurrentState();
	}
	//High score screen
	if (MenuChoice == 2){
		HighScoreImage();
		HighScoreShow();
	}
	//instruction screen
	if (MenuChoice == 3){
		Instructions();
	}
	//Credits screen
	if (MenuChoice == 4){
		Credits();
	}

	//Game over screen, when dies
	if (GameOverTime >= 50){
		HighScoreCalculate();
		GameOverImage();
	}


}







////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////                iMouse, iMouseMove, iPassiveMouse,            //////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void iPassiveMouse(int mx, int my)
{

}

void iMouseMove(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{
	/////////////////////////For main menu
	MainMenuClick(mx, my);

	//////////////////for Backbutton in Menuchoises
	if (StartChoice == 0 || StartChoice == 1 || MenuChoice == 2 || MenuChoice == 3 || MenuChoice == 4){
		if (mx > ScreenWidth - 120 && my > ScreenHeight - 80){
			MenuChoice = 0;
			StartChoice = -1;
		}
	}
	//////////////////////////Return to MainMenu after gameover
	MainMenuAfterGameOver(mx, my);

}










////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////                iKeyboard & Special              //////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void iKeyboard(unsigned char key)
{
	//////////////////////////////////////////////////All movements inside this condition so that you won't be able to move while you are dead

	if (IsStoryShowing == true){						
		if (StoryCount == 4){
			StoryCount = 0;
			IsStoryShowing = false;
			MenuChoice = 0;
			StartChoice = 0;
		}
		else if (key == ' ')
			StoryCount++;
	}													



	if (HeroHealthBar > 0 && MenuChoice == 1){
		////////////////Right Move; Background will move
		if (key == 'd' || key == 'D'){ RightButton(); }
		/////////////////Left Move; Background won't move
		else if (key == 'a' || key == 'A'){ LeftButton(); }


		/////////////////Laser Key
		if (IsHeroLaserMove == false && (key == 'l' || key == 'L') && HeroLaserBar >= 50 && (IsZombieComing == true || IsBossComing == true) && IsJumpUp == false){ LaserButton(); }
		//////////////////punch key
		else if (IsHeroPunchMove == false && (key == 'p' || key == 'P') && IsJumpUp == false){ PunchButton(); }
		//////////////////Jump Key
		else if (key == ' ' || key == 'W' || key == 'w'){ JumpButton(); }

	}


	////////////////////music key
	if (key == 'm' || key == 'M'){ MusicButton(); }


}

/*
 function iSpecialKeyboard() is called whenver user hits special keys like-
 function keys, home, end, pg up, pg down, arraows etc. you have to use
 appropriate constants to detect them. A list is:
 GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
 GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
 GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
 GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
 */
void iSpecialKeyboard(unsigned char key)
{
	//////////////////////////////////////////////////Write all movements inside this condition so that we won't be able to move while you are dead
	if (HeroHealthBar > 0){
		/////////////////////key			//Right Move; Background will move
		if (key == GLUT_KEY_RIGHT){ RightButton(); }

		/////////////////////key			//Left Move; Background won't move
		else if (key == GLUT_KEY_LEFT){ LeftButton(); }

		/////////////////////key			//Jump Move;
		else if (key == GLUT_KEY_UP){ JumpButton(); }
	}

}











////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////          Main          /////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	iInitialize(ScreenWidth, ScreenHeight, "Slum Apocalypse");

	////////////////////////////////Sound
	srand(time(NULL));
	PlaySound("Menu\\sound", NULL, SND_LOOP | SND_ASYNC);

	//////////////////////////////loading variables from save_game.txt
	FILE *fp = fopen("save_game.txt", "r");
	fscanf(fp, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d", &GameOverTime, &HeroHealthBar, &HeroLaserBar, &HeroDeadIndex, &HeroCordinateX, &HeroCordinateY, &Score, &ZombieCordinateX, &DeadZombieCount, &IsBossComing, &IsZombieComing, &BossCordinateX, &BossHealthBar, &CharacterChoice, &Level);
	fclose(fp);

	//////////////////////////////////////Image Loading functions
	BackgroundLoadFunc();              //will generate all Background images
	ZombieLoadFunc();          ////will generate all Zombie's moving images
	MenuLoadFunc();
	////////////////////////////////////////Zombie.h
	iSetTimer(250, ZombieAnimation);				 //and also, laser recharge



	////////////////////////////////////////Hero.h

	iSetTimer(40, Walking);						//hero and zombie walking
	iSetTimer(20, HeroActionChange);			//punch, laser, laser beam, Hero dead, boss animation


	//////////////////////////////////////////Background.h
	iSetTimer(80, SkyBackgroundChange);
	iSetTimer(18, MiddleBackgroundChange);
	iSetTimer(20, RoadBackgroundChange);







	iStart();

	return 0;
}

