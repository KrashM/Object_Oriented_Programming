#pragma once

#include <utility>

template <typename T, typename U>
class pair{

    public:
        pair() = default;
        pair(T const &, U const &);
        pair(pair const &) = default;
        pair(pair &&) = default;
        ~pair() = default;

        pair &operator =(pair const &) = default;
        pair &operator =(pair &&) = default;

        T &get_first();
        T const &get_first() const;

        U &get_second();
        U const &get_second() const;

    private:
        T _first;
        U _second;

};

template <typename T, typename U>
pair<T, U>::pair(T const &first, U const &second): _first(first), _second(second){}

template <typename T, typename U>
T &pair<T, U>::get_first(){ return _first; }

template <typename T, typename U>
T const &pair<T, U>::get_first() const{ return _first; }

template <typename T, typename U>
U &pair<T, U>::get_second(){ return _second; }

template <typename T, typename U>
U const &pair<T, U>::get_second() const{ return _second; }