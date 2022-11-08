#include <stdio.h>

#define Max_N 100

typedef struct {
	int data[Max_N];
	int size;
} List;

typedef struct {
	List adj[Max_N];
	int m, n; //m la cung, n la dinh
} Graph;

void make_null(List* pL){
	pL->size=0;
}

void push_back(List* pL, int x){
	pL->size++;
	pL->data[pL->size]=x;
}

int element_at(List* pL, int p){
	return pL->data[p];
}

int size(List* pL){
	return pL->size;
}

void init_graph(Graph* pG, int n, int m){
	int i;
	pG->m=m;
	pG->n=n;
	for (i=1;i<=n;i++) make_null(&pG->adj[i]);
}

void add_edge(Graph* pG, int x, int y){
	push_back(&pG->adj[x],y);
	push_back(&pG->adj[y],x);
}

int degree(Graph* pG, int x){
	return size(&pG->adj[x]);
}

int adjacent(Graph* pG, int x, int y){
	int i, found=0;
	for (i=1;i<=size(&pG->adj[x]);i++) if (element_at(&pG->adj[x],i)==y) found=1;
	return found;
}

void neighbours (Graph* pG, int x){
	int i;
	for (i=1;i<=size(&pG->adj[x]);i++) printf("%d ",element_at(&pG->adj[x],i));
}

int main() {
	freopen("t.txt", "r", stdin);
	Graph pG;
	int n, m, i, x, y;
	scanf("%d%d",&n, &m);
	init_graph(&pG,n,m);
	for (i=1;i<=pG.m;i++) {
		scanf("%d%d",&x,&y);
		add_edge(&pG,x,y);
	}
	printf("Degree 7: %d\n",degree(&pG,7));
	printf("Adjacent 3-7: %d\n",adjacent(&pG,3,7));
	printf("Neighbours 1: "); neighbours(&pG,1);
	return 0;
}


