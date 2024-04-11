
# Some Experience

## 如何获取一个字符串的字符数：
utf8.RuneCountInString(str)

## 判断字符串是否是 UTF8 文本，可使用 "unicode/utf8" 包中的 ValidString() 函数

## Golang with Lua
GopherLua  CGo

## 性能优化

### 结构体嵌套
golang 大量结构体内嵌会使编译速度慢  
### 字符串拼接
使用[]byte 替代 string +   
bytes.Buffer 效率大于 string+  
strconvFormat, strings.Builder 效率大于 fmt.Sprintf  
### 反射性能问题
+ 返回创建对象耗时约为new 的1.5倍  
+ 普通直接给字段，和通过反射 下标，名称找到对应字段赋值 性能差异巨大 1:100:1000, 可以将名称和对应下标缓冲起来，优化近似下标的效率

### sync.Pool 对象池

### 逃逸性能问题
+ 指针逃逸
+ interface{} 动态类型逃逸
+ 内存超过一定大小（栈大小影响)，发生逃逸， make([]int, 8191) 不逃逸， make([]int, 8192) ， make([]int n)逃逸

### for range
如果是复杂类型， range 拷贝有性能问题
~~~ golang
for k, v := range kvs {
    // v is copy
}
~~~

### 利用sync.Once
sync.Once 在使用时才触发， 部分场景下可以代替 init function中一些初始化， 如果未使用到，可以提升一些效率

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




## json decode 数字类型默认为float64
可以使用 struct 将数值类型映射为 json.RawMessage 原生数据类型
适用于如果 JSON 数据不着急 decode 或 JSON 某个字段的值类型不固定等情况：
~~~golang 
var result struct {
    Status json.RawMessage `json:"status"`
    Tag string `json:"tag"`
}
var name string
err = json.Unmarshal(result.Status, &name)
if err == nil {
    //name
}
var code uint64
err = json.Unmarshal(result.Status, &code)
if err == nil {
    //code
}
~~~
使用 Decoder 类型来 decode JSON 数据，明确表示字段的值类型
~~~golang
var data = []byte(`{"status": 200}`)
var result map[string]interface{}
var decoder = json.NewDecoder(bytes.NewReader(data))
decoder.UseNumber()
if err := decoder.Decode(&result); err != nil {
    log.Fatalln(err)
}
var status, _ = result["status"].(json.Number).Int64()
~~~