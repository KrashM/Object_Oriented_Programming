# Шаблони и статични членове

## Задача 1 :page_with_curl:
Да се направи темплейтен клас `List`, който има следните функционалности:

* съдържа произволен брой уникални елементи
* да се добавят нови елементи
* да се премахва елемент на определена позиция
* да се достъпват елементите във вида list[3]
* да дава информация за броя елементи
* да дава информация дали е празен
* да има функция за записване на елементите във файл
* да има функция за зареждане на елементите от файл

## Задача 2 :computer:
Създайте клас `Computer`, съдържащ следните полета (можете да ползвате `std::string` или динамично заделени символни низове):
- serial number - полето се генерира автоматично с последователни числа за всеки нов обект от класа.
- brand
- processor
- video
- hard drive
- weight
- battery life
- price
- quantity

Спазвайте принципа за капсулация на данните. Създайте конструктор, който приема всички полета. Следвайте Rule of 0/3. Създайте getters и setters за всички полета. Предефинирайте операторите за вход и изход.

## Задача 3 :department_store:
Създайте клас `ComputerShop`, описващ компютърен магазин, съдържащ следните полета (можете да ползвате `std::string` или динамично заделени символни низове):
- name
- списък с компютри (използвайте задача 1)

Създайте конструктор, който приема име на магазина. Следвайте Rule of 0/3.

Създайте следните методи:  
- добавяне на компютър - ако вече има компютър от съответната марка, увеличава количеството, ако няма, го добавя в списъка.
- принтиране на списъка с компютри
- покупка на компютър - приема brand и пари на купувача. Ако купувача има достатъчно пари спрямо цената и има достатъчно количество от съответния компютър принтира успешна покупка и намалява количеството. В противен случай извежда подходящо съобщение.
- метод, връщащ всички компютри с наличност, по-голяма от 0, с опция да филтрира компютри, подходящи за пътуване или такива за игри (за определянето използвайте методите от следващия абзац).   

Създайте `utility class` (клас, съдържащ само статични методи) `ConsultantUtils` с два метода:
- `isGoodForGaming` - приема обект от клас Computer и връща true, ако процесорът е i5 или i7, видеото е 3060, 3070, 3080, 3090 и хард диска е поне 512
- `isGoodForTravel` - приема обект от клас Computer и връща true, ако теглото е не повече от 2.5 кг и животът на батерията е над 6 часа

Приемете, че във вашия свят има само един единствен магазин за компютри. Подсигурете това, като реализирате design pattern-a `Singleton` за класа `ComputerShop`