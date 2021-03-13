//<stdlib.h> header file provide files to facilitate dynamic memory allocation in c programming
//ptr = (cast-type*) malloc(byte-size)
//it return the pointer of type void that can be cast into another type
//ptr = (cast-type*)calloc(n, element-size);
//where n is the numbet of block each of size element-size
//it initilize each block with a default value of '0'
//ptr = realloc(ptr, newSize);
//where ptr is reallocated with new size 'newSize'
//If space is insufficient, allocation fails and returns a NULL pointer.