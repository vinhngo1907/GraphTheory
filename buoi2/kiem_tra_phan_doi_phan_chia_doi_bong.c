#include <stdio.h>
#include <conio.h>

#define ElementType int
#define Max 50
#define Max_N 100

typedef struct {
	int n, m;
	int A[Max_N][Max_N];
}Graph;

void init_graph(Graph* pG, int n, int m){
	int i, j;
	pG->n=n;
	pG->m=m;
	for (i=1;i<=pG->n;i++)
		for (j=1;j<=pG->n;j++) pG->A[i][j]=0;
}

void add_edge(Graph* pG, int x, int y){
	pG->A[x][y]=pG->A[x][y]+1;
	pG->A[y][x]=pG->A[y][x]+1;
}

int adjacent(Graph* pG, int x, int y){
	if (pG->A[x][y]!=0) return 1;
		else return 0;
}

#define WHITE -1
#define BLUE 0
#define RED 1

int color[Max_N];
int conflict;

void colorize(Graph *G, int x, int c){
	int i;
	color[x]=c; 
	for (i=1;i<=G->n;i++) if(adjacent(G,x,i)) {
		if (color[i]==WHITE) colorize(G,i,!c);
		 else if (color[i]==c) {
			conflict=1;
			return;
		}
	}
}

int main(){
	freopen("duyet-do-thi.txt","r",stdin);
	Graph G;
	int i, m, n, x, y, e, f;
	scanf("%d%d",&n,&m);
	init_graph(&G,n,m);
	for (i=1;i<=G.m;i++) {
		scanf("%d%d",&x, &y);
		add_edge(&G,x,y);
	}
	conflict=0;
	for (e=1;e<=G.n;e++) color[e]=WHITE;
	colorize(&G,1,BLUE);
	if (conflict==1) printf("IMPOSSIBLE"); else {
		for (f=1;f<=G.n;f++) if(color[f]==BLUE) printf("%d ",f);
		printf("\n");
		for (f=1;f<=G.n;f++) if(color[f]==RED) printf("%d ",f);
	}
	return 0;
}
