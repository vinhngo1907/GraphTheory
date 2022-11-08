#include <stdio.h>
#include <conio.h>
#include <math.h> // ham tinh toan
#include <string.h> // ham lien quan den chuoi
#include <ctype.h> // ham upper, lower
#include <time.h> // ham random
#include <stdlib.h>

#define Max_N 100

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

int main(){
	Graph G;
	int n, m, i, j, k, x, y;
	freopen("buoi1-bai4.txt", "r", stdin);
	scanf("%d",&n);
	init_graph(&G,n);
	scanf("%d",&m);
	for (i=1;i<=m;i++){
		scanf("%d%d",&x, &y);
		add_edge(&G,x,y);
	}
	for (j=1;j<=n;j++){
		for (k=1;k<=n;k++) if(adjacent(&G,k,j)) printf("1 ");else printf("0 ");
		printf("\n");
	}
	return 0;
}

