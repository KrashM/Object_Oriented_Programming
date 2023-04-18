# Функции от по-висок ред и едносвързан списък

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
- `void pop_back()` - премахма елемент от края на списъка
- `void push_front(const T& element)` - добавя елемент в началото на списъка
- `void pop_front()` - премахма елемент от началото на списъка
- `void insertAt(const T& element, std::size_t index)` - добавя елемент на позиция `index`
- `T& operator [] (std::size_t index)` - достъпва елемента на позиция `index`
- `T& front()` - достъпва първия елемент на списъка
- `T& back()` - достъпва последния елемент на списъка
- `T& middle()` - достъпва средния елемент на списъка
- константни версии на горепосочените 4 функции
- `std::size_t size()` - дава информация за размера на списъка
- `bool empty()` - проверява дали списъкът е празен
- `void merge(const LinkedList<T>& other, std::function<bool(const T&, const T&)> compartor = [](const T& first, const T& second)->bool{return first < second;})` - слива два сортирани свързани списъка (ако `*this` или `other` не са сортирани, да не се прави нищо); за сравнение на два елемента използва `comparator`
- `void sort(std::function<bool(const T&, const T&)> compartor = [](const T& first, const T& second)->bool{return first < second;})` - сортира свързания списък; за сравнение на два елемента използва `comparator` (използвайте Merge sort)
- `MyLinkedList<T> filter(std::function<bool(const T&)> predicate)` - създава нов свързан списък с елементите, удовлетворяващи предиката `predicate`
- `MyLinkedList<R> map(std::function<R(const T&)> mapper)` - създава нов свързан списък, като върху всеки елемент на текущия списък се прилага функцията `mapper`
- `R reduce(const R& init, std::function<R(const R&, const T&)> reducer)` - по подадена начална стойност `init` връща резултата от прилагането на функцията `reducer` над всички елементи
- `T& find(std::function<bool(const T&)> predicate)` - връща първия елемент от списъка, удовлетворяващ предиката `predicate`
- `MyLinkedList<T> takeWhile(std::function<bool(const T&)> predicate)` - връща нов списък, съдържащ всички елементи до първия, за който предикатът `predicate` връща `false`
- `MyLinkedList<T> dropWhile(std::function<bool(const T&)> predicate)` - връща нов списък, съдържащ всички елементи, започвайки от първия, за който предикатът `predicate` връща `false`
- `MyLinkedList<R> zipWith(const MyLinkedList<T>& other, std::function<R(const T&, const T&)> zipper)` - връща нов списък, съдържащ елементи, които са резултати от прилагането на функцията `zipper` върху съответните елементи на `*this` и и `other`