# Функции от по-висок ред и едносвързан списък

## MyLinkedList :chains::arrow_right::scroll:	

Реализирайте шаблон на клас `MyLinkedList`, представляващ едносвързан списък. За да пазим отделните "кутии" в нашия списък, ще използваме структура от вида:

```c++
template <class T>
struct box
{
    T value; // стойност, съхранена в кутията
    box* next; // указател към следващия елемент или nullptr, ако няма такъв
};
```

Класът трябва да има следния интерфейс:
- `MyLinkedList()` - създава празен едносвързан списък
- `MyLinkedList(const T* arr, std::size_t size)` - създава свързан списък, съдържащ всички елементи от `arr`, подредени в същия ред
- Да спазва Rule of 0/3
- `void push_back(const T& element)` - добавя елемент в края на списъка
- `void pop_back()` - премахва елемент от края на списъка
- `void push_front(const T& element)` - добавя елемент в началото на списъка
- `void pop_front()` - премахва елемент от началото на списъка
- `void insertAt(const T& element, std::size_t index)` - добавя елемент на позиция `index`
- `T& operator [] (std::size_t index)` - достъпва елемента на позиция `index`
- `T& front()` - достъпва първия елемент на списъка
- `T& back()` - достъпва последния елемент на списъка
- `T& middle()` - достъпва средния елемент на списъка
- константни версии на горепосочените 4 функции
- `T head() const` - връща копие на първия елемент на списъка
- `MyLinkedList<T> tail() const` - връща копие на списъка, съдържащ всички елементи без първия
- `std::size_t size() const` - дава информация за размера на списъка
- `bool empty() const` - проверява дали списъкът е празен
- `void reverse()` - обръща списъка (`[1 2 3]` ---> `[3 2 1]`)
- `void merge(const MyLinkedList<T>& other, std::function<bool(const T&, const T&)> compartor = [](const T& first, const T& second)->bool{return first < second;})` - слива два сортирани свързани списъка (ако `*this` или `other` не са сортирани, да не се прави нищо) в нов сортиран масив (`[1 3 5 7]`, `[2 4 6 8]` ---> `[1 2 3 4 5 6 7 8]`); за сравнение на два елемента използва `comparator`
- `void sort(std::function<bool(const T&, const T&)> compartor = [](const T& first, const T& second)->bool{return first < second;})` - сортира свързания списък; за сравнение на два елемента използва `comparator` (използвайте Merge sort)
- `MyLinkedList<T> filter(std::function<bool(const T&)> predicate) const` - създава нов свързан списък с елементите, удовлетворяващи предиката `predicate`
- `MyLinkedList<R> map(std::function<R(const T&)> mapper) const` - създава нов свързан списък, като върху всеки елемент на текущия списък се прилага функцията `mapper`
- `R foldLeft(const R& init, std::function<R(const R&, const T&)> folder) const` - по подадена начална стойност `init` връща резултата от прилагането на функцията `folder` над всички елементи
- `T reduce(std::function<T(const T&, const T&)> reducer) const` - същото като `foldLeft`, но за стойност на `init` взима първия елемент на списъка
- `T& find(std::function<bool(const T&)> predicate)` - връща първия елемент от списъка, удовлетворяващ предиката `predicate`
- константна версия на горната функция
- `MyLinkedList<T> takeWhile(std::function<bool(const T&)> predicate) const` - връща нов списък, съдържащ всички елементи до първия, за който предикатът `predicate` връща `false`
- `MyLinkedList<T> dropWhile(std::function<bool(const T&)> predicate) const` - връща нов списък, съдържащ всички елементи, започвайки от първия, за който предикатът `predicate` връща `false`
- `MyLinkedList<R> zipWith(const MyLinkedList<T>& other, std::function<R(const T&, const T&)> zipper) const` - връща нов списък, съдържащ елементи, които са резултати от прилагането на функцията `zipper` върху съответните елементи на `*this` и и `other`
- `MyLinkedList<MyLinkedList<T>> group() const` - връща списък от нови списъци, конкатенацията на които е равна на първоначалния списък и всеки подсписък съдържа само еднакви елементи (`["Mississippi"]` ---> `[["M"], ["i"], ["ss"], ["i"], ["ss"], ["i"], ["pp"], ["i"]]`)
- `MyLinkedList<MyLinkedList<T>> groupBy(std::function<bool(const T&, const T&)> comparator) const` - същото като `group`, само че използва `comparator` вместо `==`
- `MyLinkedList<MyLinkedList<T>> inits() const` - връща списък от всички префикси (`["abc"]` ---> `[[""], ["a"], ["ab"], ["abc"]]`)
- `MyLinkedList<MyLinkedList<T>> tails() const` - връща списък от всички суфикси (`["abc"]` ---> `[["abc"], ["bc"], ["c"], [""]]`)
- `std::pair<MyLinkedList<T>, MyLinkedList<T>> partition(std::function<bool(const T&)> predicate) const` - връща наредена двойка от списъци - първият съдържа всички елементи, за които `predicate` дава `true`, а вторият всички, за които дава `false`
- `bool all(std::function<bool(const T&)> predicate) const` - проверява дали всички елементи на списъка удовлетворяват предиката `predicate` (*квантор за всеобщност*)
- `bool any(std::function<bool(const T&)> predicate) const` - проверява дали има поне един елемент в списъка, удовлетворяващ предиката `predicate` (*квантор за съществуване*)

Демонстрирайте употребата на всички методи на класа в `main`, като предоставите смислени примери.
