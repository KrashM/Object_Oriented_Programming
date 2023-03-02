#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::sqrt;
using std::swap;

struct quadratic{
    double a, b, c, d, x1, x2;
};

void findDiscriminant(quadratic &equation){
    equation.d = equation.b * equation.b - 4 * equation.a * equation.c;
}

void solve(quadratic &equation){

    if(equation.d < 0) equation.x1 = equation.x2 = -1000;
    else if(equation.d == 0) equation.x1 = equation.x2 = -equation.b / (2 * equation.a);
    else{

        equation.x1 = (-equation.b - sqrt(equation.d)) / (2 * equation.a);
        equation.x2 = (-equation.b + sqrt(equation.d)) / (2 * equation.a);

        if(equation.x1 > equation.x2)
            swap(equation.x1, equation.x2);

    }

}

int main(){

    quadratic equation;

    cin >> equation.a >> equation.b >> equation.c;

    findDiscriminant(equation);
    solve(equation);

    if(equation.x1 == -1000) cout << "The equation does not have real solutions!\n";
    else if(equation.x1 == equation.x2) cout << "x1 = x2 = " << equation.x1 << '\n';
    else cout << "x1 = " << equation.x1 << ", x2 = " << equation.x2 << '\n';

}