#include <stdio.h>

#define Max 100

//List
typedef struct {
	int data[Max];
	int size;
}List;

void make_null(List *pL){
	pL->size=0;
}

void push_back(List *pL, int x){
	pL->size++;
	pL->data[pL->size]=x;
}

int element_at (List *pL, int p){
	return pL->data[p];
}

int size(List *pL){
	return pL->size;
}

typedef struct {
	int A[Max][Max];
	int n;
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

int adjacent(Graph *G, int x, int y){
	return G->A[x][y]==1;	
}

int mark[Max];
List L;

void traversal(Graph *G, int x){
	int i;
	if (mark[x]==1) return;
	mark[x]=1;
	for (i=1;i<=G->n;i++) if (adjacent(G,x,i)) traversal(G,i);
}

void duyet(Graph *G, int x){
	int i;
	for (i=1;i<=G->n;i++) mark[i]=0;
	traversal(G,x);
	make_null(&L);
	for (i=1;i<=G->n;i++) if (mark[i]==1) push_back(&L,i);
	printf("Bo phan lien thong chua dinh %d la: \n",x);
	for (i=1;i<=L.size;i++) printf("%d ",L.data[i]);
}

int main() {
	freopen("dt.txt","r",stdin);
	Graph G;
	int i, j, n, m, x, y, c;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for (i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		add_edge(&G, x, y);
	}
	duyet(&G,5);
	return 0;
}

