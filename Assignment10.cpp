#include<iostream>
using namespace std;

class heap{
    public:
    int *arr;
    int size;
    int capacity;

    heap(int capacity){
        this->arr=new int[capacity];
        this->size=0;
        this->capacity=capacity;
    }

    void insert(int val){
        if(size==capacity){
            cout<<"Overflow heap "<<endl;
            return;
        }
        size++;
        int index=size;
        arr[index]=val;
        while(size>1){
            int parentindex=index/2;
            if(arr[index]>arr[parentindex]){
                swap(arr[index],arr[parentindex]);
                index=parentindex;
            }
            else{
                break;
            }
        }
    }

    int deletedata(){
        int ans=arr[1];
        int index=1;
        arr[1]=arr[size];
        size--;

        while(index<=size){
            int leftindex=index*2;
            int rightindex=index*2+1;
            int largesteleindex=index;
            if(leftindex<=size&&arr[leftindex]>arr[largesteleindex]){
                largesteleindex=leftindex;
            }
            if(rightindex<=size&&arr[rightindex]>arr[largesteleindex]){
                largesteleindex=rightindex;
            }

            if(largesteleindex==index){
                break;
            }
            else{
                swap(arr[index],arr[largesteleindex]);
                index=largesteleindex;
            }

        }
        return ans;
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
    }


};

int main(){

    heap h(20);

    h.insert(5);
    h.insert(15);
    h.insert(55);
    h.insert(12);
    h.insert(1);
    // h.print();

    for(int i=0;i<5;i++){
        int a=h.deletedata();
        cout<<a<<" ";
    }
    cout<<endl; 
    return 0;
}