#include <stdio.h>
#include <conio.h>
#include <math.h> // ham tinh toan
#include <string.h> // ham lien quan den chuoi
#include <ctype.h> // ham upper, lower
#include <time.h> // ham random
#include <stdlib.h>

#define Max_N 50
#define ElementType int

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

List Neighbours(Graph *pG, int x){
	List L;
	int i;
	make_null(&L);
	for (i=1;i<=pG->n;i++) if (adjacent(pG,x,i)) push_back(&L,i);
	return L;
}

int main() {
	Graph G;
	int n, m, i, j, x, y, k, l;
	freopen("buoi1-bai4.txt", "r", stdin);
	scanf("%d",&n);
	init_graph(&G,n);
	scanf("%d",&m);
	for (i=1;i<=m;i++){
		scanf("%d%d",&x, &y);
		add_edge(&G,x,y);
	}
	for(j=1;j<=n;j++) printf("Degree(%d) = %d\n",j,degree(&G,j));
	List L;
	for(k=1;k<=n;k++) {
		printf("Cac dinh ke cua dinh %d la: ",k);
		L=Neighbours(&G,k);
		for (l=1;l<=L.size;l++) printf("%d ",element_at(&L,l));
		printf("\n");
	}
	return 0;
}


