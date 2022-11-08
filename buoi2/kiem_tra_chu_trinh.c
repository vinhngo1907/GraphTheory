#include <stdio.h>
#include <conio.h>

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

int degree(Graph* pG, int x){
	int i, count=0;
	for (i=1;i<=pG->n;i++)  count=count+(pG->A[x][i]);
	return count;
}

int adjacent(Graph* pG, int x, int y){
	if (pG->A[x][y]!=0) return 1;
		else return 0;
}

#define WHITE -1
#define GREY 0
#define BLACK 1

int color[Max_N];
int cycle;

void visit(Graph *G, int u, int parent){
	color[u]=GREY;
	int v;
	for (v=1;v<=G->n;v++) 
		if (adjacent(G,v,u)){
			if (v==parent) continue;
		 	if (color[v]==GREY) {
		 		cycle=1;
		 		return;
			}
			if (color[v]==WHITE) visit(G,v,u);
	}
	color[u]=BLACK;
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
	for (e=1;e<=G.n;e++) color[e]=WHITE;
	cycle=0;
	for (f=1;f<=G.n;f++) if (color[f]==WHITE) visit(&G,f,0);
	if (cycle) printf("YES"); else printf("NO");
	return 0;
}

