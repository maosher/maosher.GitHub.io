# defer 和 panic
----

## defer

**defer** 执行晚于return , 可以操作命名返回值
defer执行按倒序
defer 在*1.4.2*版本之前会有效率问题
defer 执行顺序与声明顺序相反

## panic
panic 发生时, 中断后续执行，转而执行defer 函数
所以recover函数只有在defer代码块中才会有效果


