#include <stdio.h>
#include <conio.h>
#include <math.h> // ham tinh toan
#include <string.h> // ham lien quan den chuoi
#include <ctype.h> // ham upper, lower
#include <time.h> // ham random
#include <stdlib.h>

#define ElementType int
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

/* Stack */

typedef struct{
	int A[Max];
	int top_idx;
	int parent[Max];
}Stack;

void make_null_stack(Stack *S){
	S->top_idx=Max;
}

int empty(Stack *S){
	return (S->top_idx==Max);
}

int top(Stack *S){
	return S->A[S->top_idx];
}

void pop(Stack *S){
	S->top_idx++;
}

int top_pa(Stack *S){
	return S->parent[S->top_idx];
} 

void push(Stack *S, int x, int pa){
	S->top_idx--;
	S->A[S->top_idx]=x;
	S->parent[S->top_idx]=pa;
}

int parent[Max_N];

/* Duyet do thi */

void DFS(Graph *G, int var){
	Stack S;
	make_null_stack(&S);
	int mark[Max_N];
	int i, x, j, y, e, k;
	for (i=1;i<=G->n;i++) mark[i]=0;
	
	push(&S,var,0); parent[var]=0;
	while(!empty(&S)){
		x=top(&S); k=top_pa(&S); pop(&S);
		if(mark[x]==1) continue;
		mark[x]=1;
		parent[x]=k;
		for (j=1;j<=G->n;j++) if (adjacent(G,x,j)) push(&S,j,x);
	}
	for (e=2;e<=G->n;e++) 
		if (mark[e]==0) {
		make_null_stack(&S);
		push(&S,e,0); parent[e]=0;
		while(!empty(&S)){
			x=top(&S); k=top_pa(&S); pop(&S);
			if(mark[x]==1) continue;
			mark[x]=1;
			parent[x]=k;
			for (j=1;j<=G->n;j++) if (adjacent(G,x,j)) push(&S,j,x);
		}
	}	
}

int main(){
	Graph G;
	int n, m, i, j, x, y, k, l;
	freopen("duyet-do-thi-1.txt", "r", stdin);
	scanf("%d",&n);
	init_graph(&G,n);
	scanf("%d",&m);
	for (i=1;i<=m;i++){
		scanf("%d%d",&x, &y);
		add_edge(&G,x,y);
	}
	DFS(&G,1);
	for (j=1;j<=G.n;j++) printf("%d %d\n",j, parent[j]);
	return 0;
}


