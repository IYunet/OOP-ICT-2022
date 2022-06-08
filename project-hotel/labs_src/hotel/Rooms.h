#pragma once
#include <iostream>
#include <vector>
using std::string;
using std::vector;

class Room_tab {
private:
    int _room_number;
    string _type_room;
    int _price_for_night;
public:
    Room_tab(int& room_number,string& type_room);
    [[nodiscard]] int get_room_number() const;
    string get_type_room();
    [[nodiscard]] int get_price_for_night() const;
};

class Rooms {
private:
    vector<Room_tab> _list_of_room;
public:
    void add_rooms(int room_number, string type_room);
    int get_room_number(int n);
    string get_type_room(int n);
    int get_price_for_night(int n);
    int get_price_for_night_by_room_number(int room_number);
    vector<Room_tab> get_list_of_room();
};



