#include "ComplexNumber.hpp"

ComplexNumber::ComplexNumber(): real(0), im(0){}

ComplexNumber::ComplexNumber(double real, double im): real(real), im(im){}

ComplexNumber &ComplexNumber::operator +=(ComplexNumber const &other){

	real += other.real;
	im += other.im;

	return *this;

}
ComplexNumber &ComplexNumber::operator -=(ComplexNumber const &other){

	real -= other.real;
	im -= other.im;

	return *this;

}
ComplexNumber &ComplexNumber::operator *=(ComplexNumber const &other){

    double oldReal = real;
	real = real * other.real - im * other.im;
	im = oldReal * other.im + im * other.real;

	return *this;

}
ComplexNumber &ComplexNumber::operator /=(ComplexNumber const &other){

    //взимаме комплексно спрегнатата на другата дроб (b)
    ComplexNumber conjugated = other.getConjugated();

    // копираме другата (b), за да не я промяняме.
	ComplexNumber otherCopy(other);

	//Умножаваме двете по комплексно спрегнатата.
	*this *= conjugated;
    //Тук трябва да остане само реална част.
	otherCopy *= conjugated;

	if (otherCopy.real != 0){

		real /= otherCopy.real;
		im /= otherCopy.real;

	}

	return *this;

}

//След дефинирането на +=, -=, *= и /=, можем лесно да дефинираме +, -, * и /, преизползвайки вече написаните опратори.
ComplexNumber operator +(ComplexNumber const &lhs, ComplexNumber const &rhs){

    // Създаваме нов обект, който е копие на a (използваме копи-конструктора)
	ComplexNumber result(lhs);
    // Kъм копието на a, добавяме b (Използваме вече дефинирания оператор +=)
	result += rhs;

	return result;

}

//Операторите -, *, / са аналогични с +. 
ComplexNumber operator -(ComplexNumber const &lhs, ComplexNumber const &rhs){
	
    ComplexNumber result(lhs);
	result -= rhs;

	return result;

}

ComplexNumber operator *(ComplexNumber const &lhs, ComplexNumber const &rhs){

	ComplexNumber result(lhs);
	result *= rhs;

	return result;

}

ComplexNumber operator /(ComplexNumber const &lhs, ComplexNumber const &rhs){

	ComplexNumber result(lhs);
	result /= rhs;

	return result;

}

ComplexNumber ComplexNumber::getConjugated() const{

	ComplexNumber result(*this);
	result.im *= -1;

	return result;

}

// за да можем да правим  cout<<c1 или да запазваме във файл и др. 
ostream &operator <<(ostream &ofs, ComplexNumber const &r) {
	return ofs << r.real << ' ' << r.im << 'i';
}

// за да можем да правим cin>>c1 или да четем от файл и др. 
istream &operator >>(istream &ifs, ComplexNumber &r) {
	return ifs >> r.real >> r.im;
}
