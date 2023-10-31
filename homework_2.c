#include <stdio.h>
//#define ChessDemand(x, y) (x = 0 &&x <= 7 &&y = 0 && y <= 7)
#define EMPTY 0 //定義用大寫避免與變數混淆
#define BLACK 1
#define WHITE 2

int ChessBoard[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, 
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}, 
                        {0, 0, 0, 2, 1, 0, 0, 0},
                        {0, 0, 0, 1, 2, 0, 0, 0},      
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},     
                        {0, 0, 0, 0, 0, 0, 0, 0}};

// check the color of this chess
void CheckColor(x, y) {
  int color;
  switch (ChessBoard[x][y]) { // check color
  case EMPTY:
    color = EMPTY;
    printf("this chess is empty.\n");
    break;
  case BLACK:
    color = BLACK;
    printf("this chess is black.\n");
    break;
  case WHITE:
    color = WHITE;
    printf("this chess is white.\n");
    break;
  }
}

void CheckDir(x, y){
  int mine = ChessBoard[x][y];
  int opponent = 3 - ChessBoard[x][y];
  int dx = 1, dy =1;
  if (mine != EMPTY){ 
  
  //check 左上  
    while (ChessBoard[x-dx][y-dy] == opponent){
      dx++;
      dy++;
      if (ChessBoard[x-dx][y-dy] == EMPTY){
        printf("(%d, %d)\n", x-dx, y-dy);
        break;
      }
    }
    dx = 1; 
    dy = 1;
    
    //check 右上
    while (ChessBoard[x+dx][y-dy] == opponent){
      dx++;
      dy++;
      if (ChessBoard[x+dx][y-dy] == EMPTY){
        printf("(%d, %d)\n", x+dx, y-dy);
        break;
      }
    }
    dx = 1; 
    dy = 1;
    
    //check 右下
    while (ChessBoard[x+dx][y+dy] == opponent){
      dx++;
      dy++;
      if (ChessBoard[x+dx][y+dy] == EMPTY){
        printf("(%d, %d)\n", x+dx, y+dy);
        break;
      }
    }  
    dx = 1; 
    dy = 1;
    
    //check 上方
    while (ChessBoard[x][y-dy] == opponent){
      dy++;
      if (ChessBoard[x][y-dy] == EMPTY){
        printf("(%d, %d)\n", x, y-dy);
        break;
      }
    }
    dx = 1; 
    dy = 1;
    
    //check 下方
    while (ChessBoard[x][y+dy] == opponent){
      dy++;
      if (ChessBoard[x][y+dy] == EMPTY){
        printf("(%d, %d)\n", x, y+dy);
        break;
      }
    }
    dx = 1; 
    dy = 1;
  
    //check 左
    while (ChessBoard[x-dx][y] == opponent){
      dx++;
      if (ChessBoard[x-dx][y] == EMPTY){
        printf("(%d, %d)\n", x-dx, y);
        break;
      }
    }
    dx = 1; 
    dy = 1;
    
    //check 右
    while (ChessBoard[x+dx][y] == opponent){
      dx++;
      if (ChessBoard[x+dx][y] == EMPTY){
        printf("(%d, %d)\n", x+dx, y);
        break;
      }
    }
    dx = 1; 
    dy = 1; //it can't be reset in while loop
    
  } //the end of if
  else printf("you put a blank chess.\n");
}



//main code
int main() {
  int x, y;
  scanf("%d%d", &x, &y);
  CheckColor(x, y);
  CheckDir(x, y);
  



  return 0;
}

// end of main
