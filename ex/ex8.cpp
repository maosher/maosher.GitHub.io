

#include <iostream>
#include <stack>
#include <list>


struct Node {
    Node(int va) 
    : left(nullptr)
    , right(nullptr)
    ,value(va){}
    Node* left;
    Node *right;
    int value;
};

void printTree(Node* node){
    std::list<Node*> li;
    li.push_back(node);
    while (!li.empty())    {
        auto node = li.front();
        li.pop_front();
        std::cout << node->value << std::endl;
        if(node->left){
            li.push_back(node->left);
        }
        if(node->right){
            li.push_back(node->right);
        }
    }
}
void postOrder(Node *node) {
  std::stack<Node *> st;

  while (node != nullptr || !st.empty()) {
   while (node != nullptr) {
      st.push(node);
      node = node->left;
    }
    node = st.top();
    st.pop();
    if(node->right != nullptr){
        node = node->right;
    } else {
        std::cout << node->value << std::endl;
        node = nullptr;
    }
  }
}

void insertTree(Node* cur, int i){
    while (cur)   {
        if (i < cur->value ){
            if(cur->left != nullptr){
                cur = cur->left;
                continue;
            }  else {
                cur->left = new Node(i);
                return;
            }
        }

        if(cur->right != nullptr){
            cur = cur->right;
            continue;
        } else {
            cur->right = new Node(i);
            return;
        }
    }
}

int main(){
    Node *head = new Node(5);
    for(int i = 1; i < 10; i++){
        if (i == 5){
            continue;
        }
        insertTree(head, i);
    }

    printTree(head);
  std::cout << "_______________" << std::endl;
    postOrder(head);

    
    return 0;
}