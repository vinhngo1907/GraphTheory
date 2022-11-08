#include <stdio.h>

#define Max_N 100

typedef struct{
	int A[Max_N][Max_N];
	int m, n;
}Graph;

void init_graph(Graph *G, int n,  int m){
	int i, j;
	G->m=m;
	G->n=n;
	for (i=1;i<=G->n;i++)
		for (j=1;j<=G->n;j++)
			G->A[i][j]=0;
}

void add_edge(Graph *G, int x, int y){
	G->A[x][y]=1;
	G->A[y][x]=1;
}

int adjacent(Graph *G, int x, int y){
	return (G->A[x][y]==1);
}

int color[Max_N];
int find;

#define WHITE -1
#define GREY 0
#define BLACK 1

void cycle(Graph *G, int u, int parent){
	int i;
	color[u]=GREY;
	for (i=1;i<=G->n;i++) if (adjacent(G,u,i)){
		if (i==parent) continue;
		if (color[i]==GREY) {
			find=1;
			return;
		}
		if (color[i]==WHITE) cycle(G,i,u);		
	}
	color[u]=BLACK;
}

int main() {
	freopen("duyet_do_thi.txt-1", "r", stdin);
	int n, m, x, y, i, j, k;
	Graph G;
	scanf("%d%d",&n, &m);
	init_graph(&G,n,m);
	for (i=1;i<=G.n;i++){
		scanf("%d%d",&x, &y);
		add_edge(&G,x,y);
	}
	printf("1 - 2 la %d",adjacent(&G,1,2));
	for (j=1;j<=G.n;j++) color[j]=WHITE;
	find=0;
	for (k=1;k<=G.n;k++) if (color[k]==WHITE) cycle(&G,k,0);
	if (find) printf("YES"); else printf("NO");
	return 0;
}


