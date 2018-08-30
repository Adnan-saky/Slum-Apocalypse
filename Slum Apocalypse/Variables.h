#ifndef _VARIABLES_H_
#define _VARIABLES_H_
//Variables.h is needed because sometimes we need to use some variables from another file. for example, we used "ScreenWidth" variable in Zombie.h file



	//////////////////////////////////////////////////////////iMain.cpp Variables
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	int ScreenWidth = 1000, ScreenHeight = 600;




	//////////////////////////////////////////////////////////Hero.h variables
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	int HeroStand, HeroWalk[60], HeroDead[15], HeroJump[2], HeroLaser[10], HeroPunch[10], Laser, HeroSpark[10];
	int HeroCordinateX = 0, HeroCordinateY = 30;
	int HeroWalkIndex = 0, HeroWalkTime = 0;
	int HeroLaserIndex = 0, HeroPunchIndex = 0, HeroDeadIndex = 0, HeroSparkIndex = 0;
	int HeroHealthBar = 300, HeroLaserBar = 0;
	bool IsHeroRightMove = false, IsHeroLeftMove = false, IsHeroStandMove = true;
	bool IsHeroPunchMove = false;
	bool IsHeroDeadMove = false;
	bool IsJumpAndLeft = false;
	bool IsZombieInFront = false;
	bool IsBossInFront = false;
	bool IsHeroLaserMove = false, IsLaserBeam = false;
	int LaserCordinateX = HeroCordinateX + 50, LaserCordinateY = HeroCordinateY + 85;
	bool IsHeroJumpMove = false;
	bool IsJumpUp = false;
	bool IsJumpDown = true;
	int HeroCordinateJump = 0;
	int JumpIndex = 0;



	//////////////////////////////////////////////////////////Background.h Variables
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	int Middle[5], Road[2], Sky[2];
	int RoadCordinateX[] = { 0, ScreenWidth }, RoadCordinateY = 0;
	int SkyCordinateX[] = { 0, ScreenWidth }, SkyCordinateY = 200;
	int MiddleCordinateX[] = { 0, ScreenWidth }, MiddleCordinateY = 0;
	int ScoreBackground;
	int CaveBackground;
	int BirdImage[9];
	struct Bird{
		int BirdCordinateX;
		int BirdCordinateY;// = ScreenHeight - 50 - rand() % 180;
		int BirdImageIndex = rand() % 8;
	};
	Bird MultipleBird[5];


	//////////////////////////////////////////////////////////Zombie.h Variables 
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	int Zombie[4][4], ZombieDead;
	int ZombieCordinateX = ScreenWidth-200, ZombieCordinateY = HeroCordinateY - 10;
	int ZombieDeadCordinateX, ZombieDeadCordinateY;
	int ZombieTypeIndex = 0, ZombieWalkIndex = 0, ZombieDeadTime = 0;
	bool IsZombieComing = true;
	int BossAttack[2], BossWalk[3];
	int BossCordinateX = ScreenWidth - 100, BossCordinateY = HeroCordinateY - 10;
	int DeadZombieCount=0;
	bool IsBossComing = false;
	int BossWalkIndex = 0;
	int BossAttackIndex = 0;
	int BossHealthBar = 200;
	int BossDead;										
	int BossDeadTime = 0;
	//////////////////////////////////////////////////////////Menu.h Variables 
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//info:
	//MenuChoice:1 = Game Playing Screen,		MenuChoice:{2,3,4} = {Highscore, instruction, Credits}
	//Startchoice:0 = New, Load GameScreen, Startchoice:1 = Character Choose Screen
	//Startchoice;2 Loadgame
	int MenuChoice = 0;		//MenuChoice:0 = Mainmenu
	int StartChoice = -1;	//Startchoice(-1) = Nothing
	int CharacterChoice = 0;	//CharacterChoice(1,2) = ironman, ultron
	int Menuimage[10];
	int GameOverimage;
	int BackButtonImage;
	int GameOverTime = 0;
	bool IsMusicOn = true;
	int HomeButton, NewGameButton, LoadGameButton;
	int StartGameBackground;
	int CharacterImage[2];
	int Story[4];
	bool IsStoryShowing = false;
	int StoryCount = 0;

	//////////////////////////////////////////////////////////Score.h Variables 
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	int Score = 0;
	char Scoress[1000000];
	int Level = 0;
	char Levelss[1000000];
	int FinalScore;
	int HighScore=0;








#endif