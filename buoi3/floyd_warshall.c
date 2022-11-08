#include <stdio.h>

// Dinh - Dinh

#define Max_N 100
#define NO_EDGE -1
#define INF 999

typedef struct{
	int n;
	int L[Max_N][Max_N];
}Graph;

void init_graph(Graph *G, int n){
	int i, j;
	G->n=n;
	for (i=1;i<=G->n;i++)
		for (j=1;j<=G->n;j++)
			G->L[i][j]=NO_EDGE;
}

void add_edge(Graph *G, int x, int y, int len){
	G->L[x][y]=len;
//	G->L[y][x]=len; // bo dong nay neu la do thi co huong
}

int adjacent(Graph *G, int x, int y){
	return G->L[x][y]!=NO_EDGE;
}

int pi[Max_N][Max_N];
int next[Max_N][Max_N];

void Floyd_Warshall(Graph *G){
	int u, v, big;
	for (u=1;u<=G->n;u++)
		for (v=1;v<=G->n;v++){
			pi[u][v]=INF;
			next[u][v]=-1;
		}
	for (u=1;u<=G->n;u++) 
		pi[u][u]=0;
	for (u=1;u<=G->n;u++)
		for (v=1;v<=G->n;v++) 
			if (adjacent(G,u,v)){
				pi[u][v]=G->L[u][v];
				next[u][v]=v;
			}
	for (big=1;big<=G->n;big++)
		for (u=1;u<=G->n;u++)
			for (v=1;v<=G->n;v++)
				if (pi[u][v]>pi[u][big]+pi[big][v]){
					pi[u][v]=pi[u][big]+pi[big][v];
					next[u][v]=next[big][v];
				}
}

int main(){
	freopen("dt.txt","r",stdin);
	Graph G;
	int n, m, x, y, l, i, u, v;
	scanf("%d%d",&n, &m);
	init_graph(&G,n);
	for (i=1;i<=m;i++){
		scanf("%d%d%d",&x, &y, &l);
		add_edge(&G,x,y,l);
	}
	Floyd_Warshall(&G);		
	for (u=1;u<=n;u++)
			for (v=1;v<=n;v++)
				if (pi[u][v]>=INF-10) printf("%d -> %d: oo\n",u,v);
					else printf("%d -> %d: %d\n",u,v,pi[u][v]);
	return 0;
}
