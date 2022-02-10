package main

import (
	"fmt"
	"math/rand"
)

var (
	WIDTH  = 10
	HEIGHT = 10
)

// f(x, y) = s[x][y] + min(f(x+1, y), f(x, y+1))
// f(9, 9) = s[9][9]
// f(8, 8) = s[8][8] + min(f(9, 8), f(8, 9))
// f(9, 8) = s[9][8] + f(9, 9)
// f(8, 9) = s[8][9] + f(9, 9)
// f(0, 0) = s[0][0] + min(f(1, 0), f(0, 1))
// f(1, 0) = s[1][0] + min(f(2, 0), f(1, 1))
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

func printMap(s [][]int) {
	for i := 0; i < WIDTH; i++ {
		for j := 0; j < HEIGHT; j++ {
			fmt.Printf("%v\t", s[i][j])
		}
		fmt.Println("")
	}
	fmt.Println("------------------")
}
func main() {
	// rand.Seed(time.Now().UnixNano())
	s := make([][]int, WIDTH)
	r := make([][]int, WIDTH)
	for i := 0; i < WIDTH; i++ {
		s[i] = make([]int, HEIGHT)
		r[i] = make([]int, HEIGHT)
		for j := 0; j < HEIGHT; j++ {
			s[i][j] = rand.Int() % 10
			r[i][j] = 0
		}
	}
	printMap(s)
	findMinPath(s, r)
	printMap(r)

}
