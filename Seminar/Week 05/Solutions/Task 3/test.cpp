#include "MagicalBox.hpp"

int main(){

    MagicalBox test;

    for(size_t i = 0; i < 10; ++i)
        test.insert(i);
    
    
    for(size_t i = 0; i < 11; ++i)
        cout << test.pop() << '\n';

}