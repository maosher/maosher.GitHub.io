
#include <iostream>
#include <queue>
#include <stack>

struct Node {
  Node *left;
  Node *right;
  int value;
  Node() : left(nullptr), right(nullptr), value(0) {}
};
void inOrder(Node *node) {
  std::stack<Node *> st;
  while (node != nullptr || !st.empty()) {
    while (node != nullptr) {
      st.push(node);
      node = node->left;
    }

    node = st.top();
    st.pop();
    std::cout << node->value << std::endl;
    node = node->right;
  }
}

void inOrderRecursive(Node *node) {
  if (node->left != nullptr) {
    inOrderRecursive(node->left);
  }
  std::cout << node->value << std::endl;
  if (node->right != nullptr) {
    inOrderRecursive(node->right);
  }
}
int main() {
  Node *root = new Node();
  root->value = 0;
  int index = 1;

  std::queue<Node *> st;
  st.push(root);

  while (!st.empty() && index < 10) {
    auto n = st.front();
    st.pop();
    n->left = new Node();
    n->left->value = index;
    n->right = new Node();
    n->right->value = index + 1;
    st.push(n->left);
    st.push(n->right);
    index += 2;
  }
  std::cout << "inOrderRecursive" << std::endl;
  inOrderRecursive(root);
  std::cout << "inOrder" << std::endl;
  inOrder(root);
  return 0;
}