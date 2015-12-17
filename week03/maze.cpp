#include <iostream>
using namespace std;
typedef enum {wood , stone} material;

typedef struct{
  int x,y;
  bool isWall;
  material type;
}field;

#define n 16
#define m 12
field playground[n][m];
int x=5;
int y=5;
// Alternatively: don't define as global variables and instead
// have function void display(field **playground, int x, int y);

void display(){
  for (int j=0; j<m; j++){
    for (int i=0; i<n; i++){
      if (playground[i][j].isWall)
	cout << "*";
      else
	if (i==x && j==y)
	  cout << "O";
	else
	  cout << " ";
    }
    cout << endl;
  }
}

int main(){
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
      playground[i][j].x=i;
      playground[i][j].y=j;
      playground[i][j].isWall=(i==0||i==(n-1)||(j==0&&i!=3) ||j==(m-1) );
      if (playground[i][j].isWall)
	playground [i][j].type=stone;
      else
	playground [i][j].type=wood;
    }
  }

  char c;
  display();
  cin >> c;
  while (c!='q'){
    if (c=='l' && x>0 && !playground[x-1][y].isWall) x--;
    if (c=='r' && x<n-1 && !playground[x+1][y].isWall) x++;
    if (c=='u' && y>0 && !playground[x][y-1].isWall) y--;
    if (c=='d' && y<m-1 && !playground[x][y+1].isWall) y++;
    display();
    cin >> c;
  }
}
    
    
  
