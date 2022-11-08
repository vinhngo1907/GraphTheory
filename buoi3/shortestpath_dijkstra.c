#include <stdio.h>

/* Dinh - Dinh */

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

int pi[Max_N], p[Max_N], mark[Max_N];

// Lap {
// Buoc 1: Chon dinh x co pi[x] nho nhat chua duyet
// Buoc 2: Danh dau x da duoc duyet
// Buoc 3: Cap nhat pi cac dinh ke CHUA DUYET cua x
// }

void Dijkstra(Graph *G, int s){ // CHU Y CACH DAT BIEN
	int u, j, v, Min_pi, big, i;
	for (i=1;i<=G->n;i++){ // Khoi tao
		pi[i]=INF;
		mark[i]=0;
	}
	pi[s]=0;
	p[s]=-1;
	for (big=1;big<=G->n;big++){ //Lap
		Min_pi=INF;
		for (j=1;j<=G->n;j++) // Buoc 1
			if (mark[j]==0 && pi[j]<Min_pi) {
				Min_pi=pi[j];
				u=j;
			}	
		mark[u]=1; // Buoc 2
		for (v=1;v<=G->n;v++) // Buoc 3
			if (adjacent(G,u,v) && mark[v]==0){
				if (pi[v]> pi[u]+G->L[u][v]) {
					pi[v]= pi[u]+G->L[u][v];
					p[v]=u;
			}
		}
	}
}


int main() {
	freopen("dt.txt","r",stdin);
	Graph G;
	int x, y, n, m, l, i, j, k, s, t;
	scanf("%d%d",&n, &m);
	init_graph(&G,n);
	for (i=1;i<=m;i++){
		scanf("%d %d %d",&x,&y,&l);
		add_edge(&G,x,y,l);
	}
//	scanf("%d%d",&s,&t);
	Dijkstra(&G,1);
	printf("%d",pi[n]);
	return 0;
}


