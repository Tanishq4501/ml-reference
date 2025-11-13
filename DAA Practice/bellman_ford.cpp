#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 1e18;

vector<long long> bellman_ford(int V,vector<vector<int>> &edges,vector<int> &pred,int src){
    vector<long long> dist(V+1,INF);

    pred.assign(V+1,-1);

    dist[src] = 0;
    pred[src] = -1;

    for(int i = 0;i<=V-1;i++){
        for(auto &e:edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if(dist[u] != INF && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pred[v] = u;
            }
        }
    }

    bool neg_cycle = false;

    for(int i = 0;i<=V-1;i++){
        for(auto &e:edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if(dist[u] != INF && dist[u] + w < dist[v]){
                neg_cycle = true;
                break;
            }
        }
    }

    if (neg_cycle == true){
        return {-1};
    }

    return dist;
}

void display_path(int ver,vector<int> &pred,vector<long long> &dist){
    vector<int> path;
    for(int v = ver; pred[v] != -1;v= pred[v]){
        path.push_back(v);
    }

    reverse(path.begin(),path.end());

    for(int v: path){
        cout << v;
        if (v != path.back()) cout << "->";
    }

    cout << "( cost: " << dist[ver] << " )";
}

int main(){

    int t;

    cout << "Enter no of testcases: ";
    cin >> t;
    cout << endl;

    int V,E;

    while(t--){

        cout << "Enter no of vertices: ";
        cin >> V;
        cout << endl;
        cout << "Enter no of edges: ";
        cin >> E;
        cout << endl;

        vector<vector<int>> edges(E,vector<int>(3));
        cout << "Enter edge in the form of (u,v,w): " << endl;
        for(int i = 0;i<E;i++){
            cin >> edges[i][0] >> edges[i][1] >> edges[i][2]; 
        }
        cout << endl;

        int src;
        cout << "Enter source: ";
        cin >> src;
        cout << endl;

        vector<int> pred(V+1);
        vector<long long> result = bellman_ford(V,edges,pred,src);

        if (result.size() == 1 && result[0] == -1){
            cout << "Negative cycle detected!" << endl;
        }else{
            for(int i = 1;i<=V;i++){
                cout << "Path from " << src << "to " << i << ": " ;
                if(result[i] == INF){
                    cout << "No path to the vertex." << endl;
                    break;
                }else{
                    display_path(i,pred,result);
                }
                cout << endl;
            }
        }

    }

    return 0;
}