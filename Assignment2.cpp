#include <iostream>
#include <queue>
#include<vector>
using namespace std;

class node {
public:
    node *left;
    node *right;
    int data;

    node(int data) {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};

class bst {
public:
    node *root;

    int cmp;
    bst() {
        root = NULL;
        cmp=0;
    }

    node *createbst(node *&root) {
        cout << "Enter root: ";
        int data;
        cin >> data;

        while (data != -1) {
            insertinbst(root, data);
            cout << "data: ";
            cin >> data;
        }
    }

    node *insertinbst(node *&root, int data) {
        if (root == NULL) {
            root = new node(data);
            return root;
        }

        if (data > root->data) {
            root->right = insertinbst(root->right, data);
        }
        else {
            root->left = insertinbst(root->left, data);
        }

        return root;
    }

    void levelorder(node *root) {
        queue<node *> q;
        q.push(root);
        q.push(NULL);

        while (!q.empty()) {
            node *front = q.front();
            q.pop();

            if (front == NULL) {
                cout << endl;

                if (!q.empty()) {
                    q.push(NULL);
                }
            } 
            else {
                cout << front->data << " ";

                if (front->left != NULL) {
                    q.push(front->left);
                }

                if (front->right != NULL) {
                    q.push(front->right);
                }
            }
        }
    }


    node* maxnode(node *root) {
        if (root == NULL) {
            return 0;
        }

        node *temp = root;

        while (temp->right != NULL) {
            temp = temp->right;
        }

        return temp;
    }

    node* minnode(node *root) {
        if (root == NULL) {
            return 0;
        }

        node *temp = root;

        while (temp->left != NULL) {
            temp = temp->left;
        }
        return temp;
    }

    node *swapleftright(node *root) {
        if (root == NULL) {
            return NULL;
        }

        node *temp = root->left;
        root->left = root->right;
        root->right = temp;

        swapleftright(root->left);
        swapleftright(root->right);
    }
    bool search(node*root,int data){
        if(root==NULL){
            return false;
        }
        else{
            cmp++;
            if(root->data==data){
                return true;
            }
            else if(data>root->data){
                search(root->right,data);
            }
            else{
                search(root->left,data);
            }

        }

    }

    vector<int>longestpath(node*root){
        if(root==NULL){
            vector<int>t={};
            return t ;
        }
        vector<int>l;
        vector<int>r;

        l=longestpath(root->left);
        r=longestpath(root->right);

        if(l.size()>r.size()){
            l.push_back(root->data);
        }
        else {
            r.push_back(root->data);
        }

        if(l.size()>r.size()){
            return l;
        }
        else{
            return r;
        }

    }

    node*deletenode(node*root,int target){
        if(root==NULL){
            return NULL;
        }
        if(root->data==target){
            if(root->left==NULL&&root->right==NULL){
                delete root;
                return NULL;
            }
            else if(root->left!=NULL&&root->right==NULL){
                node*subtree=root->left;
                delete root;
                return subtree;
            }
            else if(root->right!=NULL&&root->left==NULL){
                node*subtree=root->right;
                delete root;
                return subtree;
            }
            else{
                node*mini=minnode(root->right);
                root->data=mini->data;
                root->right=deletenode(root->right,mini->data);
                return root;
            }
        }
        if(root->data>target){
            root->left=deletenode(root->left,target);
        }
        else if(root->data<target){
            root->right=deletenode(root->right,target);
        }
        return root;
    }

    
};

// int bst::cmp=0;
// 50 30 60 20 40 55 70 -1

int main() {
    bst t;
    node *root = NULL;
    // t.createbst(root);
    // cout << endl;

    int p=1;
    while(p!=-1){
        cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"MENU\n1)Create Bst\n2)Insert node in BST\n3)Level Order traversal\n4)Longest path\n5)Search\n6)Min element\n7)Max element\n8)Delete Node"<<endl;
        cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
        int o;
        cout<<"Enter The Index : ";
        cin>>o;
        cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
        if(o==1){
            t.createbst(root);
            cout<<endl;
            t.levelorder(root);

        }

        else if(o==2){
            cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
            cout << "Enter the node you want to insert: ";
            int d;
            cin >> d;
            t.insertinbst(root, d);
            cout<<"updated tree is : "<<endl;
            t.levelorder(root);
            cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;

        }
        else if(o==3){cout<<"Comparisons are : "<<t.cmp<<endl;
            cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
            t.levelorder(root);
            cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
        }
        else if(o==4){
            cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
            vector<int>l;
            l=t.longestpath(root);
            cout<<"Longest path is : ";
            for(int i=0;i<l.size();i++){
                cout<<l[i]<<"->";
            }
            cout<<endl;
            cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
        }
        else if(o==5){
            cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
            int k;
            cout<<"Which element you want to search : ";
            cin>>k;

            bool ans=t.search(root,k);
            if(ans){
                cout<<"Found"<<endl;
            }
            else{
                cout<<"Not Found "<<endl;
            }
            cout<<"Maximum Comparisons are : "<<t.cmp<<endl;
             cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
        }
        else if(o==6){
             cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
            cout << "Min node is " << t.minnode(root)->data << endl;
             cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
        }
        else if(o==7){
             cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
            cout << "Max node is " << t.maxnode(root)->data << endl;
             cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
        }
        else if(o==8){
             cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
             int x;
            cout<<"Enter the data you want to delete from the BST : ";
            cin>>x;
            t.deletenode(root,x);
            cout<<endl;
            cout<<"Updated tree is : "<<endl;
            t.levelorder(root);
             cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
        }
        else{
             cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
            cout<<"Enter correct input "<<endl;
             cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
        }

        cout<<"do you want to continue ";
        cin>>p;
    }

    return 0;
}
