#include <stdio.h>

// Dinh - Dinh

#define Max_N 100
#define NO_EDGE -1
#define INF 999

//typedef struct{
//	int n;
//	int L[Max_N][Max_N];
//}Graph;
//
//void init_graph(Graph *G, int n){
//	int i, j;
//	G->n=n;
//	for (i=1;i<=G->n;i++)
//		for (j=1;j<=G->n;j++)
//			G->L[i][j]=NO_EDGE;
//}
//
//void add_edge(Graph *G, int x, int y, int len){
//	G->L[x][y]=len;
////	G->L[y][x]=len; // bo dong nay neu la do thi co huong
//}
//
//int adjacent(Graph *G, int x, int y){
//	return G->L[x][y]!=NO_EDGE;
//}

typedef struct{
	int u, v, w;
}edges;

typedef struct{
	edges A[Max_N];
	int n, m;
}Graph;

void initg(Graph *G, int n){
	G->n=n;
	G->m=0;
}

void adde(Graph *G, int u, int v, int w){
	G->A[G->m].u=u;
	G->A[G->m].v=v;
	G->A[G->m].w=w;
	G->m++;
}

int pi[Max_N], p[Max_N], mark[Max_N];

//void Dijkstra(Graph *G, int s){
//	int i, j, big, u, v, minpi;
//	for (i=1;i<=G->n;i++){
//		pi[i]=INF;
//		mark[i]=0;
//	}
//	pi[s]=0;
//	p[s]=-1;
//	for (big=1;big<G->n;big++){
//		minpi=INF;
//		for (j=1;j<=G->n;j++) if (mark[j]==0 && pi[j]<minpi) {
//			minpi=pi[j];
//			u=j;
//		}
//		mark[u]=1;
//		for (v=1;v<=G->n;v++) if (adjacent(G,u,v) && mark[v]==0){
//			if (pi[v]>pi[u]+G->L[u][v])
//				pi[v]=pi[u]+G->L[u][v];
//				p[v]=u;
//		}
//	}
//}

void BellFord(Graph *G, int s){
	int i, j, u, v, w, big;
	for (i=1;i<=G->n;i++) pi[i]=INF;
	pi[s]=0;
	p[s]=-1;
	for (big=1;big<G->n;big++){
		for (j=0;j<G->m;j++){
			u=G->A[j].u;
			v=G->A[j].v;
			w=G->A[j].w;
			if (pi[v]> pi[u]+w){
				pi[v]=pi[u]+w;
				p[v]=u;
			}
		}	
	}		
}

int main(){
	freopen("dt.txt","r", stdin);
	Graph G;
	int n, m, x, y, w, i, s, j;
//	scanf("%d%d",&n, &m);
//	init_graph(&G,n);
//	for (i=1;i<=m;i++){
//		scanf("%d%d%d",&x, &y, &w);
//		add_edge(&G,x,y,w);
//	}
//	Dijkstra(&G,1);
	scanf("%d%d",&n, &m);
	initg(&G,n);
	for (i=1;i<=m;i++){
		scanf("%d%d%d",&x, &y, &w);
		adde(&G,x,y,w);
	}
	BellFord(&G,1);	
	for (j=1;j<=n;j++) printf("Dinh %d co SP voi 1 la: %d\n",j,pi[j]);
	return 0;
}
