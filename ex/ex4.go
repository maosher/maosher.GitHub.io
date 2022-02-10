package main

import "fmt"

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

func main() {
	s1 := []int{1, 2, 2, 3, 4, 5}
	s2 := []int{1, 3, 6, 8}
	s3 := mergeSortedSlice(s1, s2)
	fmt.Printf("%v\n", s3)

}
