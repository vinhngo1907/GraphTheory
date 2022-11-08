#include <stdio.h>
#define ElementType int
#define Max 50
#define Max_N 100

/* Kieu bieu dien do thi: Dinh - Dinh */

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

int mark[Max_N];
int parent[Max_N];

void traversal(Graph *G, int x, int pa){
	int i;
	if (mark[x]==1) return;
	mark[x]=1;
	parent[x]=pa;
	for (i=1;i<=G->n;i++) if (adjacent(G,i,x)) traversal(G,i,x);
}

void duyet(Graph *G){
	int i, j;
	for (i=1;i<=G->n;i++) mark[i]=0;
	traversal(G,1,0);
	for (j=1;j<=G->n;j++) if (mark[j]==0) traversal(G,j,0);
}

int main(){
	freopen("duyet-do-thi.txt","r",stdin);
	Graph G;
	int i, m, n, x, y, e, j;
	scanf("%d%d",&n,&m);
	init_graph(&G,n,m);
	for (i=1;i<=G.m;i++) {
		scanf("%d%d",&x, &y);
		add_edge(&G,x,y);
	}
	duyet(&G);
	for (j=1;j<=G.n;j++) printf("%d %d\n",j, parent[j]);
	return 0;
}
