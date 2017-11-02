The structure of this directory is:

file "README.md"
file "getinput.h"
file "readline.h"
file "history.h"
file "chardefs.h"
file "keymaps.h"
file "rlstdc.h"
file "rltypedefs.h"
file "tillde.h"
file "getinput.cpp"
directory "x64_lib"
	file "libreadline.so"
directory "x86_lib"
	file "libreadline.so"

In linux, if we write a C/C++ file and it have to get something from screen(such as using "scanf" or "cin"), we can't use the direction keys to move the cursor when inputing. That is very disgusting! This directory provides a part of interface of GNU Readline Library. With using "readline" user can move cursor by direction keys easily and user can also use "up" key to show the history line. (Windows user don't need this and can't use it.)