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
