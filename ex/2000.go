package main

/*
#include <stdio.h>

void printint(int v) {
    printf("printint: %d\n", v);
}
void printuint(unsigned int v) {
    printf("printint: %u\n", v);
}
*/
import "C"

func main() {
	v := 42
	C.printint(C.int(v))
	var uv uint32 = 0
	C.printuint(C.uint(uv))

	// var str string
	// cstr := C.CString(str)
	// defer C.free(unsafe.Pointer(cstr))
}
