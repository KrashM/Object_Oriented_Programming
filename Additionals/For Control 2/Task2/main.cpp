#include "System.hpp"

int main(){

    System s;
    s.register_user("Hristo", "hrt@mail.com", "I love OOP");

    Product shirt("Shirt", 10.50, Product::Size::L);
    Product pants("Pants", 40.99, Product::Size::XL);

    User *me = s.log_in_user("Hristo", "I love OOP");

    if(!me)
        std::cout << "This user does not exist\n";
    else{

        me -> add_product(shirt);
        me -> add_product(pants);

        me -> print();

    }

}