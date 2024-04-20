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
        // if(root==NULL){
        //     return;
        // }
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

    node*deletenode(node*root,int target){
        if(root==NULL){
            return NULL;
        }
        if(target==root->data){
            if(root->left==NULL&&root->right==NULL){
                delete root;
                return NULL;
            }
            if(root->left!=NULL&&root->right==NULL){
                node*subtree=root->left;
                delete root;
                return subtree;
            }
            if(root->right!=NULL&&root->left==NULL){
                node*subtree=root->right;
                delete root;
                return subtree;
            }

            else{
                node*min=mini(root->right);
                root->data=min->data;
                root->right=deletenode(root->right,min->data);
                return root;
            }

        }

        if(target>root->data){
            root->right=deletenode(root->right,target);
        }
        else{
            root->left=deletenode(root->left,target);
        }

        return root;
    }

};


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
    cout<<"Deleting 11 "<<endl;
    t.deletenode(root,11);
    t.levelorder(root);
    
    return 0;
}