#include <Gamer.h>
Gamer gamer;

int gameScreen[] = {
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
};

int xPos = 0;
int yPos = 0;
int vis = 0;

void setup()
{             
  gamer.begin();
}

void loop() 
{
  clearGameScreen();
  vis = vis==0 ? 1 : 0;
  gamer.display[yPos][xPos] = vis;
  printGameScreen();
  getInput();
  delay(200);
}

void printGameScreen() {
  int scrPos = 0;
  for(int col=0; col<8; col++) {
    for(int row=0; row<8; row++) {
      gamer.display[row][col] = (row==yPos and col==xPos) ? vis : gameScreen[scrPos];
      scrPos++;
    }
  }
  gamer.updateDisplay();
}

void clearGameScreen() {
  for(int i=0; i<8; i++) {
    for(int j=0; j<8; j++) {
      gamer.display[j][i] = 0;
    }
  }
  gamer.updateDisplay();
}

void getInput() {
  if(gamer.isPressed(LEFT) and yPos >0) { 
    yPos -= 1;
  }
  else if(gamer.isPressed(RIGHT) and yPos <8) { 
    yPos += 1;
  }
  else if(gamer.isPressed(UP) and xPos >0) { 
    xPos -= 1;
  }
  else if(gamer.isPressed(DOWN) and xPos <8) { 
    xPos += 1;
  }
  else if(gamer.isPressed(START)) {
    if(gameScreen[(8*xPos)+yPos] == 0) {
      gameScreen[(8*xPos)+yPos] = 1;
    }
    else {
      gameScreen[(8*xPos)+yPos] = 0;
    }
  }
}
