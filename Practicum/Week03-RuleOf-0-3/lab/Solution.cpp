#include <iostream>
#include <cstring>

struct Duration {
    unsigned m_minutes{ 0 };
    unsigned m_seconds{ 0 };
};

class Song {
public:
    Song() : Song("", Duration{}, "") {}

    Song(const char* name, Duration duration, const char* gerne)
        : m_duration(duration) {
        parmsConstructor(name, gerne);
    }

    Song(const char* name, unsigned minutes, unsigned seconds, const char* gerne)
        : m_duration(Duration{ minutes, seconds }) {
        parmsConstructor(name, gerne);
    }

    Song(const Song& other) {
        copyDataFrom(other);
    }
    
    ~Song() {
        deleteData();
    }

    void setName(const char* name) {
        delete[] m_name;
        m_name = new (std::nothrow) char[strlen(name) + 1];

        if (!m_name) {
            std::cout << "Memory problem in setName" << std::endl;

            return;
        }

        strcpy(m_name, name);
    }

    const char* getName() const {
        return m_name;
    }

    void setDuration(const Duration& duration) {
        m_duration = duration;
    }

    void setDuration(unsigned minutes, unsigned seconds) {
        m_duration = Duration{ minutes, seconds };
    }
    
    Duration getDuration() const {
        return m_duration;
    }

    void setGerne(const char* gerne) {
        delete[] m_gerne;
        m_gerne = new (std::nothrow) char[strlen(gerne) + 1];

        if (!m_gerne) {
            std::cout << "Memory problem in setGerne" << std::endl;

            return;
        }

        strcpy(m_gerne, gerne);
    }

    const char* getGerne() const {
        return m_gerne;
    }

    Song& operator=(const Song& other) {
        if (this != &other) {
            deleteData();
            copyDataFrom(other);
        }

        return *this;
    }

private:
    void deleteData() {
        delete[] m_name;
        m_name = nullptr;

        delete[] m_gerne;
        m_gerne = nullptr;
    }

    void copyDataFrom(const Song& other) {
        setName(other.m_name);
        setDuration(other.m_duration);
        setGerne(other.m_gerne);
    }

    void parmsConstructor(const char* name, const char* gerne) {
        setName(name);

        if (!m_name) {
            m_duration = Duration{};

            std::cout << "Memory problem in params constructor" << std::endl;

            return;
        }

        setGerne(gerne);

        if (!m_gerne) {
            deleteData();
            m_duration = Duration{};

            std::cout << "Memory problem in params constructor" << std::endl;

            return;
        }
    }

private:
    char* m_name{ nullptr };
    Duration m_duration{};
    char* m_gerne{ nullptr };
};

constexpr std::size_t PLAYLIST_SONGS_INITIAL_CAPACITY{ 2 };
constexpr std::size_t PLAYLIST_SONGS_CAPACITY_MULTIPLIER{ 2 };

class Playlist {
public:
    Playlist() : Playlist("") {}

    Playlist(const char* name) {
        // allocateMemory
        setName(name);

        if (!m_name) {
            std::cout << "Memory problem in params constructor" << std::endl;
        }
    }

    Playlist(const Playlist& other) {
        copyDataFrom(other);
    }
    
    ~Playlist() {
        deleteData();
    }

    void setName(const char* name) {
        delete[] m_name;
        m_name = new (std::nothrow) char[strlen(name) + 1];

        if (!m_name) {
            std::cout << "Memory problem in setName" << std::endl;

            return;
        }
    }

    const char* getName() const {
        return m_name;
    }

    int getSongIndex(const char* songName) const {
        for (std::size_t index{ 0 }; index < nSize; ++index) {
            if (strcmp(m_songs[index].getName(), songName) == 0) {
                return index;
            }
        }

        return -1;
    }

    void addSong(const Song& songToAdd) {
        if (nSize >= nCapacity) {
            allocateMemory(nCapacity * PLAYLIST_SONGS_CAPACITY_MULTIPLIER);
        }

        m_songs[nSize++] = songToAdd;
    }

    bool removeSong(const char* songName) {
        for (std::size_t index{ 0 }; index < nSize; ++index) {
            if (strcmp(m_songs[index].getName(), songName) == 0) {
                m_songs[index] = m_songs[--nSize];
                
                return true;
            }
        }
        
        return false;
    }

    Playlist& operator=(const Playlist& other) {
        if (this != &other) {
            deleteData();
            copyDataFrom(other);
        }

        return *this;
    }

private:
    void deleteData() {
        delete[] m_name;
        m_name = nullptr;

        delete[] m_songs;
        m_songs = nullptr;
    }

    void copyDataFrom(const Playlist& other) {
        setName(other.m_name);

        if (!m_name) {
            std::cout << "Memory problem in copyDataFrom" << std::endl;
            
            return;
        }

        m_songs = new (std::nothrow) Song[other.nCapacity];

        if (!m_songs) {
            deleteData();

            std::cout << "Memory problem in copyDataFrom" << std::endl;
            
            return;
        }

        for (std::size_t index{ 0 }; index < other.nSize; ++index) {
            m_songs[index] = other.m_songs[index];
        }

        nSize = other.nSize;
        nCapacity = other.nCapacity;
    }

    void allocateMemory(std::size_t newCapacity) {
        if (newCapacity <= nSize) {
            newCapacity = nCapacity * PLAYLIST_SONGS_CAPACITY_MULTIPLIER;
        }

        Song* blockOfMem{ new (std::nothrow) Song[newCapacity] };

        if (!blockOfMem) {
            std::cout << "Memory problem in allocateMemory" << std::endl;
            
            return;
        }

        for (std::size_t index{ 0 }; index < nSize; ++index) {
            blockOfMem[index] = m_songs[index];
        }

        delete[] m_songs;
        m_songs = blockOfMem;

        nCapacity = newCapacity;
    }

private:
    char* m_name{ nullptr };

    Song* m_songs{ nullptr };
    std::size_t nSize{ 0 };
    std::size_t nCapacity{ 0 };
};

int main() {

    return 0;
}
