
# Some Experience
## 结构体嵌套
golang 大量结构体内嵌会使编译速度慢

## 字符串的效率问题
需要对一个字符串进行频繁的操作时，谨记在 go 语言中字符串是不可变的（类似 java 和 c#）。使用诸如 a += b 形式连接字符串效率低下，尤其在一个循环内部使用这种形式。这会导致大量的内存开销和拷贝。应该使用一个字符数组代替字符串，将字符串内容写入一个缓存中  bytes.Buffer

## 如何获取一个字符串的字符数：
utf8.RuneCountInString(str)

## Golang with Lua
GopherLua  CGo

## go tools

## go1.8动态库 plugin 
go build -buildmode=plugin
~~~ golang
pdll, err := plugin.Open("test.so")
if err != nil {
    //...
    return 
}
//获取动态库方法
fun, err := pdll.Lookup("TestFunc")
if err != nil {
        //...
        return
}

~~~

## 使用chan 来限制并发数
~~~ golang
var sem = make(chan int, 1000)
func handle(r *Request) {
    //do something , will cost lot time
    <-sem
}
func Server(queue chan *Request) {
    for {
        sem <- 1
        request := <-queue
        go handle(request)
    }
}
func main() {
    queue := make(chan *Request)
    go Server(queue)
}
~~~






