package main

import (
	"fmt"
	"os"
	"runtime/trace"
)

func main() {
	f, e := os.Create("trace.out")
	if e != nil {
		panic(e)
	}
	defer f.Close()

	e = trace.Start(f)
	if e != nil {
		panic(e)
	}

	defer trace.Stop()

	fmt.Println("exit")
}
