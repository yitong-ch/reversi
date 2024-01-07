#include <stdio.h>
#define ChessDemand(x, y) (x = 0 &&x <= 7 &&y = 0 && y <= 7)
#define EMPTY 0 //定義用大寫避免與變數混淆
#define BLACK 1
#define WHITE 2

int di[]={-1,-1,-1,0,0,1,1,1};
int dj[]={-1,0,1,-1,1,-1,0,1};

int ChessBoard[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 2, 1, 0, 0, 0},
                        {0, 0, 0, 1, 2, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}};

// check the color of this chess
void CheckColor(int x, int y) {
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

void CheckDir(int i, int j){
    int go_i, go_j, go_ii, go_jj;
    int itself = ChessBoard[i][j];
    int opponent = 3 - ChessBoard[i][j];
    if (ChessBoard[i][j] == EMPTY){
        printf("you can't put the chess.\n");
    }
    else{
        for(int n = 0; n<8; n++){
            go_i = i + di[n];
            go_j = j + dj[n];
            //judge x and y axis, oblique??
            while (ChessBoard[go_i][go_j] == opponent && go_j>=0 && go_j<=7 && go_i >=0 && go_i<= 7){
                    go_i += di[n];
                    go_j += dj[n];
                    if(ChessBoard[go_i][go_j] == EMPTY){
                        printf("(%d, %d)\n", go_i, go_j);
                        break;
                    }
                }
            }

    }
}

//main code
int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    CheckColor(x, y);
    CheckDir(x, y);
    return 0;
}


//below are the record of trial and error
/*void CheckDir(int x, int y){
    int itself = ChessBoard[x][y];
    int opponent = 3 - ChessBoard[x][y];
    for(int i = 0; i<8; i++){
        x += dx[i];
        y += dy[i];
        if (ChessBoard[x][y] == itself){
            for(int i = 0; i<8; i++){
                x += dx[i];
                y += dy[i];
                while (ChessBoard[x][y] == opponent && x<=7 && x>=0 && y<=7 && y>=0){
                    x += dx[i];
                    y += dy[i];
                    if (ChessBoard[x][y] == EMPTY){
                        printf("(%d, %d)", x, y);
                        break;
                    }
                }
            }
        }
    }
}*/


/*void CheckDir(x, y){
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
      dx += 1;
      dy += 1;
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

}*/


























