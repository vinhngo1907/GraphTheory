#include <stdio.h>

#define Max 100

//Dinh - Dinh
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
}

int degree(Graph *G, int x){
	int i, count=0;
	for (i=1;i<=G->n;i++) if (G->A[i][x]==1) count++;
	return count;
}

//Danh sach cung
//typedef struct {
//	int u, v; 
//}Edge;
//
//typedef struct {
//	Edge A[Max];
//	int n, m;
//}Graph;
//
//void init_graph(Graph *G, int n){
//	G->n=n;
//	G->m=0;
//}
//
//void add_edge(Graph *G, int x, int y){
//	G->A[G->m].u=x;
//	G->A[G->m].v=y;
//	G->m++;
//}
//
//int degree(Graph *G, int x){
//	int i, count=0;
//	for (i=0;i<G->m;i++) if (G->A[i].v==x)
//		count++;
//	return count;
//}

int main() {
	freopen("dt1.txt","r",stdin);
	int m, n, i, j, x, y;
	Graph G;
	scanf("%d%d",&n, &m);
	init_graph(&G,n);
	for (i=1;i<=m;i++){
		scanf("%d%d",&x, &y);
		add_edge(&G,x,y);
	}
	for (j=1;j<=n;j++) printf("%d ",degree(&G,j));
	return 0;
}


