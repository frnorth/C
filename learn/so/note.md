cc hello.c -fPIC -shared -o hello.so
cc main.c -lm ./hello.so
