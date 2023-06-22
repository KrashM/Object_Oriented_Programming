#include <iostream>
#include <vector>

template <class T>
class Set
{
public:
    virtual bool member (const T&) const = 0;

    virtual Set* clone() const = 0;

    virtual ~Set() = default;
};

// PredicateSet
// Конструкторът приема функция от типа: T -> bool
// Конструкторът приема функция, която определя ... 

template <class T>
class PredicateSet : public Set<T>
{
private:
    std::function<bool(const T&)> predicate;

public:
    PredicateSet(std::function<bool(const T&)> predicate) : predicate(predicate) {}

    virtual bool member (const T& x) const
    {
        return predicate(x);
    }

    virtual PredicateSet* clone() const
    {
        return new PredicateSet(*this);
    }

    virtual ~PredicateSet() = default;
};

template <class T>
class Range : public Set<T>
{
private:
    T a, b;

public:
    Range(const T& a, const T& b) : a(a), b(b) {}

    virtual bool member (const T& x) const override final
    {
        return a <= x && x <= b;
    }

    virtual Range* clone() const override final
    {
        return new Range(*this);
    }

    virtual ~Range() = default;
};

class EvenNumbers : public Set<int>
{
public:
    virtual bool member (const int& x) const override final
    {
        return x % 2 == 0;
    }

    virtual EvenNumbers* clone() const override final
    {
        return new EvenNumbers(*this);
    }

    virtual ~EvenNumbers() = default;
};

template <class T>
class Container : public Set<T>
{
private:
    static const std::size_t INITIAL_CAPACITY = 2;
    static const std::size_t INCREASE_STEP = 2;
    
    T* data;
    std::size_t size, capacity;

    void copy(const Container<T>& other)
    {
        this->data = new T[other.capacity];
        for (std::size_t i = 0; i < other.size; ++i)
        {
            this->data[i] = other.data[i];
        }

        this->size = other.size;
        this->capacity = other.capacity;
    }

    void deallocate()
    {
        delete[] this->data;
    }

    void resize()
    {
        T* newData = new T[this->capacity * INCREASE_STEP];
        for (std::size_t i = 0; i < this->size; ++i)
        {
            newData[i] = this->data[i];
        }

        delete[] this->data;
        this->data = newData;

        this->capacity *= INCREASE_STEP;
    }

public:
    Container() : data(new T[INITIAL_CAPACITY]), size(0), capacity(INITIAL_CAPACITY) {}

    Container(const Container<T>& other)
    {
        this->copy(other);
    }

    Container& operator = (const Container<T>& other)
    {
        if (this != &other)
        {
            this->deallocate();
            this->copy(other);
        }

        return *this;
    }

    virtual ~Container() 
    {
        this->deallocate();
    }

    virtual bool member (const T& x) const override final
    {
        for (std::size_t i = 0; i < this->size; ++i)
        {
            if (this->data[i] == x)
            {
                return true;
            }
        }

        return false;
    }

    virtual Container* clone() const override final
    {
        return new Container(*this);
    }

    void add (const T& element)
    {
        if (this->member(element))
        {
            return;
        }

        if (this->size == this->capacity)
        {
            resize();
        }

        this->data[this->size++] = element;
    }

    Container<T> operator + (const Container<T>& other) const
    {
        Container<T> result;

        for (std::size_t i = 0; i < other.size; ++i)
        {
            result.add(other.data[i]);
        }

        return result;
    }

    bool operator <= (const Container<T>& other) const
    {
        if (this->size > other.size)
        {
            return false;
        }

        for (std::size_t i = 0; i < this->size; ++i)
        {
            if (!other.member(this->data[i]))
            {
                return false;
            }
        }

        return true;
    }

    class ContainerIterator
    {
    private:
        friend class Container;
        T* pointer;

    public:
        ContainerIterator(T* pointer) : pointer(pointer) {}

        T& operator * ()
        {
            return *pointer;
        }

        const T& operator * () const
        {
            return *pointer;
        }

        // ++it
        ContainerIterator& operator ++ ()
        {
            ++pointer;
            return *this;
        }

        // it++
        ContainerIterator operator ++ (int)
        {
            ContainerIterator old = *this;
            ++(*this);
            return old;
        }

        bool operator == (const ContainerIterator& other) const
        {
            return this->pointer == other.pointer;
        }

        bool operator != (const ContainerIterator& other) const
        {
            return this->pointer != other.pointer;
        }
    };

    ContainerIterator begin()
    {
        return ContainerIterator(this->data);
    }

    ContainerIterator end()
    {
        return ContainerIterator(this->data + this->size);
    }
};

template <class T>
class ManySets : public Set<T>
{
private:
    std::vector<Set<T>*> sets;

    void copy(const ManySets<T>& other)
    {
        for (Set<T>* currentSet : other.sets)
        {
            sets.push_back(currentSet->clone());
        }
    }

    void deallocate()
    {
        for (Set<T>* currentSet : this->sets)
        {
            delete currentSet;
        }

        this->sets.clear();
    }

public:
    ManySets() = default;

    ManySets(const ManySets<T>& other)
    {
        this->copy(other);
    }

    ManySets& operator = (const ManySets<T>& other)
    {
        if (this != &other)
        {
            this->deallocate();
            this->copy(other);
        }
        
        return *this;
    }

    virtual bool member (const T& x) const override final
    {
        for (Set<T>* currentSet : this->sets)
        {
            if (!currentSet->member(x))
            {
                return false;
            }
        }

        return true;
    }

    virtual ManySets* clone() const override final
    {
        return new ManySets(*this);
    }

    void add (const Set<T>* newSet)
    {
        sets.push_back(newSet->clone());
    }

    virtual ~ManySets()
    {
        this->deallocate();
    }
};

bool myPredicate(int x)
{
    return x % 4 == 0;
}

int main ()
{
    Container<int> c;

    c.add(1);
    c.add(3);
    c.add(5);
    c.add(7);
    c.add(9);
    c.add(12);

    EvenNumbers e;

    Range<int> r(10, 15);

    // for (Container<int>::ContainerIterator it = c.begin(); it != c.end(); ++it)
    // {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;


    // for (int current : c)
    // {
    //     std::cout << current << " ";
    // }
    // std::cout << std::endl;

    ManySets<int> ms;

    ms.add(&c);
    ms.add(&e);
    ms.add(&r);

    std::cout << std::boolalpha << ms.member(12) << std::endl;

    Container<int> c1, c2;

    c1.add(2);
    c1.add(7);
    c1.add(8);

    c2.add(2);
    c2.add(7);
    c2.add(8);
    c2.add(9);

    Container<int> c3 = c1 + c2;

    for (int current : c3)
    {
        std::cout << current << " ";
    }
    std::cout << std::endl;

    std::cout << std::boolalpha << (c1 <= c2) << std::endl;
    std::cout << std::boolalpha << (c2 <= c1) << std::endl;

    Container<int> empty;

    std::cout << std::boolalpha << (empty <= empty) << std::endl;
    std::cout << std::boolalpha << (empty <= c1) << std::endl;
    std::cout << std::boolalpha << (c1 <= empty) << std::endl;

    PredicateSet<int> ps([](int element)->bool{ return element % 4 == 0;});
    // PredicateSet<int> ps(myPredicate);

    ms.add(&ps);

    std::cout << std::boolalpha << ms.member(12) << std::endl;

    return 0;
}


