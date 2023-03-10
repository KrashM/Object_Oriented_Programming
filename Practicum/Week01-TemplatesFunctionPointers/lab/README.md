# Шаблони на функции. Функции от по-висок ред

## Задача :one:

Напишете програма, която прочита цял ред низ (с максимална големина 1024) от конзолата. Да се реализира функция, която извършва операция върху всяко една буква приемаща указател към функция. Реализирайте 2 помощни функции, които да се подават с указател:

- toLowerCase - преобразува главните букви в малки
- toUpperCase - преобразува малките букви в главни

```

Вход:
Hello world 1+2+#!

Изход:
HELLO WORLD 1+2+#!
hello world 1+2+#!

```

## Задача :two:

Напишете програма, която прочита масив (с максимална големина от 100) от цели числа. Напишете функция **sort**, която приема фунцкия за сортиране като указател. Реализирайте следните функции за сортиране:

- bubble sort
- insertion sort
- merge sort

```

Вход:
6
4 3 6 1 5 2

Изход:
Bubble sort: 1 2 3 4 5 6
Insertion sort: 1 2 3 4 5 6
Merge sort: 1 2 3 4 5 6

```

## Задача :three:

Направете темплейтна структура **MyArray**, която съдържа в себе си масив (максимум 100 елемента) от произволен тип и неговата големина. Реализирайте следните функции:

- **pushBack** - добавя елемент към края на обект от тип **MyArray**, ако масива е пълен използвайте *assert* с подходящо съобщение
- **popBack** - премахва последния елемент на обeкт от тип **MyArray**, ако масива е празен използвайте *assert* с подходящо съобщение
- **at** - връща елемент на определена позиция, ако позицията е невалидна изпозлвайте *assert* с подходящо съобщение
- **empty** - проверява дали обект от тип **MyArray** е празен
- **print** - принтира всички елементи на обeкт от тип **MyArray**

## Задача :four:

Реализирайте функцията за натрупаване **accumulate** със следната сигнатура:

``` c++

int accumulate(int from, int to, ... term, ... op, int startingValue); // на местата на ... трябва сами да определите какъв ще е подходящият тип

```

където:
- **[from, to]** е интервал от цели числа
- **term** е функция над цели числа; *тази функция ще извърша промяна над сегашното цяло число x*
- **op** е бинарна операция над стойностите получени чрез прилагане на term(x); *сбор, разлика, произведение*
- **startingValue** е начална стойност, която се подава на op в началото

Примерна употреба:

``` c++

int id(int num) {
    return num;
}

int pow2(int num) {
    return num * num;
}

int sum(int firstNum, int secondNum) {
    return firstNum + secondNum;
}

int product(int firstNum, int secondNum) {
    return firstNum * secondNum;
}
int main() {
    std::cout << accumulate(1, 4, id, sum, 0) << std::endl; // 10
    std::cout << accumulate(1, 4, pow2, sum, 0) << std::endl; // 30
    std::cout << accumulate(1, 5, id, product, 1) << std::endl; // 120

    return 0;
}

```

## Задача :five:

Реализирайте **accumulate** с темплейти (шаблони).

## Задача :six:

Реализирайте функция **map**, която приема масив от произволен тип и функция от по-висок ред, която приема само един параметър от същия произволен тип като масива и променя параметъра по някакъв начин.

Реализирайте функция **filter**, която приема масив от произволен тип и функция от по-висок ред, която ще е предикат. **filter** ще премахва всеки елемент от масива, който не удовлетворява предиката.

Примерна употреба:

``` c++

void multBy2(int& num) {
    num *= 2;
}

bool divBy4(int num) {
    return num % 4 == 0;
}

int main() {
    constexpr std::size_t ARR_SIZE = 5;

    int arr[ARR_SIZE] = { 1, 2, 3, 4, 5 };

    map(arr, ARR_SIZE, multBy2); // 2 4 6 8 10
    filter(arr, ARR_SIZE, divBy4); // 4 8

    return 0;
}

```

## Задача :seven:

Реализирайте функция за натрупване при масиви **fold** със следната сигнатура:

``` c++

... fold(... arr, std::size_t size, ... op, ... startingValue);

```

където:
- **arr** е масив от произволен тип и **size** е неговата големина
- **op** е бинарна операция, която ще приема типа на **startingValue** и типа на **arr** и ще връща типа на **startingValue**
- **startingValue** е начална стойност, която се подава на op в началото

Примерна употреба:

``` c++

int max2(int firstNum, int secondNum) {
    return std::max(firstNum, secondNum);
}

bool anyEven(bool res, int num) {
    return res || num % 2 == 0;
}

int main() {
    constexpr std::size_t ARR_SIZE = 5;
    int arr[ARR_SIZE] = { 1, 2, 8, 4, 5 };

    std::cout << fold(arr, ARR_SIZE, max2, arr[0]) << std::endl; // 8
    std::cout << std::boolalpha << fold(arr, ARR_SIZE, anyEven, false) << std::endl; // true

    return 0;
}

```
