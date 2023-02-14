#include "Context.hpp"

void Context::getUsersFromDB(Vector <User> &users){

    ifstream ifs("Database/users.db", ios::binary);

    while(ifs.peek() != EOF){

        User temp;
        temp.read(ifs);
        users.pushBack(temp);

    }

    ifs.close();

}

void Context::save(const Vector<User> &users){

    ofstream ofs("Database/users.db", ios::binary | ios::trunc);
    for(size_t i = 0; i < users.size(); i++)
        users[i].write(ofs);
    ofs.close();

}