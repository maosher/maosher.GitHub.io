
# Some Experience

## 如何获取一个字符串的字符数：
utf8.RuneCountInString(str)

## Golang with Lua
GopherLua  CGo

## 反射性能问题
+ 返回创建对象耗时约为new 的1.5倍  
+ 普通直接给字段，和通过反射 下标，名称找到对应字段赋值 性能差异巨大 1:100:1000, 可以将名称和对应下标缓冲起来，优化近似下标的效率

## for range
如果是复杂类型， range 拷贝有性能问题
~~~ golang
for k, v := range kvs {
    // v is copy
}
~~~


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






