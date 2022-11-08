#include <stdio.h>

#define Max 100

// Dinh - Dinh

typedef struct{
	int A[Max][Max];
	int n;
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

int adjacent(Graph *G, int x, int y){
	return (G->A[x][y]!=0);
}

int degree_in(Graph *G, int y){
	int i, count=0;
	for (i=1;i<=G->n;i++)
		if (G->A[i][y]==1) count++;
	return count;
}

int degree_out(Graph *G, int y){
	int i, count=0;
	for (i=1;i<=G->n;i++)
		if (G->A[y][i]==1) count++;
	return count;
}

// Danh sach

typedef struct{
	int Data[Max];
	int size;
}List;

void makenull_list(List *L){
	L->size=0;
}

void push_back(List *L, int x){
	L->size++;
	L->Data[L->size]=x;
}

int element_at(List *L, int i){
	return L->Data[i];
}

void copy_list(List *S1, List *S2){
	int i;
	makenull_list(S1);
	S1->size=S2->size;
	for (i=1;i<=S2->size;i++)
		S1->Data[i]=S2->Data[i];
}


int rank[Max];

void ranking(Graph *G){
	int i, j, k, y;
	int d[G->n]; //bac vao cua cac dinh
	List S1, S2;
	makenull_list(&S1);
	for (i=1;i<=G->n;i++) {
		d[i]=degree_in(G,i);
		if (d[i]==0) push_back(&S1,i);
	}
	k=0;
	while(S1.size!=0){
		makenull_list(&S2);
		for (i=1;i<=S1.size;i++){
			y=element_at(&S1,i);
			rank[y]=k;
			for (j=1;j<=G->n;j++)
				if (adjacent(G,y,j)){
					d[j]--;
					if (d[j]==0) push_back(&S2,j);
			}
		}
		k++;
		copy_list(&S1,&S2);
	}
}

int max(int a, int b){
	if (a>b) return a;
		else return b;
}

int min(int a, int b){
	if (a>b) return b;
		else return a;
}

int main(){
	freopen("t.txt", "r", stdin);
	Graph G;
	int time[Max];
	int i, j, x, y, n, m, temp, u;
	List L;
	int t[Max], T[Max];
	
	// Doc do thi
	scanf("%d",&n);
	init_graph(&G,n+2);
	time[n+1]=0;
	for (i=1;i<=n;i++){
		scanf("%d",&time[i]);
		scanf("%d",&temp);
		while (temp!=0){
			add_edge(&G,temp,i);
			scanf("%d",&temp);
		}
	}

			
	//Them cung giua cac dinh co bac vao = 0 voi alpha va bac ra = 0 vao beta
	for (i=1;i<=n;i++){
		if (degree_in(&G,i)==0) add_edge(&G,n+1,i);
		if (degree_out(&G,i)==0) add_edge(&G,i,n+2);
	}

	
	//Topo Sort
	for (i=1;i<=n;i++) rank[i]=-1;
	ranking(&G);
	makenull_list(&L);
	int te=0; 
	while(te<=G.n){
		for (i=1;i<=G.n;i++) if (rank[i]==te) push_back(&L,i);
		te++;
	}
	
	//Tinh t[]
	t[n+1]=0;
	for (i=2;i<=L.size;i++){
		u=element_at(&L,i);
		for (j=1;j<=G.n;j++) if (adjacent(&G,j,u)){
			t[u]=max(t[u],t[j]+time[j]);
		}
	}
	
	//Tinh T[]
	T[n+2]=t[n+2];
	for (i=L.size-1;i>=1;i--){
		u=element_at(&L,i);
		T[u]=999;
		for (j=1;j<=G.n;j++) if (adjacent(&G,u,j)){
			T[u]=min(T[u],T[j]-time[u]);
		}
	}
	
	//In
	printf("%d\n",t[n+2]);
	for (i=1;i<=G.n;i++) printf("%d-%d\n",t[i],T[i]);
	
	return 0;
}
