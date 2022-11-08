#include <stdio.h>
#include <conio.h>

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

int degree(Graph* pG, int x){
	int i, count=0;
	for (i=1;i<=pG->n;i++)  count=count+(pG->A[x][i]);
	return count;
}

int adjacent(Graph* pG, int x, int y){
	if (pG->A[x][y]!=0) return 1;
		else return 0;
}

void neighbours (Graph* pG, int x){
	int i;
	for (i=1;i<=pG->n;i++) if (pG->A[x][i]>1) printf("%d ",i);
}

/* Khai bao Queue */

//typedef struct {
//	ElementType Data[Max];
//	int Front, Rear;
//}Queue;
//
//void make_null_queue(Queue *Q){
//	Q->Front=0;
//	Q->Rear=-1;
//}
//
//int empty(Queue *Q){
//	return (Q->Front>Q->Rear);
//}
//
//ElementType top(Queue *Q){
//	return Q->Data[Q->Front];
//}
//
//void pop(Queue *Q){
//	Q->Front++;
//}
//
//int full(Queue *Q){
//	return (Q->Rear==Max-1 && Q->Front==0);
//}
//
//void push(Queue *Q, ElementType x){
//	Q->Rear++;
//	Q->Data[Q->Rear]=x;
//}

/* Khai bao stack */

typedef struct{
	ElementType A[Max];
	int size;
}Stack;

void make_null_stack(Stack *S){
	S->size=Max;
}

void push(Stack *S, ElementType x){
	S->A[S->size-1]=x;
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

/* Khai bao List */
typedef struct{
	ElementType Data[Max_N];
	int size;
}List;

void make_null(List *L){
	L->size=0;
}

void push_back(List *L, ElementType x){
	L->Data[L->size]=x;
	L->size++;
}

ElementType element_at(List *L, int i){
	return L->Data[i-1];
}

int L_Size(List *L){
	return L->size;
}

List neighbors(Graph *pG, int x){
	List L;
	int i;
	make_null(&L);
	for (i=1;i<=pG->n;i++) if (adjacent(pG,x,i)) push_back(&L,i);
	return L;
}

/* Duyet do thi */

void first_search(Graph *G){
	Stack frontier;
	List L;
	make_null_stack(&frontier);
	int mark[Max_N];
	int i, x, j, y;
	for (i=1;i<=G->n;i++) mark[i]=0;
	push(&frontier,1); mark[1]=1;
	while(!empty(&frontier)){
		x=top(&frontier); pop(&frontier);
		printf("Duyet %d \n",x);
		L=neighbors(G,x);
		for (j=1;j<=L.size;j++){
			y=element_at(&L,j);
			if (mark[y]==0){
				mark[y]=1;
				push(&frontier,y);
			}
		}
	}
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
	first_search(&G);
	return 0;
}

