#include "Sentence.hpp"

using std::cout;

int main(){

    Word v;
    v += 'a';
    v += 'c';
    v += 'h';
    v + 'w';

    Word v1;

    v1 = v;

    Sentence s;
    s.addWord(v1);

    cout << s << '\n';
    
}