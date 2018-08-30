#include "Variables.h"




//::::::::::::::::::::::::Background Image Initialization::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
void BackgroundLoadFunc(){
	Middle[0] = iLoadImage("Background\\Middle1.png"); //Two image will move
	Middle[1] = iLoadImage("Background\\Middle2.png");


	Road[0] = iLoadImage("Background\\Road.png");          // one image will move
	Road[1] = iLoadImage("Background\\Road.png");

	Sky[0] = iLoadImage("Background\\Sky.png");            // one image will move
	Sky[1] = iLoadImage("Background\\Sky.png");

	BirdImage[0] = iLoadImage("Bird\\1.png");
	BirdImage[1] = iLoadImage("Bird\\2.png");
	BirdImage[2] = iLoadImage("Bird\\3.png");
	BirdImage[3] = iLoadImage("Bird\\4.png");
	BirdImage[4] = iLoadImage("Bird\\5.png");
	BirdImage[5] = iLoadImage("Bird\\6.png");
	BirdImage[6] = iLoadImage("Bird\\7.png");
	BirdImage[7] = iLoadImage("Bird\\8.png");
	BirdImage[8] = iLoadImage("Bird\\9.png");

	ScoreBackground = iLoadImage("Background\\ScoreBackground.PNG");

	CaveBackground = iLoadImage("Background\\Cave.PNG");

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MiddleBackgroundChange(){
	for (int i = 0; i < 2; i++){
		if ((IsBossComing == false) && (IsHeroRightMove == true) && (HeroCordinateX >= 360) && (IsJumpUp == false))		//Here,351 throughout x axis is the deadline of hero on the screen
			MiddleCordinateX[i] -= 2;

		if (MiddleCordinateX[i] + ScreenWidth < 0)
			MiddleCordinateX[i] = MiddleCordinateX[(i + 1) % 2] + ScreenWidth;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void RoadBackgroundChange(){
	for (int i = 0; i < 2; i++){
		if ((IsBossComing == false) && (IsHeroRightMove == true) && (HeroCordinateX >= 360) && (IsJumpUp == false))
			RoadCordinateX[i] -= 5;

		if (RoadCordinateX[i] + ScreenWidth <= 0)
			RoadCordinateX[i] = RoadCordinateX[(i + 1) % 2] + ScreenWidth;

	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SkyBackgroundChange(){
	for (int i = 0; i < 2; i++){
		SkyCordinateX[i] -= 1;

		if (SkyCordinateX[i] + ScreenWidth <= 0)
			SkyCordinateX[i] = SkyCordinateX[(i + 1) % 2] + ScreenWidth;
	}


	//for bird in the sky
	for (int i = 0; i < 5; i++){
		MultipleBird[i].BirdCordinateX -= 10;

		if (MultipleBird[i].BirdCordinateX < -20){
			MultipleBird[i].BirdCordinateX = ScreenWidth + rand() % 600;
			MultipleBird[i].BirdCordinateY = ScreenHeight - 100 - rand() % 180;
		}
		MultipleBird[i].BirdImageIndex++;

		if (MultipleBird[i].BirdImageIndex > 8)
			MultipleBird[i].BirdImageIndex = 0;
	}

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////