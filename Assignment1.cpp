#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;


    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

class bintree{
    public:
        int count=0;
        int total=0;
        node*root;
    bintree(){
        root=NULL;
    }
    
    node*create(){
        queue<node*>q;

        int data;
        cout<<"Enter root ";
        cin>>data;
        node*root=new node(data);

        if(root!=NULL){
            q.push(root);
        }

        while(!q.empty()){
            node*curr=q.front();
            
            int l,r;
            cout<<"insert data left of (insert -1 if none) "<<curr->data<<" : ";
            cin>>l;
            if(l!=-1){
                curr->left=new node(l);
                q.push(curr->left);
            }  
            cout<<"enter data right of (insert -1 if none) "<<curr->data<<" : ";
            cin>>r;
            if(r!=-1){
                curr->right=new node(r);
                q.push(curr->right);
            }
            q.pop();

        }
        return root;

    }

    void preorder(node*root){
        //NLR
        if(root==NULL){
            return;
        }
        else{
            cout<<root->data<<" ";

            preorder(root->left);

            preorder(root->right);

        }
    }

    void inorder(node*root){
        //LNR
        if(root==NULL){
            return;
        }
        else{
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
    }

    void postorder(node*root){
        //LRN
        if(root==NULL){
            return;
        }
        else{
            postorder(root->left);
            postorder(root->right);
            cout<<root->data<<" ";
        }
    }

    int height(node*root){
        int count=1;
        queue<node*>p;
        if(root==NULL){
            return 0;
        }
        else{
            p.push(root);
            p.push(NULL);

            while(p.size()>1){
                node*front=p.front();
                p.pop();
                if(front==NULL){
                    count++;
                    p.push(NULL);
                }
                else{
                    if(front->left!=NULL){
                        p.push(front->left);
                    }
                    if(front->right!=NULL){
                        p.push(front->right);
                    }
                }
            }
            cout<<"height is : "<<count<<endl;
        }
    }

    int leaf(node*root){       
        if(root==NULL){
            return 0;
        }
        else{          
            if(root->left==NULL&&root->right==NULL){
                count++;
            }
            else{
                if(root->left!=NULL){
                    leaf(root->left);  
                }
                if(root->right!=NULL){
                    leaf(root->right);
                }   
            }           
        }
        return count;
    }

    int totalnodes(node* root) {
        if (root == NULL) {
            return 0;
        } 
        else {
            return 1 + totalnodes(root->left) + totalnodes(root->right);
        }
    }

    node*swapleftright(node*root){
        if(root==NULL){
            return NULL;
        }
        node*temp=root->left;
        root->left=root->right;
        root->right=temp;
        swapleftright(root->left);
        swapleftright(root->right);

    }

    void levelorder(node*root){
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

    void deleteBinaryTree(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        deleteBinaryTree(root->left);
        deleteBinaryTree(root->right);
        delete root;
    }

    node *operator=(node *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        node *tcopy = new node(root->data);
        tcopy->left = operator=(root->left);
        tcopy->right = operator=(root->right);
        return tcopy;
    }
    
      //12 23 14 15 56 89 -1 -1 -1 -1 -1 -1 -1 -1
};



int main(){
    bintree t;
    node*k=NULL;
    node*root=t.create();   

    int i,leaf,total;

    while(i!=0){
        cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"MENU : \n1)Preorder traversal\n2)Inorder traversal\n3)Postorder traversal\n4)Print level order\n5)No of leaf nodes\n6)Total no of nodes\n7)Swap the nodes\n8)Copy the tree\n9)Delete the tree "<<endl;
        cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
        int o;
        cout<<"Enter The Index : ";
        cin>>o;

        switch (o)
        {
        case 1:
        cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
            t.preorder(root);
            cout<<endl;
        cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
            break;
        case 2:
        cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
            t.inorder(root);
            cout<<endl;  
        cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;  
            break;
        case 3:
        cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
            t.postorder(root);
            cout<<endl; 
        cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;   
            break;
        case 4:
        cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
            t.levelorder(root);  
        cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;  
            break;
        case 5:
        cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
            leaf=t.leaf(root);
            cout<<"leaf nodes are : "<<leaf<<endl;     
        cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;  
            break;
        case 6:
        cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
            total=t.totalnodes(root);
            cout<<"total nodes are : "<<total<<endl;   
        cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;     
            break;
        case 7:
        cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
            t.swapleftright(root);
                cout<<endl;
            t.levelorder(root);
                cout<<endl;
        cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
            
            break;
        case 8:
        cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
             
                k=root;
                cout<<"New tree is : "<<endl;
                t.levelorder(k);
        cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
            break;
        
        case 9:
        cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
            t.deleteBinaryTree(root);
            cout<<"Tree is deleted Successfully "<<endl;    
        cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;   
            break;
        
        default:

            cout<<"Enter Correct Index !!! "<<endl;
            break;
        }
        cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;

        cout<<"Do you want to continue (1/0) : ";
        cin>>i;
    }
   

    return 0;
}

