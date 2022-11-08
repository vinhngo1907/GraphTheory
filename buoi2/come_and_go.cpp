#include <stdio.h>
#include <conio.h>

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

void add_edge(Graph* pG, int x, int y, int z){
	if (z==1) pG->A[x][y]=pG->A[x][y]+1;
		else if (z==2) {
			pG->A[x][y]=pG->A[x][y]+1;
			pG->A[y][x]=pG->A[y][x]+1;
		}
}

int adjacent(Graph* pG, int x, int y){
	if (pG->A[x][y]!=0) return 1;
		else return 0;
}

int min(int a, int b){
	if (a>=b) return b;
		else return a;
}

/* Khai bao Stack */

typedef struct{
	int A[Max];
	int top_idx;
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

void push(Stack *S, int x){
	S->top_idx--;
	S->A[S->top_idx]=x;
}

/* Giai thuat Tarjan */

int num[Max_N];
int min_num[Max_N];
int on_stack[Max_N];
int k;
Stack S;
int dem;

void SCCs(Graph *G, int x){
	int i, tam;
	num[x]=min_num[x]=k++; push(&S,x); on_stack[x]=1;
	for (i=1;i<=G->n;i++) 
		if (adjacent(G,x,i))
		{
			if (num[i]<0) 
			{
				SCCs(G,i);
				min_num[x]=min(min_num[x], min_num[i]);
			}
			else if (on_stack[i]) min_num[x]=min(num[i], min_num[x]);
		}
	if (min_num[x]==num[x]){
		dem++;
		do{
			tam=top(&S); pop(&S);
			on_stack[tam]=0;
			printf("%d \n",tam);
		} while (tam!=x);
	} 
}

int main(){
	freopen("duyet-do-thi.txt","r",stdin);
	Graph G;
	int i, m, n, x, y, z, e, f, g;
	scanf("%d%d",&n,&m);
	init_graph(&G,n,m);
	for (i=1;i<=G.m;i++) {
		scanf("%d%d",&x, &y, &z);
		add_edge(&G,x,y,z);
	}
	for (e=1;e<=G.n;e++) {
		num[e]=-1;
		on_stack[e]=0;
	}
	k=1;
	make_null_stack(&S);
	for (g=1;g<=G.n;g++) if (num[g]==-1) SCCs(&G,g);	
	if(dem>1) printf("NO"); else printf("OKIE"); 
	printf("\n%d",dem);
	return 0;
}

