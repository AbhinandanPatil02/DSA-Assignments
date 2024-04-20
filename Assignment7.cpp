#include<iostream>
#include<unordered_map>
#include<climits>
#include<list>

using namespace std;

class graph{

    public:
    unordered_map<int,list<pair<int,int>>>adjlist;
    void addedge(int u,int v,int w,bool dir){
        if(dir==1){
            adjlist[u].push_back({v,w});
        }
        else if(dir==0){
            adjlist[u].push_back({v,w});
            adjlist[v].push_back({u,w});
        }
    }

    void print(){
        for(auto i:adjlist){
            cout<<i.first<<" : { ";
            for(auto j:i.second){
                cout<<" ( "<<j.first<<" , "<<j.second<<" ) ";
            }
            cout<<" } "<<endl;
        }
    }

    int getminval(int key[],bool mst[]){
        int temp=INT_MAX;
        int index=-1;
        for(int i=0;i<adjlist.size();i++){
            if(key[i]<temp&&mst[i]==false){
                temp=key[i];
                index=i;
            }
        }
        return index;
    }

    void prims(){
        int n=adjlist.size();
        int key[n];
        int parent[n];
        bool mst[n];
        for(int i=0;i<n;i++){
            key[i]=INT_MAX;
            parent[i]=-1;
            mst[i]=false;
        }

        key[0]=0;
        while(true){
            int u=getminval(key,mst);

            mst[u]=true;
            for(auto edge:adjlist[u]){
                int v=edge.first;
                int w=edge.second;
                if(w<key[v]&&mst[v]==false){
                    parent[v]=u;
                    key[v]=w;
                }
            }
 
            if(u==-1){
                break;
            }
        }

        cout<<"\nMST is : "<<endl;
        cout<<"  edge"<<"\t"<<"       weight"<<endl;
        for(int i=1;i<n;i++){
            cout<<parent[i]<<" <-> "<<i<<" \t "<<key[i]<<endl;
        }

    }

};


int main(){
    graph g;
    g.addedge(0,1,1,0);
    g.addedge(1,2,11,0);
    g.addedge(1,3,1,0);
    g.addedge(2,3,1,0);

    g.print();

    g.prims();

    
    return 0;
}