<h1>Наследяване</h1>

<h3>Пример за наследяване</h3>

При създаване на нов клас, който има общи компоненти и поведение с вече дефиниран клас, вместо да дефинира повторно тези компоненти и поведение, можем да го обявим за наследник на вече дефинирания.

```c++
class A
{
	.
	. 
	.
public:
	void f()
	{
	.
	.
	.
	}
	.
	.
	.	
};
class B : public A
{
	.
	.
	.
};

int main()
{
	B obj;
	obj.f(); // OK!
}
```

При наследяването:
- Наследяват се полетата и методите на основните класове
- Получава се достъп до **някои** от наследените компоненти на основните класове

В нашия пример класът **В е наследник на класа А.** Обекти от класовете изглеждат така:

![enter image description here](https://i.ibb.co/Fshm2LJ/Untitled-Diagram.png)

След като  В е наследник на класа А, то при създаване на обект от тип В се създава обект от тип А, **който е част от обекта** от тип В.

<h3>Видове наследяване</h3>

Някои типове наследяване в c++:

- private (по подразбиране)
- protected
- public

Примери:
```c++
class A 
{
    public:
       int x;
    protected:
       int y;
    private:
       int z;
};

class B : public A
{
    // x is public
    // y is protected
    // z is not accessible from B
};

class C : protected A
{
    // x is protected
    // y is protected
    // z is not accessible from C
};

class D : private A    // 'private' is default for classes
{
    // x is private
    // y is private
    // z is not accessible from D
};
```

<h3>Подаване като параметри на функции.</h3>

Класове-наследници могат да бъдат подавани като параметри на функции, които приемат обекти от базовия клас. Може да се използва функционалността само от базовия клас.

```c++
class A
{
public:
	int a;
};
class B : public A
{
public:
	int b;
};
void f(A& obj)
{
	obj.a++;
}

void g(A* ptr)
{
	(*ptr).a++;
}

void t(B& obj)
{
	obj.b++;
}

int main()
{
	A obj1;
	B obj2;
	
	f(obj1); //OK!
	f(obj2); //OK!
	
	g(&obj1); //OK!
	g(&obj2); //OK!
	
	t(obj2);  //OK!
	//t(obj1)// not ok!
}
```

<h3>Конструктори и деструктори при наследяване.</h3>
Във всеки конструктор на класа-наследник трябва да се оказва кой конструктор да се извика за базовия клас. Ако не е оказано, ще се извика конструкторът по подразбиране.

```c++
class B : public A
{
.
.
.
public:
	B(...) : A(...) //some constructor of A.
	{
	.
	.
	.
	}
};
```

Деструкторът на наследения клас извиква деструктора на базовия клас.

<h3>Копиране при наследяване</h3>

При разписване на конструктора за копиране и оператора за присовяване на клас-наследник, трябва експлицитно да извикваме копиране и за базовия клас.

```c++
B::B(const B& other) : A(other) // (copy constructor of A (base class)
{
	copyFrom(other);
}

B& B::operator=(const B& other)
{

	if (this != &other)
	{
		A::operator=(other); //operator= of A (base class)
		free();
		copyFrom(other);
	}
	return *this;
}
```
 
Разписваме копирането и триенето само ако наследникът ползва необработена динамична памет! Ако няма, то генерираните от компилатора (по горната схема) работят коректно!

<h3>Множествено наследяване</h3>

Един клас наследник, може да има повече от един базов клас.

<h5>Пример за множествено наследяване:</h5>

```c++
#include <iostream>

class Polygon
{
protected:
    int width, height;
public:
    Polygon(int a, int b) : width(a), height(b){}
};

class Output
{
public:
    static void print(int i);
};

void Output::print(int i)
{
  cout << i << '\n';
}

class Rectangle: public Polygon, public Output
{
public:
    Rectangle(int a, int b) : Polygon(a,b){}
    int area()
    {
        return width*height;
    }
};

class Triangle: public Polygon, public Output
{
public:
    Triangle(int a, int b) : Polygon(a,b){}
    int area()
    {
        return width*height/2;
    }
};
  
int main()
{
    Rectangle rect(4,5);
    Triangle trgl(4,5);
    rect.print(rect.area());
    Triangle::print(trgl.area());
}
```

<h3>Примерни задачи:</h3>

**Задача 1:** Нека имаме следната структура от класове Natural -> Integer -> Real -> Complex. Където всеки следващ клас наследява от предишният. Нека всеки клас има следните полета и методи:

1. Natural
	- Полета:
		- number: uint
	- Методи:
		- Print: Принтира числото

2. Integer
	- Полета:
		- isNegative: bool
	- Методи:
		- Print: Принтира числото

3. Real
	- Полета:
		- denominator: uint
	- Методи:
		- Print: Принтира числото

4. Complex
	- Полета:
		- imaginary: Real
	- Методи:
		- Print: Принтира числото