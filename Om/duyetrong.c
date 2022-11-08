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

//Queue
typedef struct{
	int A[Max];
	int F, R;
}Queue;

void make_null(Queue *Q){
	Q->F=0;
	Q->R=-1;
}

int empty(Queue *Q){
	return Q->F>Q->R;
}

int top(Queue *Q){
	return Q->A[Q->F];
}

void pop(Queue *Q){
	Q->F++;
}

void push(Queue *Q, int x){
	Q->R++;
	Q->A[Q->R]=x;
}

int mark[Max];

void BFS(Graph *G, int x){ //duyet roi dua vao

	int i, y;
	Queue Q;
	make_null(&Q);
	
	mark[x]=1;
	printf("%d ",x);
	push(&Q,x);
	
	while(!empty(&Q)){
		y=top(&Q); pop(&Q);
		for (i=1;i<=G->n;i++) if (G->A[y][i]==1 && mark[i]==0) {
			mark[i]=1;
			printf("%d ",i);
			push(&Q,i);
		}
	}
}

int main() {
	freopen("dt.txt","r",stdin);
	int n, m, i, x, y;
	Graph G;
	scanf("%d%d",&n, &m);
	init_graph(&G,n);
	for (i=1;i<=m;i++){
		scanf("%d%d",&x, &y);
		add_edge(&G,x,y);
	}
	for (i=1;i<=G.n;i++) mark[i]=0;
	for(i=1;i<=G.n;i++) if (mark[i]==0) BFS(&G,i);
	return 0;
}


