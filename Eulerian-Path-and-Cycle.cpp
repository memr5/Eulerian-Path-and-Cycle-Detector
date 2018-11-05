#include<bits/stdc++.h>

using namespace std;

void DFS(int v,vector<vector<int> > adl,vector<bool> &visited){
    visited[v]=true; //Visiting vertex v
    for(int i=0;i<adl[v].size();i++){
        //if unvisited vertex is found in adjacency list then recursively doing DFS from that vertex
        if(!visited[adl[v][i]]){
            DFS(adl[v][i],adl,visited);
        }
    }
}

int main(){

    int n; //Number of Vertices in Graph
    cout<<"Enter number of Vertex: ";
    cin>>n;

    vector<vector<int> > adl(n+1); //Adjacency list of Graph

    //Taking Edges as Input from user

    cout<<"\n\nEnter Edges in Graph (ex: 1 v1 v2 to add Edge | 0 to finish adding Edges) :\n";
    int q,x,y;
    do{
        cin>>q;
        if(q==1){
            cin>>x>>y;
            //adding vertex y in adjacency list of x
            adl[x].push_back(y);
            //adding vertex x in adjacency list of y
            adl[y].push_back(x);
        }
    }while(q!=0);

    vector<bool> visited(n+1,false); //To keep Track on Visited and unvisited Vertices

    //Finding first vertex of Non-zero Degree to start Traversing from it in Graph to check if Vertices with non-zero degree are connected
    int i;
    for(i=1;i<=n;i++){
        //adl[i].size() indicates degree of ith vertex
        if(adl[i].size()!=0){
            break; //Breaking the "for" loop when first vertex of non-zero degree is found
        }
    }

    //Checking if all vertex in the graph are Disconnected => Hence Zero Edges
    if(i==n+1){
        cout<<"\nGraph Have 0 Edges->Eulerian\n";
    }

    else{
        //Using "Depth First Search" to Traverse the Graph from Vertex-i
        DFS(i,adl,visited);

        //checking if all Vertices with non-zero degree are Visited after DFS
        for(i=1;i<=n;i++){
            if( !visited[i] && adl[i].size()>0 ){
                //if vertex with non-zero degree is unvisited then => Graph is not Eulerian
                cout<<"\nNeither Eulerian Cycle nor Path\n";
                exit(0);
            }
        }

        //Else Counting Vertices with Odd Degrees
        int odd=0;
        for(i=1;i<=n;i++){
            if(adl[i].size()%2!=0){
                ++odd;
            }
        }

        //If more than two are of odd degree => Graph is not Eulerian
        if(odd>2){
            cout<<"\nNeither Eulerian Cycle nor Path\n";
        }
        //else if number of vertices with odd degree are Two => Eulerian Path
        else if(odd==2){
            cout<<"\nEulerian Path\n";
        }
        //else Eulerian Cycle
        else{
            cout<<"\nEulerian Cycle\n";
        }
    }
}
