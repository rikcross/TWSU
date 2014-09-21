/*
* 'Reaction'
*  Line up the 8 blocks to progress
*  The game gets faster every level
*/

#include <Gamer.h>
#include <Images.h>

Gamer gamer;

//the horizontal position of the block
int currentBlockPos = 0;
int currentRow = 1;
int stoppedPos[8] = {0,0,0,0,0,0,0,0};
int dir = -1;
int startingDelayAmount = 800;
int delayTime = startingDelayAmount;
int frameCounter = 1;

byte titleAnim[30][8] = {
		{B00000000,
		B11101110,
		B10101000,
		B11101100,
		B11001100,
		B10101000,
		B10101110,
		B00000000},

		{B00000000,
		B11011101,
		B01010001,
		B11011001,
		B10011001,
		B01010001,
		B01011101,
		B00000000},

		{B00000000,
		B10111011,
		B10100010,
		B10110011,
		B00110010,
		B10100010,
		B10111010,
		B00000000},

		{B00000000,
		B01110111,
		B01000101,
		B01100111,
		B01100101,
		B01000101,
		B01110101,
		B00000000},

		{B00000000,
		B11101110,
		B10001010,
		B11001110,
		B11001010,
		B10001010,
		B11101010,
		B00000000},

		{B00000000,
		B11011101,
		B00010101,
		B10011101,
		B10010101,
		B00010101,
		B11010101,
		B00000000},

		{B00000000,
		B10111011,
		B00101010,
		B00111010,
		B00101010,
		B00101010,
		B10101011,
		B00000000},

		{B00000000,
		B01110111,
		B01010100,
		B01110100,
		B01010100,
		B01010100,
		B01010111,
		B00000000},

		{B00000000,
		B11101110,
		B10101000,
		B11101000,
		B10101000,
		B10101000,
		B10101110,
		B00000000},

		{B00000000,
		B11011101,
		B01010000,
		B11010000,
		B01010000,
		B01010000,
		B01011100,
		B00000000},

		{B00000000,
		B10111011,
		B10100001,
		B10100001,
		B10100001,
		B10100001,
		B10111001,
		B00000000},

		{B00000000,
		B01110111,
		B01000010,
		B01000010,
		B01000010,
		B01000010,
		B01110010,
		B00000000},

		{B00000000,
		B11101110,
		B10000100,
		B10000100,
		B10000100,
		B10000100,
		B11100100,
		B00000000},

		{B00000000,
		B11011101,
		B00001001,
		B00001001,
		B00001001,
		B00001001,
		B11001001,
		B00000000},

		{B00000000,
		B10111010,
		B00010010,
		B00010010,
		B00010010,
		B00010010,
		B10010010,
		B00000000},

		{B00000000,
		B01110101,
		B00100101,
		B00100101,
		B00100101,
		B00100101,
		B00100101,
		B00000000},

		{B00000000,
		B11101011,
		B01001010,
		B01001010,
		B01001010,
		B01001010,
		B01001011,
		B00000000},

		{B00000000,
		B11010111,
		B10010101,
		B10010101,
		B10010101,
		B10010101,
		B10010111,
		B00000000},

		{B00000000,
		B10101110,
		B00101010,
		B00101010,
		B00101010,
		B00101010,
		B00101110,
		B00000000},

		{B00000000,
		B01011101,
		B01010101,
		B01010101,
		B01010101,
		B01010101,
		B01011101,
		B00000000},

		{B00000000,
		B10111011,
		B10101010,
		B10101010,
		B10101010,
		B10101010,
		B10111010,
		B00000000},

		{B00000000,
		B01110111,
		B01010101,
		B01010101,
		B01010101,
		B01010101,
		B01110101,
		B00000000},

		{B00000000,
		B11101110,
		B10101010,
		B10101010,
		B10101010,
		B10101010,
		B11101010,
		B00000000},

		{B00000000,
		B11011100,
		B01010100,
		B01010100,
		B01010100,
		B01010100,
		B11010100,
		B00000000},

		{B00000000,
		B10111000,
		B10101000,
		B10101000,
		B10101000,
		B10101000,
		B10101000,
		B00000000},

		{B00000000,
		B01110000,
		B01010000,
		B01010000,
		B01010000,
		B01010000,
		B01010000,
		B00000000},

		{B00000000,
		B11100000,
		B10100000,
		B10100000,
		B10100000,
		B10100000,
		B10100000,
		B00000000},

		{B00000000,
		B11000000,
		B01000000,
		B01000000,
		B01000000,
		B01000000,
		B01000000,
		B00000000},

		{B00000000,
		B10000000,
		B10000000,
		B10000000,
		B10000000,
		B10000000,
		B10000000,
		B00000000},

		{B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000,
		B00000000}};

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

byte tick[8] = {B00000000,
                B00000001,
                B00000010,
                B00000100,
                B10001000,
                B01010000,
                B00100000,
                B00000000};

byte cross[8] = {B10000001,
                 B01000010,
                 B00100100,
                 B00011000,
                 B00011000,
                 B00100100,
                 B01000010,
                 B10000001};


void setup()
{             
  gamer.begin();
  showTitle();
  gamer.clear();
  delay(500);
}

void loop() 
{
  gamer.clear();
  //block position (add 8 for each vertical level
  gameScreen[(8*(8-currentRow)) +currentBlockPos] = 1;
  printGameScreen();
  //down = place block
  if(gamer.isPressed(DOWN)) {
    gameScreen[(8*(8-currentRow)) +currentBlockPos] = 1;
    stoppedPos[currentRow-1] = currentBlockPos;
    currentRow += 1;
    //stops cheating by repeatedly pressing down
    frameCounter = startingDelayAmount;
    //if the block isn't in line with the block below it... game over!
    if(currentRow > 2 and stoppedPos[currentRow-2] != stoppedPos[currentRow-3]) {
      delay(300);
      gamer.printImage(cross);
      delay(1000);
      //reset to start game
      resetGame();
      delayTime = startingDelayAmount;
      delay(1000);
    }
  }
  if(frameCounter==0) {
  //change direction at the ends of the screen
  if (currentBlockPos == 7) {
    dir = dir * -1;
  }
  if (currentBlockPos == 0) {
    dir = dir * -1;
  }
  //remove the block's last position from the screen
  gameScreen[(8*(8-currentRow)) +currentBlockPos] = 0;
  //move the block
  currentBlockPos = currentBlockPos + dir;
  //this means the player has lined up the 8 blocks
  if(currentRow == 9)
  {
    delay(300);
    gamer.printImage(tick);
    delay(1000);
    //reset for next level
    resetGame();
    if(delayTime > 199) {
      delayTime = delayTime - 200;
    }
    else {
      delayTime = startingDelayAmount;
    }
    delay(1000);  
  } }
  delay(1);
  //only moves blocks on frame '0'
  //this is instead of a delay, which causes a lag in input
  frameCounter += 1;
  if (frameCounter >= delayTime/currentRow) {
    frameCounter = 0;
  }
}


//reset game variables
void resetGame() {
  gamer.clear();
  clearBoard();
  currentRow = 1;
  currentBlockPos = 0;
  for(int l=0;l<8;l++) {  
    stoppedPos[l] = 0;
  }
  dir = -1;
  frameCounter = 1;
}

void showTitle() {
  // Loop through all frames
  for(int i=0; i<30; i++) {
    gamer.printImage(titleAnim[i]);
    if (i==0) {
      delay(1000);
    }
    else {
      delay(200);
    }
  }
}

//prints the contents of the gameScreen array
void printGameScreen() {
  int scrPos = 0;
  for(int col=0; col<8; col++) {
    for(int row=0; row<8; row++) {
      gamer.display[row][col] = gameScreen[scrPos];
      scrPos++;
    }
  }
  gamer.updateDisplay();
}


//clear the blocks at the start of each level 
void clearBoard() {
   for(int n=0;n<64;n++) {
     gameScreen[n] = 0;
   }
}

