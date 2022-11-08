#include <stdio.h>

#define Max 100

typedef struct{
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
}

int adjacent(Graph *G, int x, int y){
	return (G->A[x][y]!=0);
}

int degree(Graph *G, int y){
	int i, count=0;
	for (i=1;i<=G->n;i++)
		if (adjacent(G,i,y)) count++;
	return count;
}

// List

typedef struct{
	int size;
	int Data[Max];
}List;

void makenull_list(List *L){
	L->size=0;
}

void push_back(List *L, int x){
	L->size++;
	L->Data[L->size]=x;
}

int element_at(List *L, int i){
	return L->Data[i];	
}

// Queue

typedef struct {
	int A[Max];
	int F, R;
}Queue;

int null(Queue *Q){
	return (Q->R<Q->F);
}

void makenull_queue(Queue *Q){
	Q->R=-1;
	Q->F=0;
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

void topo(Graph *G, List *T){
	int i, j, y, tem;
	int d[Max];
	Queue Q;
	makenull_queue(&Q);	
	for (i=1;i<=G->n;i++){
		d[i]=degree(G,i);
		if (d[i]==0) push(&Q,i);
	}
	while(!null(&Q)){
		y=top(&Q); pop(&Q);
		push_back(T,y);
		for (j=1;j<=G->n;j++)
		{
			if (adjacent(G,y,j))
			{
				d[j]--;
				if (d[j]==0) push(&Q,j);
			}
		}
	}
}

int main(){
	freopen("t2.txt","r",stdin);
	Graph G;
	int i, j, n, m, x, y;
	int temp=0;
	List T;	
	scanf("%d%d", &n, &m);
	init_graph(&G,n);
	for (i=1;i<=m;i++){
		scanf("%d%d",&x, &y);
		add_edge(&G,x,y);
	}
	makenull_list(&T);
	topo(&G, &T);
	for (j=1;j<=T.size;j++) printf("%d ",T.Data[j]);
	return 0;
}
