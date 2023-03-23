<h1>Unit testing</h1>

<h3>Дефиниция</h3>

Тестването на индивидуални софтуерни компоненти (units).

<h3>Какво представлява unit?</h3>

Unit е най-малката частица код, която може да се test-ва (или си заслужава да се тества).
Обикновено това може да е цял модул, но обикновенно е функция или метод.
Има 1 или няколко входа и **един** изход.

*Някои от по-известните framework-ове.*

|Language  |Test framework  |
|----------|----------------|
|C++       |CppUnit, doctest|
|C#        |NUnit, csUnit   |
|Java      |JUnit, Jtest    |
|JavaScript|JSUnit, QUnit   |

<h3>Какъв подход се използва за писане на unit тестове?</h3>

- най-използвания подход е test \- function \- expected value
- идеята е, че тестваме точно определена функционалност
- В помощ на unit test-овете влизат method stubs, mock objects, fakes и test harnesses, 
като идеята е, че те ни позволяват да се фокусираме над това, което тестваме
- Целта на unit test-овете е да изолират всяка една част на програмата и да покажат, че е коректна.
- Unit test-овете намират проблеми от рано в development процесът
- **[тук](https://github.com/doctest/doctest)** можете да намерите doctest framework-а.

<h3>Code coverage</h3>

Code coverage е измеримост на това, колко линии/блокове от нашия код са изпълнени, докато автоматизираните тестове текат.

<h3>White vs Black box testing</h3>

<!-- TODO: Оправи който -->
- Black Box Testing е метод на тестване, при който вътрешната структура/дизайн/имплементация на блокът, който се тества, не са известни на този, който ги тества.
- White Box Testing е метод на тестване, при който вътрешната структура/дизайн/имплементация на блокът, който се тества са известни на този, който ги тества.

<h3>Кой пише unit тестове?</h3>

- Обикновенно самите софтуерни разработчици пишат тестовете си.

<h3>Ползи от unit тестове</h3>

- Unit тестовете осигурява сигурност при промяна/поддръжка на кода ни.
- Кодът става преизползваем, защото кодът става на модули, които могат да бъдат тествани отделно.
- Усилията, които ще ни коства да оправим дефект, засечен по време на тестване, са по-малко отколкото да оправим дефект, засечен на по-високо ниво.
- Debug-ването е по-лесно.

<h3>Примери от живота</h3>

<!-- TODO: Оправи -->
Lets say you have a program comprising of two units and the only test you perform is system testing. (You skip unit and integration testing.)
During testing, you find a bug. Now, how will you determine the cause of the problem?

Нека приемем, че имаме програма, която се състои от два unit-а и единственият тест, който правим е системен тест. (Пропускаме unit и integration тестовете.)
По време на тестване намираме bug в програмата. Сега, как ще определим от къде идва той?

Имаме следните варианти:

- В unit 1 ли е проблемът?
- В unit 2 ли е проблемът?
- И в двата unit-а ли има проблеми?
- Проблемът в интерфейса между двата unit-а ли е?
- Проблемът в тестът или в тест case-ът е?

<h3>Doctest</h3>
[Линк към Doctest repo-то](https://github.com/doctest/doctest)

<h3>Test Driven Development (TDD)</h3>

**Test-driven development (TDD)** е процес за софтуерна разработка, който разчита на повторението на един много кратък цикъл на разработка:

- Първо програмистът пише тест, който не минава, обаче дефинира желано подобрение или нова функционалност.
- След това пише код, който да минава тестът.
- И накрая рефакторира новият код, за да е по-четим.

Test-driven development is related to the test-first programming concepts of extreme programming, and often linked to an agile programming approach. In its pure form, TDD has benefits, but it also has drawbacks. But we can use some practices to improve quality of code in our projects.

TDD методът за работа може да се опише, като повторение на следните стъпки (показани на снимката):

- Избираме, коя функционалност трябва да се имплементира.
- Добавяме тест(ове) за избраната функционалност.
- Компилираме, тестваме и гледаме дали има някакви грешки.
- Пишем код, който да работи.
- Рефакторираме написаният код.
- Повтаряме тестовете, оправяме кода ако има грешни тестове.
- Commit-ваме промените.
- Отиваме на следващата функционалност и повтаряме стъпките.

![](https://i.ibb.co/61tp58D/TDD.png)

<!-- TODO: It gets really boring -->
<h3>Unit testing and frameworks</h3>

За да се опрости разработването на модулни тестове, обикновено се използват модулни тестови рамки. Рамката за тестване на модули трябва да предоставя следната функционалност:

- Писането на модулни тестове трябва да бъде просто и очевидно за новите потребители.
- Рамката трябва да позволява на напреднали потребители да извършват нетривиални тестове.
- Тестовият модул трябва да може да има много малки тестови случаи и разработчикът трябва да може да ги групира в тестови пакети.
- В началото на разработката потребителите може да искат да видят многословно и описателно съобщение за грешка, докато по време на регресионното тестване може просто да искат да знаят само дали има неуспешни тестове.
- За малки тестови модули времето за изпълнение трябва да преобладава над времето за компилиране: потребителите не искат да чакат нито минута, за да компилират тест, който отнема секунда за изпълнение.
- За продължителни и сложни тестове потребителите може да искат да могат да видят напредъка на теста.
- Изпълнението на отделните тестове трябва да бъде независимо от други тестове. Например прекратяването (сривът) на един тест не трябва да води до пропускане на всички останали тестове.
- Простите тестове не трябва да изискват външна библиотека.
- Почти всеки език за програмиране вече има няколко рамки за тестване на единици. Най-широко разпространени са фреймуърките от така нареченото `xUnit` семейство рамки (JUnit, CppUnit, NUnit и др.). Рамките от това семейство са много лесни за използване и споделят общи функции и архитектура. Всяка от тези рамки се състои от:

- Твърдения, които проверяват индивидуалните условия;
- Тестови случаи, които комбинират няколко твърдения, базирани на някаква обща функционалност;
- Тестови пакети, които комбинират няколко теста, логически свързани помежду си;
- Фикстури, които осигуряват настройка на данни или състояние, необходими за изпълнение на някои тестове, и почистване на състояние и/или данни след приключване на теста. (Някои рамки предоставят отделни тестови случаи, тестови пакети и/или глобални фикстури)
- Рамките също включват монитор за изпълнение, който контролира как се изпълняват тестовете и събира данни за неуспешни тестове.
To simplify development of unit tests, unit test frameworks are usually used. Unit testing framework should provide following functionality:

## How to organize tests
Usually unit tests should be created for all publicly exposed functions — free functions not declared as static, and all public functions of classes, including public constructors and operators. Unit tests should cover all main paths through functions, including different branches of conditionals, loops, etc. Your unit test should handle both trivial, and edge cases, providing wrong and/or random data, so you will be able to test error handling. You can find more advices on unit tests code organization in **[following article](https://geosoft.no/unittesting.html)**.

Test cases are often combined into test suites by some criteria — common functionality, different use cases for same functions, common fixtures, etc. Fixtures are used to perform setup and cleanup of data that are needed to perform test cases — this also allows unit tests to be very short and easy to understand.

There are some recommended ways to implement tests:

- your test case should test only one thing;
- test case should be short;
- test should run fast, so it will possible to run it very often;
- each test should work independent of other tests. Broken test shouldn't prevent other tests from execution;
- tests shouldn't be dependent on the order of their execution.
- Some people argues, that combining of all test cases into big functions, improves readability of code, and make it more concise. But there are arguments against this approach (some of them are mentioned in following document):

- if fatal error happens, or an exception is thrown by some check, then the rest of tests will be skipped and there is no way to prevent this;
- there is no way to perform only checks for a particular subsystem of the tested unit.

Testability of code also depends on its design. Sometimes it's very hard to write unit tests, because functionality to be tested is hidden behind many interfaces, or there are many dependencies, so it's hard to set up the test correctly. There are some suggestions on how code should be written to allow easier writing of unit tests for it:

- code should be loosely coupled — class or function should have as few dependencies as possible;
- avoid creation of particular instances of complex classes inside your class. It's better to pass pointers/references to these classes to your class/function — this will allow to use mocking to test your code;
- you should try to minimize public API that is provided by class — it's better to write several classes, that perform separate tasks, instead of creating one class, that does everything.
More advice on writing testable code you can find in following blog post.

## Mocking
In a unit test, mock objects can simulate behavior of complex, real (non-mock) objects and they are very useful when a real object is impractical or impossible to incorporate into a unit test. If an object has any of the following characteristics, it may be useful to use a mock object instead:

- supplies non-deterministic results (e.g., current time or current temperature);
- has states that are difficult to create or reproduce (e.g. a network error);
- slow (e.g. a complete database, which would have to be initialized before the test);
- does not exist yet, or may change behavior;
- would have to include information and methods exclusively for testing purposes (and not for its actual task).

Mock objects have the same interface as real objects they mimic, allowing a client object to remain unaware of whether it's using a real object, or a mock object. Many available mock object frameworks allow the programmer to specify which, and in what order, methods will be invoked on a mock object, and what parameters will be passed to them, as well as what values that will be returned. Thus, the behavior of a complex object, such as a network socket, can be emulated by a mock object, allowing the programmer to discover whether the object being tested responds appropriately to the wide variety of states, such objects may be in.

Typical workflow looks following way:

- you should have an interface for class that you will test, so you can have mocked class and real-world class;
- you create a mocked class using some framework (you can also write it yourself, but it's bad idea);
- you have a code, that you want to test against mocked object;
- you create a test case that will use your mocked object instead of real-world one. Inside this test case you do following:
  - you create an instance of mocked class;
  - you setup behavior and expectations on mocked object — which methods should be called (or not called), which data will be returned for a particular call, etc.
  - you run your code that will use mocked object some way;
  - after execution of your code, you evaluate results of execution and check expectations against actual results — usually this is done automatically by framework, when a mocked object is destroyed.

# Задачи

## За всички задачи да бъдат напиасни тестове със 100% code coverage 

> Задача 1

1. Да се дефинира клас Dictionary, който представлява тълковен речник. Нека речникът се състои от двойки дума\-тълкуване. В един речник не може да има повече от 500 такива двойки.
- да се дефинира подходящ клас, описващ една двойка дума тълкувание със следните методи
    - `init(const char*, const char*)` - инициализира структурата
    - `copy()` - връща нова структура, копие на оригиналната
    - `print()` - принтира двойката на екрана по подходящ начин
    - `deleteDynamic()` - зачиства динамичната памет
- за класа `Dictionary` да се дефинират:
    - `init(Record*, int)` - инициализира речника с масив от двойки
    - `print()` - принтира съдържанието на речника
    - `add(const Record&)` - добавя нова двойка към речника
    - `remove(const char*)` - премахва дадена двойка, като търсенето става по думата
    - `findMeaning(const char*)` - връща значението на дадена дума
    - `getByIndex(int index)` - връща значението на двойка с номер index
    - `sort()` - сортира двойките лексикографски по първи член на двойката (не по значението)
    - `deleteDynamic()` - обичайното 

> Задача 2. 
Да се създаде

```enum Position {JUNIOR_DEV, DEV, SENIOR_DEV, QA, MANAGER};```

Да се създаде структура `Developer` със следните полета:
- mId - идентификационен номер в компанията. Представлява случайно генерирано 4-цифрено число.
- mFirstName;
- mLastName;
- mPosition - позиция, която заема. Една от константите Position.

Да се реализират функции:
- за инициализация на полетата на developer;
- за зачистване на диманичната памет  на developer;
- за записване на Developer във файл. При записване във файл developer-a да се добавя на края на съществуващия файл;
- за четене на полетата на Developer от файл;
- за принтиране на стандартния изход. Използвайте записването във файл.

Помислете как можете да добавите поле на Developer, което представлява прекия мениджър на developer-a и може да се заема само от друг Developer, чиято позиция е Manager.

П.П. Знанията за решаване на тази задача ще дойдат малко по-късно.

# Домашно
Напишете тестове за класът `Vector` от миналата седмица.