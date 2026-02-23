#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


int main(int argc, char **argv) {

	(void)argc;                                                                      // we ignore the argc
    int w = atoi(argv[1]);                                                         // we save the width
    int h = atoi(argv[2]);                                                         // we save the height
    int iter = atoi(argv[3]);                                                       // we save the iterations

    int board[h][w];                                          // board is a 2D array of size h x w
    int next[h][w];                                          // next is a 2D array of size h x w
    
    int x = 0;                                                // x is the current x position
    int y = 0;                                                // y is the current y position
    int pen = 0;                                              // pen is the current pen state of the pen, 0 is up, 1 is down
                                                              // down means that the pen is down and can draw
                                                              // up means that the pen is up and cannot draw
    
    char c;                                                    // c is the current character read from the standard input
    
    // Initialize
    for (int i = 0; i < h; i++)                 // we iterate through the height of the board
        for (int j = 0; j < w; j++)                //for each row we iterate through the width of the board
            board[i][j] = 0;                          // we initialize the whole board to 0
    
    // Draw

    // w, s, a, d, x came from keyboard movement and x is the pen up and down
    while (read(0, &c, 1) == 1) {                // read return -1 if end of file is reached, 1 if read successfully
        if (c == 'w' && y > 0) y--;              // y[0] is on top of y[1], thats why we do y--
                                                 // y > 0 because we do not want to go out of the board from the top y axis
        else if (c == 's' && y < h-1) y++;       // y < h-1 because we do not want to go out of the board from the bottom y axis
                                                 // h is the height, since we start at 0, the last index is h-1
        else if (c == 'a' && x > 0) x--;        
        else if (c == 'd' && x < w-1) x++;      
        else if (c == 'x') pen = !pen;          // if we have x, we toggle the pen state
        if (pen) board[y][x] = 1;               // if the pen is down, we draw a 1 in the board grid we are at
    }
    
    // Simulate
    for (int t = 0; t < iter; t++)              // now we loop through the iterations count we have
    {
        for (int i = 0; i < h; i++)             // we loop through the height of the board
        {
            for (int j = 0; j < w; j++)            // for each row we loop through the width of the board
            {
                int n = 0;                             // n is the number of live neighbors
                for (int di = -1; di <= 1; di++)        // it will go through -1, 0, 1 for the x axis
                    for (int dj = -1; dj <= 1; dj++)      // it will go through -1, 0, 1  for the y axis   
                        if ((di || dj) && i+di >= 0 && i+di < h && j+dj >= 0 && j+dj < w){ // (0,0) means we are cell it self, so we do not count it
                                                                                           // i+di >= 0 -> i is the current row, and by i + di we check if the neighbor is in the board
                                                                                           // i+di < h -> i is the current row, and by i + di we check if the neighbor is in the board
                                                                                           // j+dj >= 0 -> j is the current column, and by j + dj we check if the neighbor is in the board
                                                                                           // j+dj < w -> j is the current column, and by j + dj we check if the neighbor is in the board
                            n += board[i+di][j+dj];                                        // if the neighbor is in the board, we add 1 to the number of live neighbors
                        }
                                                                                           // so now we know how many live neighbors we have for a cell
                next[i][j] = (board[i][j] && (n == 2 || n == 3)) || (!board[i][j] && n == 3);  // in next is next state of the board after checking the number of live neighbors
                                                                                               // if the cell is alive and has 2 or 3 live neighbors, it stays alive
                                                                                               // if the cell is dead and has 3 live neighbors, it turns alive
            }
        }

        for (int i = 0; i < h; i++)                // we loop through the height of the board
            for (int j = 0; j < w; j++)                // for each row we loop through the width of the board
                board[i][j] = next[i][j];                // we update the board with the next state of the board
    }
    
    // Print
    for (int i = 0; i < h; i++) {                // we loop through the height of the board
        for (int j = 0; j < w; j++)                // for each row we loop through the width of the board
            putchar(board[i][j] ? '0' : ' ');                // if the cell is alive, we print a 0, otherwise we print a space
        putchar('\n');
    }
    return 0;
}
//
//111
//111
//111
//
