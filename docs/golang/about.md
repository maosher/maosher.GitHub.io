# 思考

## golang 带来了什么？ 或者和c++不同之处
可以用“高产”二字来概括  
多核的利用优势? 其它语言也可以实现
编译优势，优秀的包管理  

## 垃圾回收是个问题吗？
Go可以让你深入到内存布局，你可以分配自己的空间，如果你想的话可以自己做内存管理。虽然没有alloc和free方法，但是你可以声明一个缓存把东西放进去，这个技巧可用来避免产生不必要的垃圾。就像在C语言一样，在C里，如果你老是malloc和free，代价很大。因此，你分配一个对象数组并把它们链接在一起，形成一个链表，管理你自己的空间，而且还不用malloc和free，那么速度会很快。你可以做与Go所做相同的事情，因为Go赋予你与底层事物安全打交道的能力，因此不用欺骗类型系统来达到目的，你实际上可以自己来做。

前面我表达了这样的观点，在Java里，无论何时你在结构里嵌入其它东西，都是通过指针来实现的，但在Go里你可以把它放在一个单一结构中。因此如果你有一些需要若干缓存的数据结构，你可以把缓存放在结构的内存里，这不仅意味着高效（因为你不用间接得到缓存），而且还意味着单一结构可以在一步之内进行内存分配与垃圾回收。这样开销就会减少。因此，如果你考虑一下垃圾回收的实际情况，当你正在设计性能要求不高的东西时，你不应该总是考虑这个问题。但如果是高性能要求的，考虑到内存布局，尽管Go是具有真正垃圾回收特性的语言，它还是给了你工具，让你自己来控制有多少内存和产生了的垃圾。我想这是很多人容易忽略的。