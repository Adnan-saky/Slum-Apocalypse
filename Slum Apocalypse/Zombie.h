#include "Variables.h"



//:::::::::::::::::::::::::::::::::::::::::::::Zombie Image Initialize::::::::::::::::::::::::::::::::::::::::::::::::::::://
void ZombieLoadFunc(){       //there are four types of zombies with 4 different moving images

	ZombieDead = iLoadImage("Zombie\\ZombieDead.png");
	BossDead = iLoadImage("Zombie\\BossDead.png");

	Zombie[0][0] = iLoadImage("Zombie\\Zombie1_1.png");
	Zombie[0][1] = iLoadImage("Zombie\\Zombie1_2.png");
	Zombie[0][2] = iLoadImage("Zombie\\Zombie1_3.png");
	Zombie[0][3] = iLoadImage("Zombie\\Zombie1_4.png");

	Zombie[1][0] = iLoadImage("Zombie\\Zombie2_1.png");
	Zombie[1][1] = iLoadImage("Zombie\\Zombie2_2.png");
	Zombie[1][2] = iLoadImage("Zombie\\Zombie2_3.png");
	Zombie[1][3] = iLoadImage("Zombie\\Zombie2_4.png");

	Zombie[2][0] = iLoadImage("Zombie\\Zombie3_1.png");
	Zombie[2][1] = iLoadImage("Zombie\\Zombie3_2.png");
	Zombie[2][2] = iLoadImage("Zombie\\Zombie3_3.png");
	Zombie[2][3] = iLoadImage("Zombie\\Zombie3_4.png");

	Zombie[3][0] = iLoadImage("Zombie\\Zombie4_1.png");
	Zombie[3][1] = iLoadImage("Zombie\\Zombie4_2.png");
	Zombie[3][2] = iLoadImage("Zombie\\Zombie4_3.png");
	Zombie[3][3] = iLoadImage("Zombie\\Zombie4_4.png");

	BossAttack[0] = iLoadImage("Zombie\\ZombieBossAttack1.PNG");
	BossAttack[1] = iLoadImage("Zombie\\ZombieBossAttack2.PNG");

	BossWalk[0] = iLoadImage("Zombie\\ZombieBossWalk1.PNG");
	BossWalk[1] = iLoadImage("Zombie\\ZombieBossWalk2.PNG");
	BossWalk[2] = iLoadImage("Zombie\\ZombieBossWalk3.PNG");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ZombieAnimation(){             //////////////////////////animation     
	/////////////////////////////////////for zombie
	ZombieWalkIndex++;

	if (ZombieWalkIndex == 4)
		ZombieWalkIndex = 0;

	/////////////////////////////////////for boss
	if (BossHealthBar > 0){
		if ((HeroCordinateX + 40 < BossCordinateX) || (BossCordinateX < HeroCordinateX)){
			BossWalkIndex++;										//move animation
			if (BossWalkIndex == 3)
				BossWalkIndex = 0;
		}
		else if ((HeroCordinateX <= BossCordinateX) && (BossCordinateX <= HeroCordinateX + 40)){
			BossAttackIndex++;										//attack animation
			if (BossAttackIndex == 2)
				BossAttackIndex = 0;
		}
	}
	////////////////////////////////////zombie Dead image, zombie coming again	
	if (IsBossComing == true && BossHealthBar <= 0){
		BossDeadTime++;
		DeadZombieCount = 0;
		if (BossDeadTime == 1)
			Level++;

		if (BossDeadTime == 10){
			IsBossComing = false;
			BossDeadTime = 0;
			Score += 100;
			BossCordinateX = ScreenWidth;
		}
	}

	if (IsZombieComing == false && ZombieDeadTime != 4){			//This is for showing zombie's dead image for a certein milisecond
		ZombieDeadTime++;

	}
	else if (((IsBossComing == false) || (IsZombieComing == false)) && (ZombieDeadTime == 4)){		/////////////////Zombie will come again
		ZombieCordinateX = ScreenWidth;				//zombie Comes from (screenwidth) Cordinate
		ZombieTypeIndex++;
		IsZombieComing = true;
		ZombieDeadTime = 0;
		if (ZombieTypeIndex == 4)
			ZombieTypeIndex = 0;
	}



	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////Laser Recharge animation
	if (HeroLaserBar < 300 && MenuChoice == 1)
		HeroLaserBar += (2 + Level);			
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////