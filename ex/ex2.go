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
	//taskData[0][]
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

func main() {
	t := [][]int{{1}, {2}, {}}
	for i, v := range t {
		fmt.Printf("%v : %v\n", i, v)
	}

	if !canTaskFinish(len(t), t) {
		fmt.Println("fail")
	}
	fmt.Println("exit")
}
