package main

import (
	"fmt"
	"runtime"
	"runtime/debug"
	"strings"
	"time"
)

func foo() {
	defer func() {
		if e := recover(); e != nil {
			fmt.Println("recover!", e)
		}
	}()

	m := make(map[int]int)
	go func() {
		for {
			m[0] = 0
		}
	}()
	for {
		fmt.Println("Panic:", m[0])
	}
}

func printMemInfo() {
	var rtm runtime.MemStats
	runtime.ReadMemStats(&rtm)
	fmt.Printf("%f Mb\n", float64(rtm.Alloc)/1024/1024)
}

type St struct {
	m map[int]string
}

func (st *St) Fill() {
	s := strings.Repeat("x", 1024)
	for i := 0; i < 100000; i++ {
		st.m[i] = s
	}
}
func (st *St) Free() {
	for i := 0; i < 100000; i++ {
		delete(st.m, i)
	}
}
func main() {
	m := make(map[int]string)
	// st := &St{
	// 	m: make(map[int]string),
	// }
	printMemInfo()
	s := strings.Repeat("x", 1024)
	for i := 0; i < 100000; i++ {
		m[i] = s
	}
	// st.Fill()
	printMemInfo()
	debug.FreeOSMemory()
	printMemInfo()
	for i := 0; i < 100000; i++ {
		delete(m, i)
	}
	// st.Free()
	debug.FreeOSMemory()
	for {
		printMemInfo()
		debug.FreeOSMemory()
		time.Sleep(time.Second)
	}
}
