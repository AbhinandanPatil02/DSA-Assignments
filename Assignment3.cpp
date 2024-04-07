#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;
    bool rthread;
    bool lthread;
    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        rthread = false;
        lthread = false;
    }
};

class tbt {
public:
    node *root;
    tbt() {
        root = NULL;
    }
    node *insert(node *root, int d) {
        node *ptr = root;
        node *par = NULL;
        while (ptr != NULL) {
            if (d == ptr->data) {
                cout << "duplicate data" << endl;
                return NULL;
            }
            par = ptr;
            if (d < ptr->data) {
                if (ptr->lthread == false)
                    ptr = ptr->left;
                else
                    break;
            } else {
                if (ptr->rthread == false)
                    ptr = ptr->right;
                else
                    break;
            }
        }
        node *temp = new node(d);
        temp->lthread = true;
        temp->rthread = true;
        if (par == NULL) {
            root = temp;
            temp->left = NULL;
            temp->right = NULL;
        } else if (d < par->data) {
            temp->left = par->left;
            temp->right = par;
            par->lthread = false;
            par->left = temp;
        } else {
            temp->left = par;
            temp->right = par->right;
            par->rthread = false;
            par->right = temp;
        }
        return root;
    }
    void inorder(node *root) {
        if (root == NULL) {
            cout << ("Tree is empty");
        }
        node *ptr = root;
        while (ptr->lthread == false) {
            ptr = ptr->left;
        }
        while (ptr != NULL) {
            cout << (ptr->data) << " ";
            ptr = inorderSuccessor(ptr);
        }
    }
    void preorder(node *root) {
        if (root == NULL) {
            cout << ("Tree is empty");
            return;
        }
        node *ptr = root;
        while (ptr != NULL) {
            cout << (ptr->data) << " ";
            if (ptr->lthread == false) {
                ptr = ptr->left;
            } else if (ptr->rthread == false) {
                ptr = ptr->right;
            } else {
                while (ptr != NULL && ptr->rthread == true) {
                    ptr = ptr->right;
                }
                if (ptr != NULL) {
                    ptr = ptr->right;
                }
            }
        }
    }
    node *inorderPredecessor(node *root) {
        if (root->lthread) {
            return root->left;
        }
        root = root->left;
        while (!root->rthread) {
            root = root->right;
        }
        return root;
    }
    node *inorderSuccessor(node *root) {
        if (root->rthread == true) {
            return root->right;
        }
        root = root->right;
        while (root->lthread == false) {
            root = root->left;
        }
        return root;
    }
    node *deletenode(node *root, int key) {
        node *par = NULL;
        node *ptr = root;
        bool found = false;
        while (ptr != NULL) {
            if (key == ptr->data) {
                found = true;
                break;
            }
            par = ptr;
            if (key < ptr->data) {
                if (ptr->lthread == false)
                    ptr = ptr->left;
                else
                    break;
            } else {
                if (ptr->rthread == false)
                    ptr = ptr->right;
                else
                    break;
            }
        }
        if (!found) {
            cout << "Key is not present in the tree." << endl;
            return root;
        }
        // Case A: Node to be deleted has no children
        if (ptr->lthread && ptr->rthread) {
            root = caseA(root, par, ptr);
        }
        // Case B: Node to be deleted has only one child
        else if (ptr->lthread && !ptr->rthread) {
            root = caseB(root, par, ptr, ptr->right);
        } else if (!ptr->lthread && ptr->rthread) {
            root = caseB(root, par, ptr, ptr->left);
        }
        // Case C: Node to be deleted has two children
        else {
            root = caseC(root, ptr);
        }
        return root;
    }
    // Case A: Node to be deleted has no children
    node *caseA(node *root, node *par, node *ptr) {
        cout << "par : " << par->data << endl;
        cout << "ptr : " << ptr->data << endl;
        if (ptr == par->left) {
            cout << "par : " << par->data << endl;
            cout << "ptr : " << ptr->data << endl;
            par->left = ptr->left;
            par->lthread = true;
            delete ptr;
        } else {
            cout << "par : " << par->data << endl;
            cout << "ptr : " << ptr->data << endl;
            par->right = ptr->right;
            par->rthread = true;
            delete ptr;
        }
        return root;
    }
    // Case B: Node to be deleted has only one child
    node *caseB(node *root, node *par, node *ptr, node *child) {
        if (ptr == par->left) {
            par->left = child;
        } else {
            par->right = child;
        }
        node *succ = inorderSuccessor(ptr);
        node *pred = inorderPredecessor(ptr);
        if (ptr->lthread) {
            pred->right = succ;
        }
        if (ptr->rthread) {
            succ->left = pred;
        }
        delete ptr;
        return root;
    }
    // Case C: Node to be deleted has two children
    node *caseC(node *root, node *ptr) {
        node *succ = inorderSuccessor(ptr);
        node *parSucc = NULL;
        while (succ->lthread == false) {
            parSucc = succ;
            succ = succ->left;
        }
        ptr->data = succ->data;
        if (succ->lthread && succ->rthread) {
            root = caseA(root, parSucc, succ);
        } else {
            root = caseB(root, parSucc, succ, succ->right);
        }
        return root;
    }
};

int main() {
    node *root = NULL;
    tbt t;
    int o;
    int k = 1;
    while (k == 1) {
        cout << "-------------------------------------------------------------------------------------------------" << endl;
        cout << "Menu\n1)Insert node in tree\n2)Print inorder\n3)Print preorder \n4)print Successor\n5)Delete node" << endl;
        cout << "Enter index : ";
        cin >> o;
        if (o == 1) {
            cout << "-------------------------------------------------------------------------------------------------" << endl;
            cout << "Enter the data you want to insert";
            int l;
            cin >> l;
            root = t.insert(root, l);
            cout << "-------------------------------------------------------------------------------------------------" << endl;
        } else if (o == 2) {
            cout << "-------------------------------------------------------------------------------------------------" << endl;
            cout << "inorder is : ";
            t.inorder(root);
            cout << endl;
            cout << "-------------------------------------------------------------------------------------------------" << endl;
        } else if (o == 3) {
            cout << "-------------------------------------------------------------------------------------------------" << endl;
            cout << "Preorder is ";
            t.preorder(root);
            cout << endl;
            cout << "-------------------------------------------------------------------------------------------------" << endl;
        } else if (o == 4) {
            cout << "-------------------------------------------------------------------------------------------------" << endl;
            node *successor = t.inorderSuccessor(root);
            if (successor) {
                cout << "Inorder successor: " << successor->data << endl;
            } else {
                cout << "No inorder successor found!" << endl;
            }
            cout << "-------------------------------------------------------------------------------------------------" << endl;
        } else if (o == 5) {
            cout << "-------------------------------------------------------------------------------------------------" << endl;
            int g;
            cout << "Enter the element you want to delete : ";
            cin >> g;
            t.deletenode(root, g);
            cout << endl;
            t.inorder(root);
            cout << "-------------------------------------------------------------------------------------------------" << endl;
        } else {
            cout << "-------------------------------------------------------------------------------------------------" << endl;
            cout << "Enter correct input" << endl;
            cout << "-------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "Do you want to continue : ";
        cin >> k;
    }
    return 0;
}