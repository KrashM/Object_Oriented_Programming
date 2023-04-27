<h1>Ключова дума static. Singleton. Шаблони. Header optimization. Implicit conversions and explicit keyword.</h1>

<h3>Ключова дума static</h3>

Тази ключова дума ни позволява да създадем полета и методи, които не са пряко обвързани към конкретен обект, ами към самият клас. Това означава, че можем да ги достъпваме както през обекти, така и през името на класа.

<h5>Пример за декларация на една променлива</h5>

```c++
class X { static int n; }; // декларация (използва 'static')
int X::n = 1;              // дефиниция (не използва 'static')
```

<h5>Пример за различни видове променливи</h5>

```c++
struct Foo;
struct S
{
   static int a[]; // декларация, незавършен тип
   static Foo x;   // декларация, незавършен тип
   static S s;     // декларация, незавършен тип (вътре в собствената си дефиниция)
};

int S::a[10]; // дефиниция, завършен тип
struct Foo {};
Foo S::x;     // дефиниция, завършен тип
S S::s;       // дефиниция, завършен тип
```

Забележете, че тук можем да създадем променлива, от самия клас вътре в него, вместо указател към него. Това е възможно тъй като това статичните променливи не са обвързани към конкретна инстанция, а към самият клас.

```c++
struct X
{
    static void f(); // декларация
    static int n;    // декларация
};

X g() { return X(); } // Някаква функция, която връща обект от тип X.

void f()
{
    X::f();  // X::f е валидно име на статичен метод.
    g().f(); // g().f() е израз за достъпване на статичен метод.
}

int X::n = 7; // дефиниция

void X::f() // дефиниция
{
    n = 1; // X::n може да се достъпи просто като n в този scope.
}
```

<h3>Singleton pattern</h3>

Това е принцип за дизайн на клас, който е необходимо да се инстанцира само веднъж. Такива класове са примерно Interface-ите (Input/Output). Идеята е да не се хаби памет да се правят излишни обекти за една и съща цел.

<h5>Пример за реализация с указател към обекта:</h5>

```c++
class Singleton
{
public:
	Singleton(Singleton const &) = delete;
	Singleton(Singleton &&) = delete;

	Singleton &operator =(Singleton const &) = delete;
	Singleton &operator =(Singleton &&) = delete;
	
	static Singleton *getInstance();

	void print() const;
private:
	Singleton() = default;
private:
	static Singleton *instance_ptr;
};

Singleton *Singleton::instance_ptr = nullptr;

Singleton *Singleton::getInstance()
{
	if(Singleton::instance_ptr == nullptr)
		Singleton::instance_ptr = new Singleton();
	return instance_ptr;
}

void print()
{
	std::cout << "I'm a singleton\n";
}
```

<h5>Пример за реализация с референция към обекта:</h5>

```c++
class Singleton
{
public:
	Singleton(Singleton const &) = delete;
	Singleton(Singleton &&) = delete;

	Singleton &operator =(Singleton const &) = delete;
	Singleton &operator =(Singleton &&) = delete;
	
	static Singleton &getInstance();

	void print() const;
private:
	Singleton() = default;
};

Singleton &Singleton::getInstance()
{
	static Singleton instance;
	return instance;
}

void print()
{
	std::cout << "I'm a singleton\n";
}
```

**Забележка:** Премахваме конструкторите за копиране и местене, и съответните им операторите за присвояване, защото ние имаме само 1 инстанция на този клас в цялата програма. Няма смисъл да имплементираме тези неща, тъй като те няма да се използват.

<h3>Шаблони</h3>

Функция/клас, която работи не с променливи от някой дефиниран тип, а с абстрактни променливи, се нарича шаблонна функция/клас

```c++
#include <iostream>

template <class T>
T sum(const T& a, const T& b)
{
    return a + b;
}

int main()
{
    int a = 4;
    int b = 9;
    std::cout << sum<int>(a, b) << std::endl;

    double c = 3.14;
    double d = 4.5;
    std::cout << sum<double>(c,d) << std::endl;
	
    return 0;
}
```

Компилаторът генерира т. нар. шаблонна функция, като замества параметрите на шаблона с типовете на съответните фактически параметри.

<h5>Компилация при шаблонни класове и функции</h5>

Шаблонните класове и функции генерират истинската си репрезентация, по време на компилация. Тези репрезентации се определят от типовете, които сме специфицирали, когато сме ги използвали. С други думи, ако сме казали, че извикваме с тип int и тип char, ще се генерират само тези двете. Именно поради тази причина трябва да оставим и имплементациите в header файлът.

<h3>Header optimization</h3>

Когато пишем header файлове трябва да внимаваме какво оставяме в тях, поради 2 причини:

1. Достъпност до имплементацията:
	- Не искаме потребителите да имат достъп до сложни имплементационни детайли
	- За методи като get-ери, няма особенно значение дали ще ги покажем в header-а

2. Ако се наложи да променим нещо в header файлът, се налага да компилираме наново всички файлове, който го include-ват.

<h3>Имплицитна конверзия и ключова дума explicit</h3>

<h5>Пример за имплицитна конверзия</h5>

```c++
#include <iostream>
#include <string>

class Entity
{
public:
	Entity(int num): name("Unknown"), num(num)
	{
	}
	Entity(std::string const &name): name(name), num(-1)
	{
	}
private:
	std::string name;
	int num;
};

void print(Entity const &e)
{
}

int main()
{
	Entity e = 12; // Fine!
	Entity e1 = "Hello"; // Error: 2 имплицитни конверзии на веднъж не са позволени (const char * -> string -> Entity)

	print(12); // Fine!
	print(std::string("Hello")); // Fine!
}
```

Компилаторът успява да дешифрова присвояването, което сме написали и извиква подходящ конструктор, който може да иницилизира обекта.
Плюсове:
- Може да опрости от части писането на код.
- Препоръчително е да се използва за конструктори с малко аргументи.
Минуси:
- Става трудно за разбиране, какво се опитваме да направим.
- Не можем да правим повече от 1 наведнъж.

Как можем да избегнем това поведение?

<h5>Пример с експлицитни конструктори</h5>

```c++
#include <iostream>
#include <string>

class Entity
{
public:
	explicit Entity(int num): name("Unknown"), num(num)
	{
	}
	explicit Entity(std::string const &name): name(name), num(-1)
	{
	}
private:
	std::string name;
	int num;
};

void print(Entity const &e)
{
}

int main()
{
	Entity e = 12; // Error: Конструкторът трябва да се извика експлицитно
	Entity e1("Hello"); // Fine: Правим конверзия: const char * -> std::string

	print(12); // Error: Конструкторът трябва да се извика експлицитно
	print(Entity(12)); // Fine!
}
```

<h3>Примерни задачи</h3>

1. Swaps counter
    - Брои колко размени на елементи са се случили в програмата

2. Self counting
    - Клас, който да брои, колко инстанции са направени от него и колко от тях са все още живи.

3. Pair
	- Клас, който съдържа 2 аргумента (first, second).

4. FlightScanner with exception handling
    - Класът ще има само конструктор със следните параметри:
        - Име на входен файл
        - Име на изходен файл
        - Интервал за спане
    - Класът да има само един публичен метод run, който да пуска самият процес.

От входният файл четем линия по линия flight log-овете и правим следните неща с тях:

- Проверяваме дали са в правилен формат, като за всяко трябва да се хвърли коректна грешка в противен случай.
    - Source/Destination стринговете трябва да са по точно 3 символа
    - Source/Destination стринговете са само от букви
    - Price трябва да е само от цифри

- Трябва да направим Source/Destination стринговете да са само от главни букви.

- Трябва да превърнем цената от евро в лева.

- Трябва да запишем обработеният полет в изходния файл, като го добавяме най-отзад.

- След приключване на обработването на файла да се премахне файлът.

<h1>Домашно</h1>

**Задача 1:** Релизирайте структурата от данни опашка. Опашката трябва да работи с `произволни типове`. След като е добавен един елемент в края на опашката, той ще може да бъде извлечен (премахнат) единствено след като бъдат премахнати всички елементи преди него в реда, в който са добавени.

<h5>Пример за работа:</h5>

```c++
int main()
{
	quene<int> q;
	q.push(3);
	q.push(5);
	q.push(10);

	cout << q.peek() << endl; //3
	q.pop();
	
	cout << q.peek() << endl; //5
	q.pop();

	cout << q.peek() << endl; //10
	q.pop();
	
	cout << q.isEmpty() << endl; //1	
}
```

**Задача 2:** Създайте `шаблонна` опашка с k приоритета. При взимане на елемент от опашката трябва да се връща най-отдавна добавения елемент от тези с най-висок приоритет. **Важно:** Използвайте имплементацията на опашка от предната задача!
 
```c++
int main()
{
	kPriorityQueue<char> q(4); // 4 priorities - 0, 1, 2 и 3.
	
	q.push('A',0): //adds A with lowest priority: 0
	q.push('B',3);
	q.push('C',2);
	q.push('D',2);
	q.push('E',1);
	
	//q.push('F', 5); //error! No such priority!
	
	q.peek(); // B
	q.pop();
	
	q.peek(); // C
	q.pop();
	
	q.peek(); // D
	q.pop();
	
	q.peek(); // E
	q.pop();
	
	q.peek(); // A
	q.pop();
}
```

**Допълнителна Задача:** Класът Vector да се направи темплейтен.