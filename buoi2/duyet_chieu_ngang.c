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
	int n, m;
	int A[Max_N][Max_N];
}Graph;

void init_graph(Graph* pG, int n, int m){
	int i, j;
	pG->n=n;
	pG->m=m;
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

/* Khai bao Queue */

typedef struct {
	ElementType Data[Max];
	int Front, Rear;
}Queue;

void make_null_queue(Queue *Q){
	Q->Front=0;
	Q->Rear=-1;
}

int empty(Queue *Q){
	return (Q->Front>Q->Rear);
}

ElementType top(Queue *Q){
	return Q->Data[Q->Front];
}

void pop(Queue *Q){
	Q->Front++;
}

void push(Queue *Q, ElementType x){
	Q->Rear++;
	Q->Data[Q->Rear]=x;
}

/* Khai bao List */
typedef struct{
	ElementType Data[Max_N];
	int size;
}List;

void make_null(List *L){
	L->size=0;
}

ElementType element_at(List *L, int i){
	return L->Data[i-1];
}

void push_back(List *L, ElementType x){
	L->Data[L->size]=x;
	L->size++;
}

List neighbors(Graph *pG, int x){
	List L;
	int i;
	make_null(&L);
	for (i=1;i<=pG->n;i++) if (adjacent(pG,x,i)) push_back(&L,i);
	return L;
}


/* Duyet do thi */

void BFS(Graph *G, int var){
	Queue Q;
	int i, j, a, e;
	List L;
	ElementType y;
	int mark[Max_N];

	for (i=1;i<=G->n;i++) mark[i]=0;
	make_null_queue(&Q);

	mark[var]=1; printf("%d\n",var); push(&Q,var);
	while(!empty(&Q)){
		a=top(&Q); pop(&Q);
		L=neighbors(G,a);
		for (j=1;j<=L.size;j++){
			y=element_at(&L,j);
			if (mark[y]==0) {
				printf("%d\n",y);
				mark[y]=1;
				push(&Q,y);
			}
		}
	}
	for (e=1;e<=G->n;e++) if (mark[e]==0) {
		make_null_queue(&Q);
		mark[e]=1; printf("%d\n",e); push(&Q,e);
		while(!empty(&Q)){
			a=top(&Q); pop(&Q);
			L=neighbors(G,a);
			for (j=1;j<=L.size;j++){
				y=element_at(&L,j);
				if (mark[y]==0) {
					printf("%d\n",y);
					mark[y]=1;
					push(&Q,y);
				}
			}
		}
	}
}

int main(){
	freopen("duyet-do-thi.txt","r",stdin);
	Graph G;
	int i, m, n, x, y;
	scanf("%d%d",&n,&m);
	init_graph(&G,n,m);
	for (i=1;i<=G.m;i++) {
		scanf("%d%d",&x, &y);
		add_edge(&G,x,y);
	}
	BFS(&G,1);
	return 0;
}
