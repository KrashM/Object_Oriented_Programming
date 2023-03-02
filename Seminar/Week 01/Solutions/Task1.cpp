#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::sqrt;
using std::swap;

struct point{
    double x, y;
};

struct triangle{
    point A, B, C;
    double area;
};

double findDistance(const point &A, const point &B){
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

void findArea(triangle &trie){

    double AB, AC, BC;
    AB = findDistance(trie.A, trie.B);
    AC = findDistance(trie.A, trie.C);
    BC = findDistance(trie.B, trie.C);

    double halfPeri = (AB + AC + BC) / 2;

    trie.area = sqrt(halfPeri * (halfPeri - AB) * (halfPeri - AC) * (halfPeri - BC));

}

void sort(triangle *tries, const size_t &size){

    for(size_t i = 0; i < size - 1; ++i)
        for(size_t j = i + 1; j < size; ++j)
            if(tries[i].area > tries[j].area)
                swap(tries[i], tries[j]);

}

int main(){

    size_t n;
    cin >> n;

    triangle *tries = new triangle[n];

    for(size_t i = 0; i < n; ++i){

        cin >> tries[i].A.x >> tries[i].A.y
            >> tries[i].B.x >> tries[i].B.y
            >> tries[i].C.x >> tries[i].C.y;
        findArea(tries[i]);

    }

    sort(tries, n);

    for(size_t i = 0; i < n; ++i)
        cout << tries[i].area << ' ';
    cout << '\n';

    delete[] tries;

}