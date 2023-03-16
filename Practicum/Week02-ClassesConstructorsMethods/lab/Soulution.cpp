#include <iostream>
#include <fstream>
#include <cstring>

constexpr std::size_t BUFFER_SIZE{ 1024 };
constexpr std::size_t COLOR_CAPACITY{ 100 };
constexpr std::size_t CAPACITY{ 1000 };

class Baloon {
public:
    Baloon() {}

    Baloon(const char* color, double price)
        : m_price(price) {
        setColor(color);
    }

    void setColor(const char* color) {
        strcpy(m_color, color);
    }

    const char* getColor() const {
        return m_color;
    }

    void setPrice(double price) {
        m_price = price;
    }

    double getPrice() const {
        return m_price;
    }

    void read(const char* fileName) {
        std::ifstream file(fileName);

        if (!file.good()) {
            std::cout << "Couldn't open the file!" << std::endl;
            
            return;
        }

        char buffer[BUFFER_SIZE];

        file >> buffer;

        setColor(buffer);

        if (!m_color) {
            m_price = 0;

            return;
        }

        file >> m_price;

        file.close();
    }

    void write(const char* fileName) const {
        std::ofstream file(fileName);

        if (!file.good()) {
            std::cout << "Couldn't open the file!" << std::endl;
            
            return;
        }

        file << m_color << ' ' << m_price << std::endl;

        file.close();
    }

    void print() const {
        std::cout << "Baloon with color \"" << m_color << "\" costs " << m_price << std::endl;
    }

private:
    char m_color[COLOR_CAPACITY];
    double m_price{ 0.0 };
};

class Shisha {
public:
    Shisha() {}

    Shisha(const char* brand, const char* taste, double price)
        : m_price(price) {
        setBrand(brand);

        if (!brand) {
            deleteData();

            return;
        }

        setTaste(taste);

        if (!taste) {
            deleteData();

            return;
        }
    }

    ~Shisha() {
        deleteData();
    }

    void setBrand(const char* brand) {
        delete[] m_brand;

        m_brand = new (std::nothrow) char[strlen(brand) + 1];

        if (!m_brand) {
            std::cout << "Memory problem!" << std::endl;

            return;
        }

        strcpy(m_brand, brand);
    }

    const char* getBrand() const {
        return m_brand;
    }

    void setTaste(const char* taste) {
        delete[] m_taste;

        m_taste = new (std::nothrow) char[strlen(taste) + 1];

        if (!m_taste) {
            std::cout << "Memory problem!" << std::endl;

            return;
        }

        strcpy(m_taste, taste);
    }

    const char* getTaste() const {
        return m_taste;
    }

    void setPrice(double price) {
        m_price = price;
    }

    double getPrice() const {
        return m_price;
    }

    void read(const char* fileName) {
        std::ifstream file(fileName);

        if (!file.good()) {
            std::cout << "Couldn't open the file!" << std::endl;

            return;
        }

        char buffer[BUFFER_SIZE];

        file.getline(buffer, BUFFER_SIZE);

        setBrand(buffer);

        if (!m_brand) {
            std::cout << "Memory problem!" << std::endl;
            
            deleteData();

            return;
        }

        file.getline(buffer, BUFFER_SIZE);

        setTaste(buffer);

        if (!m_taste) {
            std::cout << "Memory problem!" << std::endl;

            deleteData();

            return;
        }

        file >> m_price;

        file.close();
    }

    void write(const char* fileName) const {
        std::ofstream file(fileName);

        if (!file.good()) {
            std::cout << "Couldn't open the file!" << std::endl;
            
            return;
        }

        file << m_brand << std::endl << m_taste << std::endl << m_price << std::endl;

        file.close();
    }

    void print() const {
        std::cout << "Shisha from \"" << m_brand << "\" with a taste \"" << m_taste << "\" costs " << m_price << std::endl;
    }

    void deleteData() {
        delete[] m_brand;
        m_brand = nullptr;

        delete[] m_taste;
        m_taste = nullptr;

        m_price = 0;
    }

private:
    char* m_brand{ nullptr };
    char* m_taste{ nullptr };
    double m_price{ 0.0 };
};

class Alcohol {
public:
    Alcohol() {}

    Alcohol(const char* name, double price)
        : m_price(price) {
        setName(name);

        if (!name) {
            m_price = 0;

            return;
        }
    }

    ~Alcohol() {
        deleteData();
    }

    void setName(const char* name) {
        delete[] m_name;

        m_name = new (std::nothrow) char[strlen(name) + 1];

        if (!m_name) {
            std::cout << "Memory problem!" << std::endl;

            return;
        }

        strcpy(m_name, name);
    }

    const char* getName() const {
        return m_name;
    }

    void setPrice(double price) {
        m_price = price;
    }

    double getPrice() const {
        return m_price;
    }

    void read(const char* fileName) {
        std::ifstream file(fileName);

        if (!file.good()) {
            std::cout << "Couldn't open the file" << std::endl;

            return;
        }

        char buffer[BUFFER_SIZE];

        file.getline(buffer, BUFFER_SIZE);

        setName(buffer);

        if (!m_name) {
            std::cout << "Memory problem!" << std::endl;

            deleteData();
            
            return;
        }

        file >> m_price;

        file.close();
    }

    void write(const char* fileName) const {
        std::ofstream file(fileName);

        if (!file.good()) {
            std::cout << "Couldn't open the file!" << std::endl;
            
            return;
        }

        file << m_name << std::endl << m_price << std::endl;

        file.close();
    }

    void print() const {
        std::cout << m_name << " costs " << m_price << std::endl;
    }

    void deleteData() {
        delete[] m_name;
        m_name = nullptr;

        m_price = 0;
    }

private:
    char* m_name{ nullptr };
    double m_price{ 0.0 };
};

class NightClub {
public:
    NightClub() {}

    void addABaloon(const char* color, double price) {
        if (n_baloonsSize == CAPACITY) {
            std::cout << "No space for more baloons" << std::endl;
            
            return;
        }

        m_baloons[n_baloonsSize].setColor(color);
        m_baloons[n_baloonsSize].setPrice(price);

        ++n_baloonsSize;
    }

    void addShisha(const char* brand, const char* taste, double price) {
        if (n_baloonsSize == CAPACITY) {
            std::cout << "No space for more shishas" << std::endl;
            
            return;
        }
        
        m_shishas[n_shishasSize].setBrand(brand);
        m_shishas[n_shishasSize].setTaste(taste);
        m_shishas[n_shishasSize].setPrice(price);

        ++n_shishasSize;
    }

    void addAlcohol(const char* name, double price) {
        if (n_baloonsSize == CAPACITY) {
            std::cout << "No space for more alcohol drinks" << std::endl;
            
            return;
        }
        
        m_alcohols[n_alcoholsSize].setName(name);
        m_alcohols[n_alcoholsSize].setPrice(price);

        ++n_alcoholsSize;
    }

    void removeBaloon(const char* color) {
        for (std::size_t index{ 0 }; index < n_baloonsSize; ++index) {
            if (strcmp(m_baloons[index].getColor(), color) == 0) {
                --n_baloonsSize;
                
                if (n_baloonsSize != 0) {
                    m_baloons[index].setColor(m_baloons[n_baloonsSize].getColor());
                    m_baloons[index].setPrice(m_baloons[n_baloonsSize].getPrice());
                }

                return;
            }
        }
    }

    void removeShisha(const char* brand) {
        for (std::size_t index{ 0 }; index < n_shishasSize; ++index) {
            if (strcmp(m_shishas[index].getBrand(), brand) == 0) {
                --n_shishasSize;

                if (n_shishasSize != 0) {
                    m_shishas[index].setBrand(m_shishas[n_shishasSize].getBrand());
                    m_shishas[index].setTaste(m_shishas[n_shishasSize].getTaste());
                    m_shishas[index].setPrice(m_shishas[n_shishasSize].getPrice());
                }

                m_shishas[n_shishasSize].deleteData();

                return;
            }
        }
    }

    void removeAlcohol(const char* name) {
        for (std::size_t index{ 0 }; index < n_alcoholsSize; ++index) {
            if (strcmp(m_alcohols[index].getName(), name) == 0) {
                --n_alcoholsSize;

                if (n_alcoholsSize != 0) {
                    m_alcohols[index].setName(m_alcohols[n_alcoholsSize].getName());
                    m_alcohols[index].setPrice(m_alcohols[n_alcoholsSize].getPrice());
                }

                m_alcohols[n_alcoholsSize].deleteData();

                return;
            }
        }
    }

    bool checkForBaloonsCheaperThan(double price) {
        for (std::size_t index{ 0 }; index < n_baloonsSize; ++index) {
            if (m_baloons[index].getPrice() < price) {
                return true;
            }
        }
        
        return false;
    }

    bool checkForShishaWithTaste(const char* taste) {
        for (std::size_t index{ 0 }; index < n_shishasSize; ++index) {
            if (strcmp(m_shishas[index].getTaste(), taste) == 0) {
                return true;
            }
        }

        return false;
    }

    bool checkForAlcoholWithPriceBetween(double min, double max) {
        for (std::size_t index{ 0 }; index < n_alcoholsSize; ++index) {
            const double PRICE{ m_alcohols[index].getPrice() };

            if (min <= PRICE && PRICE <= max) {
                return true;
            }
        }

        return false;
    }

    void print() const {
        std::cout << "Baloons:" << std::endl;

        for (std::size_t index{ 0 }; index < n_baloonsSize; ++index) {
            m_baloons[index].print();
        }

        std::cout << std::endl << "Shishas:" << std::endl;

        for (std::size_t index{ 0 }; index < n_shishasSize; ++index) {
            m_shishas[index].print();
        }

        std::cout << std::endl << "Alcohol drinks:" << std::endl;

        for (std::size_t index{ 0 }; index < n_alcoholsSize; ++index) {
            m_alcohols[index].print();
        }

        std::cout << std::endl;
    }

private:
    Baloon m_baloons[CAPACITY]{};
    Shisha m_shishas[CAPACITY]{};
    Alcohol m_alcohols[CAPACITY]{};

    std::size_t n_baloonsSize{ 0 };
    std::size_t n_shishasSize{ 0 };
    std::size_t n_alcoholsSize{ 0 };
};

int main() {
    NightClub club;

    club.addABaloon("Purple", 15);
    club.addABaloon("Blue", 10);
    club.addABaloon("Green", 7);
    club.addABaloon("Red", 5);

    club.addShisha("Tangers", "Chocolate Ice Cream", 26);
    club.addShisha("Dark Side", "Grape", 20);
    club.addShisha("Ososuma", "Peach", 14);

    club.addAlcohol("Jack Daniels", 40);
    club.addAlcohol("Red Johnny Walker", 35);
    club.addAlcohol("Jim Beam", 30);
    club.addAlcohol("Absolute", 25);

    club.print();

    club.removeBaloon("Red");
    club.removeShisha("Ososuma");
    club.removeAlcohol("Red Johnny Walker");

    club.print();

    std::cout << std::boolalpha << club.checkForBaloonsCheaperThan(7.5) << std::endl;
    std::cout << club.checkForShishaWithTaste("Monster") << std::endl;
    std::cout << club.checkForAlcoholWithPriceBetween(10, 15) << std::endl;

    return 0;
}