# C++11

## shared_ptr & weak_ptr & unique_ptr

### unique_ptr
unique_ptr对象始终是关联的原始指针的唯一所有者。我们无法复制unique_ptr对象，它只能移动。
reset()	重置unique_ptr为空，delete其关联的指针。
release()	不delete关联指针，并返回关联指针。释放关联指针的所有权，unique_ptr为空。
get()	仅仅返回关联指针
std::unique_ptr<Vec3> v1 = std::make_unique<Vec3>() (c++14)

### 构造一个 shared_ptr 管理对象
class Test{}
std::shared_ptr<ClassTest> ps = std::make_shared<ClassTest>();
//指定 default_delete 作为释放规则
std::shared_ptr<int> p6(new int[10], std::default_delete<int[]>());
//初始化智能指针，并自定义释放规则
std::shared_ptr<int> p7(new int[10], deleteInt);

### std::enable_shared_from_this
当类A被share_ptr管理，且在类A的成员函数里需要把当前类对象作为参数传给其他函数时，就需要传递一个指向自身的share_ptr。
如果直接传递share_ptr<this>会造成2个非共享的share_ptr指向同一个对象，未增加引用计数导对象被析构两次。


## std::move
左值与右值这两个概念是从 C 中传承而来的，左值指既能够出现在等号左边，也能出现在等号右边的变量；右值则是只能出现在等号右边的变量。  
int a; // a 为左值  
a = 3; // 3 为右值  
int&& i = 123;  
int&& j = std::move(i);  
int&& k = i;//编译不过，这里i是一个左值，右值引用只能引用右值  
左值是可寻址的变量，有持久性；  
右值一般是不可寻址的常量，或在表达式求值过程中创建的无名临时对象，短暂性的。   
左值和右值主要的区别之一是左值可以被修改，而右值不能

要实现转移语义，需要定义转移构造函数，还可以定义转移赋值操作符。对于右值的拷贝和赋值会调用转移构造函数和转移赋值操作符。如果转移构造函数和转移拷贝操作符没有定义，那么就遵循现有的机制，拷贝构造函数和赋值操作符会被调用。


## std::bind & std::function
std::function 是一个可调用对象包装器，是一个类模板，可以容纳除了类成员函数指针之外的所有可调用对象，它可以用统一的方式处理函数、函数对象、函数指针，并允许保存和延迟它们的执行。

定义格式：std::function<函数类型>。

std::function可以取代函数指针的作用，因为它可以延迟函数的执行，特别适合作为回调函数使用。

std::bind函数看作一个通用的函数适配器，它接受一个可调用对象，生成一个新的可调用对象来“适应”原对象的参数列表。

std::bind将可调用对象与其参数一起进行绑定，绑定后的结果可以使用std::function保存。std::bind主要有以下两个作用：

将可调用对象和其参数绑定成一个防函数；
只绑定部分参数，减少可调用对象传入的参数


## lambda

