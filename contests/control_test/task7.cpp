//
// Created by EGor on 30.03.2021.
//

#include<iostream>
using std::cin;
using std::cout;
using std::endl;

namespace control {

    struct Property {    // Arasaka data
        float x, y;    // coordinates
        long int price_base;    // initial price
        long int price_current;    // current price
        Property *next;
    };
    struct BuildingsCivilian {    // Militech data, temporary data structure
        BuildingsCivilian *next;
        BuildingsCivilian *neighbors[100];
        long int price;        // current price
        float x, y, z;        // coordinates
    };

    void push(Property **root, Property dummy) {
        Property *tmp = new Property;
        *tmp = dummy;
        tmp->next = *root;
        *root = tmp;
    }

    void print(Property *root) {
        while (root) {
            cout << root->x << " " << root->y << " " << root->price_base << " " << root->price_current << endl;
            root = root->next;
        }
    }

    void clean(Property **root) {
        Property *tmp = *root;
        while (*root) {
            *root = (*root)->next;
            delete tmp;
            tmp = *root;
        }
    }

    void push_Militech(BuildingsCivilian **root, BuildingsCivilian dummy) {
        BuildingsCivilian *tmp = new BuildingsCivilian;
        *tmp = dummy;
        tmp->next = *root;
        *root = tmp;
    }

    void clean_Militech(BuildingsCivilian **root) {
        BuildingsCivilian *tmp = *root;
        while (*root) {
            *root = (*root)->next;
            delete tmp;
            tmp = *root;
        }
    }

    Property* get_Arasaka_from_Militech( BuildingsCivilian* militech ){
        if( militech != nullptr ){
            auto arasaka = new Property;
            arasaka->x = militech->x;
            arasaka->y = militech->y;

            arasaka->price_current = militech->price;
            arasaka->price_base = 0;
            return arasaka;
        }
        return nullptr;
    }

    void merge_Militech(Property **root_Arasaka, BuildingsCivilian **root_Militech){
        BuildingsCivilian* index = *root_Militech;
        //stupid solution
        if (index == nullptr){
            clean_Militech(root_Militech);
            return;
        }

        int count = 0;
        while (index != nullptr) {
            count++;
            index = index->next;
        }

        index = *root_Militech;

        auto arr = new BuildingsCivilian*[count];
        int i=0;
        while (index != nullptr) {
            arr[i] = index;
            i++;
            index = index->next;
        }

        for( i=0; i<count; i++) {
            auto temp = get_Arasaka_from_Militech(arr[count-i-1]);
            push(root_Arasaka, *temp);
            delete temp;
        }

        delete []arr;

        clean_Militech(root_Militech);
    }
// Здесь ваша реализация функции

    int task7() {
        unsigned int n = 5;
        Property *assets = nullptr;
        for (int i = 0; i < n; i++)
            push(&assets, {i * 10.5f, i * 3.3f, i * 100 + 10, i * 100 + 50, nullptr});
        BuildingsCivilian *assets_Militech = nullptr;
        for (int i = 0; i < n; i++)
            push_Militech(&assets_Militech, {nullptr, {nullptr}, i * 1000 + 121, i * 10.5f, i * 3.3f, i * 100.0f});

        merge_Militech(&assets, &assets_Militech);
        print(assets);

// Ожидаемый вывод:
// 42 13.2 410 450
// 31.5 9.9 310 350
// 21 6.6 210 250
// 10.5 3.3 110 150
// 0 0 10 50
// 42 13.2 0 4121
// 31.5 9.9 0 3121
// 21 6.6 0 2121
// 10.5 3.3 0 1121
// 0 0 0 121

        clean(&assets);
        return 0;
    }
}