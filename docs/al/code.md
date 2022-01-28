# Code

## 层序遍历二叉树


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

## 任务是否可完成
~~~ golang
package main

import (
	"fmt"
)

const (
	NONE = iota
	SUCC
	FAIL
	PENDING
)

func canFinish(index int, result []int, taskData [][]int) int {
	//已经判断过
	if result[index] != NONE {
		return result[index]
	}

	if len(taskData[index]) == 0 {
		result[index] = SUCC
		return SUCC
	}

	result[index] = PENDING
	for i := 0; i < len(taskData[index]); i++ {
		ret := canFinish(taskData[index][i], result, taskData)
		if ret == PENDING {
			result[index] = FAIL
			//loop back
			return FAIL
		}
		//one pretask is fail, then fail
		if ret == FAIL {
			result[index] = FAIL
			return FAIL
		}
	}

	result[index] = SUCC
	return SUCC
}
func canTaskFinish(taskCnt int, taskData [][]int) bool {
	result := make([]int, taskCnt)
	succCnt := 0
	for i := 0; i < taskCnt; i++ {
		ret := canFinish(i, result, taskData)
		if ret == SUCC {
			succCnt++
		}
	}
	return succCnt == taskCnt
}


~~~

## 动态规划 寻权重值最小的路径
~~~golang
func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
func findMinPath(s [][]int, r [][]int) {
	r[0][0] = s[0][0]
	for i := 1; i < WIDTH; i++ {
		r[i][0] = r[i-1][0] + s[i][0]
	}
	for i := 1; i < HEIGHT; i++ {
		r[0][i] = r[0][i-1] + s[0][i-1]
	}
	for i := 1; i < WIDTH; i++ {
		for j := 1; j < HEIGHT; j++ {
			r[i][j] = min(r[i][j-1], r[i-1][j]) + s[i][j]
		}
	}
}
~~~
## merge sorted slice 
~~~ golang
func mergeSortedSlice(s1 []int, s2 []int) []int {
	if s1 == nil {
		return s2
	}
	if s2 == nil {
		return s1
	}

	idx_s1 := 0
	idx_s2 := 0

	res := make([]int, 0, len(s1)+len(s2))
	for {
		if idx_s1 >= len(s1) {
			res = append(res, s2[idx_s2:]...)
			break
		}

		if idx_s2 >= len(s2) {
			res = append(res, s1[idx_s1:]...)
			break
		}

		if s1[idx_s1] < s2[idx_s2] {
			res = append(res, s1[idx_s1])
			idx_s1++
		} else {
			res = append(res, s1[idx_s1])
			idx_s2++
		}
	}
	return res
}
~~~

## 反转链表
~~~ c++ 
ListNode* reverseList(ListNode *head) {
    ListNode *cur = head;
    ListNode *pre = nullptr;
    while (cur)    {
        ListNode *tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}
~~~
## 列表倒数到M个节点
~~~ golang 
func pickFromTail(l *list.List, m int) *list.Element {
	if m <= 0 {
		return nil
	}
	left := l.Front()
	right := left.Next()
	dis := 0
	for {
		if right == nil {
			break
		}
		right = right.Next()
		if dis == m-1 {
			left = left.Next()
		} else {
			dis++
		}
	}
	if dis == m-1 {
		return left
	}
	return nil
}
~~~