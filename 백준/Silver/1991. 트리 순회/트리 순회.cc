#include <iostream>
#include <unordered_map>

using namespace std;

struct node {
        char left;
        char right;
};

unordered_map<char,node> tree;

void preorder(char node) {

    if (node == '.') return;
    cout << node;
    preorder(tree[node].left);
    preorder(tree[node].right);
}

void inorder(char node) {
    if (node == '.') return;
    inorder(tree[node].left);
    cout << node;
    inorder(tree[node].right);
}

void postorder(char node) {
    if (node == '.') return;
    postorder(tree[node].left);
    postorder(tree[node].right);
    cout << node;
}

int main(){
        int n;
        cin >> n;
        for(int i=0; i< n; ++i){
                char parent, left, right;
                cin >> parent >> left >> right;
                tree[parent]= {left,right};
        }

        preorder('A');
        cout << endl;
        inorder('A');
        cout << endl;
        postorder('A');
        cout << endl;

}