#include <iostream>
#include <cstring>

using std::min;
using std::cout;
using std::nothrow;

enum Sport{

    Football,
    Basketball,
    Voleyball,
    Tennis

};

class Athlete{

    public:
        Athlete();
        Athlete(char const * const &, int const &, int const &, int const &, bool const &, char const * const &, Sport const &);
        ~Athlete();

        char const *getName() const;
        int getStamina() const;
        int getSpeed() const;
        int getPower() const;
        bool getTrauma() const;
        char const *getTeam() const;
        Sport getSport() const;

        void changeTeam(char const * const &);
        void train();
        void print() const;

    private:
        char *name;
        int stamina, speed, power;
        bool trauma;
        char *team;
        Sport sport;

};

Athlete::Athlete(){

    name = team = nullptr;
    stamina = speed = power = 1;
    trauma = false;
    sport = Football;

}

Athlete::Athlete(char const * const &name, int const &stamina, int const &speed, int const &power, bool const &trauma, char const * const &team, Sport const &sport):
name(new(nothrow) char[strlen(name) + 1]), stamina(stamina), speed(speed), power(power), trauma(trauma), team(new(nothrow) char[strlen(team) + 1]), sport(sport){

    if(this -> name) strcpy(this -> name, name);
    if(this -> team) strcpy(this -> team, team);

}

Athlete::~Athlete (){

    delete[] name;
    delete[] team;

}

char const *Athlete::getName() const{
    return this -> name;
}

int Athlete::getStamina() const{
    return this -> stamina;
}

int Athlete::getSpeed() const{
    return this -> speed;
}

int Athlete::getPower() const{
    return this -> power;
}

bool Athlete::getTrauma() const{
    return this -> trauma;
}

char const *Athlete::getTeam() const{
    return this -> team;
}

Sport Athlete::getSport() const{
    return this -> sport;
}
void Athlete::changeTeam(char const * const &team){

    delete[] this -> team;
    this -> team = new(nothrow) char[strlen(team) + 1];
    strcpy(this -> team, team);

}

void Athlete::train() {

    if(trauma) return;

    power = min(power + 1, 5);
    stamina = min(stamina + 1, 5);
    speed = min(speed + 1, 5);

}

void Athlete::print() const
{
    cout << (name ? name : "\0") << ' '
        << power << ' '
        << speed << ' '
        << stamina << ' '
        << trauma << ' '
        << (team ? team : "\0") << ' ';
    switch (sport){

        case Football:
            cout << "Football\n";
            break;

        case Voleyball:
            cout << "Voleyball\n";
            break;

        case Basketball:
            cout << "Basketball\n";
            break;

        case Tennis:
            cout << "Tennis\n";
            break;
        
        default:
            break;

    }

}


int main(){

    Athlete first;
    Athlete second("Hristo", 2, 3, 1, false, "Bistriskite Tigri", Voleyball);

    first.print();
    second.print();

    second.train();
    second.print();

    second.changeTeam("Maznite banici");
    second.print();

    first.train();
    first.print();

}