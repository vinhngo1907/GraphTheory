#include <stdio.h>
#include <conio.h>
#include <math.h> // ham tinh toan
#include <string.h> // ham lien quan den chuoi
#include <ctype.h> // ham upper, lower
#include <time.h> // ham random
#include <stdlib.h>

#define Max_N 100

typedef struct {
	int m, n;
	int A[Max_N][Max_N];
}Graph;

void init_graph(Graph* pG, int n){
	int i, j;
	pG->n=n;
	pG->m=0;
	for (i=1;i<=pG->n;i++)
		for (j=1;j<=pG->n;j++) pG->A[i][j]=0;
}

void add_edge(Graph* pG, int x, int y){
	pG->A[x][y]=1;
	pG->A[y][x]=1;
}

int degree(Graph* pG, int x){
	int i, count=0;
	for (i=1;i<=pG->n;i++)  if (pG->A[x][i]==1) count++;
	return count;
}

int adjacent(Graph* pG, int x, int y){
	if (pG->A[x][y]==1) return 1;
		else return 0;
}

void neighbours (Graph* pG, int x){
	int i;
	for (i=1;i<=pG->n;i++) if (pG->A[x][i]==1) printf("%d ",i);
}

int main() {
	freopen("E:\\Study\\LTDT\\Om\\dt.txt","r",stdin);
	Graph pG;
	int n, x, y, m, i;
	scanf("%d",&n);
	init_graph(&pG,n);
	scanf("%d",&m);
	for (i=0;i<m;i++){
		printf("x, y: "); scanf("%d%d",&x, &y);
		add_edge(&pG,x,y);
	}
	printf("\nBac cua dinh 5: "); printf("%d",degree(&pG,5));
//	printf("\n6 va 3 co lien ket voi nhau: "); if (adjacent(&pG,3,7)==1) printf(" Co\n"); else printf("K\n");
//	printf("Neigh: "); neighbours(&pG,9);
	return 0;
}


