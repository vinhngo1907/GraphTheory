#include <stdio.h>

#define MAXN 1000
#define NO_EDGE 0
#define INFI 999999
///hoac gia tri dac biet nao do
typedef struct {
    int n;
    int L[MAXN][MAXN];
}Graph;
void init_graph(Graph* G, int n){
    G->n=n;
    int i,j;
    for(i=1;i<=G->n;i++)
        for(j=1;j<=G->n;j++)
            G->L[i][j]=NO_EDGE;
}
void add_edge(Graph* G, int u, int v, int w){
	G->L[u][v]=w;
}
int pi[MAXN][MAXN];
int next[MAXN][MAXN];
void Floyd_Warshall(Graph* G){
    int u,v,k;
    for(u=1;u<=G->n;u++)
        for(v=1;v<=G->n;v++){
            pi[u][v]=INFI;
            next[u][v]=-1;
        }
    for(u=1;u<=G->n;u++)
        pi[u][u]=0;
    
    for(u=1;u<=G->n;u++)
        for(v=1;v<=G->n;v++)
            if(G->L[u][v]!=NO_EDGE){
                pi[u][v]=G->L[u][v];
                next[u][v]=v;
            }
	for(k=1;k<=G->n;k++)
	    for(u=1;u<=G->n;u++)
	        for(v=1;v<=G->n;v++)
	                if(pi[u][k]+pi[k][v]<pi[u][v]){
	                    pi[u][v]=pi[u][k]+pi[k][v];
	                    next[u][v]=next[u][k];
	                }
}

int main(){
    Graph G;
    freopen("dt.txt","r",stdin);
    int n,m,u,v,i,w,s;
    scanf("%d%d",&n,&m);
    init_graph(&G, n);
    for(i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        add_edge(&G, u, v, w);
    }
    Floyd_Warshall(&G);

	for(u=1;u<=n;u++)
		for(v=1;v<=n;v++)
		printf("%d -> %d: %d\n",u,v,pi[u][v]);
	return 0;
}
