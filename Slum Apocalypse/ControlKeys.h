#ifndef _CONTROLKEYS_H_
#define _CONTROLKEYS_H_

//////////////////////////////////////////////////////////////////////////
/////////////////////////For main menu
void MainMenuClick(int mx, int my){

	if (IsStoryShowing == false && MenuChoice == 0 && StartChoice == -1){
		////////////////////for New, Load Gamescreen
		if (mx > 300 && mx< 600 && my>325 && my <380) {
			IsStoryShowing = true;
			StoryCount = 1;
		}

		//////////////////////for Score
		else if (mx >300 && mx< 600 && my>255 && my <310) { MenuChoice = 2; }
		////////////////For Instruction
		else if (mx >300 && mx< 600 && my>185 && my <240) { MenuChoice = 3; }
		//for about
		else if (mx >300 && mx< 600 && my>115 && my <170) { MenuChoice = 4; }
		//////////////////for exit
		else if (mx >300 && mx< 600 && my>45 && my < 100) { exit(0); }
	}

	else if (StartChoice == 0){
		//new game to character choose screen
		if (mx > 380 && mx< 650 && my>240 && my < 290) {
			StartChoice = 1;
		}

		//for load game
		else if (mx > 380 && mx< 650 && my>150 && my < 200) {
			if (CharacterChoice > 0)
				StartChoice = 2;
		}
	}

	else if (StartChoice == 1){ //for Character Choose screen to the game[new game]
		if (mx > 200 && mx< 380 && my>100 && my < 400) {
			GameOverTime = 0;
			MenuChoice = 0;
			HeroHealthBar = 300;
			HeroLaserBar = 0;
			HeroDeadIndex = 0;
			HeroCordinateX = 0;
			HeroCordinateY = 30;
			Score = 0;
			ZombieCordinateX = ScreenWidth - 200;
			DeadZombieCount = 0;
			IsBossComing = false;
			IsZombieComing = true;
			BossCordinateX = ScreenWidth + 100;
			StartChoice = -1;
			BossHealthBar = 200;
			CharacterChoice = 1;		//1 for ironman
			Level = 0;
			HeroLoadFunc();
		}
		if ((mx > ScreenWidth - 380) && (mx < ScreenWidth - 200) && my>100 && my < 400){
			GameOverTime = 0;
			MenuChoice = 0;
			HeroHealthBar = 300;
			HeroLaserBar = 0;
			HeroDeadIndex = 0;
			HeroCordinateX = 0;
			HeroCordinateY = 30;
			Score = 0;
			ZombieCordinateX = ScreenWidth - 200;
			DeadZombieCount = 0;
			IsBossComing = false;
			IsZombieComing = true;
			BossCordinateX = ScreenWidth + 100;
			StartChoice = -1;
			BossHealthBar = 200;
			CharacterChoice = 2;		//2 for ultron
			Level = 0;
			HeroLoadFunc();
		}
	}

	else if (StartChoice == 2){	//for load game
		if (mx > 380 && mx< 650 && my>150 && my < 200){
			HeroLoadFunc();
		}
	}

}
//////////////////////////////////////////////////////////////////////////
//////////////////for Backbutton in Gameover screen
void MainMenuAfterGameOver(int mx, int my){
	if (GameOverTime > 100 && HeroHealthBar <= 0){
		if (mx > ScreenWidth - 170 && my > ScreenHeight - 100 && my < ScreenHeight - 50){
			MenuChoice = 0;
			StartChoice = -1;
			GameOverTime = 0;
			HeroHealthBar = 300;
			HeroLaserBar = 0;
			HeroDeadIndex = 0;
			HeroCordinateX = 0;
			HeroCordinateY = 30;
			Score = 0;
			ZombieCordinateX = ScreenWidth - 200;
			DeadZombieCount = 0;
			IsBossComing = false;
			IsZombieComing = true;
			BossCordinateX = ScreenWidth + 100;
			BossHealthBar = 200;
			CharacterChoice = 0;
		}
	}
}
//////////////////////////////////////////////////////////////////////////
//////////////////for RightMove
void RightButton(){
	HeroWalkTime = 0;

	if ((IsBossComing == false) && (HeroCordinateX < 360) && (IsJumpUp == false)){
		IsHeroRightMove = true;
		HeroCordinateX += 3;
	}
	else if ((IsBossComing == false) && (HeroCordinateX < 360) && (IsJumpUp == true)){
		HeroCordinateX += 12;
	}

	if ((IsBossComing == false) && (HeroCordinateX >= 360) && (IsJumpUp == false))
		IsHeroRightMove = true;
	//when boss is present
	if ((IsBossComing == true) && (HeroCordinateX < ScreenWidth - 100) && (IsJumpUp == false)){
		IsHeroRightMove = true;
		HeroCordinateX += 3;
	}
	else if ((IsBossComing == true) && (HeroCordinateX < ScreenWidth - 100) && (IsJumpUp == true)){
		HeroCordinateX += 12;
	}

}
//////////////////////////////////////////////////////////////////////////
//////////////////for LeftMove
void LeftButton(){
	HeroWalkTime = 0;
	if (HeroCordinateX > 0 && IsJumpUp == false){
		IsHeroLeftMove = true;
		HeroCordinateX -= 3;
	}
	else if (HeroCordinateX > 0 && IsJumpUp == true){
		IsJumpAndLeft = true;
		HeroCordinateX -= 12;
	}
}
//////////////////////////////////////////////////////////////////////////
//////////////////for Jump
void JumpButton(){
	if (IsHeroJumpMove == false)
	{
		IsHeroJumpMove = true;
		IsJumpUp = true;
		IsJumpDown = false;
		JumpIndex = 0;
		HeroCordinateJump += 10;
	}
}
//////////////////////////////////////////////////////////////////////////
//////////////////for Shooting Laser
void LaserButton(){
	//for zombie
	if (ZombieCordinateX > HeroCordinateX && IsZombieComing == true && IsBossComing == false){
		Score += 5;
		DeadZombieCount++;
	}
	HeroLaserIndex = 0;                      //Can only shoot one laser at a time and when laser bar is not empty(1 laser== 50 value of HeroLaserBar)
	IsHeroStandMove = false;
	IsHeroLaserMove = true;
	IsLaserBeam = true;

	if (HeroCordinateX < ZombieCordinateX && IsZombieComing == true){
		IsZombieInFront = true;
		IsBossInFront = false;
	}
	if (HeroCordinateX < BossCordinateX + 100 && IsBossComing == true){
		IsBossInFront = true;
		IsZombieInFront = false;
	}

	LaserCordinateX = HeroCordinateX + 80;
}
//////////////////////////////////////////////////////////////////////////
//////////////////for Punching
void PunchButton(){
	if ((ZombieCordinateX < HeroCordinateX + 92) && (ZombieCordinateX >HeroCordinateX) && (IsZombieComing == true) && (IsBossComing == false)){
		Score += 2;
		DeadZombieCount++;
	}
	HeroPunchIndex = 0;
	IsHeroStandMove = false;
	IsHeroPunchMove = true;
}

//////////////////////////////////////////////////////////////////////////
//////////////////for Music
void MusicButton(){
	if (IsMusicOn){
		IsMusicOn = false;
		PlaySound(0, 0, 0);
	}
	else if (IsMusicOn == false){
		IsMusicOn = true;
		PlaySound("Menu\\sound", NULL, SND_LOOP | SND_ASYNC);
	}
}



#endif