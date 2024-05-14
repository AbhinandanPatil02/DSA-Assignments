#include<iostream>
#include<fstream>
using namespace std;

class hash1{
    public:
    int arr[10];
    int arr1[10];
    hash1(){
        for(int i=0;i<10;i++){
            arr[i]=-1;
            arr1[i]=-1;
        }

    }

    void insert(int roll,int loc);
    int search(int x);
    void del(int x);
    int hashcode(int roll);
    void display();

    friend class student;

};

int hash1  :: hashcode(int roll){
    return roll%10;
}

void hash1 :: insert(int roll,int loc){
    int h=hashcode(roll);
    if(arr[h]==-1){
        arr[h]=roll;
        arr1[h]=loc;
    }
    else{
        int temp=arr[h];
        int temp1=arr1[h];
        int nextindex=h%10;
        if(hashcode(temp)==nextindex){
            while(arr[nextindex]!=-1){
                nextindex=(nextindex+1)%10;
            }
            arr[nextindex]=roll;
            arr1[nextindex]=loc;
        }
        else{
            arr[nextindex]=roll;
            arr1[nextindex]=loc;
            while(arr[nextindex]!=-1){
                nextindex=(nextindex+1)%10;
            }
            arr[nextindex]=temp;
            arr1[nextindex]=temp1;
        }
    }

}

int hash1::search(int x){

    int h=hashcode(x);
    int flag=0;
    while (arr[h]!=-1)
    {
        if(arr[h]==x){
            flag=1;
            return arr1[h];
        }
        h=(1+h)%10;
        if(h==hashcode(x)){
            break;
        }
    }
    if(flag==0){
        return -1;
    }
}


void hash1::display(){
    for(int i=0;i<10;i++){
        if(arr[i]==-1){
            cout<<" --------Empty--------" <<endl;
        }
        else{
            cout<<"Roll no : "<<arr[i]<<"  Location : "<<arr1[i]<<endl;
        }
    }
}

void hash1::del(int x){
    int h=hashcode(x);
    while(arr[h]!=-1){
        if(arr[h]==x){
            arr[h]=-1;
            arr1[h]=-1;
        }
        h=(h+1)%10;
        if(h==hashcode(x)){
            cout<<"Element not found "<<endl;
        }
    }
}


class student{
    public:
    int roll;
    string name;
    string div;
    string address;
    student(){
        roll=0;
        name="";
        div="";
        address="";
    }
    student(int r,string n,string d,string a){
        roll=r;
        name=n;
        div=d;
        address=a;
    }

    
    friend fstream&operator<<(fstream&out,student&s);
    friend fstream&operator>>(fstream&in,student&s);
    friend ostream&operator<<(ostream&out,student&s);

    void displayf(fstream &in,student &s);
    void searchf(fstream &in,int x,student &s);
    void deletest(fstream &in,int x,student &s,int n);
    // void deletest2(fstream &in,int x,student &s,int n);


};

fstream&operator<<(fstream&out,student&s){
    out<<s.name<<" ";
    out<<s.roll<<" ";
    out<<s.div<<" ";
    out<<s.address<<" ";
    cout<<endl;
    return out;

}

fstream&operator>>(fstream&in,student&s){
    in>>s.name;
    in>>s.roll;
    in>>s.div;
    in>>s.address;
    return in;
}

ostream&operator<<(ostream&out,student&s){
    out<<s.name<<" ";
    out<<s.roll<<" ";
    out<<s.div<<" ";
    out<<s.address<<" ";
    cout<<endl;
    return out;
}

void student :: displayf(fstream &in,student &s){
    in.open("sample.txt",ios::in);
    while(1){
        in>>s;
        if(in.eof()){
            break;
        }
        // cout<<s;
        cout<<s;
    }
    in.close();

}

void student::searchf(fstream &in,int x,student &s){

    in.open("sample.txt",ios::in);
    while(1){
        in>>s;
        if(x==s.roll){
            cout<<s;
            break;
        }
        if(in.eof()){
            cout<<"Student not found !!! "<<endl;
        }
    }
    in.close();

}

void student :: deletest(fstream &in,int x,student &s,int n){
    hash1 h;
    student arr[n];
    in.open("sample.txt",ios::in);
    for(int i=0;i<n;i++){
        in>>s;
        arr[i]=s;
    }
    in.close();
    in.open("sample.txt",ios::out|ios::trunc);
    for(int i=0;i<n;i++){
        if(arr[i].roll==x){
            continue;
        }
        else{
            int l=in.tellp();
            in>>s;
            s=arr[i];
            h.insert(s.roll,l);
            cout<<s;
        }
    }
    in.close();
}

/*



void student :: del(fstream &in,int x,student &s,int n){
    student arr[n];
    hash1 h;
    in.open("sample.txt",ios::in);
    for(int i=0;i<n;i++){
        in>>s;
        arr[i]=s;

    }
    in.close();
    in.open("sample.txt",ios::out|ios::trunc);
    for(int i=0;i<n;i++){
        if(arr[i].roll==x){
            continue;
        }
        else{
            int l=int.tellp();
            in>>s;
            s=arr[i];
            h.insert(s.roll,l);
            cout<<s;

        }
    }
    in.close();

}



*/






int main()
{

    hash1 h;
    student s;
    fstream myfile;
    int c=1;
    int n;
    while(c>0)
    {
        cout<<"MENU"<<endl;
        cout<<"1.Add record to file"<<endl;
        cout<<"2.Display"<<endl;
        cout<<"3.Search"<<endl;
        cout<<"4.Delete"<<endl;
        cout<<"Enter your choice:";
        cin>>c;
        if(c==1)
        {
            myfile.open("sample.txt",ios::out);
            cout<<"Enter number of entries:";
            cin>>n;
            for(int i=0;i<n;i++)
            {
                int roll_no;
                string name;
                string div;
                string add;
                cout<<"Enter roll_no:";
                cin>>roll_no;
                cout<<"Enter name:";
                cin>>name;
                cout<<"Enter division:";
                cin>>div;
                cout<<"Enter address:";
                cin>>add;
                student s1(roll_no,name,div,add);
                int loc=myfile.tellp();
                myfile<<s1;
                h.insert(roll_no,loc);
                
            }
            myfile.close();
        }
        else if(c==2)
        {
            h.display();
        }
        else if(c==3)
        {
            int x;
            cout<<"Enter roll number to be searched :";
            cin>>x;
            int l=h.search(x);
            cout<<l<<endl;
            myfile.open("sample.txt",ios::in);
            myfile.seekg(l,ios::beg);
            myfile>>s;
            cout<<s;
            myfile.close();
        }
        else if(c==4){
            int x;
            cout<<"Enter roll number to be delete :";
            cin>>x;
            h.del(x);
            s.deletest(myfile,x,s,n);
        }
    }
    return 0;
}