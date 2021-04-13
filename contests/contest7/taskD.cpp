//
// Created by EGor on 23.03.2021.
//

#include <iostream>
#include "containers/array.h"

using containers::array::Array;

namespace contest7{

#define KNIGHT 1;
#define LIAR 0;

    struct Entry{
        std::string name;
        bool type;

        friend std::istream & operator >> (std::istream &in,  Entry& ent);
        friend std::ostream & operator << (std::ostream &out, const Entry& ent);
    };

    std::istream &operator>>(std::istream &in, Entry &ent) {
        in >> ent.name >> ent.type;
        return in;
    }

    std::ostream &operator<<(std::ostream &out, const Entry &ent) {
        out << ent.name << ' ' << int(ent.type);
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
