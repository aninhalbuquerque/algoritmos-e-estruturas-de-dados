#include <iostream>
using namespace std;

typedef struct bstnode{
    string key;
    int element;
    struct bstnode *left;
    struct bstnode *right;
}BSTNode;

typedef struct bst{
    BSTNode *root;
    int tam;
} BST;

BSTNode *create_bstnode(string key, int e){
    BSTNode *node = new BSTNode;
    node->key = key;
    node->element = e;
    node->left = NULL;
    node->right = NULL;
    return node;
}

BST *create_bst(){
    BST *bst = new BST;
    bst->root = NULL;
    bst->tam = 0;
    return bst;
}

void clear(BST *bst){
    bst->root = NULL;
    bst->tam = 0;
}

int size(BST *bst){
    return bst->tam;
}

int findhelp(BSTNode *rt, string key){
    if(rt==NULL) return (int)NULL;
    if(rt->key>key){
        return findhelp(rt->left, key);
    } else if(rt->key == key){
        return rt->element;
    } else return findhelp(rt->right, key);
}

int find(BST *bst, string key){
    return findhelp(bst->root, key);
}

BSTNode *inserthelp(BSTNode *rt, string key, int e){
    if(rt==NULL) return create_bstnode(key, e);
    if(rt->key>key){
        rt->left = inserthelp(rt->left, key, e);
    } else rt->right = inserthelp(rt->right, key, e);
    return rt;
}

void insert(BST *bst, string key, int e){
    bst->root = inserthelp(bst->root, key, e);
    bst->tam++;
}

BSTNode *getmin(BSTNode *rt){
    if(rt->left == NULL) return rt;
    return getmin(rt->left);
}

BSTNode *deletemin(BSTNode *rt){
    if(rt->left == NULL) return rt->right;
    rt->left = deletemin(rt->left);
    return rt;
}

BSTNode *removehelp(BSTNode *rt, string key){
    if(rt == NULL) return NULL;
    if(rt->key > key){
        rt->left = removehelp(rt->left, key);
    } else if(rt->key < key){
        rt->right = removehelp(rt->right, key);
    } else{
        if(rt->left==NULL) return rt->right;
        else if(rt->right == NULL) return rt->left;
        else{
            BSTNode *temp = getmin(rt->right);
            rt->element = temp->element;
            rt->key = temp->key;
            rt->right = deletemin(rt->right);
        }
    }
    return rt;
}

int remove(BST *bst, string key){
    int temp = findhelp(bst->root, key);
    if(temp!=(int)NULL){
        bst->root = removehelp(bst->root, key);
        bst->tam--;
    }
    return temp;
}

void visit_pre(BSTNode *rt){
    if(rt != NULL){
        cout << rt->key << " ";
        visit_pre(rt->left);
        visit_pre(rt->right);
    }
}

void visit_em(BSTNode *rt){
    if(rt != NULL){
        visit_em(rt->left);
        cout << rt->key << " ";
        visit_em(rt->right);
    }
}

void visit_pos(BSTNode *rt){
    if(rt != NULL){
        visit_pos(rt->left);
        visit_pos(rt->right);
        cout << rt->key << " ";
    }
}


int main(){
    BST *bst=create_bst();
    insert(bst, "ab", 1);
    insert(bst, "abcd", 3);
    insert(bst, "abc", 2);
    insert(bst, "a", 0);
    insert(bst, "abcde", 4);
    cout << find(bst, "a") << endl;
    cout << find(bst, "ab") << endl;
    cout << find(bst, "abc") << endl;
    cout << find(bst, "abcd") << endl;
    cout << find(bst, "abcde") << endl;
    visit_pre(bst->root);
    printf("\n");
    visit_em(bst->root);
    printf("\n");
    visit_pos(bst->root);
    printf("\n");
    return 0;
}