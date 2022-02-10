package main

import (
	"container/list"
	"fmt"
)

func printList(l *list.List) {
	for i := l.Front(); i != nil; i = i.Next() {
		fmt.Printf("%v\t", i.Value)
	}
	fmt.Println("______")
}

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
func main() {
	l := list.New()
	for i := 0; i < 10; i++ {
		l.PushBack(i)
	}
	printList(l)
	v := pickFromTail(l, 0)
	fmt.Println(v)

}
