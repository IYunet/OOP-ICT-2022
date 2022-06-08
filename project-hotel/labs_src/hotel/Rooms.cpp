#include "Rooms.h"

Room_tab::Room_tab(int &room_number, string& type_room) {
    _room_number = room_number;
    _type_room = type_room;
    if (type_room == "one"){
        _price_for_night = 1500;
    } else {
        _price_for_night = 3500;
    }
}

int Room_tab::get_room_number() const {
    return _room_number;
}

string Room_tab::get_type_room() {
    return _type_room;
}

int Room_tab::get_price_for_night() const {
    return _price_for_night;
}

void Rooms::add_rooms(int room_number, string type_room) {
    Room_tab temp_room(room_number, type_room);
    _list_of_room.push_back(temp_room);
}

int Rooms::get_room_number(int n) {
    if( _list_of_room[n].get_room_number() != 0) {return _list_of_room[n].get_room_number();}
    else{throw std::invalid_argument( "this room doesn't exist" );}
}

string Rooms::get_type_room(int n) {
    if( _list_of_room[n].get_room_number() != 0) {return _list_of_room[n].get_type_room();}
    else{throw std::invalid_argument( "this room doesn't exist" );}
}

vector<Room_tab> Rooms::get_list_of_room() {
    return _list_of_room;
}

int Rooms::get_price_for_night(int n) {
    if( _list_of_room[n].get_room_number() != 0) {return _list_of_room[n].get_price_for_night();}
    else{throw std::invalid_argument( "this room doesn't exist" );}
}

int Rooms::get_price_for_night_by_room_number(int room_number) {
    for (auto &i: _list_of_room) {
        if (i.get_room_number() == room_number) {
            return i.get_price_for_night();
        }
    }
    throw std::invalid_argument("this room doesn't exist");
}
