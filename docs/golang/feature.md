
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

## 结构体嵌套
golang 大量结构体内嵌会使编译速度慢
