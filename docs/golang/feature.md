
## 传引用还是传值
严格说， golang 里面全是传值类型, 要区别 ***引用类型*** 和 ***传引用*** 的区别
***map 和 slice 的行为类似于指针，它们是包含指向底层 map 或 slice 数据的指针的描述符***
看源码就明白是怎么会事了
+ chan  
~~~
func makechan(t *chantype, size int64) *hchan {
}
~~~
* map
~~~ 
//src/runtime/hashmap.go
func makemap(t *maptype, hint int64, h *hmap, bucket unsafe.Pointer) *hmap {
}
~~~



## 条件编译
+ 编译标签由空格分隔的编译选项(options)以"或"的逻辑关系组成
+ 每个编译选项由逗号分隔的条件项以逻辑"与"的关系组成
+ 每个条件项的名字用字母+数字表示，在前面加!表示否定的意思
+ 条件编译说明和package 中的空行 (go vet 可以检测出来这个错误)
+ 下划线开头的文件名会被go 编译忽略  _noused.go
~~~golang
// debug.go
// +build debug

package main
const debug = true
//relase.go
// +build !debug

package main
const debug = false
~~~
go build -tags debug



## Golang 程序启动初化执行顺序
![go init](imgs/1.png)
 >>main func执行前, 所有代码都运行在一个 goroutine, 如果init 开启了goroutine, 只有在进入了main.main 之后才开始执行 

 

## 常见坑

### 可变参数是空接口类型

传入空接口的切片时需要注意参数展开的问题
~~~golang
var a = []interface{}{1, 2, 3}
fmt.Println(a)  //[1 2 3]
fmt.Println(a...) //1 2 3
~~~