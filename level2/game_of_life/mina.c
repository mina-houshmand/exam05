#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(int ac, char **av){
	(void)ac;
	int w = atoi(av[1]);
	int h = atoi(av[2]);
	int iter = atoi(av[3]);
	
	int board[h][w];
	int next[h][w];
	
	int x = 0;
	int y = 0;
	int pen = 0;
	
	char c;
	
	for (int i = 0; i < h; i++){
		for(int j= 0; j < w; j++){
			board[i][j] = 0;
		}
	}
	
	while(read(0, &c, 1) == 1){
		if( c == 'w' && y > 0) y--;
		else if(c == 's' && y < h - 1) y++;
		else if(c == 'a' && x > 0) x--;
		else if(c == 'd' && x < w - 1) x++;
		else if(c == 'x') pen = !pen;
		if (pen)
			board[y][x] = 1;
	}
	
	for(int t = 0; t < iter; t++){
		for (int i = 0; i < h; i++){
			for(int j= 0; j < w; j++){
				int n = 0;
				for(int di = -1; di <= 1; di++){
					for(int dj = -1; dj <= 1; dj++){
						if ((di || dj) && di + i >= 0 && di + i < h && dj + j >= 0 && dj + j < w)
							n += board[di + i][dj + j];
					}
				}
				next[i][j] = (board[i][j] && ( n == 2 || n == 3)) || (!board[i][j] && n == 3);
			}
		}
	
	for (int i = 0; i < h; i++){  //yadet nare in dakhele iteretiane
		for(int j= 0; j < w; j++){
			board[i][j] = next[i][j];
		}
	}
}
	
	for (int i = 0; i < h; i++){
		for(int j= 0; j < w; j++){
			putchar(board[i][j] ? '0' : ' ');}
		putchar('\n');
		
	}
	
	
	return 0;
}
