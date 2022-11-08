#include <stdio.h>
#include <conio.h>
#include <math.h> // ham tinh toan
#include <string.h> // ham lien quan den chuoi
#include <ctype.h> // ham upper, lower
#include <time.h> // ham random
#include <stdlib.h>

#define Max_M 500

typedef struct {
	int u, v;
}Edge;

typedef struct {
	Edge edges[Max_M];
	int n,m;
}Graph;

void init_graph(Graph *pG, int n){
	pG->n=n;
	pG->m=0;
}

void add_edge(Graph *pG, int x, int y){
	Edge e;
	e.u=x; e.v=y;
	pG->edges[pG->m]=e;
	pG->m++;
}

int degree(Graph *pG, int x){
	int i, count=0;
	for (i=0;i<pG->m;i++) if (pG->edges[i].u==x || pG->edges[i].v==x) count++;
	return count;
}

int adjacent(Graph *pG, int x, int y){
	int i=0, found=0;
	while (i<pG->m){
		if (pG->edges[i].u==x && pG->edges[i].v==y) found=1;
			else if (pG->edges[i].u==y && pG->edges[i].v==x) found=1;
			i++;
	}
	return found;
}

void neighbours (Graph *pG, int x){
	int i;
	for (i=0;i<pG->m;i++)
		if (pG->edges[i].u==x) printf("%d ",pG->edges[i].v);
			else if(pG->edges[i].v==x) printf("%d ",pG->edges[i].u);
}

int main() {
	Graph pG;
	int n, x, y, m, i;
	scanf("%d",&n);
	init_graph(&pG,n);
	scanf("%d",&m);
	for (i=0;i<m;i++){
		printf("x, y: "); scanf("%d%d",&x, &y);
		add_edge(&pG,x,y);
	}
	printf("Bac cua dinh 7: "); printf("%d",degree(&pG,7));
	printf("\n6 va 3 co lien ket voi nhau: "); if (adjacent(&pG,3,7)==1) printf(" Co\n"); else printf("K\n");
	printf("Neigh: "); neighbours(&pG,5);
	return 0;
}


