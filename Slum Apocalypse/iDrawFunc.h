#include "Variables.h"
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////  :::::::::		Background		;;;;;;;;;;;;;;
void SkyDraw(){
	for (int j = 0; j < 2; j++)
		iShowImage(SkyCordinateX[j], SkyCordinateY, ScreenWidth + 10, 400, Sky[j]);
}

////////////////////////////////////////////////////////////////////////////////
void MiddleBuildingDraw(){
	for (int k = 0; k < 2; k++)
		iShowImage(MiddleCordinateX[k], MiddleCordinateY - 20, ScreenWidth + 3, 620, Middle[k]);
	// showing multiple birds in the sky
	for (int i = 0; i < 5; i++){
		iShowImage(MultipleBird[i].BirdCordinateX, MultipleBird[i].BirdCordinateY, 50, 50, BirdImage[MultipleBird[i].BirdImageIndex]);
	}
}


////////////////////////////////////////////////////////////////////////////////
void RoadDraw(){
	for (int i = 0; i < 2; i++)
		iShowImage(RoadCordinateX[i], RoadCordinateY, ScreenWidth + 10, 60, Road[i]);
}





////////////////////////////////////////////////////////////////////////////////	;;;;;;;;;;;;;;		Hero	;;;;;;;;;;;;;;;;;
void HeroDraw(){
	if (HeroHealthBar <= 0){
		iShowImage(HeroCordinateX, HeroCordinateY, 120, 120, HeroDead[HeroDeadIndex]);
	}

	else{
		if (IsHeroLaserMove == true)
			iShowImage(HeroCordinateX, HeroCordinateY, 100, 100, HeroLaser[HeroLaserIndex]);

		else if (IsHeroPunchMove == true)
			iShowImage(HeroCordinateX, HeroCordinateY, 120, 120, HeroPunch[HeroPunchIndex]);

		else if (IsHeroRightMove == true)
			iShowImage(HeroCordinateX, HeroCordinateY, 120, 120, HeroWalk[HeroWalkIndex]);

		else if (IsHeroLeftMove == true)
			iShowImage(HeroCordinateX + 120, HeroCordinateY, -120, 120, HeroWalk[HeroWalkIndex]);

		else if (IsJumpUp == true && IsJumpAndLeft == false)
			iShowImage(HeroCordinateX, HeroCordinateY + HeroCordinateJump, 120, 120, HeroJump[JumpIndex]);

		else if (IsJumpUp == true && IsJumpAndLeft == true)
			iShowImage(HeroCordinateX + 120, HeroCordinateY + HeroCordinateJump, -120, 120, HeroJump[JumpIndex]);

		else if (IsHeroStandMove == true)
			iShowImage(HeroCordinateX, HeroCordinateY - 5, 145, 140, HeroStand);

		if ((ZombieCordinateX >= HeroCordinateX) && (ZombieCordinateX <= (HeroCordinateX + 50) + 10) && (IsZombieComing == true) && (IsJumpUp == false))
			iShowImage(HeroCordinateX + 10, HeroCordinateY, 120, 120, HeroSpark[HeroSparkIndex]);
		if ((HeroCordinateX <= BossCordinateX) && (BossCordinateX <= HeroCordinateX + 40) && (IsBossComing == true) && BossHealthBar > 0 && (IsJumpUp == false)){
			iShowImage(HeroCordinateX + 10, HeroCordinateY, 120, 120, HeroSpark[HeroSparkIndex]);
		}
		if (IsLaserBeam == true && (IsZombieComing == true || IsBossComing == true))
			iShowImage(LaserCordinateX, LaserCordinateY, 200, 10, Laser);
	}
}




////////////////////////////////////////////////////////////////////////////////	:::::::::::::::::	Zombie   :::::::::::::
void ZombieDraw(){
	if (IsBossComing == false && IsZombieComing == true){
		if (HeroCordinateX<ZombieCordinateX)	//forward image
			iShowImage(ZombieCordinateX, ZombieCordinateY, 120, 120, Zombie[ZombieTypeIndex][ZombieWalkIndex]);
		else if (HeroCordinateX>ZombieCordinateX) //backward image
			iShowImage(ZombieCordinateX + 120, ZombieCordinateY, -120, 120, Zombie[ZombieTypeIndex][ZombieWalkIndex]);

		ZombieDeadCordinateX = ZombieCordinateX;
		ZombieDeadCordinateY = ZombieCordinateY;
	}

	else if (IsZombieComing == false){
		iShowImage(ZombieDeadCordinateX, ZombieDeadCordinateY, 120, 120, ZombieDead);

	}

}

////////////////////////////////////////////////////////////////////////////////////	;;;;;;;;;;;;;;;;	boss  ;;;;;;;;;;;;;;;
void BossDraw(){
	if (IsBossComing == true && BossHealthBar > 0){
		if (HeroCordinateX + 40 < BossCordinateX){	 //forward image
			iShowImage(BossCordinateX, BossCordinateY, 200, 200, BossWalk[BossWalkIndex]);
		}
		else if (HeroCordinateX > BossCordinateX){	//backward image
			iShowImage(BossCordinateX + 200, BossCordinateY, -200, 200, BossWalk[BossWalkIndex]);
		}

		else if (HeroCordinateX + 40 >= BossCordinateX && HeroCordinateX <= BossCordinateX){
			iShowImage(BossCordinateX, BossCordinateY, 200, 200, BossAttack[BossAttackIndex]);
		}
		//boss healthbar
		iSetColor(0, 255, 255);
		iRectangle(BossCordinateX, BossCordinateY + 200, 204, 5);
		iSetColor(255, 0, 0);
		iFilledRectangle(BossCordinateX + 2, BossCordinateY + 201, BossHealthBar, 3);
	}
	else if (IsBossComing == true && BossHealthBar <= 0){
		iShowImage(BossCordinateX, BossCordinateY, 200, 200, BossDead);
		if (BossDeadTime > 3 && BossDeadTime < 10){
			iShowImage(0, 0, 1000, 600, CaveBackground);
			iSetColor(255, 255, 255);
			iText(450, 100, "Level: ", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(530, 100, Levelss, GLUT_BITMAP_TIMES_ROMAN_24);
		}

		if (BossDeadTime > 0 && BossDeadTime < 4){
			iSetColor(255, 255, 255);
			iText(BossCordinateX + 100, BossCordinateY + 200, "+100", GLUT_BITMAP_TIMES_ROMAN_24);
		}
	}
}



////////////////////////////////////////////////////////////////////////////////		;;;;;;;;;;;   health and laser bar ;;;;;;;;;;;
void BarsDraw(){
	iShowImage(5, ScreenHeight - 80, 335, 80, ScoreBackground);

	iSetColor(255, 255, 255);																//Hero's health
	iText(20, ScreenHeight - 20, "Health", GLUT_BITMAP_HELVETICA_18);
	iSetColor(0, 255, 255);
	iRectangle(20, ScreenHeight - 35, 303, 10);
	iSetColor(0, 255, 0);
	iFilledRectangle(21, ScreenHeight - 33, HeroHealthBar, 7);						 ///300 health at the beginning


	iSetColor(255, 255, 255);															//Hero's Laser bar
	iText(20, ScreenHeight - 50, "Laser", GLUT_BITMAP_HELVETICA_18);
	iSetColor(0, 255, 255);
	iRectangle(20, ScreenHeight - 65, 303, 10);
	iSetColor(255, 255, 0);
	iFilledRectangle(21, ScreenHeight - 63, HeroLaserBar, 7);						 ///300 Laser energy at the beginning
	iSetColor(255, 0, 0);
	iLine(71, ScreenHeight - 65, 71, ScreenHeight - 55);							  ///Minimum laser line
}

////////////////////////////////////////////////////////////////////////////////



