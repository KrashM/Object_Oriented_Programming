#include <iostream>
#include <string>

template <class T>
class Vector
{
private:
    static const std::size_t INCREASE_STEP = 2;
    static const std::size_t INITIAL_CAPACITY = 2;

    T* arr;
    std::size_t size;
    std::size_t capacity;

    void copy(const Vector<T>& other)
    {
        this->arr = new T[other.capacity];
        for (std::size_t i = 0; i < other.size; ++i)
        {
            this->arr[i] = other.arr[i];
        }

        this->size = other.size;
        this->capacity = other.capacity;
    }

    void deallocate()
    {
        delete[] this->arr;
    }

    void resize()
    {
        T* newArr = new T[this->capacity * INCREASE_STEP];
        for (std::size_t i = 0; i < this->size; ++i)
        {
            newArr[i] = this->arr[i];
        }

        delete[] this->arr;
        this->arr = newArr;
        this->capacity += INCREASE_STEP;
    }

public:
    Vector()
        : arr(new T[INITIAL_CAPACITY]), size(0), capacity(INITIAL_CAPACITY) {}

    Vector(const Vector& other)
    {
        this->copy(other);
    }

    Vector& operator = (const Vector& other)
    {
        if (this != &other)
        {
            this->deallocate();
            this->copy(other);
        }

        return *this;
    }

    ~Vector()
    {
        this->deallocate();
    }

    void add(const T& element)
    {
        if (this->size == this->capacity)
        {
            this->resize();
        }

        this->arr[this->size++] = element;
    }

    void removeAt(std::size_t index)
    {
        if (index >= this->size)
        {
            throw std::invalid_argument("Invalid index");
        }

        for (std::size_t i = index; i < this->size - 1; ++i)
        {
            this->arr[i] = this->arr[i + 1];
        }

        --this->size;
    }

    T& operator [] (std::size_t index)
    {
        if (index >= this->size)
        {
            throw std::invalid_argument("Invalid index");
        }

        return this->arr[index];
    }

    const T& operator [] (std::size_t index) const
    {
        if (index >= this->size)
        {
            throw std::invalid_argument("Invalid index");
        }

        return this->arr[index];
    }

    std::size_t getSize() const
    {
        return this->size;
    }

    class VectorIterator
    {
    private:
        friend class Vector;
        T* pointer;

        VectorIterator(T* pointer) : pointer(pointer) {}

    public:
        T& operator * ()
        {
            return *pointer;
        }

        const T& operator * () const
        {
            return *pointer;
        }

        T* operator -> ()
        {
            return pointer;
        }

        const T* operator -> () const
        {
            return pointer;
        }

        VectorIterator& operator ++ ()
        {
            ++pointer;
            return *this;
        }

        VectorIterator operator ++ (int)
        {
            VectorIterator old = *this;
            ++(*this);
            return old;
        }

        VectorIterator& operator -- ()
        {
            --pointer;
            return *this;
        }

        VectorIterator operator -- (int)
        {
            VectorIterator old = *this;
            --(*this);
            return old;
        }

        bool operator == (const VectorIterator& other) const
		{
			return pointer == other.pointer;
		}

		bool operator != (const VectorIterator& other) const
		{
			return !(*this == other);
		}
    };

    VectorIterator begin()
    {
        return VectorIterator(this->arr);
    }

    VectorIterator end()
    {
        return VectorIterator(this->arr + this->size);
    }
};

class Person
{
private:
    std::string name;
    int age;

public:
    Person(const std::string& name = "", int age = 0) : name(name), age(age) {}

    void print() const
    {
        std::cout << "My name is " << this->name << " and I am " << this->age << " years old." << std::endl;
    }
};

int main ()
{
    Vector<int> v;

    v.add(1);
    v.add(3);
    v.add(5);
    v.add(7);
    v.add(9);
    v.add(11);

    for (std::size_t i = 0; i < v.getSize(); ++i)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    for (Vector<int>::VectorIterator it = v.begin(); it != v.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    for (int currentElement: v)
    {
        std::cout << currentElement << " ";
    }
    std::cout << std::endl;

    Vector<Person> people;

    people.add(Person("Pesho", 22));
    people.add(Person("Vasko", 21));
    people.add(Person("Gosho", 23));

    for (std::size_t i = 0; i < people.getSize(); ++i)
    {
        people[i].print();
    }

    for (Vector<Person>::VectorIterator it = people.begin(); it != people.end(); ++it)
    {
        it->print();
    }

    for (const Person& currentPerson: people)
    {
        currentPerson.print();
    }

    return 0;
}