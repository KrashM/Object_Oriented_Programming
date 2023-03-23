#include <iostream>
#include <cstring>

using std::max;
using std::min;
using std::cin;
using std::cout;
using std::boolalpha;

struct Beer{

    Beer(const char * const &, const int &);
    ~Beer();

    char *getName() const;
    int getML() const;

    void add(Beer &, const int &);
    void fill(const int &);
    bool check(const char * const &);

    char *name;
    int ml;

};

Beer::Beer(const char * const &name, const int &ml = 0): name(new char[strlen(name) + 1]), ml(ml){
    strcpy(this -> name, name);
}

Beer::~Beer(){
    delete[] name;
}

char *Beer::getName() const{
    return name;
}

int Beer::getML() const{
    return ml;
}

void Beer::add(Beer &other, const int &ml){

    strcat(this -> name, "&");
    strcat(this -> name, other.name);

    this -> ml += min(ml, other.ml);
    other.ml = max(other.ml - ml, 0);

}

void Beer::fill(const int &ml){
    this -> ml += ml;
}

bool Beer::check(const char * const &name){
    return strstr(this -> name, name);
}

int main(){

    Beer beer1("Corona", 500), beer2("Heineken", 500);

    beer1.add(beer2, 250);
    beer2.fill(250);

    cout << boolalpha << beer1.check("Heineken") << '\n';
    cout << boolalpha << beer1.check("Stella Artois") << '\n';
    cout << boolalpha << beer1.check(beer2.getName()) << '\n';

}