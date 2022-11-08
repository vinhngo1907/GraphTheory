#include <stdio.h>

#define Max 100

typedef struct {
	int u, v; 
}Edge;

typedef struct {
	Edge A[Max];
	int n, m;
}Graph;

void init_graph(Graph *G, int n){
	G->n=n;
	G->m=0;
}

void add_edge(Graph *G, int x, int y){
	G->A[G->m].u=x;
	G->A[G->m].v=y;
	G->m++;
}

int degree(Graph *G, int x){
	int i, count=0;
	for (i=0;i<G->m;i++) if (G->A[i].v==x) count++;
	return count;
}

int main() {
	freopen("dt1.txt","r",stdin);
	Graph G;
	int n, m, i, x, y;
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		add_edge(&G,x,y);
	}
	printf("Bac cua cac dinh: \n");
	for (i=1;i<=n;i++) printf("Dinh %d: %d\n",i,degree(&G,i));
	return 0;
}


