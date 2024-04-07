#include<iostream>
using namespace std;

class node{
    public:
    string key;
    int val;
    node*next;
    node(string key,int val){
        this->key=key;
        this->val=val;
        this->next=NULL;
    }

};

class hashtable{
    public:
    node*arr[10];

    hashtable(){
        for(int i=0;i<10;i++){
            arr[i]=NULL;
        }
    }

    int gethash(string key){
        int hash=0;
        for(char s:key){
            hash+=s;
        }
        return hash%10;
    }

    void insert(string key,int val){
        int hash=gethash(key);
        if(arr[hash]==NULL){
            arr[hash]=new node(key,val);
        }
        else{
            if(search(key)){
                cout<<"Element is already present"<<endl;
            }
            else{
                node*temp=arr[hash];
                while(temp->next){
                    temp=temp->next;
                }
                temp->next=new node(key,val);
            }
        }

    }

    void printll(node*head){
        node*temp=head;
        while(temp){
            cout<<"[ "<<temp->key<<" , "<<temp->val<<" ]-->";
            temp=temp->next;
        }
        cout<<"0";
    }

    void print(){
        for(int i=0;i<10;i++){
            cout<<i<<" : ";
            printll(arr[i]);
            cout<<endl;
        }
    }

    bool searchll(node*head,string key){
        node*temp=head;
        while(temp){
            if(key==temp->key){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }

    bool search(string key){
        int hash=gethash(key);
        bool found=searchll(arr[hash],key);
        if(!found){
            return false;
        }
        else{
            return true;
        }
    }

    void deletenode(string key){
        int hash=gethash(key);
        node*head=arr[hash];
        node*prev=NULL;
        node*temp=head;

        while(temp&&temp->key!=key){
            prev=temp;
            temp=temp->next;
        }

        if(!temp){
            cout<<"Element is not present"<<endl;
            return;
        }

        if(prev==NULL){
            arr[hash]=temp->next;
            delete temp;
        }
        else{
            prev->next=temp->next;
            delete temp;
        }
    }

};





int main(){
    hashtable t;
    t.insert("abhi",10);
    t.insert("a",10);
    // t.insert("ab",10);
    t.insert("ab",10);
    // t.insert("abh",10);
    t.insert("abh",10);
    t.insert("abh",10);
    // t.print();
    cout<<endl;
    if(t.search("patil")){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }

    // t.deletenode("abhi");  
    t.print();
    return 0;
}