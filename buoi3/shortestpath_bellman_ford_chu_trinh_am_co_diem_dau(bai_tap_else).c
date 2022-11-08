#include <stdio.h>

#define Max_N 100

typedef struct{
	int u, v, w;
}Edges;

typedef struct{
	Edges A[Max_N];
	int n, m;
}Graph;

void init_graph(Graph *G,  int n){
	G->n=n;
	G->m=0;
}

void add_edge(Graph *G, int u, int v, int w){
	G->A[G->m].u=u;
	G->A[G->m].v=v;
	G->A[G->m].w=w;
	G->m++; // Bat dau mang tu 0
}

#define INF 9999

int pi[Max_N], p[Max_N];
int negative;

void Bellman_Ford(Graph *G, int s){
	int i, j, big, u, v, w;
	for (i=1;i<=G->n;i++){
		pi[i]=INF;
	}
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
	for (j=0;j<G->m;j++){ //kiem tra chu trinh am
		u=G->A[j].u;
		v=G->A[j].v;
		w=G->A[j].w;
		if (pi[v]> pi[u]+w){
			negative=1;
			break;
		}
	}
}

int main(){
	freopen("dt.txt","r", stdin);
	Graph G;
	int n, m, x, y, w, i, s;
	scanf("%d%d",&n, &m);
	init_graph(&G,n);
	for (i=1;i<=m;i++){
		scanf("%d%d%d",&x, &y, &w);
		add_edge(&G,x,y,w);
	}
	scanf("%d",&s);
	negative=0;
	Bellman_Ford(&G,s);
	if(negative) printf("YES"); else printf("NO");
	return 0;
}


