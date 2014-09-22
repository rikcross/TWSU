#include <Gamer.h>

Gamer gamer;
int charXPos = 3;
int charYPos = 0;
//position of the level may on the display
int offset = 0;

//length of level
int levelSize = 15;

int level[8][15] = {
  {0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  {0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  {0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  {0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  {0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  {0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  {0,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};


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

  //gravity
  if(level[charYPos+1][charXPos]==0) {
    charYPos += 1;
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
    if(level[charYPos][charXPos+offset+1] == 0) {
      offset += 1;
    }
  }
  else if( gamer.isHeld(LEFT) ) {
    if(level[charYPos][charXPos+offset-1] == 0) {
      offset -= 1;
    }
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
        gamer.display[j][i] = level[i][j+offset];
      }
    }
  }
  
  //place character
  gamer.display[charXPos][charYPos] = 1;
  
  gamer.updateDisplay();
}



