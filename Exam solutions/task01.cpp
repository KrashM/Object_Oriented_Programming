#include <iostream>
#include <functional>
#include <vector>

template <class T>
class Sequence
{
private:
    std::vector<T> data;

public:
    Sequence(const T& a0, std::size_t k, std::function<T(const T&)> next)
    {
        data.push_back(a0);

        for (std::size_t i = 0; i < k - 1; ++i)
        {
            data.push_back(next(data[i]));
        }
    }

    T& operator [] (std::size_t index)
    {
        if (index >= data.size())
        {
            throw std::invalid_argument("Invalid index");
        }

        return this->data[index];
    }

    const T& operator [] (std::size_t index) const
    {
        if (index >= data.size())
        {
            throw std::invalid_argument("Invalid index");
        }

        return this->data[index];
    }

    class SequenceIterator
    {
    private:
        friend class Sequence;
        T* pointer;

    public:
        SequenceIterator(T* pointer) : pointer(pointer) {}

        T& operator * ()
        {
            return *pointer;
        }

        const T& operator * () const
        {
            return *pointer;
        }

        SequenceIterator& operator ++ ()
        {
            ++this->pointer;

            return *this;
        }

        SequenceIterator operator ++ (int)
        {
            SequenceIterator old = *this;
            ++(*this);

            return old;
        }

        bool operator == (const SequenceIterator& other) const
        {
            return this->pointer == other.pointer;
        }

        bool operator != (const SequenceIterator& other) const
        {
            return this->pointer != other.pointer;
        }
    };

    SequenceIterator begin()
    {
        return SequenceIterator(&this->data[0]);
    }

    SequenceIterator end()
    {
        return SequenceIterator(&this->data[0] + this->data.size());
    }
};

int p2(int x)
{
    return x + 2;
}

int main ()
{
    Sequence<int> even10(0, 10, p2);

    for (int x : even10)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
