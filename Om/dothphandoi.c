#include <stdio.h>

#define Max 100

// Bieu dien ma tran
typedef struct {
	int n;
	int A[Max][Max];
}Graph;

void init_graph(Graph *G, int n){
	int i, j;
	G->n=n;
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			G->A[i][j]=0;
}

void add_edge(Graph *G, int x, int y){
	G->A[x][y]=1;
	G->A[y][x]=1;
}

int color[Max];
int conflict;

#define Blue 1
#define Red 0
#define White -1

void colorize(Graph *G, int x, int c){
	int i;
	
	color[x]=c;
	for (i=1;i<=G->n;i++) if (G->A[x][i]==1){
		if (color[i]==c){
			conflict=1;
			return;
		}
		if (color[i]==White) colorize(G,i,!c);
	}
}

int main() {
	freopen("dt1.txt","r",stdin);
	int n, m, i, x, y;
	Graph G;
	
	scanf("%d%d",&n, &m);
	init_graph(&G,n);
	for (i=1;i<=m;i++){
		scanf("%d%d",&x, &y);
		add_edge(&G,x,y);
	}
	conflict=0;
	for (i=1;i<=m;i++) color[i]=White;
//	for (i=1;i<=m;i++) if(color[i]==White) 
	colorize(&G,1,Blue);
	if (conflict) printf("Co conflict!");
		else printf("Khong co conflict!");

	return 0;
}


