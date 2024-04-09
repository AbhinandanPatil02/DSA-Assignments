#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<list>
#include<climits>
using namespace std;

class graph {
public:
    unordered_map<int, list<pair<int, int>>> adjlist;

    void addedge(int u, int v, int wt, bool direction) {
        if (direction == 1) {
            adjlist[u].push_back({v, wt});
        }
        else {
            adjlist[u].push_back({v, wt});
            adjlist[v].push_back({u, wt});
        }
    }

    void print() {
        for (auto i : adjlist) {
            cout << i.first << ": { ";
            for (pair<int, int> p : i.second) {
                cout << " ( " << p.first << " , " << p.second << " ) ";
            }
            cout << " }" << endl;
        }
    }

    int minimum_key(int key[], bool mst[]) {
        int min = INT_MAX, min_index;
        // cout<<"Min_index : "<<min_index<<endl;
       

        for (int v = 0; v < adjlist.size(); v++){
            if (mst[v] == false && key[v] < min){
                 min = key[v], min_index = v;
            }
        }
           
               
                cout<<"Min_index : "<<min_index<<endl;

        return min_index;
    }
void prim() {
    int n = adjlist.size();
    int parent[n];
    int key[n];
    bool mst[n];
    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
   
    for (int count = 0; count < n-1; count++)
    {
        int min_edge_vertex = minimum_key(key, mst);
        mst[min_edge_vertex] = true;
       
        for (auto it : adjlist[min_edge_vertex])
        {
            int vertex = it.first;
            int weight = it.second;
            if (mst[vertex] == false && weight <  key[vertex])
            {
                parent[vertex]  = min_edge_vertex;
                key[vertex] = weight;
            }
        }
    }
   
    cout<<"MST of given graph is: \n"<<endl;
    cout<<"\nEdge \t Weight\n";
    for(int i=1; i<n; i++) {
        cout<<parent[i]<<" <-> "<<i<<" \t "<<key[i]<<endl;
    }
}

};

int main() {
    graph g;
    g.addedge(0, 1, 1, 0);
    g.addedge(1, 2, 4, 0);
    g.addedge(1, 3, 2, 0);
    g.addedge(2, 3, 3, 0);
    g.addedge(1, 5, 7, 0);
    g.addedge(3, 4, 4, 0);
    g.addedge(5, 4, 8, 0);
    g.addedge(4, 6, 5, 0);
    g.addedge(3, 6, 3, 0);

    g.print();
   
    g.prim();

    return 0;
}