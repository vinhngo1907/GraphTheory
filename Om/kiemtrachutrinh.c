#include <stdio.h>

#define Max 100

// Bieu dien ma tran
typedef struct {
	int n;
	int A[Max][Max];
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

int color[Max];
int cycle;

#define Grey 0
#define Black 1
#define White -1

void traversal(Graph *G, int x){ // co huong
	int i;
	
	color[x]=Grey;
	for (i=1;i<=G->n;i++) if (G->A[x][i]==1){
		if (color[i]==Grey){
			cycle=1;
			return;
		} else 
		if (color[i]=White) traversal(G,i);
	}
	color[x]=Black;
}

//void traversal(Graph *G, int x, int parent){ // vo huong
//	int i;
//	
//	color[x]=Grey;
//	for (i=1;i<=G->n;i++) if (G->A[x][i]==1){
//		if (i==parent) continue;
//		if (color[i]==Grey){
//			cycle=1;
//			return;
//		}
//		if (color[i]==White) traversal(G,i,x);
//	}
//	color[x]=Black;
//}

//void traversal(Graph *G, int x){
//	int i;
//	
//	if (mark[i]==1) return;
//	mark[i]=1;
//	for (i=1;i<=G->n;i++) if (G->A[x][i]==1 && mark)
//		traversal(G,i); 
//}

int main() {
	freopen("dt1.txt","r",stdin);
	int n, m, i, x, y;
	Graph G;
	
	scanf("%d%d",&n, &m);
	init_graph(&G,n);
	for (i=1;i<=m;i++){
		scanf("%d%d",&x, &y);
		add_edge(&G,x,y);
	}
	
	for (i=1;i<=m;i++) color[i]=White;
	cycle=0;
	traversal(&G,1);
	//Neu co nhieu bo phan lien thong, them 1 vong lap
	if (cycle==1) printf("Co chu trinh!");
		else printf("Khong co chu trinh!");
	
	return 0;
}


