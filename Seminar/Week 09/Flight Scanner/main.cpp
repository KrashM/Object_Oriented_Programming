#include "FlightScanner.hpp"

int main(){

	FlightScanner scanner("inputFlights.txt", "outputFlights.txt", 10);
	scanner.run();

}