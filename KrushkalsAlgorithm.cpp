#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int weight;
    int start;
    int end;
};

struct Output {
    int weight;
    int start;
    int end;
};

int main() {
    cout<<"Enter the number of Vertices and Edges: "<<endl;
    int V, E;
    cin >> V >> E;

    int matrix[3][100];
    cout<<"Enter the starting node, ending node and weight of each edge you want to insert in your graph respectively: "<<endl;
    for (int i = 0; i < E; i++) {
        cin >> matrix[0][i] >> matrix[1][i] >> matrix[2][i];
        cout<<endl;
    }

    Edge edges[100];

    for (int i = 0; i < E; i++) {
        edges[i].weight = matrix[2][i];
        edges[i].start = matrix[0][i];
        edges[i].end = matrix[1][i];
    }
    sort(edges, edges + E, [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    int parent[100];
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    Output output[100];
    int edgeCount = 0, i = 0;
    while (edgeCount < V - 1 && i < E) {
        int weight = edges[i].weight;
        int u = edges[i].start;
        int v = edges[i].end;

        int fp = u, sp = v;
        while (parent[fp] != fp)
            fp = parent[fp];
        while (parent[sp] != sp)
            sp = parent[sp];

        if (fp != sp) {
            output[edgeCount].weight = weight;
            output[edgeCount].start = u;
            output[edgeCount].end = v;
            edgeCount++;
            parent[fp] = sp;
        }
        i++;
    }
    cout<<"No. of Edges in the Spanning Tree: "<<edgeCount<<endl<<endl;
    for (int j = 0; j < edgeCount; j++) {
        if (output[j].start > output[j].end) {
            
            cout <<"Nodes: "<< output[j].end << " to " << output[j].start << " Weight: " << output[j].weight << endl;
        } else {
            cout <<"Nodes: " <<output[j].start << " to " << output[j].end << " Weight: " << output[j].weight << endl;
        }
    }

    return 0;
}
