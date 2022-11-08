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

int mark[Max];

void traversal(Graph *G, int x){
	int i;
	if (mark[x]==1) return;
	mark[x]=1;
	printf("%d ",x);
	for (i=1;i<=G->n;i++) if (G->A[x][i]==1)
		traversal(G,i);
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
	
	for (i=1;i<=n;i++) mark[i]=0;
	for (i=1;i<=n;i++) if (mark[i]==0) traversal(&G,i);
	
	return 0;
}




