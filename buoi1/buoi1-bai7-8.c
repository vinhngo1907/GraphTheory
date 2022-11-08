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
	freopen("buoi1-bai4.txt", "r", stdin);
	Graph pG;
	int n, m, i, x, y, j, k, max, mark;
	scanf("%d%d",&n, &m);
	init_graph(&pG,n,m);
	for (i=1;i<=pG.m;i++) {
		scanf("%d%d",&x,&y);
		add_edge(&pG,x,y);
	}
	max=degree(&pG,1);
	mark=1;
	for (j=2;j<=n;j++) if (max<degree(&pG,j)) {
	    max=degree(&pG,j);
	    mark=j;
	}
	printf("%d %d",mark, max);
//	for (j=1;j<=n;j++) printf("Bac cua dinh %d la: %d\n",j,degree(&pG,j));
//	for (k=1;k<=n;k++){
//		printf("Cac dinh ke cua dinh %d la: ",k);
//		neighbours(&pG,k);
//		printf("\n");
//	} 
	return 0;
}
