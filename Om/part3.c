#include <stdio.h>

#define Max 100

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

typedef struct {
	int A[Max];
	int top_idx;
}Stack;

void make_null_stack(Stack *S){
	S->top_idx=Max;
}

int empty(Stack *S){
	return S->A[S->top_idx]==Max;
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

int num[Max];
int min_num[Max];
int on_stack[Max];
int k;
Stack S;
int dem;
int parent[Max];

void SCCs(Graph *G, int x, int pa){
	int i, w, count=0;
	num[x]=k; min_num[x]=k; k++;
	push(&S,x); on_stack[x]=1;
	parent[x]=pa;
	for (i=1;i<=G->n;i++) if (adjacent(G,x,i))
		if (num[i]<0){
			SCCs(G,i,x);
			min_num[x]=min(min_num[x], min_num[i]);
		}	else if (on_stack[i]) min_num[x]=min(num[i],min_num[x]);
	if (min_num[x]==num[x]){
		dem++;
		do{
			w=top(&S);pop(&S);
			on_stack[w]=0;
			printf("%d\n",w);
			count++;
		}while(w!=x);
//		printf("Thanh phan lien thong manh thu %d co %d dinh",dem, count);
		printf("\n");
	}
}

int main() {
	freopen("dt.txt","r",stdin);
	Graph G;
	int i, j, n, m, x, y;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for (i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		add_edge(&G, x, y);
	}
	int e, g;
	for (e=1;e<=G.n;e++){
		num[e]=-1;
		on_stack[e]=0;
		parent[e]=-1;
	}
	k=1;
	dem=0;
	make_null_stack(&S);
	for (g=1;g<=G.n;g++) if (num[g]==-1) SCCs(&G,g,0);
	printf("Co %d bpltm!\n",dem);
	for (g=1;g<=G.n;g++) printf("Parent dinh %d: %d\n",g,parent[g]);
	return 0;
}


