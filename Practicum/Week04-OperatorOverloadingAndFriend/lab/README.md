# Разделна компилация. Предефиниране на оператори. Ключовата дума friend

## Задача 1 :calendar:

Да се реализира клас **Date**, който пази в себе си информация за следните променливи:

* Дата - std::uint8_t
* Месец - std::uint8_t
* Година - std::uint16_t

Класът да има следния интерфейс:

* Класът НЕ ТРЯБВА да има конструктор по подразбиране.
* Date(unsigned int day, unsigned int month, unsigned int year) - конструктор, създаващ нов обект за дата и проверяващ с assert валидността й.
* unsigned int day() const
* unsigned int month() const;
* unsigned int year() const;
* bool operator==(const Date& rhs) const;
* bool operator<(const Date& rhs) const;
* Предефинирайте оператора за изход <<, така че да принтира **Date** в следния формат: "DD.MM.YYYY"

## Задача 2 :heavy_dollar_sign:

Да се реалзира изброим тип **Currency**, който ще има следните стойности:

* BGN
* USD
* EUR

## Задача 3 :currency_exchange:

Напишете структура **ConvertionRate**, която ще съдържа следната информация:

* Обменен курс - double
* Стара валута - **Currency**
* Нова валута - **Currency**

## Задача 4 :money_mouth_face:

Да се реализира клас **Money**, който да пази в себе си следната информация:

* Сума пари - double
* Вид валута - ще бъде един от следните: [BGN, USD, EUR]

Класът да има следния интерфейс:

* Money(); // ***Парите ще са 0 и валутата ще е BGN***
* Money(double startingMoney, Currency currency);
* Метод, който ще връща парите
* Метод, който ще връща валутата
* **Не искаме директни сетъри за парите и валутата!**
* Money softConvert(const ConvertionRate& convertion) const; ***// Не променя стойностите на класа, но променя копие на класа и го връща него.***
* void hardConvert(Currency newCurrency); ***// Променя самия клас.***
* Предефинирайте следните оператори +, +=, -, -= да работят с реални числа.
* Предефинирайте следните операторите +, +=, -, -= да работят с обекти от тип **Money**, като ако валутата е различна, то няма да се добави нищо и ще се изпринтира съобщение на конзолата, че валутите са различни.
* Предефинирайте оператор -, така че като е поставен пред обекта да обръща неговата стойност. ***// m -> 5, BGN; -m -> -5, BGN***
* Предефинирайте операторите за сравнение: ==, !=, <, >, <= , >=
* Предефинирайте следния оператор <<, така че да извеждате информация за парите

## Задача 5 :man_beard:

Да се реализира клас **Client**, който да пази в себе си следната информация:

* Име - низ с точен размер
* ЕГН - низ с точно 10 символа
* Рожден ден - обект от тип **Date**
* Пари - обект от тип **Money**

Класът да има следния интерфейс:

* Client(const char\* name, const char\* identificationNumber, const Date& birthday, const Money& money);
* Преценете дали ще има The Rule of 0 или The Rule of 3
* Реализирайте нужните гетъри и сетъри
* Предефинирайте следния оператор <<, така че да извеждате информация за парите

## Задача 6 :bank:

Да се реализира клас **Bank**, който да пази в себе си следната информация:

* Име на банката - низ с точен размер
* Потребители - самоуголемяващ се масив от **Client**
* Големина на потребителите - std::size_t
* Капацитет на потребителите - std::size_t
* Обменни курсове - масив от точно 6 обекта от тип **ConvertionRate**. Трябва да има обменен курс от всяка валута към всяка друга.

Класът да има следния интерфейс:

* Bank(const char* name, ConvertionRate rates[6]);
* Сами преценете дали ще имаме The Rule of 0 или The Rule of 5
* void addClient(const Client& client);
* bool removeClient(const char* identificationNumber);
* std::size_t getClientIndex(const char* identificationNumber) const;
* bool deposit(const char* identificationNumber, const Money& toDeposit);
* bool withdraw(const char* identificationNumber, const Money& toWithdraw);
* bool transfer(const char\* sourceClientIdentificationNumber, const char\* destinationClientIdentifinationNumber, Money moneyToTransfer); ***// Първо трябва да се провери дали съществуват клиентите, после дали source клиента има достатъчно пари да прехвърли към destionation клиента. После маха парите от source и ги дава на destination. При различни валути може да се наложи конвертиране на парите***
* bool convertClientMoney(const char* identificationNumber, Currency newCurrency);
* const Client& operator[](std::size_t index) const;
* const Client& operator[](const char* identificationNumber) const; // Ще връща потребител с подаденото ЕГН, ако такъв съществува.
* std::ostream& operator<<(std::ostream& out, const Bank& bank); // Принтира името на банката, информация за всички клиенти на банката и обменните курсове
