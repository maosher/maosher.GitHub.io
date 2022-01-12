# Tree
## 非递归中序遍历二叉树
枚举当前节点(不存储输出)并用栈存储，节点指向左节点，直到左孩子为null。  
抛出栈顶访问。如果有右节点，访问其右节点重复步骤1，如有没右节点，继续重复步骤2抛出。
~~~c++
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
~~~