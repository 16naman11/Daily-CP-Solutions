#include <iostream>
using namespace std;
#define V 6
int minVertex(int value[],bool setMST[]){
    int minimum=999;
    int vertex;
    for(int i=0;i<V;i++){
        if(setMST[i]==false && value[i]<minimum){
            vertex=i;
            minimum=value[i];
        }
    }
    return vertex;
}
void findMST(int graph[V][V]){
    int parent[V];
    int value[V];
    bool setMST[V];
    for(int i=0;i<V;i++){
        value[i]=999;
        setMST[i]=false;
    }
    parent[0]=-1;
    value[0]=0;
    for(int i=0;i<V-1;++i){
        int U=minVertex(value,setMST);
        setMST[U]=true;
        for(int j=0;j<V;j++){
            if(graph[U][j]!=0 && setMST[j]==false && graph[U][j]<value[j]){
                value[j]=graph[U][j];
                parent[j]=U;
            }
        }
    }
    cout<<"\n\noutput\n";
    for(int i=1;i<V;++i){
       
        cout<<"V"<<parent[i]<<"->"<<i<<" wt="<<graph[parent[i]][i]<<"\n";
    }
}
int main() {
    //int graph[V][V]={{0,4,6,0,0,0},{4,0,6,3,4,0},{6,6,0,1,8,0},{0,3,1,0,2,3},{0,4,8,2,0,7},{0,0,0,3,7,0}};
    int graph[V][V];

    // Input adjacency matrix from user
    cout << "Name: Naman Shah\n";
    cout << "Enrollment: 0827CS221174\n";
    cout << "Aim: Prim's Algorithm\n";

    cout << "\nEnter the adjacency matrix representation of the graph (size " << V << "x" << V << "):\n";
    for(int i = 0; i < V; ++i) {
        cout << "Enter row " << i + 1 << ": ";
        for(int j = 0; j < V; ++j) {
            cin >> graph[i][j];
        }
    }
    cout<<"\n Adjacency Matrix Representation:\n    1\t2\t3\t4\t5\t6\t";
    for(int i=0;i<V;i++)
    {
        cout<<endl<<i+1<<" | ";
        for(int j=0;j<V;j++){
            cout<<graph[i][j]<<"\t";
        }
    }
    findMST(graph);
    return 0;
    }