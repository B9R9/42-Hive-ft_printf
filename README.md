# 42-Hive-ft_printf

## Objectives
The versatility of the printf function in C represents a great exercise in programming for
us. This project is of moderate difficulty. It will enable you to discover variadic functions
in C in a particularly relevant context as well as learn about a great example of a basic
“dispatcher” in C via the use of an array of function’s pointers.

The key to a successful ft_printf is a well-structured and good extensible code. This
is because as time goes by, you will be more and more tempted to continue to extend
your ft_printf, making your life easier for your future projects. So take your time to
code properly while keeping in mind that you will have to read again your code in a few
weeks or a few months to extend its functionality according to your needs. It would be a
shame not to being able to do it because your can’t read your own work. What do you
think?

### Prototype
```c
int	ft_printf(const char *format, ...)
```

### Allowed functions
- write
- malloc
- free
- exit
- the funcction of man 3 stdarg

### Conversion Specifications
A conversion specification consists of optional and required fields in this form:
```
%[flags][width][.precision][size]type
```

### Specifiers
The **specifier** is the last part of a **conversion specification**. These are the ones we had to implement:

* `c`: character
* `s`: string
* `d`: integer
* `i`: integer
* `u`: unsigned integer
* `p`: memory address
* `x`: hexadecimal
* `X`: hexadecimal
* `f`: float 


### Flags
These are the flags to implement:

* `#`: Alternate form
* `0`: Zero padded (ignored if '-' flag, or specified 'Precision' with d i o u x X)
* `-`: Left align result
* `+`: Prepend sign (+ or -) to SIGNED conversions
* ` `: (A space character. Overrides '+' flag) Leave a space before:

	* Positive numbers produced by SIGNED conversions.
	* Before strings.

### Length
The length modifier:

* `h`:	Signed/unsigned **char**: hd, hi, hu
	* Signed: hd, hi
	* Unsigned: hu

* `hh`:	Signed/unsigned **short int**: hhc, hhu
	* Signed: hhc
	* Unsigned: hhu

* `l`:	Signed/unsigned **long int**:
	* Signed: ld, li, l
	* Unsigned: lu

* `ll`: Signed/unsigned **long long int**: lld, lli, llu
	Signed **double**: llf, lli, llu

* `L`:	Signed **long double**: Lf

Test.sh
=======
* test.sh clean
  * remove *.o && valgrind.log && leaksreport.txt && executable
* test.sh test
  * compil the programm:
```
    gcc -o ./test/main.o  -c ./test/main.c -Iinclude -I./libft/includes -g
    gcc -o test_printf ./test/main.o -L. -lftprintf -g
    ./test_printf
```
* test.sh valgrind
  * compil your programm && generate a log
```
  valgrind  --leak-check=full --show-leak-kinds=all --log-file="./test/leaks/valgrindlog" test_ftprintf
```
* test.sh push "commitname"
```
    git add .
    git commit -m "$2"
    git push
```
* test.sh pull
```
    git fetch
    git pull
```
### Documentation
* http://manpagesfr.free.fr/man/man3/stdarg.3.html#lbAE
* https://zestedesavoir.com/tutoriels/755/le-langage-c-1/notions-avancees/les-pointeurs-de-fonction/
* https://docs.microsoft.com/fr-fr/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-170
* https://docs.microsoft.com/en-us/cpp/c-language/cpp-integer-limits?view=msvc-170
* https://stackoverflow.com/questions/23191203/convert-float-to-string-without-sprintf#23191630
