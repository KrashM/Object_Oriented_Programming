<h1>Абстракция. Копиращ конструктор и оператор=. Голямата четворка. Разделна компилация.</h1>

<h3>Абстракция</h3>

Абстракцията е процес на дизайнерско ниво и се използва, за да се намали сложността на дизайна, на даден проект.
Правейки един клас абстрактен, ние позволяваме, той да може да се използва за повече от една цел.

<h5>Пример за лоша капсулация:</h5>

```c++
struct Triangle
{
	int x1;
	int y1;
	
	int x2;
	int y2;

	int x3;
	int y3;
};
int getPer(const Triangle& t)
{
	return
	 sqrt( (t.x1-t.x2)*(t.x1-t.x2) + (t.y1-t.y2)*(t.y1-t.y2) ) +
	 sqrt( (t.x2-t.x3)*(t.x2-t.x3) + (t.y2-t.y3)*(t.y2-t.y3) ) +
	 sqrt( (t.x3-t.x1)*(t.x3-t.x1) + (t.y3-t.y1)*(t.y3-t.y1) );
}
```

В горният пример проблем се получава, ако някой извън класът сложи например name = nullptr. От там деструкторът ще даде грешка (неочаквано поведение за този клас).

<h5>Пример за по-добра капсулация:</h5>

```c++
struct Point
{
	int x, y;
	double getDistTo(const Point& other) const
	{
		return sqrt((x-other.x)*(x-other.x)+(y-other.y)*(y-other.y));
	}
};
struct Triangle
{
	Point p1;
	Point p2;
	Point p3;
};
int getPerTriangle(const Triangle& t)
{
	return t.p1.getDistTo(t.p2) + t.p2.getDistTo(t.p3) + t.p3.getDistTo(t.p1);
}
struct Rectangle{
    Point p1;
    Point p2;
    Point p3;
    Point p4;
};
int getPerTriangle(const Rectangle& r)
{
	return r.p1.getDistTo(r.p2) + r.p2.getDistTo(r.p3) + r.p3.getDistTo(r.p4) + r.p4.getDistTo(r.p1);
}
```

<h3>Копиращ конструктор</h3>

Конструктор с параметър от тип `const <името-на-класа>&`. Като конструктор има инициализиращ списък. Целта му е да създаде нов обект със стойности на полетата същите като тези на другия подаден. Ако бъде пропуснат ще се генерира автоматично такъв от компилатора, който прави т. нар. `shallow copy`.

<h5>Синтаксис</h5>

```c++
class Test
{
private:
    int i;
    double d;
public:
    Test(const Test& other): i{other.i}, d{other.d}{}    
};
```

<h3>Кога се извиква</h3>

- При създаване на нови обекти от други обекти.
- Неявно при създаване на нов локален обект за дадена функция.
- При връщане на копие на обект от фунцкия

```c++ 
void doSomethingWithTest(Test t) // Извиква копи конструкторът
{
}

Test doSomethingElseWithTest(Test t) // Извиква копи конструкторът
{
    return t;
}

int main()
{
    Test t, t1(t), t2 = t1; // t1 и t2 извикват копи конструкторът
}
```

<h3>Оператор =</h3>

Дясно асоциативен оператор за присвояване на стойност на вече съществуващ обект. След извърване на промените по текущия обект, той се връща. Това позволява наслагване на равенство между няколко обекта.

<h3>Синтаксис</h3>

```c++
class Test
{
private:
    int i;
    double d;
public:
    // стандартна имплементация на operator= 
    Test& operator=(const Test& rhs)
    {
        if(this != &rhs)
        {
            i = rhs.i;
            d = rhs.d;
        }
        return *this;
    }
};
```

<h3>Кога се извиква</h3>

При присвояване на нова стойност на вече съществуващ обект. 

```c++
int main()
{
    Test t, t1(t), t2 = t1;
    t = t1;
    t = t1 = t2; // еквивалентно на t.operator=(t1.operator=(t2));
}
```

**Забележка:** Копиращият конструктор създава нов обект, а оператор= модифицира вече съществуващ такъв!

<h3>Shallow vs deep copy</h3>

Когато копираме данните на обекти обикновено искаме всеки обект да разполага сам с паметта на данните си. Това означава да се заделя памет при създаване на обекта и да се изтрива при унищожаването му.

<h5>Shallow copy</h5>

```c++
class Test
{
private:
    char* name;
    int age;
public:
    // shallow copy - the memory for name is now shared between this and other
    Test(const Test& other): name{other.name}, age{other.age} {} 
    Test& operator=(const Test& rhs)
    {
        name = rhs.name;
        age = rhs.age;
        return *this;
    }
};
```

![enter image description here](https://i.ibb.co/q5rfGBf/Capture.png)

<h5>Deep copy</h5>

```c++
class Test
{
private:
    char* name;
    int age;
public:
    // deep copy - we now manage our own memory
    Test(const Test& other): name{new char[strlen(other.name) + 1]}, age{other.age}
    {
        strcpy(name, other.name);
    } 
    Test& operator=(const Test& rhs)
    {
        if(this != &rhs)
        {
            // here name already exists so we have to manage the memory first
            delete[] name;
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
            age = rhs.age;
        }
        return *this;
    }
};
```

![enter image description here](https://i.ibb.co/XZq5rGT/33.png)

<h3>Голямата четворка</h3>

- Конструктор по подразбиране (конструктор без параметри)
- Конструктор за копиране
- Оператор =
- Деструктор

<h5>Примерна имплементация:</h5>

```c++
class Person
{
public:
	Person(): name{nullptr}, age{0} {}
	Person(const Person& other)
	{	
		copyFrom(other); // копираме
	}
	Person& operator=(const Person& other)
	{
		if (this != &other)
		{
			free(); //трием
			copyFrom(other); //копираме
		}
		return *this;
	}
	~Person()
	{
		free(); //трием
	}
private:
    void copyFrom(const Person& other)
    {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        age = other.age;
    }

    void free()
    {
        delete[] name;
    }

    char *name;
    int age;
};
```

При всички класове, които използват динамична памет, тези функции изглеждат по този начин. Разликите са в имплементациите на функциите **free** и **copyFrom**.

<h3>Разделна компилация</h3>

![enter image description here](https://camo.githubusercontent.com/28dc183568fa5f05a944d8ec4f3033c8ee08e4c87b6c19ae051dc55ea7979f69/68747470733a2f2f692e6962622e636f2f664436584c4a4d2f436f6d70696c6174696f6e2e706e67)

Една програма на С++ може да бъде разбита в множество файлове, които се **компилират независимо един от друг**, т.е. осъществява се **разделна компилация**. В резултат на компилацията се получават няколко **обектни файла** (файлове с разширение **.obj**). Изпълнимият код напрограмата (файл с разширение .ехе) се получава след свързване на обектните файлове (**Linking**).

За да се възполваме максимално от разделната компилация, разделяме класовете на **.h** и **.cpp** файлове. Навсякъде където ще работим с класа, ще включваме **само .h файла.** По този начин, ако променим реализацията на някоя от функциите на класа, ще се **прекомпилира само този файл**.

![enter image description here](https://i.ibb.co/N9RnMHv/sss.png)

<h3>Guards</h3>

Разделяйки кодът ни на отделни файлове се появява един проблем. Какво ако добавя кода повече от 1 път в друг файл?

```c++
// A.h
class A
{
public:
    A(int a) : m_a(a) {}
    void setA(int a) { m_a = a; }
    int getA() const { return m_a; }

private:
    int m_a;
};
```

```c++
// main.cpp
#include "unguarded.hpp"
#include "unguarded.hpp"

int main()
{
    A a(5);
    a.setA(0);
    return a.getA();
}
```

Получаваме следната грешка:

```
In file included from main.cpp:2:
A.h:1:7: error: redefinition of 'class A'
 class A
       ^
In file included from main.cpp:1:
A.h:1:7: note: previous definition of 'class A'
 class A
       ^
```

С други думи сме опитали да редефинираме класът А. Което очевидно не е добре. Тук се появяват guard клаузите.

```c++
// A.h
#ifndef __GUARDED_HPP
#define __GUARDED_HPP

class A
{
public:
    A(int a) : m_a(a) {}
    void setA(int a) { m_a = a; }
    int getA() const { return m_a; }

private:
    int m_a;
};

#endif // __GUARDED_HPP
```

```c++
#include "guarded.hpp"
#include "guarded.hpp"

int main()
{
    A a(5);
    a.setA(0);
    return a.getA();
}
```

Тук програмата се компилира без проблем. Това се случва защото сме сложили защита за редефиниране на класа.

Алтернативна клауза е **#pragme once**.

<h3>Примерни задачи</h3>

**Задача 1:** Да се реализира клас String.

<h3>Домашно</h3>

**!!!Важно!!!**
Нека домашните да се качват в [този](https://drive.google.com/drive/folders/1t6Zqfk5bGzzl8G2Z5mIfVSm6WiA4QU6A?usp=sharing) drive.

**Задача 1:** Напишете клас *Laptop*. Един лаптоп се нуждае от марка и модел (стринг с произволна дължина), цена, размер на екрана (в инчове), процесор (помислете как да представите процесора с нужните му характеристики - тактова честота, брой ядра и размер на КЕШ паметта), РАМ памет и капацитет на батерията. Напишете следните специални методи:

- Конструктор по подразбиране
- Конструктор за копиране
- Конструктор(и) с параметри, данните за един лаптоп
- Оператор за присвояване
- Деструктор

Напишете подходящи методи за upgrade на процесора и РАМ-а, както и метод за подходящо принтиране на информацията.

**Задача 2:** Напишете клас *ToDo*, който описва задача, която трябва да се изпълни. Всяка задача си има id, описание и индикатор за това дали тя е изпълнена или не. Напишете следните специални методи на класа:

- Конструктор по подразбиране
- Конструктор за копиране
- Оператор за присвояване
- Деструктор
- Метод за изпълнение на задачата

**Задача 3:** Магьосникът Маг-О-Кодерски е магьосник в местното за ФМИ заведение BeerOverflow. Там той изпълнява всяка вечер своя коронен номер - всеки посетител на BeerOverflow пуска нещо в "магическата кутия" на Маг-О-Кодерски, а в края на вечерта кутия изхвърля един предмет във въздуха, на случаен принцип.

Маг-О-Кодерски също е и програмист. Той иска да напише програма, в която да въвежда променливи от целочислен тип, и при извикване на даден метод, "кутията" да му връща случайна променлива от вече въведените.

Да се напише клас **MagicalBox** със следните:

**Полета:**

- Динамичен масив (който да се разширява при необходимост)

**Методи:**

- *insert()* - добавя елемент към кутията 
- *pop()* - премахва случаен елемент от кутията. Ако кутията е празна, да показва  подходящо съобщение 

Може да дефинирате допълнителни методи и полета.