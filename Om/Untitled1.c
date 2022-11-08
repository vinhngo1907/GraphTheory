#include <stdio.h>
#define Max_N 100
#define Max 100
typedef struct {
	int n;
	int A[100][100];
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

int min(int a, int b){
	if (a>b) return b;
		else return a;
}

int num[Max_N];
int min_num[Max_N];
int on_stack[Max_N];
int k;
Stack S;
int dem;

void SCCs(Graph *G, int x){
	int i, w;
	num[x]=k; min_num[x]=k; k++; push(&S,x); on_stack[x]=1;
//	printf("SCC %d\n",x);
	for (i=1;i<=G->n;i++) 
		if (adjacent(G,x,i))
			if (num[i]<0) {
				SCCs(G,i);
				min_num[x]=min(min_num[x], min_num[i]);
			} else if (on_stack[i]) min_num[x]=min(num[i], min_num[x]);
//		printf("min_num[x]= %d, num[x]=%d, x=%d\n",min_num[x],num[x],x);
	if (min_num[x]==num[x]){
		dem++;
		do{
		 w=top(&S); pop(&S);
		 on_stack[w]=0;
//		 printf("%d \n",w);
		} while (w!=x);	
//		printf("----\n");
	}	
}

int main() {
	freopen("on.txt","r",stdin);
	Graph G;
	int i, n, m, x, y, s;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for (i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&s);
		if (s==1) add_edge(&G,x,y);
			else {
				add_edge(&G,x,y);
				add_edge(&G,y,x);
			}
	}
	int e, g, lt=1; 	
	for (e=1;e<=G.n;e++) {
		num[e]=-1;
		on_stack[e]=0;
	}
	k=1;
	make_null_stack(&S);
	SCCs(&G,1);
	for (g=1;g<=G.n;g++) if (num[g]==-1) lt=0;
	if (lt==1 && dem==1) printf("OKIE");
		else printf("NO");

	return 0;
}


