#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <io.h>
#include <windows.h>
#define MAXVEX 50
#define INFINITY 32768
#define MAXL 20
#define MAXC 66

int visited[INFINITY];
int stack[INFINITY];
int count;

struct user //�������Ա�ʺ�����Ľṹ��
{
    char id[20];  //����Ա�ʺ�
    char passwd[20];  //����Ա����
    struct user *next;
};
typedef struct //����ص���Ϣ�Ľṹ��
{
    int No;    //У԰�ص����
    char name[20];    //У԰�ص���
    char description[200];  //�ص�����
}Vextype;
typedef struct //�ڽӾ���
{
    int arcs[MAXVEX][MAXVEX];   //�߼�
    Vextype vex[MAXVEX];        //���㼯
    int vexnum;                 //������Ŀ
    int arcnum;                 //����Ŀ
}AdjMatrix;
typedef struct //�������
{
    int point; //�õ��Ƿ���У԰�ص�
    char name[20]; //�õ�У԰�ص���
    int No; //�õ�У԰�ص����
}SchoolMap;
typedef struct Node
{
    int date;  //����Ԫ�ص�ֵ���洢�ص����
    struct Node *next;
}LinkQueueNode;
typedef struct
{
    LinkQueueNode *front; //ͷָ��
    LinkQueueNode *fear; //βָ��
}LinkQueue;

int IsEmpty(LinkQueue *Q) //�����п�
{
    if(Q->front == Q->fear)
        return 1;
    else
        return 0;
}
int InitQueue(LinkQueue *Q)//�ӵĳ�ʼ��
{
    Q->front = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if(Q->front != NULL) {
        Q->fear = Q->front;
        Q->front->next = NULL;
        return 1;
    }
    else {
        return 0;
    }
}
int EnterQueue(LinkQueue *Q, int x) //���
{
    LinkQueueNode *NewNode;
    NewNode = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if(NewNode != NULL) {
        NewNode->date = x;
        NewNode->next = NULL;
        Q->fear->next = NewNode;
        Q->fear = NewNode;
        return 1;
    }
    else {
        return 0;
    }
}
int DeleteQueue(LinkQueue *Q, int *x) //����
{
    LinkQueueNode *p;
    if(Q->front == Q->fear)
        return 1;
    p = Q->front->next;
    Q->front->next = p->next;
    if(Q->fear == p)
        Q->fear = Q->front;
    *x = p->date;
    free(p);
    return 1;
}

void Instruction1()
{
    system("cls");
    printf("\n\n");
    printf("\t\t\t\t|================================================|\n");
    printf("\t\t\t\t|*                                              *|\n");
    printf("\t\t\t\t|*    ***��ӭʹ�������ʵ��ѧ����У������***    *|\n");
    printf("\t\t\t\t|*                                              *|\n");
    printf("\t\t\t\t|*----------------------------------------------*|\n");
    printf("\t\t\t\t|*                                              *|\n");
    printf("\t\t\t\t|*     ��ӭ���������ʵ��ѧ����У�������������� *|\n");
    printf("\t\t\t\t|* ����ǵĵ���Сyou~ʲô������Է���ģ���֪���� *|\n");
    printf("\t\t\t\t|* ô�ߣ������·����ɶѽ������~~��Щ���ⶼ�Ѳ� *|\n");
    printf("\t\t\t\t|* ����Ŷ������������Բ鿴У԰ƽ��ͼ��Ϊ��չʾ *|\n");
    printf("\t\t\t\t|* У԰�ص������ֲ��������Բ�ѯĳ���ص����� *|\n");
    printf("\t\t\t\t|* ��Ϣ���Լ����ص������·��������·������� *|\n");
    printf("\t\t\t\t|* ����������ֻҪ�������⣬�Ҷ����Լ�ʱΪ���� *|\n");
    printf("\t\t\t\t|* ��~~��ľ�г���ҵĸо�>o< ��𣬸Ͽ�������� *|\n");
    printf("\t\t\t\t|* һ��Ҫ�ǵ�����~~����Сyou����Ϊ���ʴ���QWQ   *|\n");
    printf("\t\t\t\t|*                                              *|\n");
    printf("\t\t\t\t|*==============================================*|\n");
    printf("\n\n");
    printf("\n\t\t\t\t\t\t�����������...");
    getch();
}

void Instruction2()
{
    system("cls");
    printf("\n\n");
    printf("\t\t\t\t|================================================|\n");
    printf("\t\t\t\t|*                                              *|\n");
    printf("\t\t\t\t|*    ***��ӭʹ�������ʵ��ѧ����У������***    *|\n");
    printf("\t\t\t\t|*                                              *|\n");
    printf("\t\t\t\t|*----------------------------------------------*|\n");
    printf("\t\t\t\t|*                                              *|\n");
    printf("\t\t\t\t|*     ��ӭ���������ʵ��ѧ����У�������������� *|\n");
    printf("\t\t\t\t|* ����ǵĵ���Сyou~ʲô������Է���ģ���֪���� *|\n");
    printf("\t\t\t\t|* ô�ߣ������·����ɶѽ������~~��Щ���ⶼ�Ѳ� *|\n");
    printf("\t\t\t\t|* ����Ŷ������������Բ鿴У԰ƽ��ͼ��Ϊ��չʾ *|\n");
    printf("\t\t\t\t|* У԰�ص������ֲ��������Բ�ѯĳ���ص����� *|\n");
    printf("\t\t\t\t|* ��Ϣ���Լ����ص������·��������·������� *|\n");
    printf("\t\t\t\t|* ����������ֻҪ�������⣬�Ҷ����Լ�ʱΪ���� *|\n");
    printf("\t\t\t\t|* ��~~��ľ�г���ҵĸо�>o< ��Ϊ����Ա���㻹�� *|\n");
    printf("\t\t\t\t|* ��ָ���ң�������ӻ����ص㰡�����·�߰��� *|\n");
    printf("\t\t\t\t|* �Ȳ�����Ҳ������ע���µĹ���Ա�ʺţ��ǲ��Ǻ� *|\n");
    printf("\t\t\t\t|* �度��������Сyou����Ϊ���ʴ���QWQ           *|\n");
    printf("\t\t\t\t|*                                              *|\n");
    printf("\t\t\t\t|*==============================================*|\n");
    printf("\n\n");
    printf("\n\t\t\t\t\t\t�����������...");
    getch();
}

void Print(AdjMatrix *G)
{
    int i,count = 0;
    printf("\t\t\t\t|================================================|\n");
    printf("\t\t\t\t|*                                              *|\n");
    printf("\t\t\t\t|*    ***��ӭʹ�������ʵ��ѧ����У������***    *|\n");
    printf("\t\t\t\t|*                                              *|\n");
    printf("\t\t\t\t|*==============================================*|\n\n");
    for(i = 1; i <= G->vexnum; i++) {
        printf("    %d.%-8s\t",i,G->vex[i].name);
        count++;
        if(count == 7) {
            printf("\n");
            count = 0;
        }
    }
    printf("\n\n");
}

//�����ڽӾ��󴴽�����ͼ
int Create(AdjMatrix *G,SchoolMap M[MAXL][MAXC])
{
    int i,j,weight,m,n;

    FILE *fp1;
    fp1=fopen("·����Ϣ.txt","r");

    //��"·����Ϣ.txt"�ļ��ж�ȡУ԰ͼ�ľ�����Ŀ��·����Ŀ
    fscanf(fp1, "%d %d", &G->vexnum, &G->arcnum);

    //��ʼ���ڽӾ���
    for(i = 1; i <= G->vexnum; i++)
        for(j = 1; j<= G->vexnum; j++) {
            G->arcs[i][j] = INFINITY;
    }
    //��ȡ"·����Ϣ.txt"�ļ���������ż����룬����ֵ���ڽӾ���
    while(fscanf(fp1,"%d %d %d",&i,&j,&weight) != EOF) {
            G->arcs[i][j] = weight;
            G->arcs[j][i] = weight;
    }
    fclose(fp1);

    FILE *fp2;
    fp2 = fopen("�ص����.txt", "rt");

    //��"�ص����.txt"�ļ��ж�ȡУ԰ͼ�еľ�����������
    for(i = 1; i <= G->vexnum; i++) {
        G->vex[i].No = i;
        fscanf(fp2, "%s %d %d %s", G->vex[i].name,&m,&n,G->vex[i].description);
        M[m][n].point = 1;
        M[m][n].No = i;
        strcpy(M[m][n].name,G->vex[i].name);
    }
    fclose(fp2);
    return 1;
}

//��ʾ��ͼ
void Display(AdjMatrix *G,SchoolMap M[MAXL][MAXC])
{
    int i, j, m, n;
    system("cls");
    printf("\n\n");
    printf("\t\t\t\t|================================================|\n");
    printf("\t\t\t\t|*                                              *|\n");
    printf("\t\t\t\t|*      ***��ӭʹ�������ʵ��ѧ��������***      *|\n");
    printf("\t\t\t\t|*                                              *|\n");
    printf("\t\t\t\t|*==============================================*|\n\n");

    FILE *fp2;
    fp2=fopen("�ص����.txt","r");

    //��"�ص����.txt"�ļ��ж�ȡУ԰ͼ�еľ�����������
    for(i = 1; i <= G->vexnum; i++) {
        G->vex[i].No = i;
        fscanf(fp2, "%s %d %d %s", G->vex[i].name,&m,&n,G->vex[i].description);
        M[m][n].point = 1;
        strcpy(M[m][n].name, G->vex[i].name);

    }
    fclose(fp2);
    int count = 0;
    for(i = 1; i <= MAXL; i++) {
        printf("\t\t\t");
        for(j = 1; j <= MAXC; j++) {
            if(M[i][j].point == 1) {
                printf("%s",M[i][j].name);
                j += strlen(M[i][j].name);
                j--;
            }
            else{
                printf("`");
            }
        }
        printf("\n");
    }
    printf("\n      ********************************************У԰·���������***********************************************\n\n");
    //���������л����
    for(i = 1; i <= G->vexnum; i++) {
        for(j = 1; j <= G->vexnum; j++) {
            if(G->arcs[i][j] != INFINITY && G->arcs[i][j] != 0) {
                printf("      %-8s <---> %8s: %3d m  ",G->vex[i].name,G->vex[j].name,G->arcs[i][j]);
                count ++;
                if(count == 3) {
                    printf("\n");
                    count = 0;
                }
            }
        }
    }
    printf("\n\t\t\t\t\t\t�����������...");
    getch();
}

//�鿴��ͼ����
void Description(AdjMatrix *G)
{
    int i,j,choice;
    system("cls");
    printf("\n\n");
    Print(G);
    do{
        printf("\t\t\t\t\t������Ҫ��ѯ�ĵص����(��0����):");
        scanf("%d",&choice);
        if(choice == 0) break;
        if(choice < 0 || choice > G->vexnum)
            continue;
        printf("\n\t\t--->%s:%s\n",G->vex[choice].name,G->vex[choice].description);
        printf("\t\t\t\t\t�õص��·�����Ϊ:\n");
        for(i = 1; i <= G->vexnum; i++) {
            if(i == choice) { //���������иþ��������һ�еĸ���Ԫ��
                for(j = 1; j <= G->vexnum; j++) {
                    if(G->arcs[i][j] != INFINITY) { //�л����
                        printf("\t\t\t\t\t%-8s <---> %8s: %3d m\n", G->vex[i].name,G->vex[j].name,G->arcs[i][j]);
                    }
                }
            }
        }
        printf("\n\n");
    }while(1);
    printf("\n\t\t\t\t\t�����������...");
    getch();
}

void DFS(AdjMatrix *G, int m, int i, int end)
{
    int j,k;
    for(j = 1; j <= G->vexnum; j++){
        if(G->arcs[i][j] != INFINITY && visited[j] == 0) {
            visited[j] = 1;
            if(j == end) {
                count++;
                printf("��%d.",count);
                for(k = 1; k < m; k++) {
                    printf("%s->", G->vex[stack[k]].name);
                }
                printf("%s\n", G->vex[end].name);
                visited[j] = 0;
            }
            else {
                stack[m] = j;
                m++;
                DFS(G, m, j, end);
                m--;
                visited[j] = 0;
            }
        }
    }
}

//��ѯ���м�·��
void SearchDFS(AdjMatrix *G)
{
    int start, end;
    system("cls");
    printf("\n\n");
    Print(G);
    do{
        printf("\t\t\t\t\t������������:");
        scanf("%d",&start);
    }while(start<=0 || start>G->vexnum);
    do{
        printf("\t\t\t\t\t�������յ����:");
        scanf("%d",&end);
    }while(start<=0 || start>G->vexnum);
    printf("\n\t\t\t\t\t���ص�������·�����Ϊ:\n\n");
    int m = 2;
    memset(stack,0,INFINITY);
    memset(visited,0,MAXVEX);
    stack[1] = start;
    visited[start] = 1;
    DFS(G, m, start, end);
    printf("\n\t\t\t\t\t�����������...");
    memset(stack,0,INFINITY);
    memset(visited,0,MAXVEX);
    count = 0;
    getch();
}

int NextAdjVertex(AdjMatrix *G, int w, int v)
{
    int i, j;
    for(i = w+1;i < G->vexnum; i++) {
        if(G->arcs[v][i] != INFINITY) {
            j = i;
            return j;
        }
    }
    return -1;
}

void BFS(AdjMatrix *G, int start, int end)
{
    int vis[INFINITY];
    int i, num;
    int w, v;
    LinkQueue *Q;

    Q=(LinkQueue*)malloc(sizeof(LinkQueue));
    if(start == end)
        return;
    memset(vis, 0, INFINITY);
    vis[start] = 1;
    InitQueue(Q);
    EnterQueue(Q, start);
    while(Q->front != Q->fear){
        DeleteQueue(Q, &v);
        num = v;
        for(i = 1;i <= G->vexnum; i++){
            if(G->arcs[num][i] != INFINITY) {
                w = i;  //�����ǰ�ڵ�ĵ�һ���ڽӵ㣨�����ţ�
                while(w != -1){
                    if(vis[w] == 0){
                        if(w == end){
                            BFS(G, start, num);
                            printf("%s->",G->vex[num].name);
                            return;
                        }
                        vis[w] = 1;
                        EnterQueue(Q, w);
                        w = NextAdjVertex(G, w, v);
                        //w����ĵõ�һ���ڽӵ㣬v�����w��һ���ڽӵ�(�����һ���ڽӵ�����)
                    }
                    break;
                }
            }
        }
    }
}

//��ѯ���·�ߣ���ת���٣�
void SearchBFS(AdjMatrix *G)
{
    int start, end;
    system("cls");
    printf("\n\n");
    Print(G);
    do{
        printf("\t\t\t\t\t������������:");
        scanf("%d",&start);
    }while(start<=0 || start>G->vexnum);
    do{
        printf("\t\t\t\t\t�������յ����:");
        scanf("%d",&end);
    }while(start<=0 || start>G->vexnum);

    if(G->arcs[start][end] != INFINITY)
        printf("\n\t\t\t\t\t��%s��%s����Ҫ��ת������ֱ�ӵ���!\n",G->vex[start].name,G->vex[end].name);
    if(G->arcs[start][end] == INFINITY) {
        printf("\n\t\t\t\t\t��%s��%s��ת���������ٵ�·��Ϊ:\n\n",G->vex[start].name,G->vex[end].name);
        printf("\t\t\t����");
        BFS(G, start, end);
        printf("%s\n",G->vex[end].name);
    }
    printf("\n\t\t\t\t\t�����������...");
    getch();

}

void Dijkstra(AdjMatrix *G, int start, int end, int dist[], int path[][MAXVEX])
{
    int mindist, i, j, k, t = 1;
    for(i = 1; i <= G->vexnum; i++) {
        dist[i] = G->arcs[start][i];  //��dist�����ʼ��
        if(G->arcs[start][i] != INFINITY)
            path[i][1] = start;  //����û����ڣ���path[i][1]ΪԴ��
    }
    path[start][0] = 1; //start���뵽S��
    for(i = 2; i <= G->vexnum; i++) {  //Ѱ�Ҹ������·��
        mindist = INFINITY;
        for(j = 1; j <= G->vexnum; j++)
            if(!path[j][0] && dist[j] < mindist) {
                k = j;
                mindist = dist[j];
            }

            if(mindist == INFINITY)
                return ;
            path[k][0] = 1;   //�ҵ����·�������õ���뵽S������
            for(j = 1; j <= G->vexnum; j++) {  //�޸�·��
                if(!path[j][0] && G->arcs[k][j] < INFINITY && dist[k]+G->arcs[k][j] < dist[j]) {
                    dist[j] = dist[k] + G->arcs[k][j];
                    t = 1;
                    while(path[k][t] != 0) {
                        path[j][t] = path[k][t];
                        t++;
                    }
                    path[j][t] = k;
                    path[j][t+1] = 0;
                }
            }
    }

    for(i = 1; i <= G->vexnum; i++)
        if(i == end)
            break;
    printf("\n    ����%s--->%s�����·��Ϊ: ��%s",G->vex[start].name,G->vex[end].name,G->vex[start].name);
    for(j = 2; path[i][j] != 0; j++) {
        printf("->%s",G->vex[path[i][j]].name);
    }
    printf("->%s, ����Ϊ%d m\n",G->vex[end].name,dist[i]);
    printf("\n\t\t\t\t\t�����������...");
    getch();
}

//����Dijkstra�㷨��ô���㽨�������յ㽨�������·��
void Shortcut(AdjMatrix *G)
{
    int start, end;
    int dist[MAXVEX];
    int path[MAXVEX][MAXVEX] = {{0}};
    system("cls");
    printf("\n\n");
    Print(G);
    do{
        printf("\t\t\t\t\t���������:");
        scanf("%d",&start);
    }while(start<=0 || start>G->vexnum);
    do{
        printf("\t\t\t\t\t�������յ�:");
        scanf("%d",&end);
    }while(end<=0 || end>G->vexnum);
    Dijkstra(G,start,end,dist,path);
}

void Prim(AdjMatrix *G, int start)
{
    struct
    {
        int adjvex;
        int lowcost;
    }closedge[MAXVEX];
    int i, e, k, m, min;
    closedge[start].lowcost = 0;

    //�Գ��˳���������deep���ж����ʼ����Ӧ��closedge����
    for(i = 1; i <= G->vexnum; i++) {
        if(i != start) {
            closedge[i].adjvex = start;
            closedge[i].lowcost = G->arcs[start][i];
        }
    }

    for(e = 1; e <= G->vexnum-1; e++)  //����ѡ�е�n-1�����������ı�
    {
        //ѡ��Ȩֵ��С�ı�
        min = INFINITY;
        for(k = 1; k <= G->vexnum; k++) {
            if(closedge[k].lowcost != 0 && closedge[k].lowcost < min) {
                m = k;
                min = closedge[k].lowcost;
            }
        }
        printf("\t\t\t\t\t��%s---%s:%d m\n", G->vex[closedge[m].adjvex].name,G->vex[m].name,closedge[m].lowcost);
        closedge[m].lowcost = 0;

        for(i = 1; i <= G->vexnum; i++) {
            if(i != m && G->arcs[m][i] < closedge[i].lowcost) {
                closedge[i].lowcost = G->arcs[m][i];
                closedge[i].adjvex = m;
            }
        }
    }
    printf("\n\t\t\t\t\t�����������...");
    getch();
}

//��ѯ��С������
void MiniSpanTree(AdjMatrix *G)
{
    int i,count=0;
    int start;
    system("cls");
    printf("\n\n");
    Print(G);
    do{
        printf("\t\t\t\t\t������������:");
        scanf("%d",&start);
    }while(start<=0 || start>G->vexnum);
    for(i = 1; i <= G->vexnum; i++){
        if(G->arcs[start][i] != INFINITY)
            count++;
    }
    if(count == 0) {
        printf("\n\t\t\t\t\t�����������...");
        getch();
    }
    else {
        printf("\n");
        Prim(G, start);
    }
}

//�����µص�
void AddPoint(AdjMatrix *G,SchoolMap M[MAXL][MAXC])
{
    int i,j;
    int x,y;
    system("cls");
    printf("\n\n");
    Print(G);
    printf("\t\t\t\t\t���������ӵĵص�����:");
    scanf("%s",G->vex[++G->vexnum].name);
    G->vex[G->vexnum].No = G->vexnum;
    printf("\t\t\t\t\t������õص�ļ��:");
    scanf("%s",G->vex[G->vexnum].description);
    do{
        printf("\t\t\t\t\t������õص������(x,y):");
        scanf("%d,%d",&x,&y);
    }while((x<=0 || x>=20) || (y<=0 || y>=63));
    M[x][y].point = 1;
    M[x][y].No = G->vexnum;
    strcpy(M[x][y].name,G->vex[G->vexnum].name);
    for(i = 1; i <= G->vexnum; i++) {
        G->arcs[G->vexnum][i] = INFINITY;
        G->arcs[i][G->vexnum] = INFINITY;
    }

    FILE *fp;
    fp=fopen("·����Ϣ.txt","wt");
    fprintf(fp,"%d %d\n",G->vexnum,G->arcnum);
    for(i = 1; i <= G->vexnum; i++)
        for(j = i; j <= G->vexnum; j++) {
            if(G->arcs[i][j] != INFINITY) {
                fprintf(fp,"%d %d %d\n",i,j,G->arcs[i][j]);
            }
        }
    fclose(fp);

    FILE *fp2;
    fp2=fopen("�ص����.txt","at");
    fprintf(fp2,"\n%s %d %d %s", G->vex[G->vexnum].name, x, y, G->vex[G->vexnum].description);
    fclose(fp2);
    printf("\n\t\t\t\t\t�õص���ӳɹ�~��ȥ��ͼ��Ϣ��鿴��!\n");
    printf("\n\t\t\t\t\t�������������һ��...");
    getch();
}

//�����·��
void AddEdge(AdjMatrix *G)
{
    int i,j;
    int start, end, weight;
    system("cls");
    printf("\n\n");
    Print(G);
    do{
        printf("\t\t\t\t\t����������·�ߵ���㽨��:");
        scanf("%d",&start);
    }while(start<=0 || start>G->vexnum);
    do{
        printf("\t\t\t\t\t����������·�ߵ��յ㽨��:");
        scanf("%d",&end);
    }while(end<=0 || end>G->vexnum);
    printf("\t\t\t\t\t����������·�ߵľ���:");
    scanf("%d",&weight);
    if(G->arcs[start][end]== INFINITY ) { //�����ǰû���������������
        G->arcs[start][end] = weight;
        G->arcs[end][start] = weight;   //��������Ԫ�ظ�ֵ��ͼ����+1
        G->arcnum ++;

        //���½������·��֮���ͼ����Ϣд��"������Ϣ.txt"�ļ���
        FILE *fp;
        fp=fopen("·����Ϣ.txt","wt");
        fprintf(fp,"%d %d\n",G->vexnum,G->arcnum);
        for(i = 1; i <= G->vexnum; i++)
            for(j = i; j <= G->vexnum; j++) {
                if(G->arcs[i][j] != INFINITY) {
                    fprintf(fp,"%d %d %d\n",i,j,G->arcs[i][j]);
                }
            }
        fclose(fp);
        printf("\n\t\t\t\t\t����·����ӳɹ�~��ȥ��ͼ��Ϣ��鿴��!\n");
    }

    else {
        printf("\n\t\t\t\t\t����·���Ѿ��������~�����ظ������!\n");
    }
    printf("\n\t\t\t\t\t�����������...");
    getch();
}

/*void DelPoint(AdjMatrix *G,SchoolMap M[MAXL][MAXC])
{
    int i,j,k;
    int x,y;
    int No;
    system("cls");
    printf("\n\n");
    Print(G);
    do{
        printf("\t\t\t\t\t�����볷���ĵص����:");
        scanf("%d",&No);
    }while(No<=0 || No>G->vexnum);
    G->vexnum--;

    FILE *fp;
    fp=fopen("������Ϣ.txt","wt");
    fprintf(fp,"%d %d\n",G->vexnum,G->arcnum);
    for(i = 1; i <= G->vexnum; i++)
        for(j = i; j <= G->vexnum; j++) {
            if(G->arcs[i][j] != INFINITY) {
                fprintf(fp,"%d %d %d\n",i,j,G->arcs[i][j]);
            }
        }
    fclose(fp);

    FILE *fp2;
    fp2=fopen("�������.txt","wt");
    for(i = 1; i <= G->vexnum; i++) {
        for(j = 1; j <= G->vexnum; j++) {
            for(k = 1; k <= G->vexnum; k++) {
                if(i == M[j][k].No) {
                    x = j;
                    y = k;
                }
            }
        }
        fprintf(fp2,"%s %d %d %s\n", G->vex[i].name, x, y, G->vex[i].description);
    }
    fclose(fp2);
    printf("\n\t\t\t\t\t�õص㳷���ɹ�~��ȥ��ͼ��Ϣ��鿴��!\n");
    printf("\n\t\t\t\t\t�������������һ��...");
    getch();
}
*/

//������·��
void DelEdge(AdjMatrix *G)
{
    int i,j;
    int start, end;
    system("cls");
    printf("\n\n");
    Print(G);
    do{
        printf("\t\t\t\t\t�����볷��·�ߵ���㽨��:");
        scanf("%d",&start);
    }while(start<=0 || start>G->vexnum);
    do{
        printf("\t\t\t\t\t�����볷��·�ߵ��յ㽨��:");
        scanf("%d",&end);
    }while(end<=0 || end>G->vexnum);


    if(G->arcs[start][end] != INFINITY ) {  //�����ǰ��������
        G->arcs[start][end] = INFINITY;
        G->arcs[end][start] = INFINITY;  //�򽫾���Ԫ�ظ�ֵΪ�����ʾû����������
        G->arcnum --;     //����ͼ�ı���-1

        ////���½�������֮���ͼ����Ϣд��"������Ϣ.txt"�ļ���
        FILE *fp;
        fp=fopen("·����Ϣ.txt","wt");
        fprintf(fp,"%d %d",G->vexnum,G->arcnum);
        fputc('\n',fp);
        for(i = 1; i <= G->vexnum; i++)
            for(j = i; j <= G->vexnum; j++) {
                if(G->arcs[i][j] != INFINITY) {
                    fprintf(fp,"%d %d %d",i,j,G->arcs[i][j]);
                    fputc('\n',fp);
                }
            }
        fclose(fp);
        printf("\n\t\t\t\t\t����·�߳����ɹ�~��ȥ��ͼ��Ϣ��鿴��!\n");
    }
    else {
        printf("\n\t\t\t\t\t����·�߲������~\n");
    }
    printf("\n\t\t\t\t\t�����������...");
    getch();

}

//�οͲ˵�
int User()
{
    AdjMatrix G;
    SchoolMap M[MAXL][MAXC];
    int choice;
    Create(&G,M);
    do{
        system("cls");
        printf("\n\n");
	    printf("\t\t\t\t|================================================|\n");
	    printf("\t\t\t\t|*                                              *|\n");
	    printf("\t\t\t\t|*    ***��ӭʹ�������ʵ��ѧ����У������***    *|\n");
	    printf("\t\t\t\t|*                                              *|\n");
	    printf("\t\t\t\t|*----------------------------------------------*|\n");
	    printf("\t\t\t\t|*                                              *|\n");
	    printf("\t\t\t\t|*               1. ����ʹ��˵��                *|\n");
	    printf("\t\t\t\t|*               2. У԰ƽ���ͼ                *|\n");
	    printf("\t\t\t\t|*               3. �鿴�ص���Ϣ                *|\n");
        printf("\t\t\t\t|*               4. ��ѯ��·��                *|\n");
	    printf("\t\t\t\t|*               5. ��ѯ���·��                *|\n");
	    printf("\t\t\t\t|*               6. ��ѯ����·��                *|\n");
	    printf("\t\t\t\t|*               7. ��Ѳ�������                *|\n");
	    printf("\t\t\t\t|*               0. �˳�                        *|\n");
	    printf("\t\t\t\t|*                                              *|\n");
	    printf("\t\t\t\t|*==============================================*|\n");
        printf("\n\n");
        do{
            printf("\t\t\t\t��ѡ����Ҫ���еĲ���(����0����7):");
            scanf("%d",&choice);
        }while(choice<0 || choice>7);
        getchar();
        printf("\t\t\t\t�������������һ��...");
        getch();
        printf("\n");
        switch(choice)
        {
            case 1:Instruction1();break;
            case 2:Display(&G,M);break;
            case 3:Description(&G);break;
            case 4:SearchDFS(&G);break;
            case 5:SearchBFS(&G);break;
            case 6:Shortcut(&G);break;
            case 7:MiniSpanTree(&G);break;
            case 0:return 0;
        }
    }while(1);
}

//��ȡadmin.txt�ļ�
struct user *Read()
{
    struct user *phead,*pnew,*pend;  //��������
    FILE *fp;
    fp=fopen("admin.txt","rt");  //��ֻ����ʽ��admin.txt�ı��ļ�
    phead=NULL; //ͷָ��ָ���
    if(fp!=NULL){
        while(!feof(fp)) {
            pnew=(struct user *)malloc(sizeof(struct user));  //���½�㿪�ٿռ�
            pnew->next=NULL;
            if((fscanf(fp,"\n%s %s",pnew->id,pnew->passwd))!=2)  //���һ�в�����������,����ֹѭ��
               break;
            if(phead==NULL) {
                phead=pnew;
            }
            else {
                pend->next=pnew;
            }
            pend=pnew;
        }
    }
    fclose(fp); //�ر��ļ�
    return phead; //����ͷָ��
}

//����Աע��
void Register()
{
    FILE *fp;
    char id[20];
    char passwd1[20];
    char passwd2[20];
    struct user *t;
    t=Read();  //���ļ��������ͷָ���ַ����ָ��t
    system("cls");
    printf("\n\n");
    printf("\t\t\t\t|================================================|\n");
    printf("\t\t\t\t|*                                              *|\n");
    printf("\t\t\t\t|*    ***��ӭʹ�������ʵ��ѧ����У������***    *|\n");
    printf("\t\t\t\t|*                                              *|\n");
    printf("\t\t\t\t|*----------------------------------------------*|\n");
    printf("\t\t\t\t|*                                              *|\n");
    printf("\t\t\t\t|*                  ����Աע��                  *|\n");
    printf("\t\t\t\t|*                                              *|\n");
    printf("\t\t\t\t|*==============================================*|\n");
    printf("\n\n");
    printf("\t\t\t\t\t�������ʺ�:");
    scanf("%s",id);
    getchar(); //���ջس�
    while(t!=NULL) {
        if(strcmp(id,t->id)==0) {
            printf("\n\t\t\t\t\t���ʺ��Ѵ���!�����������.");
            getch();
            return;
        }
        t=t->next;
    }
    fp=fopen("admin.txt","at");  //��׷�ӷ�ʽ���ļ�
    printf("\n\t\t\t\t\t����������:");
    scanf("%s",passwd1);
    printf("\n\t\t\t\t\t���ٴ���������:");
    scanf("%s",passwd2);
    if(strcmp(passwd1,passwd2)==0){
        fprintf(fp,"%s %s\n",id,passwd1);
        fclose(fp);
        printf("\n\t\t\t\t\t�ʺ�ע��ɹ�!�����������.");
    }
    else {
        fclose(fp);
        printf("\n\t\t\t\t\t������������,�ʺ�ע��ʧ��!\n�����������.");
    }
    getch(); //���������
}

//����Ա�˵�
int Admin()
{
    AdjMatrix G;
    SchoolMap M[MAXL][MAXC];
    int choice;
    Create(&G,M);
    do{
        system("cls");
        printf("\n\n");
	    printf("\t\t\t\t|================================================|\n");
	    printf("\t\t\t\t|*                                              *|\n");
	    printf("\t\t\t\t|*    ***��ӭʹ�������ʵ��ѧ����У������***    *|\n");
	    printf("\t\t\t\t|*                                              *|\n");
	    printf("\t\t\t\t|*----------------------------------------------*|\n");
	    printf("\t\t\t\t|*                                              *|\n");
	    printf("\t\t\t\t|*               1. ����ʹ��˵��                *|\n");
	    printf("\t\t\t\t|*               2. У԰ƽ���ͼ                *|\n");
	    printf("\t\t\t\t|*               3. �鿴�ص���Ϣ                *|\n");
        printf("\t\t\t\t|*               4. ��ѯ��·��                *|\n");
	    printf("\t\t\t\t|*               5. ��ѯ���·��                *|\n");
	    printf("\t\t\t\t|*               6. ��ѯ����·��                *|\n");
	    printf("\t\t\t\t|*               7. ��Ѳ�������                *|\n");
	    printf("\t\t\t\t|*               8. ����µص�                  *|\n");
	    printf("\t\t\t\t|*               9. �����·��                  *|\n");
	    printf("\t\t\t\t|*               10.������·��                  *|\n");
	    printf("\t\t\t\t|*               11.ע�����Ա                  *|\n");
	    printf("\t\t\t\t|*               0. �˳�                        *|\n");
	    printf("\t\t\t\t|*                                              *|\n");
	    printf("\t\t\t\t|*==============================================*|\n");
        printf("\n\n");
        do{
            printf("\t\t\t\t��ѡ����Ҫ���еĲ���(����0����11):");
            scanf("%d",&choice);
        }while(choice<0 || choice>11);
        getchar();
        printf("\t\t\t\t�������������һ��...");
        getch();
        printf("\n");
        switch(choice)
        {
            case 1:Instruction2();break;
            case 2:Display(&G,M);break;
            case 3:Description(&G);break;
            case 4:SearchDFS(&G);break;
            case 5:SearchBFS(&G);break;
            case 6:Shortcut(&G);break;
            case 7:MiniSpanTree(&G);break;
            case 8:AddPoint(&G,M);break;
            case 9:AddEdge(&G);break;
            case 10:DelEdge(&G);break;
            case 11:Register();break;
            case 0 :exit(0);
        }
    }while(1);
}

//����Ա��¼
void AdminLogin()
{
    system("cls");
    printf("\n\n");
    printf("\t\t\t\t|================================================|\n");
    printf("\t\t\t\t|*                                              *|\n");
    printf("\t\t\t\t|*    ***��ӭʹ�������ʵ��ѧ����У������***    *|\n");
    printf("\t\t\t\t|*                                              *|\n");
    printf("\t\t\t\t|*----------------------------------------------*|\n");
    printf("\t\t\t\t|*                                              *|\n");
    printf("\t\t\t\t|*                  ����Ա��¼                  *|\n");
    printf("\t\t\t\t|*                                              *|\n");
    printf("\t\t\t\t|*==============================================*|\n");
    printf("\n\n");
    int i,n,count=0;
    char ch;
    for(i=0;i<3;i++) {
        struct user *t;
        t=Read();
        char id[20]={0};
        char passwd[20]={0};
        printf("\n\t\t\t\t\t�������ʺ�:");
        scanf("%s",id);
        getchar();  //���ջس�
        printf("\n\t\t\t\t\t����������ʱ�Ƿ���Ҫ��������:(Y/N):");
        scanf("%c",&ch);
        printf("\n");
        if(ch=='Y'||ch=='y') {
            printf("\t\t\t\t\t����������:");
            for(n=0;;n++) {
                passwd[n]=getch();
                switch(passwd[n])
                {
                    case '\b':
                            passwd[--n]='\0';
                            n--;
                            printf("\b \b");
                            break;
                    case '\r':
                            passwd[n]='\0';
                            putchar('\n');
                            break;
                    default :
                            putchar(' ');
                            break;
                }
                if(passwd[n]=='\0')
                    break;
            }
        }
        if(ch=='N'||ch=='n') {
            getchar();
            printf("\n\t\t\t\t\t����������:");
            scanf("%s",passwd);
        }
        while(t!=NULL) {
            if(strcmp(id,t->id)==0&&strcmp(passwd,t->passwd)==0) {
                printf("\n\t\t\t\t\t��¼�ɹ�!��������������˵�.");
                getch();
                Admin();
                break;
            }
            t=t->next;
        }
        if(t==NULL) {
            printf("\n\t\t\t\t\t�û�������������,����������!\n\n");
            count++; //�������
        }
    }
    if(count==3) {
        printf("\n\t\t\t\t\t��������3���û�����������������,��¼ʧ��!ϵͳ���˳�.\n");
        Sleep(4000);  //���ߺ�������ʱ����ͣ
        exit(0);
    }
}

int main()
{
    int choice;
    do{
        system("cls");
        printf("\n\n");
	    printf("\t\t\t\t|================================================|\n");
	    printf("\t\t\t\t|*                                              *|\n");
	    printf("\t\t\t\t|*    ***��ӭʹ�������ʵ��ѧ����У������***    *|\n");
	    printf("\t\t\t\t|*                                              *|\n");
	    printf("\t\t\t\t|*----------------------------------------------*|\n");
	    printf("\t\t\t\t|*                                              *|\n");
	    printf("\t\t\t\t|*    HELLO~���ǣ�                              *|\n");
        printf("\t\t\t\t|*                                              *|\n");
	    printf("\t\t\t\t|*               1. �����ο�                    *|\n");
	    printf("\t\t\t\t|*               2. ���ǹ���Ա                  *|\n");
	    printf("\t\t\t\t|*               0. �˳�                        *|\n");
	    printf("\t\t\t\t|*                                              *|\n");
	    printf("\t\t\t\t|*==============================================*|\n");
        printf("\n\n");
        do{
            printf("\t\t\t\t��ѡ����Ҫ���еĲ���(����0����2):");
            scanf("%d",&choice);
        }while(choice<0 || choice>2);
        getchar();
        printf("\t\t\t\t�������������һ��...");
        getch();
        printf("\n");
        switch(choice)
        {
            case 1:User();break;
            case 2:AdminLogin();break;
            case 0:return 0;
        }
    }while(1);
    return 0;
}

