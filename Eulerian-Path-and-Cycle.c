#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Structure of Node in Adjacency List
struct node {
    int data;
    struct node* next;
};

//Function to Insert Adjacent vertex in Adjacency List (It will insert node at the end of the List)
struct node* Insert(struct node* head,int v){
    struct node* nw = (struct node*)malloc(sizeof(struct node));
    nw->data=v;
    nw->next=NULL;
    if(head==NULL){
        head=nw;
    }
    else{
        struct node* temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=nw;
    }
return head;
}

//Depth-First-Search to Visit Connected Vertices
void DFS(int v,struct node* head[],bool visited[]){
    //visiting vertex v
    visited[v]=true;
    //visiting unvisited Vertices from adjacency list of "v"
    for(struct node* i=head[v];i!=NULL;i=i->next){
        if(!visited[i->data]){
            DFS(i->data,head,visited);
        }
    }
}

//To Find Degree of Vertex
int Degree(struct node* head){
    struct node* temp=head;
    int degree=0;
    while(temp){
        ++degree;
        temp=temp->next;
    }
return degree;
}

int main(){

    //Number of Vertices
    int n;
    printf("\nEnter Number of Vertices : ");
    scanf("%d",&n);

    //Head-Pointers of Adjacency-Lists
    struct node* head[n+1];

    //Initializing Head-Pointer with NULL Value
    for(int i=1;i<=n;i++){
        head[i]=NULL;
    }

    int x,y,q;

    //Taking Edges as Input from user
    printf("\n\nEnter Edges in Graph (ex: 1 v1 v2 to add Edge | 0 to finish adding Edges) :\n");
    do{
        scanf("%d",&q);
        if(q==1){
            scanf("%d %d",&x,&y);
            head[x]=Insert(head[x],y); //Adding "y" in the Adjacency List of "x"
            head[y]=Insert(head[y],x); //Adding "x" in the Adjacency List of "y"
        }
    }while(q!=0);

    //To keep Track on Visited and unvisited Vertices
    bool visited[n+1];

    //Initializing "Visited" array with False Value
    for(int i=1;i<=n;i++){
        visited[i]=false;
    }

    //Finding First Non-Zero Degree Vertex
    int i;
    for(i=1;i<=n;i++){
        //Breaking the loop when 1st Non-Zero Degree Vertex is Found
        if(head[i]!=NULL){
            break;
        }
    }

    //Checking if all the Vertex are of Zero Degree or Not => If yes then Graph is Eulerian
    if(i==n+1){
        printf("\nEulerian\n");
    }

    else{

        //Starting Depth-First-Search from 1st Vertex of Non-Zero Degree which is => i
        DFS(i,head,visited);

        //checking if all Vertex with non-zero degree are Visited after DFS
        for(i=1;i<=n;i++){
            if(!visited[i] && head[i]!=NULL){
                printf("\nNot-Eulerian\n"); //If there is a unvisited Vertex with non-zero degree then the Graph is Not-Eulerian
                exit(0);
            }
        }

        //Else counting Number of Vertices with Odd Degree
        int odd=0;
        for(i=1;i<=n;i++){
            if(Degree(head[i])%2!=0){
                ++odd;
            }
        }

        //If more than two are of odd degree => Graph is not Eulerian
        if(odd>2){
            printf("\nNot-Eulerian\n");
        }
        //else if number of Vertices with odd degree are Two => Eulerian Path
        else if(odd==2){
            printf("\nEulerian Path\n");
        }
        //else Eulerian Cycle
        else{
            printf("\nEulerian Cycle\n");
        }
    }
return 0;
}
