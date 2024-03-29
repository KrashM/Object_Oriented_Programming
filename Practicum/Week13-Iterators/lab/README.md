# Итератори. Подготовка за изпит

1) [0.25т.] Да се реализира шаблон на абстрактен базов клас `Set<T>`, дефиниращ метода `bool member (const T&)`. Шаблонът описва множество с елементи от тип `T`, а методът `member` дава истина за членовете на множеството.

2) Да се дефинират следните наследници на `Set<T>`:


[0.25т.] `Range<T>`: при конструиране на обекти се задават параметри `a` и `b` от тип `T`. Смятаме, че всяка стойност `x`, таква че `a <= x <= b`, принадлежи на множеството

[0.25т.] `EvenNumbers`: смятаме, че елементите на това множество са всички числа `x` от тип int, за които `x % 2 == 0`

`Container`: позволява добавяне на произволен брой елементи от тип `T`, като всяка различна стойност от тип `T` може да се съдържа само по веднъж в контейнера. За елементи на множеството, съответно на контейнера, се считат добавените в него елементи.

При реализацията на `Container` да се демонстрира работа с динамичната памет (`new` и `delete`). Не се допуска използването на готови класове за представяне на елементите (напр. `std::vector` или други готови контейнери). 

3) За клас `Container` да се реализират:

[0.5т.] Конструктор, деструктор, конструктор за копиране и оператор за присвояване

[0.5т.] Метод `add` за добавяне на елемент в контейнера

[0.25т.] Оператор за обединение (`+`) на два контейнера. Резултатният контейнер съдържа тези елементи, които са срещат в поне един от двата изходни контейнера

[0.25т.] Оператор `a <= b`, проверяващ дали множеството на елементите на един контейнер е подмножество на елементите на друг контейнер

4) [1т.] За клас `Container` да се разработи итератор. Класът да поддържа операциите `begin` и `end`, които да връщат обект от клас, реализиращ необходимите методи за forward итератор (`++`, `*`, `!=`).

5) [0.25т.] Използването на итератора да се демонстрира в примерна програма, която инициализира контейнер с няколко елемента и ги извежда на стандартния изход чрез итериране с помощта на реализирания итератор. 

6) Да се реализира клас `ManySets<T>`, наследник на `Set<T>`. Класът служи като колекция от множества, наследници на `Set<T>` и  да позволява:


[1т.] Добавяне на множество от произволен тип (`Range`, `EvenNumbers`, `Container`, `ManySets`) към колекцията чрез метод `add`

[0.25т.] За членове на множество от вид `ManySets<T>` считаме тези стойности от тип `T`, които са елементи на всички множества в колекцията. Методът `member` да се реализира съответно 

За клас `ManySets` можете да използвате готови колекции (напр. `std::vector` или друг). 

> **Внимание:** не се изисква `ManySets` да се грижи за жизнения цикъл на вложените множества (т.е. не е необходимо да реализирате дълбоко копиране, но може да го направите за бонус).