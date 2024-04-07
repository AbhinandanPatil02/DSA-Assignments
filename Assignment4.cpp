#include<iostream>
using namespace std;

class pairkv{
    public:
    string name;
    long long int no;
    pairkv(){
        name="";
        no=0;
    }
    pairkv(string name,long long int no){
        this->name=name;
        this->no=no;
    }




};

class table{
    public:
    pairkv*arr[10];

    table(){
        for(int i=0;i<10;i++){
            arr[i]=NULL;
        }
    }

    int gethash(int no){
        return no%10;
    }


    void withoutr(pairkv*pair){
        int h=gethash(pair->no);
        if(arr[h]==NULL){
            arr[h]=pair;
        }
        else{
            int nextindex=(h+1)%10;
            while(arr[nextindex]!=NULL){
                nextindex=(nextindex+1)%10;
            }
            if(arr[nextindex]==NULL){
                arr[nextindex]=pair;
            }
            else{
                cout<<"Hashmap is full "<<endl;
            }
        }
    }

    void withr(pairkv*pair){
        int h=gethash(pair->no);
        if(arr[h]==NULL){
            arr[h]=pair;
        }
        else if(gethash(arr[h]->no)==gethash(pair->no)){
            int nextindex=(h+1)%10;
            while(arr[nextindex]!=NULL){
                nextindex=(nextindex+1)%10;
            }
            if(arr[nextindex]==NULL){
                arr[nextindex]=pair;
            }
            else{
                cout<<"Hashmap is full"<<endl;
            }

        }
        else{
            pairkv*temp=arr[h];
            arr[h]=pair;
            int nextindex=(h+1)%10;

            while(arr[nextindex]!=NULL){
                nextindex=(nextindex+1)%10;
            }

            if(arr[nextindex]==NULL){
                arr[nextindex]=temp;
            }

            else{
                cout<<"FULL"<<endl;
            }
            
        }
    }



    void print(){
        for(int i=0;i<10;i++){
            if(arr[i]!=NULL){
                cout<<"Index "<<i<<" : "<<arr[i]->name<<" - "<<arr[i]->no<<endl;
            }
        }
    }

 
  void search(pairkv* pair) {
    int h = gethash(pair->no);
    
    if (arr[h] == NULL) {
        cout << "not found" << endl;
        return;
    }
    if (arr[h]->no == pair->no && arr[h]->name == pair->name) {
        cout << "present1" << endl;
        return;
    }
    int nextindex = (h + 1) % 10;
    while (nextindex != h) {
        if (arr[nextindex] != NULL && arr[nextindex]->no == pair->no && arr[nextindex]->name == pair->name) {
            cout << "found2" << endl;
            return;
        }
        nextindex = (nextindex + 1) % 10;
    }
    cout << "not found" << endl;
}



void searchele(pairkv*pair){
    int h=gethash(pair->no);
    if(arr[h]==NULL){
        cout<<"Not found"<<endl;
        return;
    }
    if(arr[h]->no==pair->no&&arr[h]->name==pair->name){
        cout<<"Found 1"<<endl;
        return;
    }
    int nextindex=(h+1)%10;
    while(nextindex!=h){
        if(arr[nextindex]!=NULL&&arr[nextindex]->no==pair->no&&arr[nextindex]->name==pair->name){
            cout<<"found 2"<<endl;
            return;
        }
        nextindex=(nextindex+1)%10;
    }
    cout<<"Not found"<<endl;
}


};





int main(){
    pairkv*k;
    // long long int no;
    // string key;
    // cout<<"Enter name : ";
    // cin>>key;
    // cout<<"Enter phone : ";
    // cin>>no;
    // k=new pairkv(key,no);
    table t;
    // t.withoutr(k);
    t.withr(new pairkv("a",1));
    t.withr(new pairkv("b",1));
    t.withr(new pairkv("m",1));
    t.withr(new pairkv("c",2));
    // t.withr(new pairkv("d",3));
    // t.withr(new pairkv("c",2));
    // t.withr(new pairkv("d",3));
    // t.withr(new pairkv("e",3));
   
    t.print();
    // t.search(new pairkv("m",1));
    t.searchele(new pairkv("m",1));

    
    return 0;
}