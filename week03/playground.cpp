#include <iostream>
 
typedef enum {wood , stone} material;
 
typedef struct{
  int x,y;
  bool isWall;
  material type;
}field;
 
#define n 16
#define m 12
field playground[n][m];
 
int main(){
  int px = 5, py = 5;
  char c;
 
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      playground[i][j].x=i;
      playground[i][j].y=j;
      playground[i][j].isWall=(i==0||i==(n-1)||(j==0&&i!=3) ||j==(m-1));
      if (playground[i][j].isWall && !(i==3 && j==0))
        playground [i][j].type=stone;
      else
        playground [i][j].type=wood;
    }
  }
 
  do {
 
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (i == py && j == px) {
          std::cout << "O";
        } else if (playground[j][i].isWall) {
          std::cout << "*";
        } else {
          std::cout << " ";
        }
      }
      std::cout << "\n";
    }
 
    std::cin >> c;
    switch(c) {
      case 'u':
        if (py > 1 || (py == 1 && !playground[px][0].isWall)) 
          py--;
        break;
      case 'd':
        if (py < m-2 || (py == (m-2) && !playground[px][m-1].isWall)) 
          py++;
        break;
      case 'l':
        if (px > 1 || (px == 1 && !playground[0][py].isWall)) 
          px--;
        break;
      case 'r':
        if (px < n-2 || (px == (n-2) && !playground[n-1][py].isWall)) 
          px++;
        break;
      default:
        c = 'q';
    }
 
  } while (c != 'q');  
}