#include <stdio.h>

#define Max 100

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
}

int adjacent(Graph *G, int x, int y){
	if (G->A[x][y]==1) return 1;
		else return 0;
}

int degree(Graph *G, int x){
	int i;
	int count=0;
	for (i=1;i<=G->n;i++) if (G->A[i][x]==1) count++;
	return count;
}

// Stack

typedef struct {
	int A[Max];
	int top_idx;
}Stack;

void make_null_stack(Stack *S){
	S->top_idx=Max;
}

int empty(Stack *S){
	return S->top_idx==Max;
}

int top(Stack *S){
	return S->A[S->top_idx];
}

void pop(Stack *S){
	S->top_idx++;
}

void push(Stack *S, int x){
	S->top_idx--;
	S->A[S->top_idx]=x;
}

// Queue

//typedef struct {
//	int A[Max];
//	int F, R;
//}Queue;
//
//void make_null_queue(Queue *Q){
//	Q->F=0;
//	Q->R=-1;
//}
//
//void empty(Queue *Q){
//	return Q->F>Q->R;
//}
//
//int top(Queue *Q){
//	return Q->A[Q->F];
//}
//
//void pop(Queue *Q){
//	Q->F++;
//}
//
//void push(Queue *Q, int x){
//	Q->R++;
//	Q->A[Q->R]=x;
//}

void DFS(Graph *G, int n){
	
}

int main() {
	freopen("dt1.txt","r",stdin);
	Graph G;
	int n, m, i, x, y;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for (i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		add_edge(&G,x,y);
	}
	printf("Bac vao cua cac dinh: \n");
	for (i=1;i<=n;i++) printf("Dinh %d: %d\n",i,degree(&G,i));
	return 0;
}


