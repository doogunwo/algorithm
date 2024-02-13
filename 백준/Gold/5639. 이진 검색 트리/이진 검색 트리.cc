#include <iostream>
#include <vector>
using namespace std;

// 이진 검색 트리 노드 구조체
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// 이진 검색 트리에 노드 삽입
void insert(Node*& root, int value) {
    if (root == nullptr) {
        root = new Node(value);
        return;
    }

    if (value < root->data) {
        insert(root->left, value);
    } else {
        insert(root->right, value);
    }
}

// 이진 검색 트리 후위 순회
void postOrderTraversal(Node* root) {
    if (root == nullptr) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Node* root = nullptr;
    int num;

    // 입력을 받아 이진 검색 트리 구축
    while (cin >> num) {
        insert(root, num);
    }

    // 후위 순회 결과 출력
    postOrderTraversal(root);

    return 0;
}
