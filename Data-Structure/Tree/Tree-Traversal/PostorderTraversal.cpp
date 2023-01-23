// Postorder Traversal using Recursion

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

Node *Insert(Node *root, int data) {
  if (root == NULL) {
    root = new Node();
    root->data = data;
    root->left = root->right = NULL;
  } else if (data <= root->data) {
    root->left = Insert(root->left, data);
  } else {
    root->right = Insert(root->right, data);
  }
  return root;
}

void postorder(Node *root) {
  if (root == NULL)
    return;

  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}

int main(void) {
  Node *root = NULL;
  int t;
  cout << "Enter total number of nodes: ";
  cin >> t;

  for (int i = 1; i <= t; i++) {
    int n;
    cout << "Enter node " << i << ": " << endl;
    cin >> n;
    root = Insert(root, n);
  }

  cout<<"Postorder: ";
  postorder(root);
  return 0;
}