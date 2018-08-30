#include "Variables.h"


//::::::::::::::::::::::::Image Initialization::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
void HeroLoadFunc(){
	//will generate all Hero's moving images
	////////////////////////////////////////////////////////////////////////////////////////////////////////// ironman
	if (CharacterChoice == 1){
		///stand image
		HeroStand = iLoadImage("Hero\\Ironman\\Stand.png");

		////walk image
		for (int i = 0; i < 10; i++)
			HeroWalk[i] = iLoadImage("Hero\\Ironman\\Walk1.png");

		for (int i = 10; i < 20; i++)
			HeroWalk[i] = iLoadImage("Hero\\Ironman\\Walk2.png");
	
		for (int i = 20; i < 30; i++)
			HeroWalk[i] = iLoadImage("Hero\\Ironman\\Walk3.png");

		for (int i = 30; i < 40; i++)
			HeroWalk[i] = iLoadImage("Hero\\Ironman\\Walk4.png");

		for (int i = 40; i < 50; i++)
			HeroWalk[i] = iLoadImage("Hero\\Ironman\\Walk5.png");

		for (int i = 50; i < 60; i++)
			HeroWalk[i] = iLoadImage("Hero\\Ironman\\Walk6.png");


		//dead image
		for (int i = 0; i < 5; i++)
			HeroDead[i] = iLoadImage("Hero\\Ironman\\Dead1.png");

		for (int i = 5; i < 10; i++)
			HeroDead[i] = iLoadImage("Hero\\Ironman\\Dead2.png");

		for (int i = 10; i < 15; i++)
			HeroDead[i] = iLoadImage("Hero\\Ironman\\Dead3.png");


		//jump image
		HeroJump[0] = iLoadImage("Hero\\Ironman\\Jump1.png");
		HeroJump[1] = iLoadImage("Hero\\Ironman\\Jump2.png");


		//laser image
		for (int i = 0; i < 5; i++)
			HeroLaser[i] = iLoadImage("Hero\\Ironman\\Laser1.png");

		for (int i = 5; i < 10; i++)
			HeroLaser[i] = iLoadImage("Hero\\Ironman\\Laser2.png");

		Laser = iLoadImage("Hero\\Ironman\\LaserBeam.png");


		//punch image
		for (int i = 0; i < 5; i++)
			HeroPunch[i] = iLoadImage("Hero\\Ironman\\Punch1.png");

		for (int i = 5; i < 10; i++)
			HeroPunch[i] = iLoadImage("Hero\\Ironman\\Punch2.png");
		
		for (int i = 0; i < 5; i++)
			HeroSpark[i] = iLoadImage("Hero\\Ironman\\Spark1.png");
		
		for (int i = 5; i < 10; i++)
			HeroSpark[i] = iLoadImage("Hero\\Ironman\\Spark2.png");
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////// ultron
	if (CharacterChoice == 2){
		///stand image
		HeroStand = iLoadImage("Hero\\Ultron\\Stand.png");

		////walk image
		for (int i = 0; i < 10; i++)
			HeroWalk[i] = iLoadImage("Hero\\Ultron\\Walk1.png");

		for (int i = 10; i < 20; i++)
			HeroWalk[i] = iLoadImage("Hero\\Ultron\\Walk2.png");

		for (int i = 20; i < 30; i++)
			HeroWalk[i] = iLoadImage("Hero\\Ultron\\Walk3.png");

		for (int i = 30; i < 40; i++)
			HeroWalk[i] = iLoadImage("Hero\\Ultron\\Walk4.png");

		for (int i = 40; i < 50; i++)
			HeroWalk[i] = iLoadImage("Hero\\Ultron\\Walk5.png");

		for (int i = 50; i < 60; i++)
			HeroWalk[i] = iLoadImage("Hero\\Ultron\\Walk6.png");


		//dead image
		for (int i = 0; i < 5; i++)
			HeroDead[i] = iLoadImage("Hero\\Ultron\\Dead1.png");

		for (int i = 5; i < 10; i++)
			HeroDead[i] = iLoadImage("Hero\\Ultron\\Dead2.png");

		for (int i = 10; i < 15; i++)
			HeroDead[i] = iLoadImage("Hero\\Ultron\\Dead3.png");


		//jump image
		HeroJump[0] = iLoadImage("Hero\\Ultron\\Jump1.png");
		HeroJump[1] = iLoadImage("Hero\\Ultron\\Jump2.png");


		//laser image
		for (int i = 0; i < 5; i++)
			HeroLaser[i] = iLoadImage("Hero\\Ultron\\Laser1.png");

		for (int i = 5; i < 10; i++)
			HeroLaser[i] = iLoadImage("Hero\\Ultron\\Laser2.png");

		Laser = iLoadImage("Hero\\Ultron\\LaserBeam.png");


		//punch image
		for (int i = 0; i < 5; i++)
			HeroPunch[i] = iLoadImage("Hero\\Ultron\\Punch1.png");

		for (int i = 5; i < 10; i++)
			HeroPunch[i] = iLoadImage("Hero\\Ultron\\Punch2.png");

		for (int i = 0; i < 5; i++)
			HeroSpark[i] = iLoadImage("Hero\\Ultron\\Spark1.png");
		for (int i = 5; i < 10; i++)
			HeroSpark[i] = iLoadImage("Hero\\Ultron\\Spark2.png");

	}


	MenuChoice = 1;			///starts the game with Ironman's images

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Walking(){
	///////////////////////////////////////////////////////////////       Hero Walking Animation
	if (HeroWalkTime == 1){			//This is used for stopping hero's walking animation, while not pressing LEFT or RIGHT key
		IsHeroRightMove = false;
		IsHeroLeftMove = false;
	}

	else if (IsHeroRightMove == true || IsHeroLeftMove == true){					////Hero Right,left Move Animation
		HeroWalkIndex += 3;
		HeroWalkTime++;
		if (HeroWalkIndex >= 60){ HeroWalkIndex = 0; }
	}




	/////////////////////////////////////////////////////   :::::::::::::Hero Health decrease:::::::::::::::
	//while zombie attacks
	if ((ZombieCordinateX >= HeroCordinateX) && (ZombieCordinateX <= (HeroCordinateX + 50) + 10) && (IsBossComing == false) && (IsZombieComing == true) && (IsJumpUp == false)){
		if (HeroHealthBar > 0){ HeroHealthBar -= 1; }
	}
	//while boss attacks
	if (BossHealthBar > 0){
		if ((HeroCordinateX <= BossCordinateX) && (BossCordinateX <= HeroCordinateX + 40) && (IsJumpUp == false)){
			if (HeroHealthBar > 0){ HeroHealthBar -= 3; }
		}
		else if ((HeroCordinateX <= BossCordinateX) && (BossCordinateX <= HeroCordinateX + 40) && (IsJumpUp == true)){
			if (HeroHealthBar > 0){ HeroHealthBar -= 1; }
		}
	}
	///////////////////////////////////////////////////////   ::::::::::::::zombie move(Cordinate change):::::::::::::
	if ((MenuChoice != 0) && (MenuChoice == 1) && (IsHeroRightMove == true) && (IsBossComing == false) && (HeroCordinateX >= 360) && (ZombieCordinateX >= HeroCordinateX + 50))
		ZombieCordinateX -= (10 + Level * 2);

	else if ((MenuChoice != 0) && (MenuChoice == 1) && (IsBossComing == false) && (ZombieCordinateX >= HeroCordinateX + 50))
		ZombieCordinateX -= (5 + Level * 2);

	else if (IsBossComing == false && ZombieCordinateX < (HeroCordinateX + 50))
		ZombieCordinateX += (4 + Level * 2);


	////////////////////////////////////////////////////  :::::::::::::::::::::::::Boss move(Cordinate change)::::::::::::::::::::
	if (BossHealthBar > 0){												
		if ((MenuChoice != 0) && (MenuChoice == 1) && (ZombieDeadTime == 0) && (IsBossComing == true) && (BossCordinateX >= HeroCordinateX + 40))
			BossCordinateX -= (3 + Level);

		else if ((MenuChoice != 0) && (MenuChoice == 1) && (IsBossComing == true) && (BossCordinateX < HeroCordinateX))
			BossCordinateX += (4 + Level);
	}

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void HeroActionChange(){
	///////////////////////////////////////////////////// :::::::::::::::::Laser shooting animation, Laser Bar decrease, collision:::::::::::::::::
	if (IsHeroLaserMove == true){
		if (HeroLaserBar > 0){ HeroLaserBar -= 5; }					///This will make the laser fire only 6 times ( 300/ (5*10) )
		HeroLaserIndex++;
		if (HeroLaserIndex == 10){ IsHeroLaserMove = false; }			//10 lasershooting images for better animation
	}

	else
		IsHeroStandMove = true;


	/////////Laser Beam Cordinate change
	if (IsLaserBeam == true && LaserCordinateX > ScreenWidth){
		IsHeroLaserMove = false;
		IsLaserBeam = false;
	}
	else if (IsLaserBeam == true && LaserCordinateX <= ScreenWidth){
		LaserCordinateX += 80;			/////Speed or cordinate change of laser beam
	}
	////Collision Between Laser and zombie
	if (IsLaserBeam == true && LaserCordinateX > ZombieCordinateX && IsBossComing == false && IsZombieInFront == true){
		IsLaserBeam = false;
		IsZombieComing = false;
		IsZombieInFront = false;
	}


	//////condition for boss coming after certain amount of zombie kills
	if (DeadZombieCount > (4 + Level * 2) && ZombieDeadTime == 3){
		IsZombieComing = false;
		IsBossComing = true;
		BossHealthBar = 200;
	}

	////Collision Between Laser and boss:
	if (IsLaserBeam == true && (LaserCordinateX > BossCordinateX + 50) && (IsBossComing == true) && (IsBossInFront == true)){
		IsLaserBeam = false;
		IsBossInFront = false;
		BossHealthBar -= 20;

		if (BossHealthBar > 0)							
			Score += 5;
	}



	///////////////////////////////////////////////// ::::::::::::::::::::::Punching Animation, Collision:::::::::::::::::::::
	if (IsHeroPunchMove == true){
		HeroPunchIndex++;

		////////collision between punch and zombie
		if (HeroCordinateX < ZombieCordinateX && IsBossComing == false && ZombieCordinateX <= (HeroCordinateX + 50) + 5){
			IsZombieComing = false;
		}

		if (HeroPunchIndex == 10)	////////////10 Punching images for better animation
			IsHeroPunchMove = false;
	}

	else
		IsHeroStandMove = true;






	/////////////////////////////////////////////////::::::::::::::::::::::::::::::::Dead Animation:::::::::::::::::::::::::
	if (HeroHealthBar <= 0){
		if (HeroDeadIndex < 14)
			HeroDeadIndex++;
		GameOverTime++;
	}



	////////////////////////////////////////////////////::::::::::::::::::::::::::::::::::Spark Animation:::::::::::::::::::::
	//while zombie is attacking hero
	if ((ZombieCordinateX >= HeroCordinateX) && (ZombieCordinateX <= (HeroCordinateX + 50) + 10) && (IsBossComing == false) && (IsZombieComing == true) && (IsJumpUp == false)){
		HeroSparkIndex++;
		if (HeroSparkIndex == 10)
			HeroSparkIndex = 0;
	}
	//while boss is attacking hero
	if ((HeroCordinateX <= BossCordinateX) && (BossCordinateX <= HeroCordinateX + 40) && (IsBossComing == true)){
		HeroSparkIndex++;
		if (HeroSparkIndex == 10)
			HeroSparkIndex = 0;
	}



	//////////////////////////////////////////////////////::::::::::::::::::::::::::::::::Jumping Animation;:::::::::::::::::::
	if (IsJumpUp == true){

		if ((HeroCordinateJump <= 150) && (IsJumpDown == true)){
			HeroCordinateJump -= 5;
			if (HeroCordinateJump == 0){
				IsJumpUp = false;
				IsHeroJumpMove = false;
				IsJumpAndLeft = false;
			}
		}

		else if ((HeroCordinateJump >= 0) && (HeroCordinateJump < 150) && (IsJumpUp == true) && (IsJumpDown == false)){
			HeroCordinateJump += 10;
			if (HeroCordinateJump == 100){
				JumpIndex = 1;
			}
			if (HeroCordinateJump == 150){
				IsJumpDown = true;
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
