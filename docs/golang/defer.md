# defer 和 panic
----

## defer

**defer** 执行晚于return , 可以操作命名返回值
defer执行按倒序
defer 在*1.4.2*版本之前会有效率问题
defer 执行顺序与声明顺序相反
~~~golang
func f(n int) (r int) {
	defer func() {
		r += n
		recover()
	}()

	var f func()

	defer f()
	f = func() {
		r += 2
	}
	return n + 1
}

func main() {
	fmt.Println(f(3))
}
~~~

## panic
panic 发生时, 中断后续执行，转而执行defer 函数
所以recover函数只有在defer代码块中才会有效果

### recover 有无法捕获panic 的风险， 比如二个goroutine 并发写同一个map
~~~golang
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

func main() {
	foo()
}
~~~