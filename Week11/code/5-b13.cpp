//ÌÀğ©Óî ¼ÆËã»ú 2454307
#include <iostream>  
#include <random>  
#include <ctime>  
using namespace std;  

int main()
{  
	srand(static_cast<unsigned int>(time(0)));
   char map[10][26];
   int cnt = 0;
   int dir[8][2] = { {0, 1}, {1, 0}, {1, 1}, {0, -1}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1} };
   while (cnt < 50) {
	   int i = rand() % 10;
	   int j = rand() % 26;
	   if (map[i][j] == '*')
		   continue;
	   map[i][j] = '*';
	   cnt++;;
   }
   for (int i = 0; i < 10; i++) {
	   for (int j = 0; j < 26; j++) {
		   if (map[i][j] == '*')
			   continue;
		   int cnt = 0;
		   for (int k = 0; k < 8; k++) {
			   int i1 = i + dir[k][0];
			   int j1 = j + dir[k][1];
			   if (i1 < 0 || i1 >= 10)
				   continue;
			   if (j1 < 0 || j1 >= 26)
				   continue;
			   cnt += (map[i1][j1] == '*');
		   }
		   map[i][j] = cnt + '0';
	   }
   }
   for (int i = 0; i < 10; i++) {
	   for (int j = 0; j < 26; j++) {
		   cout << map[i][j] << ' ';
	   }
	   cout << endl;
   }
   return 0;  
}