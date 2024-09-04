// Online C++ compiler to run C++ program online
#include <iostream>
#define INF 99999
using namespace std;
 
int main() {
    int v, e;
    cout << "Name: Naman Shah\n";
    cout << "Enrollment no.: 0827CS221174\n";
    cout << "Topic: Floyd Warshal Algorithm\n";
    cout << "\nEnter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;
    int distance[v][v], path[v][v], transitive[v][v];
 
    // Initialize distance matrix
    for(int i = 1; i <=v; i++) 
	{
        for(int j = 1; j <= v; j++) 
		{
            distance[i][j] = INF;
        }
    }
 
    cout << "Enter Distance Matrix (Source, Destination, Weight):\n";
    for(int i = 1; i <= e; i++) 
	{
        int u, y, w;
        cin >> u >> y >> w;
        distance[u][y] = w;
    }
 
    // Initialize path matrix
    for(int i = 1; i <= v; i++) 
	{
        for(int j = 1; j <= v; j++) 
		{
            if(distance[i][j] != INF && i != j)
                path[i][j] = i;
            else
                path[i][j] = -1;
        }
    }
    for(int k = 1; k <= v; k++) 
	{
        for(int i = 1; i <= v; i++) 
		{
            for(int j = 1; j <= v; j++) 
			{
                if(distance[i][k] != INF && distance[k][j] != INF && distance[i][j] > distance[i][k] + distance[k][j]) 
				{
                    distance[i][j] = distance[i][k] + distance[k][j];
                    path[i][j] = k;
                }
            }
        }
        cout<<"\n---------------------------------------------------------------------------------------\n";
                cout<<"STEP "<<k+1<<" : \n";
        cout << "DISTANCE MATRIX:\n";
    cout << " |\t0\t1\t2\t3\t\n";
    cout<<"---------------------------------\n";
    for(int i = 1; i <= v; i++) 
	{
        cout << i << "|\t";
        for(int j = 1; j <= v; j++) 
		{
            if(i!=j)
            {
            	if(distance[i][j]==INF)
            	cout<<"INF\t";
            	else
            	cout << distance[i][j] << "\t";
			}
            else
            cout << "0" << "\t";
        }
        cout << endl;
    }
 
    cout << "PATH MATRIX:\n";
    cout << " |\t 0\t 1\t 2\t 3\t\n";
    cout<<"---------------------------------\n";
    for(int i = 1; i <= v; i++) 
	{
        cout << i << "|\t";
        for(int j = 1; j <= v; j++) 
		{
            if(i!=j)
            cout <<" "<<path[i][j] << "\t";
            else
            cout << "-1" << "\t";
        }
        cout << endl;
    }
 
    cout << "TRANSITIVE MATRIX:\n";
    cout << " |\t0\t1\t2\t3\t\n";
    cout<<"---------------------------------\n";
    for(int i = 1; i <= v; i++) 
		{
        cout << i << "|\t";
        for(int j = 1; j <= v; j++) 
		{
            if(distance[i][j] != INF && i != j)
                transitive[i][j] = 1;
            else
                transitive[i][j] = 0;
            cout << transitive[i][j] << "\t";
        }
        cout << endl;
    	}
    }
 
 
    return 0;
}