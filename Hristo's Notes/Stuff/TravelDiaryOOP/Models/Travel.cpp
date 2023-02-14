#include "Travel.hpp"

void Travel::erase(){

    delete[] this -> destination;
    delete[] this -> comment;
    delete[] this -> photos;

}

void Travel::copy(const Travel &other){

    this -> destination = new char[strlen(other.destination) + 1];
    strcpy(this -> destination, other.destination);

    this -> from = other.from;
    this -> to = other.to;

    this -> grade = other.grade;

    this -> comment = new char[strlen(other.comment) + 1];
    strcpy(this -> comment, other.comment);

    this -> photos = new char[strlen(other.photos) + 1];
    strcpy(this -> photos, other.photos);

}

Travel::Travel(): destination(new char[1]), from(Date()), to(Date()), grade(0), comment(new char[1]), photos(new char[1]){}
Travel::Travel(const char *destination, const Date &from, const Date &to, const unsigned char grade, const char *comment, const char *photos){

    if(to > from) throw InvalidFormatException("To date is before from date");
    if(grade < '0' || grade > '5') throw InvalidFormatException("Grade is invalid");
    size_t photosSize = strlen(photos);
    for(size_t i = 0; i < photosSize; i++){

        char temp[DEFAULT_STRING_SIZE];
        memset(temp, '\0', DEFAULT_STRING_SIZE);
        size_t j = 0;
        for(j = 0; j + i < photosSize; j++){

            if(photos[i + j] == ' ') break;
            temp[j] = photos[i + j];

        }

        i += j;

        if(!StringChecker::isPhoto(temp)) throw InvalidFormatException("Photo is invalid");

    }

    this -> destination = new char[strlen(destination) + 1];
    strcpy(this -> destination, destination);

    this -> from = from;
    this -> to = to;

    this -> grade = grade;

    this -> comment = new char[strlen(comment) + 1];
    strcpy(this -> comment, comment);

    this -> photos = new char[strlen(photos) + 1];
    strcpy(this -> photos, photos);

}
Travel::Travel(const Travel &other){ this -> copy(other); }
Travel::~Travel(){ this -> erase(); }

Travel &Travel::operator =(const Travel &other){

    if(this != &other){

        this -> erase();
        this -> copy(other);

    }

    return *this;

}

ostream &operator <<(ostream &os, const Travel &obj){

    os << obj.from << '\n' << obj.to << '\n' << obj.grade << "\nComment\n" << obj.comment << "\nPhotos\n" << obj.photos;
    return os;

}

void Travel::write(ofstream &ofs) const{

    size_t destSize = strlen(this -> destination);
    ofs.write((const char *)&destSize, sizeof(size_t));
    ofs.write(this -> destination, destSize);

    ofs.write((const char *)&this -> from, sizeof(Date));

    ofs.write((const char *)&this -> to, sizeof(Date));
    
    ofs.write((const char *)&this -> grade, sizeof(unsigned char));

    size_t commentSize = strlen(this -> comment);
    ofs.write((const char *)&commentSize, sizeof(size_t));
    ofs.write(this -> comment, commentSize);

    size_t stringSize = strlen(this -> photos);
    ofs.write((const char *)&stringSize, sizeof(size_t));
    ofs.write(this -> photos, stringSize);

}

void Travel::read(ifstream &ifs){

    size_t destSize;
    ifs.read((char *)&destSize, sizeof(size_t));

    this -> destination = new char[destSize + 1];
    ifs.read(this -> destination, destSize);
    this -> destination[destSize] = '\0';

    ifs.read((char *)&this -> from, sizeof(Date));
    ifs.read((char *)&this -> to, sizeof(Date));
    ifs.read((char *)&this -> grade, sizeof(unsigned char));

    size_t commentSize;
    ifs.read((char *)&commentSize, sizeof(size_t));

    this -> comment = new char[commentSize + 1];
    ifs.read(this -> comment, commentSize);
    this -> comment[commentSize] = '\0';

    size_t stringSize;
    ifs.read((char *)&stringSize, sizeof(size_t));
    this -> photos = new char[stringSize + 1];
    ifs.read(this -> photos, stringSize);
    this -> photos[stringSize] = '\0';

}

void Travel::setDestination(const char *destination){

    this -> destination = new char[strlen(destination) + 1];
    strcpy(this -> destination, destination);

}
void Travel::setFromDate(const Date &from){ this -> from = from; }
void Travel::setToDate(const Date &to){ this -> to = to; }
void Travel::setGrade(const unsigned short grade){ this -> grade = grade; }
void Travel::setComment(const char *comment){
    
    this -> comment = new char[strlen(comment) + 1];
    strcpy(this -> comment, comment);

}
void Travel::setPhotos(const char *photos){

    this -> photos = new char[strlen(photos) + 1];
    strcpy(this -> photos, photos);

}

char *Travel::getDestination() const{ return this -> destination; }
Date Travel::getFromDate() const{ return this -> from; }
Date Travel::getToDate() const{ return this -> to; }
unsigned char Travel::getGrade() const{ return this -> grade; }
char *Travel::getComment() const{ return this -> comment; }
char *Travel::getPhotos() const{ return this -> photos; }