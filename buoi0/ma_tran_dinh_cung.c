#include <stdio.h>

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
	for (i=1;i<=pG->m;i++) if (pG->A[i][x]==1) count++;
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
	freopen("t.txt", "r", stdin);
	Graph pG;
	int n, m, i, x, y;
	scanf("%d%d",&n, &m);
	init_graph(&pG,n,m);
	for (i=1;i<=pG.m;i++) {
		scanf("%d%d",&x,&y);
		add_edge(&pG,i,x,y);
	}
	printf("Degree 7: %d\n",degree(&pG,7));
	printf("Adjacent 2 - 7: %d\n",adjacent(&pG,2,7));
	printf("Neighbours 1: "); neighbours(&pG,1);
	return 0;
}

