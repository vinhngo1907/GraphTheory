#include <stdio.h>
#include <conio.h>

#define Max 50
#define Max_N 100

/* Kieu bieu dien do thi: Dinh - Dinh */

typedef struct {
	int n;
	int A[Max_N][Max_N];
}Graph;

void init_graph(Graph* pG, int n){
	int i, j;
	pG->n=n;
	for (i=1;i<=pG->n;i++)
		for (j=1;j<=pG->n;j++) pG->A[i][j]=0;
}

void add_edge(Graph* pG, int x, int y){
	pG->A[x][y]=pG->A[x][y]+1;
	pG->A[y][x]=pG->A[y][x]+1;
}

int adjacent(Graph* pG, int x, int y){
	if (pG->A[x][y]!=0) return 1;
		else return 0;
}


typedef struct {
	int u;
	int parent;
}ElementType;

typedef struct{
	ElementType A[Max];
	int size;
}Stack;

void make_null_stack(Stack *S){
	S->size=Max;
}

void push(Stack *S, int x, int par){
	S->A[S->size-1].u=x;
	S->A[S->size-1].parent=par;
	S->size--;
}

ElementType top(Stack *S){
	return S->A[S->size];
}

void pop(Stack *S){
	S->size++;
}

int empty(Stack *S){
	return (S->size==Max);
}

/* Duyet do thi */

void DFS(Graph *G){
	Stack S;
	make_null_stack(&S);
	int mark[Max_N];
	int parents[Max_N];
	int i, j, y, e, f;
	ElementType x;
	ElementType Z[Max_N];
	for (i=1;i<=G->n;i++) mark[i]=0;
	
	push(&S,1,0); parents[1]=0;
	while(!empty(&S)){
		x=top(&S); pop(&S);
		if(mark[x.u]==1) continue;
		mark[x.u]=1; parents[x.u]=x.parent;
		for (j=1;j<=G->n;j++) if (adjacent(G,x.u,j)) {
			parent[j]=x;
			push(&S,j,x.u);
		}
	}
	for (e=2;e<=G->n;e++) if (mark[e]==0) {
		make_null_stack(&S);
		push(&S,e,parv);
		while(!empty(&S)){
			x=top(&S); pop(&S);
			if(mark[x.u]==1) continue;
			mark[x.u]=1; x.parent=parv; parents[x.u]=x.parent;
			for (j=1;j<=G->n;j++) if (adjacent(G,x.u,j)) push(&S,j,x.u);
		}
	}
	for (f=1;f<=G->n;f++) printf("%d %d\n", f, parents[f]);	
}

int main(){
	Graph G;
	int n, m, i, j, x, y, k, l;
	freopen("duyet-do-thi.txt", "r", stdin);
	scanf("%d",&n);
	init_graph(&G,n);
	scanf("%d",&m);
	for (i=1;i<=m;i++){
		scanf("%d%d",&x, &y);
		add_edge(&G,x,y);
	}
	DFS(&G,1,0);
	return 0;
}

