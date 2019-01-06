#include<bits/stdc++.h>
#define INF 1e9
using namespace std;

template<class T>
class myVector
{
private:
    int len;
    int cap;
    T *data;

public:
    myVector() {
        data = new T[4];
        cap = 4;
        len = 0;
    }
    myVector(const int n) {
        data = new T[n];
        cap = n;
        len = n;
    }
    void Push_back(const T &val) {
        if( len == cap ) {
            T *tmpData = new T[2*cap];
            for(int i =0 ; i < cap ; i++ ) {
                tmpData[i] = data[i];
            }
            cap *=2;
            delete[] data;
            data = tmpData;
        }
        data[len++] = val;
    }
    void Pop_back() {
        len--;
    }

    T& operator[](const int pos) {
        return data[pos];
    }

    void Clear() {
        delete[] data;
        data = new T[4];
        cap = 4;
        len = 0 ;
    }
    int Size() {
        return len;
    }

    ~myVector() {
        delete[] data;
    }
};

template<class T>
class Node {

public:
    Node<T> *left , *right , *parent;
    T data;
    Node(T data) {
        this->data= data;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

template<class T>
class treePrinterUtil {
    myVector<Node<T>*>Nodes;

public:

    void printNode(Node<T>*root) {
        if( root==NULL) return;

        int maxLvl = maxLevel(root);
        Nodes.Clear();

        Nodes.Push_back(root);
        printNodeInternal(maxLvl);
    }

    int maxLevel(Node<T>*currNode) {
        if( currNode == NULL) return 0;
        return max( maxLevel(currNode->left ), maxLevel(currNode->right) ) + 1;
    }

    bool isAllElementsNull() {
        for(int i =0 ; i < Nodes.Size() ; i++) {
            if( Nodes[i] != NULL) return false;
        }
        return true;
    }

    void printWhitespaces(int cnt) {
        for(int i =0 ; i < cnt ; i++ ) cout<<" ";
    }

    void printNodeInternal(int maxLevel) {

        for(int level =1 ; level<=maxLevel ; level++) {


            int floor = maxLevel - level;
            int endgeLines = 1 << max(floor - 1, 0) ;
            int firstSpaces = (1<< floor ) - 1;
            int betweenSpaces = (1<<(floor + 1) ) - 1;

            printWhitespaces(firstSpaces);

            myVector<Node<T>*>newNodes;

            for(int i =0 ; i < Nodes.Size() ; i++) {

                if( Nodes[i] ==NULL) {
                    newNodes.Push_back(NULL);
                    newNodes.Push_back(NULL);
                    cout<<" ";
                }
                else {
                    cout<<Nodes[i]->data;
                    newNodes.Push_back(Nodes[i]->left);
                    newNodes.Push_back(Nodes[i]->right);
                }
                printWhitespaces(betweenSpaces);
            }

            cout<<endl;

            for (int i = 1; i <= endgeLines; i++) {
                for (int j = 0; j < Nodes.Size(); j++) {
                    printWhitespaces(firstSpaces - i);
                    if (Nodes[j] == NULL) {
                        printWhitespaces(endgeLines + endgeLines + i + 1);
                        continue;
                    }

                    if (Nodes[j]->left != NULL)
                         cout<<"/";
                    else
                        printWhitespaces(1);

                    printWhitespaces(i + i - 1);

                    if (Nodes[j] -> right != NULL)
                        cout<<"\\";
                    else
                        printWhitespaces(1);

                    printWhitespaces(endgeLines + endgeLines - i);
                }

                cout<<endl;
            }

            Nodes.Clear();
            for(int i =0 ; i < newNodes.Size() ; i++ ) Nodes.Push_back(newNodes[i]);
        }
    }

};

template<class T>
class splayTree {

    treePrinterUtil<T> printer;


public:
    Node<T>*root;

    splayTree<T>() {
        root = NULL;
    }
    splayTree<T>(Node<T>* root) {
        this->root = root;
    }
    void print() {
        printer.printNode(root);
    }

    void leftRotate(Node<T>* x) {
        Node<T>* par = x->parent;
        Node<T>* grand = par->parent;
        Node<T>* lft = x->left;
        Node<T>* rt = x->right;

        x->parent = grand;

        if( grand != NULL ) {
            if( grand->left == par) grand->left = x;
            else grand->right = x;
        }
        x->left = par;

        par->parent = x;
        par->right = lft;

        if( lft != NULL) lft->parent = par;

    }

    void rightRotate(Node<T>* x) {

        Node<T>* par = x->parent;
        Node<T>* grand = par->parent;
        Node<T>* lft = x->left;
        Node<T>* rt = x->right;

        x->parent = grand;

        if( grand != NULL ) {
            if( grand->left == par) grand->left = x;
            else grand->right = x;
        }

        x->right = par;

        par->parent = x;
        par->left = rt;

        if( rt != NULL ) rt->parent = par;
    }

    void splay(T val) {

        if( root == NULL) return;

        Node<T> *x ;

        Node<T> *now = root;

        while(1) {

            if(val == now->data) {
                x = now;
                break;
            }
            else if(val < now->data) {
                if( now->left ==NULL) {
                    x = now;
                    break;
                }
                now = now->left;
            }
            else if( val > now->data ){
                if( now->right ==NULL) {
                    x = now;
                    break;
                }
                now = now->right;
            }
        }

        while(x->parent !=NULL) {
            Node<T>* par= x ->parent;
            Node<T>* grand = par->parent;
            if( grand == NULL) zig(x);
            else if( grand->left == par && par->left == x) zig_zig(x);
            else if( grand->right == par && par->right == x ) zig_zig(x);
            else zig_zag(x);
        }
        root = x;
    }

    void zig(Node<T>* x) {

        Node<T>* par = x->parent;

        if( par->left == x) rightRotate(x);
        else leftRotate(x) ;
    }

    void zig_zig(Node<T>* x) {
        Node<T>*par = x->parent;

        if( par ->left == x) {
            rightRotate(par);
            rightRotate(x);
        }
        else {
            leftRotate(par);
            leftRotate(x);
        }
    }

    void zig_zag(Node<T>* x) {
        Node<T> *par = x->parent;

        if(par->right ==x ) {
            leftRotate(x);
            rightRotate(x);
        }
        else {
            rightRotate(x);
            leftRotate(x);
        }
    }

    void Insert(T val) {

        if( root == NULL) {
            root = new Node<T>(val);
            return;
        }
        splay(val);
        if( root->data == val) return;

        Node<T> *tmp = new Node<T>(val);

        if(tmp->data > root->data ) {

            tmp->left = root;
            tmp->right= root->right;

            if( root->right !=NULL) root->right->parent = tmp;
            root->right = NULL;
            root->parent = tmp;
        }
        else {
            tmp->right = root;
            tmp->left = root->left;

            if( root->left !=NULL) root->left->parent = tmp;
            root->left = NULL;
            root->parent = tmp;
        }
        root = tmp;
    }


    void Search(int key) {
        splay(key);
//        if(root !=NULL && root->data == key) {
////            cout<<"Found!"<<endl;
//        }
//        else cout<<"Not Found!"<<endl;
    }


    void join(Node<T>* leftNode , Node<T>*rightNode) {

        if( leftNode == NULL) {
            root = rightNode;
            if( root != NULL) root->parent = NULL;
            return;
        }
        if( rightNode == NULL) {
            root = leftNode;
            if( root != NULL) root->parent = NULL;
            return;
        }
        root = leftNode;
        root->parent = NULL;
        splay(INF);
        root->right = rightNode;
        if(rightNode!=NULL) rightNode->parent = root;
    }

    void Delete(int key) {
        splay(key);
        if( root==NULL || root->data != key ){
//            cout<<"Not Deleted"<<endl;
            return;
        }
        Node<T>* tmp = root;
        join(root->left , root->right);
//        cout<<"Deleted"<<endl;
        delete tmp;
    }
    ~splayTree<T>() {
        while( root != NULL ) {
            Delete(root->data);
        }
    }

};



void myprinter(Node<int>*root)  {

    if( root== NULL) return ;
    myprinter(root->left);
    cout<<root->data<<endl;
    myprinter(root->right);

}

int main()
{
    splayTree<int> sTree;

    int n;
    cin>>n;
    while( n --) {
        int tmp;
        cin>>tmp;
        sTree.Insert(tmp);
    }

    sTree.Search(-200);
    sTree.Delete(sTree.root->data);

    if( sTree.root == NULL ) cout<<"NO"<<endl;
    else {
        sTree.Search(-200);
        cout<<sTree.root->data<<endl;
    }
    return 0;
}

