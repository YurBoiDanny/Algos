#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
#define N 7
#define INF INT_MAX

int dist[N];
vector<tuple<int, int, int>> edges;

vector<tuple<int, int, int>> createGraph()
{
    vector<tuple<int, int, int>> _edges;
    int a, b, w;

    //cout << "Enter Graph Edges\n";
    while (cin >> a >> b >> w)    
    {
        //cout << "a = " << a << " b = " << b << " w = " << w << "\n";
        _edges.push_back({a, b, w});
    }
    return _edges;
}

//Bellman Ford Algo
//Complexity O(nm)
//Finds the shortest paths from at starting node x to all other nodes on the graph
void bl(int x)
{
    for (int i = 1; i <= N - 1; i++)
    {
        dist[i] = INF;
    }
    dist[x] = 0;

    for (int i = 1; i <= N - 1; i++)
    {
        //cout << "i = " << i << "\n";
        for (auto e : edges)
        {
            int a, b, w;
            tie(a, b, w) = e; //Asigned tuple params into the variables
            dist[b] = min(dist[b], dist[a] + w);
            //cout << "dist[" << b << "] = " << dist[b] << "\n" ;
        }
    }
}

int main()
{
    //Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    //File I/O
    freopen("../intput.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    
    //cout << "Hello world \n";
    edges = createGraph();
    int startingNode = 1; 
    //cout << "startingNode = " << startingNode << "\n";
    bl(startingNode);

    for (auto u : dist)
    {
        cout << u  << "\n";
    }

    cout << "Program terminating";
    return 0;
    
}