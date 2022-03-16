package main

import "fmt"

type Demo struct {
	name string
}

func NewDemo(name string) *Demo {
	d := &Demo{}
	d.name = name
	return d
}

func main() {
	demo := NewDemo("demo")
	fmt.Println(demo)
}
