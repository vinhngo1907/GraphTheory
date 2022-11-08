#include <stdio.h>
#include <conio.h>
#include <math.h> // ham tinh toan
#include <string.h> // ham lien quan den chuoi
#include <ctype.h> // ham upper, lower
#include <time.h> // ham random
#include <stdlib.h>

#define Max_N 100
#define Max_M 500
#define ElementType int
typedef struct {
	int m, n; //n la dinh, m la cung
	int A[Max_M][Max_N];
} Graph;

void init_graph(Graph* pG, int n, int m){
	int i, j;
	pG->m=m;
	pG->n=n;
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++) pG->A[i][j]=0;
}
void add_edge(Graph *pG, int e, int x, int y){
	pG->A[e][x]=1;
	pG->A[e][y]=1;
//	if (x==y) pG->A[e][x]=2;
}
int degree(Graph *pG, int x){
	int i, count=0;
	for (i=1;i<=pG->m;i++) if (pG->A[i][x
	]==1) count++;
	return count;
}
int adjacent(Graph *pG, int x, int y){
	int i, found=0;
	for (i=1;i<=pG->m;i++)
		if (pG->A[i][x]==1 && pG->A[i][y]==1 && x!=y) found=1;
	return found;
}
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
List neighbors(Graph *G, int x){
	List L;
	int i;
	make_null(&L);
	for (i=1;i<=G->n;i++) if (adjacent(G,i,x)) push_back(&L,i);
	return L;
}
int main(){
	freopen("buoi1-bai1.txt", "r", stdin);
	int n, m, i, j, x, y, k, l;
	Graph G;
	scanf("%d%d",&n, &m);
	init_graph(&G,n,m);
	for (i=1;i<=m;i++){
		scanf("%d%d",&x, &y);
		add_edge(&G, i, x, y);
	}
	for (j=1;j<=n;j++){
		for (k=1;k<=n;k++) if(adjacent(&G,k,j)) printf("1 ");else printf("0 ");
		printf("\n");
	}
//	for (j=1;j<=n;j++) printf("Degree(%d) = %d\n",j,degree(&G,j));
	List L;
	for(k=1;k<=n;k++) {
		printf("Cac dinh ke cua dinh %d la: ",k);
		L=neighbors(&G,k);
		for (l=1;l<=L.size;l++) printf("%d ",element_at(&L,l));
		printf("\n");
	}
	//	Graph G;
//	int n=4, m=5, j;
//	init_graph(&G,n,m);
//	add_edge(&G, 1, 1, 2);
//	add_edge(&G, 2, 1, 3);
//	add_edge(&G, 3, 1, 3);
//	add_edge(&G, 4, 3, 4);
//	add_edge(&G, 5, 1, 4);
//	for (j=1;j<=n;j++) printf("Degree(%d) = %d\n",j,degree(&G,j));
	return 0;
}
