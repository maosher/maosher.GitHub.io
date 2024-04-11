# Lua和c语言调用

## c调用Lua

lua函数入栈
lua_getglobal(L, "lua_funcName")


lua_pushnumber(L, 2) //参数入栈
...  //如果多个参数， 要考虑检查栈空间够不够


lua_pcall(L, n, r, 0)  //调用lua 函数, n表示参数个数，r返回值个数

//错误检查
//弹出返回值


## lua调用c
