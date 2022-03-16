
# cgo
## 

## use lua in cgo
~~~
/*
#cgo LDFLAGS: -L/usr/local/lib -llua -ldl -lm

#include <string.h>
#include <stdlib.h>
#include "lua.h"
#include "lualib.h"
#include "luaxlib.h"


*/
import "C"

~~~