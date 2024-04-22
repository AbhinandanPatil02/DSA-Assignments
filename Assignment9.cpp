#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    node*right;
    node*left;
    int data;
    int height;
    node(int data){
        this->right=NULL;
        this->left=NULL;
        this->data=data;
        this->height=1;
    }
};

class AVL{
    public:
    node*root;
    AVL(){
        root=NULL;
    }

    int height(node*root){
        if(root==NULL){
            return 0;
        }
        else{
            return root->height;
        }
    }

    int getbal(node*root){
        if(root==NULL){
            return 0;
        }
        else{
            return height(root->left)-height(root->right);
        }
    }

    node*createbst(node*&root){
        int data;
        cout<<"Enter root : ";
        cin>>data;
        while(data!=-1){
            root=insertinbst(root,data);
            cout<<"data : ";
            cin>>data;

        }
        return root;
    }

    node*insertinbst(node*&root,int data){
        if(root==NULL){
            root=new node(data);
            return root;
        }
        if(data>root->data){
            root->right=insertinbst(root->right,data);
        }
        else{
            root->left=insertinbst(root->left,data);

        }

        root->height=1+max(height(root->left),height(root->right));

        int balance=getbal(root);
        //ll
        if(balance>1&&data<root->left->data){
            return rightrotate(root);
        }

        //rr
        if(balance<-1&&data>root->right->data){
            return leftrotate(root);
            
        }

        //lr
        if(balance>1&&data>root->left->data){
            root->left=leftrotate(root->left);
            return rightrotate(root);
        }

        //rl
        if(balance<-1&&data<root->right->data){
            root->right=rightrotate(root->right);
            return leftrotate(root);
        }
        
        return root;

    }

    node*leftrotate(node*root){
        node*newroot=root->right;
        root->right=newroot->left;
        newroot->left=root;

        root->height=1+max(height(root->left),height(root->right));
        newroot->height=1+max(height(newroot->left),height(newroot->right));
        return newroot;
    }

    node*rightrotate(node*root){
        node*newroot=root->left;
        root->left=newroot->right;
        newroot->right=root;

        root->height=1+max(height(root->left),height(root->right));
        newroot->height=1+max(height(newroot->left),height(newroot->right));
        return newroot;
    }

    void inorder(node*root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    void levelorder(node*root){
        if(root==NULL){
            return;
        }
        queue<node*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            node*front=q.front();
            q.pop();
            if(front==NULL){
                cout<<endl;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                cout<<front->data<<" ";
                if(front->left!=NULL){
                    q.push(front->left);
                }
                if(front->right!=NULL){
                    q.push(front->right);
                }   
            }
        }
    }

    node*mini(node*root){
        if(root==NULL){
            return NULL;
        }
        node*temp=root;
        while(temp->left){
            temp=temp->left;
        }
        return temp;
    }

    node* deletenode(node* root, int target) {
    if (root == NULL) {
        return NULL;
    }

    // Search for the target node
    if (target < root->data) {
        root->left = deletenode(root->left, target);
    } 
    else if (target > root->data) {
        root->right = deletenode(root->right, target);
    } 
    else {
        // Node to be deleted found
        
        // Case 1: Node has no children
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Case 2: Node has one child
        else if (root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        } 
        else if (root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Node has two children
        else {
            // Find the minimum value node in the right subtree (or maximum value node in the left subtree)
            node* temp = mini(root->right);

            // Copy the data of the minimum value node to this node
            root->data = temp->data;

            // Delete the minimum value node
            root->right = deletenode(root->right, temp->data);
        }
    }

    // Update height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    // Check balance factor and perform rotations if necessary
    int balance = getbal(root);
    //ll
    if (balance > 1 && getbal(root->left) >= 0) {
        return rightrotate(root);
    }
    //lr
    if (balance > 1 && getbal(root->left) < 0) {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    //rr
    if (balance < -1 && getbal(root->right) <= 0) {
        return leftrotate(root);
    }
    //rl
    if (balance < -1 && getbal(root->right) > 0) {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }

    return root;
}


};

// 20 11 5 32 40 2 4 27 23 28 50 -1

int main(){
    AVL t;
    node*root=NULL;
    root=t.createbst(root);
    cout<<endl;
    cout<<"Inorder : ";
    t.inorder(root);
    cout<<endl;
    cout<<"Level Order : "<<endl;
    t.levelorder(root);
    // cout<<"Deleting 11 "<<endl;
    // t.deletenode(root,11);
    t.levelorder(root);
    int k=1;
    while(k!=-1){
        int d;
        cout<<"Data to delete : ";
        cin>>d;
        t.deletenode(root,d);

        cout<<"After deletion of : "<<d<<endl;
        t.levelorder(root);
        cout<<"Want to cntinue : ";
        cin>>k;
    }

    
    return 0;
}