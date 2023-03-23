#include <iostream>

using std::cin;
using std::cout;
using std::swap;
using std::boolalpha;

struct Time{

    Time();
    Time(unsigned const &, unsigned const &, unsigned const &);

    Time timeTillMidnight() const;
    void increaseWithSecond();
    bool isTimeForDinner() const;
    bool isTimeForParty() const;
    Time difference(Time const &) const;
    int compare(Time const &) const;
    void print() const;

    unsigned hours, minutes, seconds;

};

void sort(Time * const &, size_t const &);

int main(){

    {

        Time t1(23, 21, 00);
        Time t2(12, 32, 12);

        cout << boolalpha << t1.isTimeForParty() << '\n';
        cout << boolalpha << t2.isTimeForDinner() << '\n';

        t1.timeTillMidnight().print();

        t1.difference(t2).print();
        t2.difference(t1).print();
        t1.difference(t1).print();
    
    }

    cout << "Second part:\n";

    {

        Time times[10] = {Time(17, 47, 34),
                        Time(4, 29, 4),
                        Time(6, 18, 22),
                        Time(8, 5, 5),
                        Time(1, 27, 1),
                        Time(11, 55, 2),
                        Time(3, 36, 51),
                        Time(12, 2, 33),
                        Time(4, 22, 21),
                        Time(20, 38, 35)};
        
        sort(times, 10);

        for(size_t i = 0; i < 10; ++i)
            times[i].print();

    }

}

void sort(Time * const &times, size_t const &size){

    size_t index;

    for(size_t i = 0; i < size - 1; ++i){

        index = i;

        for(size_t j = i + 1; j < size; ++j)
            if(times[index].compare(times[j]) == 1)
                index = j;
        
        if(i != index)
            swap(times[i], times[index]);

    }

}

Time::Time(): hours(0), minutes(0), seconds(0){}
Time::Time(unsigned const &hours, unsigned const &minutes, unsigned const &seconds): hours(hours), minutes(minutes), seconds(seconds){}

Time Time::timeTillMidnight() const{

    unsigned seconds = 0, minutes = 0, hours = 24;
    
    if(this -> minutes){

        minutes = 60 - this -> minutes;
        hours--;

    }

    if(this -> seconds){

        seconds = 60 - seconds;
        minutes--;

    }

    return Time(hours, minutes, seconds);

}

void Time::increaseWithSecond(){

    seconds++;

    if(seconds == 60){

        seconds = 0;
        minutes++;

    }

    if(minutes == 60){

        minutes = 0;
        hours++;

    }

    if(hours == 24)
        hours = 0;

}

bool Time::isTimeForDinner() const{
    return (hours >= 20 && minutes >= 30 && hours < 22) || (hours == 22 && !minutes && !seconds);
}

bool Time::isTimeForParty() const{
    return (hours >= 23 && hours < 24) || (hours < 6) || (hours == 6 && !minutes && !seconds);
}

Time Time::difference(Time const &other) const{
    
    unsigned hours, minutes, seconds;
    int comparison = compare(other);

    if(!comparison) return Time();

    if(comparison == 1){

        hours = this -> hours - other.hours;
        if(this -> minutes < other.minutes){

            minutes = this -> minutes + 60 - other.minutes;
            hours--;

        }
        if(this -> seconds < other.seconds){

            seconds = this -> seconds + 60 - other.seconds;
            minutes--;

        }

    }
    else{

        hours = other.hours - this -> hours;
        if(this -> minutes > other.minutes){

            minutes = other.minutes + 60 - this -> minutes;
            hours--;

        }
        if(this -> seconds > other.seconds){

            seconds = other.seconds + 60 - this -> seconds;
            minutes--;

        }

    }

    return Time(hours, minutes, seconds);

}

int Time::compare(Time const &other) const{

    if(this -> hours != other.hours)
        if(this -> hours > other.hours) return 1;
        else return -1;
    if(this -> minutes != other.minutes)
        if(this -> minutes > other.minutes) return 1;
        else return -1;
    if(this -> seconds != other.seconds)
        if(this -> seconds > other.seconds) return 1;
        else return -1;
    
    return 0;

}

void Time::print() const{
    cout << (hours < 10 ? '0' : '\0') << hours
        << ':' << (minutes < 10 ? '0' : '\0') << minutes
        << ':' << (seconds < 10 ? '0' : '\0') << seconds
        << '\n';
}