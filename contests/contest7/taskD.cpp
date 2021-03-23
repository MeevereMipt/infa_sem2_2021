//
// Created by EGor on 23.03.2021.
//

#include <iostream>
#include "my_array.h"

namespace contest7{

#define KNIGHT 1;
#define LIAR 0;

    struct Entry{
        std::string name;
        bool type;

        std::istream & operator >> (std::istream &in,  Entry& ent);
        std::ostream & operator << (std::ostream &out, const Entry& ent);
    };

    std::istream &Entry::operator>>(std::istream &in, Entry &ent) {
        in >> name >> type;
        return in;
    }

    std::ostream &Entry::operator<<(std::ostream &out, const Entry &ent) {
        out << name << ' ' << int(type);
        return out;
    }

    int taskD(){
        int n; bool news;
        std::cin >> n >> news;

        Array<Entry> people(n);
        std::cin >> people;

        int days;
        std::cin >> days;

        return 0;
    }
}
