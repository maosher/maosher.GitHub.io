

## violatile
violatile关键字通常用来修饰多线程共享的全局变量和IO内存。告诉编译器，不要把此类变量优化到寄存器中，每次都要老老实实的从内存中读取

## define和inline函数有什么差别
define不是函数，只是在编译前（编译预处理阶段）做简单的字符替换，且不做类型检查。
inline函数是函数，但在编译时不单独产生代码，而是将代码直接镶嵌到调用处，减少了普通函数调用时的资源消耗，且inline函数因为是函数所以要做参数类型检查。一般的，当一个简单函数（函数内不包含for、while、switch语句）被多次调用时，就应该考虑用inline。

## 结构体中位域的对齐：
1） 如果相邻位域字段的类型相同，且其位宽之和小于类型的 sizeof 大小，则后面的字段将紧邻前一个字段存储，直到不能容纳为止；  
2） 如果相邻位域字段的类型相同，但其位宽之和大于类型的 sizeof 大小，则后面的字段将从新的存储单元开始，其偏移量为其类型大小的整数倍；  
3） 如果相邻的位域字段的类型不同，则各编译器的具体实现有差异， VC6 采取不压缩方式（不同位域字段存放在不同的位域类型字节中）， Dev-C++ 和 GCC 都采取压缩方式； 
4） 如果位域字段之间穿插着非位域字段，则不进行压缩。

# 内存泄露
如何发现：htop top 查看内存增长， 日志
如何解决：
1. 重载或者重写内存分配释放 malloc/free new/delete 
2. 使用 hook方式，（dlsym） ，重写malloc /free  
3. 使用智能指针 
4. 使用三方工具 Valgrind， Sanitizer等
## 一些第三方工具
addr2line 地
Sanitizer 使用ASan时，只需gcc选项加上-fsanitize=address选项


