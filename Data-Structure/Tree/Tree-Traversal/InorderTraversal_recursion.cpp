// Inorder Traversal using Recursion

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
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

void inorder(Node *root) {
  if (root == NULL)
    return;

  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

int main(void) {
  Node *root = NULL;
  int t;
  cout << "Enter total number of nodes: \n";
  cin >> t;

  for (int i = 1; i <= t; i++) {
    int n;
    cout << "Enter node " << i << ": " << endl;
    cin >> n;
    root = Insert(root, n);
  }

  cout << "Inorder: ";
  inorder(root);
  return 0;
}

//input = 50 30 20 40 70 60 80
//output = 20 30 40 50 60 70 80