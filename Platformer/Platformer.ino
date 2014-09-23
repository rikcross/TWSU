#include <Gamer.h>

Gamer gamer;
int charXPos = 3;
int charYPos = 6;
//position of the level may on the display
int offset = 0;

//length of level
int levelSize = 40;

boolean jumping = false;
int jumpHeight = 0;

// 0=nothing 1=platform 2=exit
int level[8][40] = {
  {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,1},
  {0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1},
  {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {0,1,0,0,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1},
  {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

//face image
byte face[8] = {B00000000,
                B00100100,
                B00100100,
                B00000000,
                B10000001,
                B01000010,
                B00111100,
                B00000000};

                
/*
* ------------------------
* the main game!
* ------------------------
*/
void setup() {
  gamer.begin();
}
void loop() {
  
  drawScreen();
  getInput();
  
  //jumping
  if(jumping == true) {
    //if there's no platform above the player
    if(level[charYPos-1][charXPos+offset]==0) {
      charYPos -= 1;
      jumpHeight += 1;
      //only jump 3 squares high
      if(jumpHeight >= 3) {
        jumping = false;
      }
    }
    //if there is a platform above
    else {
      jumping = false;
      jumpHeight = 0;
    }
  }
  //gravity
  else {
    //if there isn't a block below the player
    if(level[charYPos+1][charXPos+offset]!=1) {
      charYPos += 1;
      jumpHeight -= 1;
    }
    else {
      jumpHeight = 0;
    }
  }
  
  //has the player got to the end?
  if(level[charYPos][charXPos+offset]==2) {
    delay(300);
    gamer.clear();
    gamer.printImage(face);
    delay(2000);
    gamer.clear();
    resetLevel();
  }
  
  delay(100);
}


/*
* ------------------------
* functions!
* ------------------------
*/
void getInput() {
  if( gamer.isHeld(RIGHT) ) {
    if(level[charYPos][charXPos+offset+1] != 1) {
      offset += 1;
    }
  }
  else if( gamer.isHeld(LEFT) ) {
    if(level[charYPos][charXPos+offset-1] != 1) {
      offset -= 1;
    }
  }

  if( gamer.isPressed(UP) ) {
    jumping = true;
  }  
  
}

void drawScreen() {
  
  gamer.clear();
  
  //draw level
  for(int i=0;i<8;i++) {
    for (int j=0;j<8;j++) {
      if ( (j+offset >= levelSize) || (j+offset <= 0)  ) {
        gamer.display[j][i] = 0;
      }
      else {
        gamer.display[j][i] = min(level[i][j+offset],1);
      }
    }
  }
  
  //place player
  gamer.display[charXPos][charYPos] = 1;
  
  gamer.updateDisplay();
}

void resetLevel() {
  charXPos = 3;
  charYPos = 6;
  offset = 0;
  jumping = false;
  jumpHeight = 0;
}

