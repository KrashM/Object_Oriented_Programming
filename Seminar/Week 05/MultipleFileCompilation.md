<h1>Multiple file compilation</h1>

> The "compilation" of a program actually consitsts of two major stages.

1. Compile stage

- Syntax checked for correctness.
- Variables and function calls checked to insure that correct declarations were made and that they match. (Note:& The compiler doesn't need to match function definitions to their calls at this point).
- Translation into object code. Object code is just a translation of your code file -- it is not an executable program, at this point. (Note: the word "object" in object code does not refer to the definition of "object" that we use to define object-oriented programming. These are different terms.)

2. Linking stage

- Links the object code into an executable program.
- May involve one or more object code files.
- The linking stage is the time when function calls are matched up with their definitions, and the compiler checks to make sure it has one, and only one, definition for every function that is called.
- The end result of linking is usually an executable program.

<h3>Commands for compiling c++ code via terminal with g++</h3> 

> First -> create .o (object files) from every .cpp
```bash
g++ -c mycpp.cpp
g++ -c main.cpp

or 

g++ -c *.cpp # compiles every .cpp file in the directory and creates .o
```

> Second -> compile all the .o files together
```bash
g++ mycpp.o main.o -o myProgram

or

g++ *.o -o myProgram # compiles every .o file together and creates executable
```

> if there are no errors, you will have `myProgram` as executable file :)

**Rule of thumb:** Only include the header files, not the .cpp files (in the code)

<h1>Разделна компилация</h1>

<h3>Какво е компилация изобщо?</h3>
Това е процесът на създаване на изпълними файлове с машинен код от подадени входни файлове. В езика С++ така наречените source файлове играят ролята на входни. Те обикновено са с разширение `.cpp`, `.cxx`, `.cc`. За процесът на компилация използваме помощни програми наречени компилатори. Някои известни такива са `Microsoft Visual C++ compiler` за Windows, GCC (Gnu C Compiler), Clang - за UNIX системи.   

Примерите тук са правени от следната машина:
```console
uname -sr
Linux 5.4.0-99-generic

g++ --version
g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
```

<h3>Какъв е процесът на компилация?</h3>
Всеки С++ source файл трябва да бъде превърнат в object файл.

Source файловете могат да използват други файлове, познати като header файлове, като използват `#include` директивата. Header файловете обикновено имат разширение `.h`, `.hpp`, или `.hxx`. Понякога нямат разширение изобщо като например всикчи файлове в С++ стандартната библиотека. Разширенията нямат значение за препроцесора.

Първата стъпка, която ще изпълни компилаторът, е препроцесорът. За всеки source файл препроцесорът ще изпълни всички препроцесорни директиви - те се разпознават с това, че започват с #. Например `#include` директивата ще бъде директно заменена със съдържането на съответния header файл. Препроцесорът създава `translation unit`.

`g++ -E main.cpp -o main.ii` - Creates the preprocessed file

```
g++ -c main.cpp
g++ -c print.cpp 
g++ -c sum.cpp 
g++ -o cpp-app sum.o print.o main.o
cpp-app 
1 + 2 = 3
1.5 + 2.5 = 4
```


```
g++ -E main-guarded.cpp 
# 1 "main-guarded.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "main-guarded.cpp"
# 1 "guarded.hpp" 1



class A
{
public:
    A(int a) : m_a(a) {}
    void setA(int a) { m_a = a; }
    int getA() const { return m_a; }

private:
    int m_a;
};
# 2 "main-guarded.cpp" 2


int main()
{
    A a(5);
    a.setA(0);
    return a.getA();
}

g++ -o guarded main-guarded.cpp
```
No problems


```
g++ -E main-unguarded.cpp 
# 1 "main-unguarded.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "main-unguarded.cpp"
# 1 "unguarded.hpp" 1
class A
{
public:
    A(int a) : m_a(a) {}
    void setA(int a) { m_a = a; }
    int getA() const { return m_a; }

private:
    int m_a;
};
# 2 "main-unguarded.cpp" 2
# 1 "unguarded.hpp" 1
class A
{
public:
    A(int a) : m_a(a) {}
    void setA(int a) { m_a = a; }
    int getA() const { return m_a; }

private:
    int m_a;
};
# 3 "main-unguarded.cpp" 2

int main(int argc, char *argv[])
{
    A a(5);
    a.setA(0);
    return a.getA();
}
g++ -o unguarded main-unguarded.cpp 
main-unguarded.cpp:2:0:

unguarded.hpp:1:7: error: redefinition of 'class A'
 class A {
       ^
In file included from main-unguarded.cpp:1:0:
unguarded.hpp:1:7: error: previous definition of 'class A'
 class A {
       ^
```
