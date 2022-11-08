#include <stdio.h>
#include <conio.h>
#include <math.h> // ham tinh toan
#include <string.h> // ham lien quan den chuoi
#include <ctype.h> // ham upper, lower
#include <time.h> // ham random
#include <stdlib.h>

#define Max_N 100
#define Max_M 500

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
		if (pG->A[i][x]==1 && pG->A[i][y]==1) found=1;
//		if (pG->A[i][x]==2 && pG->A[i][y]==1) found=2;
	return found;
}
void neighbours(Graph *pG, int x){
	int i;
	for (i=1;i<=pG->n;i++) if (adjacent(pG,x,i)==1) printf("%d ",i);
}

int main(){
	freopen("buoi1-bai2.txt", "r", stdin);
	int n, m, i, j, x, y;
	Graph G;
	scanf("%d%d",&n, &m);
	init_graph(&G,n,m);
	for (i=1;i<=m;i++){
		scanf("%d%d",&x, &y);
		add_edge(&G, i, x, y);
	}
	for (j=1;j<=n;j++) printf("Degree(%d) = %d\n",j,degree(&G,j));
//	Graph G;
//	int n=7, m=9, j;
//	init_graph(&G,n,m);
//	add_edge(&G, 1, 1, 2);
//	add_edge(&G, 2, 1, 3);
//	add_edge(&G, 3, 1, 3);
//	add_edge(&G, 4, 3, 6);
//	add_edge(&G, 5, 1, 4);
//	add_edge(&G, 6, 3, 4);
//	add_edge(&G, 7, 5, 6);
//	add_edge(&G, 8, 5, 6);
//	add_edge(&G, 9, 4, 5);
//	for (j=1;j<=n;j++) printf("Degree(%d) = %d\n",j,degree(&G,j));
	return 0;
}
