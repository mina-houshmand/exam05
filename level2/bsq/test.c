#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
int rows;
int cols;
char empty;
char obs;
char fill;
char **grid;
} Map;


int min(int a, int b, int c){
	return (a < b ? (a < c ? a : c) : (b < c ? b : c));

}
void free_map(Map *m){
	if (!m)
		return;
	for (int i = 0; i < m->rows; i++){
		free(m->grid[i]);
	}
	free(m->grid);
	free(m);
}

int validate(const Map *m){
	if (!m || m->rows < 1 || m->cols < 1)
		return 0;
	if (m->empty == m->obs || m->empty == m->fill || m->obs == m->fill)
		return 0;
	for (int i = 0; i < m->rows; i++){
		for (int j = 0; j < m->cols; j++)
			if (m->grid[i][j] != m->empty && m->grid[i][j] != m-> obs)
				return 0;
	}
	return 1;
}

Map *read_map(const char *av){     //const
	FILE *f = av ? fopen(av, "r") : stdin;
	if (!f)
		return NULL;
	Map *m = calloc(1, sizeof(Map));
	if (fscanf(f, "%d %c %c %c\n", &m->rows, &m->empty, &m->obs, &m->fill) != 4)
		goto err;
	m->grid = malloc(m->rows * sizeof(char*));
	
	for (int i = 0; i < m->rows; i++){
		size_t len = 0;
		if(getline(&m->grid[i], &len, f) < 0)
			goto err;
		
		int collen = 0;
		while (m->grid[i][collen] && m->grid[i][collen] != '\n')
			collen++;
		m->grid[i][collen] = '\0';
		
		if (!i)
			m->cols = collen;
		else if (m->cols != collen)
			goto err;
	}
	if (f != stdin)
		fclose(f);
	return m;
err:
	if(f != stdin)
		fclose(f);
	free_map(m);
	return NULL;
}


void solve(Map *m){

int R = m->rows;
int C = m->cols;
int **dp = calloc(R , sizeof(*dp));

for (int i = 0; i < R; i++){   //only one for
		dp[i] = calloc(C, sizeof(*dp[i]));
	}
	
int best = 0;
int bi = 0;
int bj = 0;

for (int i = 0; i < R; i++){
	for (int j = 0; j < C; j++){
		if (m->grid[i][j] == m->obs)   // this == 
			dp[i][j] = 0;
		else
			dp[i][j] =( i && j ?  min(dp[i -1][j], dp[i][j - 1], dp[i -1][j -1]) : 0) + 1;
	
		if (dp[i][j] > best){    //this part
			best = dp[i][j];
			bi = i;
			bj = j;
	}
}

for (int i =  bi - best  + 1; i <= bi; i++){   //bi - best + 1
	for(int j =  bj -best + 1; j <= bj; j++){
			m->grid[i][j] = m->fill;    //this
		}
		
	}
}
for (int i = 0; i < R; i++)   //this
		free(dp[i]);
	free(dp);

}

void process(char *av){
	Map *m = read_map(av);
	if (!m || !validate(m)){
		fprintf(stderr, "map failed\n");
		free(m);
		return;
	}
	solve(m);
	for (int i = 0; i < m->rows; i++)
		fprintf(stdout, "%s\n", m->grid[i]);
	free_map(m);
}

int main(int ac, char **av){
	if (ac < 2)
		process(NULL);
	else{
		for (int i = 1; i < ac; i++)    //i = 1
			process(av[i]);
	}
	return 0;
}


//free_map 3 use => 2 in process one in err:
//free 5 use => 3 in free_map 2 in solve
