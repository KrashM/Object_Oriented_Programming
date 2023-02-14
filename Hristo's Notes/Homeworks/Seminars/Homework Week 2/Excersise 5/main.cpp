#include "Point.h"
#include "Triangle.h"
#include <iostream>

using std::cin;
using std::cout;

void swap(Triangle &A, Triangle &B){

    Triangle temp = A;
    A = B;
    B = temp;

}

void sortTriangles(Triangle triangles[], int N){

    for(int i = 0; i < N - 1; i++)
        for(int j = i + 1; j < N; j++)
            if(triangles[i].area > triangles[j].area) swap(triangles[i], triangles[j]);

}

int main(){

    int N;
    cin >> N;
    Triangle triangles[N];

    for(int i = 0; i < N; i++){

        cin >> triangles[i].A.x >> triangles[i].A.y
            >> triangles[i].B.x >> triangles[i].B.y
            >> triangles[i].C.x >> triangles[i].C.y;    

        triangles[i].initTriangle();

    }

    sortTriangles(triangles, N);

    for(int i = 0; i < N; i++)
        triangles[i].print();

}