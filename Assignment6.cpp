#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

class graph{
    public:

    unordered_map<int,vector<int>>adjlist;

    void addedge(int u,int v,bool direction){
        if(direction==1){
            adjlist[u].push_back(v);
        }

        if(direction==0){
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);

        }
       
    }

    void print(){
        unordered_map<int,vector<int>>::iterator it;
        for(it=adjlist.begin();it!=adjlist.end();it++){
            cout<<it->first<<" :-> { ";
            for(int j=0;j<it->second.size();j++){
                cout<<it->second[j]<<" , ";
            }
            cout<<" }"<<endl;
        }
    }

    void printauto(){
        for(auto i:adjlist){
            cout<<i.first<<" :-> { ";
            for(auto j:i.second){
                cout<<j<<" , ";
            }
            cout<<" }"<<endl;
        }
    }

    // void bfs(int src){
    //     queue<int>q;
    //     unordered_map<int,bool>vis;
    //     q.push(src);
    //     vis[src]=true;

    //     while(!q.empty()){
    //         int frontnode=q.front();
    //         cout<<frontnode<<" ";
    //         q.pop();

    //         for(auto nbr:adjlist[frontnode]){
    //             int nbrdata=nbr;
    //             if(!vis[nbrdata]){
    //                 q.push(nbrdata);
    //                 vis[nbrdata]=true;
    //             }
    //         }
    //     }
    // }
    void bfs(int src){
        unordered_map<int,bool>vis;
        queue<int>q;
        q.push(src);
        vis[src]=true;

        while(!q.empty()){
            int frontnode=q.front();
            cout<<frontnode<<" ";
            q.pop();

            for(auto i:adjlist[frontnode]){
                int nbrdata=i;
                if(!vis[nbrdata]){
                    q.push(nbrdata);
                    vis[nbrdata]=true;
                }
            }
        }
    }

    // void dfs(int src,unordered_map<int,bool>&vis){
    //     vis[src]=true;

    //     cout<<src<<" ";

    //     for(auto i:adjlist[src]){
    //         int nbrdata=i;
    //         if(!vis[nbrdata]){
    //             dfs(nbrdata,vis);
    //         }
    //     }


    // }

    void dfs(int src,unordered_map<int,bool>&vis){
        vis[src]=true;
        cout<<src<<" ";
        for(auto i:adjlist[src]){
            int nbrdata=i;
            if(!vis[nbrdata]){
                dfs(nbrdata,vis);
            }
        }
    }

};



int main(){
    graph g;
    g.addedge(0,1,1);
    g.addedge(1,2,1);
    g.addedge(1,3,1);
    g.addedge(2,3,1);

    g.print();
    cout<<endl;
    g.printauto();

    // g.bfs(0);
    unordered_map<int,bool>vis;
    g.dfs(0,vis);
    
    return 0;
}