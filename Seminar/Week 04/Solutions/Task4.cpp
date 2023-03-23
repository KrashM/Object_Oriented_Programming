#include <iostream>
#include <cmath>

using std::min;
using std::max;
using std::cin;
using std::cout;
using std::boolalpha;

struct Interval{

    Interval();
    Interval(int const &, int const &);

    int getLeft() const;
    int getRight() const;

    void setLeft(int const &);
    void setRight(int const &);

    unsigned getLength() const;
    bool isInInterval(int const &) const;

    unsigned countOfPrimeNumbers() const;
    unsigned countOfPalindromeNumbers() const;
    unsigned countOfNonRepeatingNumbers() const;

    bool arePowersOfTwo() const;
    Interval intersect(Interval const &) const;
    Interval unification(Interval const &) const;
    bool isSuperInterval(Interval const &) const;

    int a, b;

};

int main(){

    Interval t1(3,10); // [3, 10]
    Interval t2(4,14); // [4, 14]
    Interval t3; // [0, 0]

    Interval result = t1.intersect(t2); // [4, 10]
    
    cout << boolalpha << t2.isSuperInterval(result) << '\n'; //true
    
    cout << result.countOfPrimeNumbers() << '\n'; // 2 (only 5 and 7)
    cout << Interval(120, 140).countOfNonRepeatingNumbers() << '\n'; // 17 (120, 123, 124, 125, 126, 127, 128, 129, 130, 132, 134, 135, 136, 137, 138, 139, 140)
    cout << Interval(120, 140).countOfPalindromeNumbers() << '\n'; // 2 (only 121 and 131)

    cout << boolalpha << result.arePowersOfTwo() << '\n'; // false

}

Interval::Interval(): a(0), b(0){}

Interval::Interval(int const &a, int const &b){

    if(a <= b){

        this -> a = a;
        this -> b = b;

    }
    else this -> a = this -> b = 0;

}

int Interval::getLeft() const{
    return a;
}

int Interval::getRight() const{
    return b;
}

void Interval::setLeft(int const &a){
    if(a <= b) this -> a = a;
}

void Interval::setRight(int const &b){
    if(a <= b) this -> b = b;
}

unsigned Interval::getLength() const{
    return b - a;
}

bool Interval::isInInterval(int const &n) const{
    return a <= n && n <= b;
}

bool isPrime(int const &n){

    for(int i = 2; i <= sqrt(n); ++i)
        if(n % i == 0) return false;
    return true;

}

unsigned Interval::countOfPrimeNumbers() const{

    unsigned counter = 0;
    for(int i = max(a, 2); i <= b; ++i)
        counter += isPrime(i);
    return counter;

}

unsigned biggestPowTen(int const &n){

    unsigned pow = 1;
    while(pow * 10 < n) pow *= 10;
    return pow;

}

bool isPalindrome(int const &n){

    unsigned left = biggestPowTen(n), right = 1;

    while(left > right){

        if(n / left % 10 != n / right % 10) return false;
        left /= 10;
        right *= 10;

    }

    return true;

}

unsigned Interval::countOfPalindromeNumbers() const{
    
    unsigned counter = 0;

    for(int i = a; i <= b; ++i)
        counter += isPalindrome(i);

    return counter;

}

bool hasRepeatingDigits(int n){

    unsigned mask = 10;

    while(n != 0){

        while(mask <= n){

            if(n % 10 == n / mask % 10) return true;
            mask *= 10;

        }

        n /= 10;

    }

    return false;

}

unsigned Interval::countOfNonRepeatingNumbers() const{

    unsigned counter = 0;
    for(int i = a; i <= b; ++i)
        counter += !hasRepeatingDigits(i);
    return counter;

}

bool Interval::arePowersOfTwo() const{
    return !(a & (a - 1)) && !(b & (b - 1));
}

Interval Interval::intersect(Interval const &other) const{
    return Interval(max(a, other.a), min(b, other.b));
}

Interval Interval::unification(Interval const &other) const{

    if(!intersect(other).getLength()) return Interval();
    return Interval(min(a, other.a), max(b, other.b));

}

bool Interval::isSuperInterval(Interval const &other) const{
    return a <= other.a && other.b <= b;
}