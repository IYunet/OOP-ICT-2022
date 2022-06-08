#include "Book.h"

#include <utility>
#include <cstdlib>
#include <ctime>


Book_tab::Book_tab(int& id_contract, int &start_date_living, int &end_date_living, int &payment,
                   Workers& list_of_workers, Rooms &rooms, Client_tab &current_client, int& room_number) {
     srand(time(nullptr));
     sleep(3);
    _current_id_contract = id_contract + 1;
    _start_date_living = start_date_living;
    _end_date_living = end_date_living;
    _payment = payment;
    _current_client = current_client;
    _room_number = room_number;
    _id_worker = list_of_workers.get_id_worker(rand()%int(list_of_workers.get_number_of_workers()));//случайным образом выбираем работника
}


int Book_tab::get_contract_id_of_client() const {
    return  _current_id_contract;
}

int Book_tab::get_worker_id() const {
    return _id_worker;
}

int Book_tab::get_start_date() const {
    return _start_date_living;
}

int Book_tab::get_end_date() const {
    return _end_date_living;
}

int Book_tab::get_room_number() const{
    return _room_number;
}

void Book_tab::add_room_number(int n) {
    _room_number = n;
}

vector<Book_tab> Book::get_all_contracts() {
    return _all_contracts;
}

int Book::get_numbers_of_all_contracts() {
    return int(_all_contracts.size());
}

void Book::add_contract(int start_date_living, int end_date_living, int payment,
                        Workers list_of_workers, Rooms rooms,
                        Client_tab current_client, const string& type_room, Book &current_book) {
    // проверка свободна ли комната и отдает какая свбодная свободна и какой тип
    Check_rooms find_free_room(rooms, start_date_living, end_date_living, type_room, current_book);
    if(find_free_room.get_number_free_room() == 0){
        throw std::invalid_argument( "haven't got free room for this date" );
    }
    //проверка оплаты проживания
    int free_room = find_free_room.get_number_free_room();
    Check_payment check_payment(start_date_living, end_date_living, rooms, free_room, payment);
    if(!(check_payment.get_status_payment())){
        throw std::invalid_argument( "haven't got enough money" );
    }

    int size = int(_all_contracts.size());
    int room_number = find_free_room.get_number_free_room();
    Book_tab temp_book(size,start_date_living,end_date_living, payment, list_of_workers,
                       rooms, current_client,room_number);
    _all_contracts.push_back(temp_book);
}

int Book::get_contract_of_client(int n) {
    if( _all_contracts[n].get_contract_id_of_client() != 0) {return _all_contracts[n].get_contract_id_of_client();}
    else{throw std::invalid_argument( "this contract doesn't exist" );}
}

int Book::get_worker_id(int n) {
    return _all_contracts[n].get_worker_id();
}

int Book::get_start_date(int n) {
    return _all_contracts[n].get_start_date();
}

int Book::get_end_date(int n) {
    return _all_contracts[n].get_end_date();
}


Check_rooms::Check_rooms(Rooms &room, int date_start, int date_end, const string &type_room, Book &current_book) {
    if (int(current_book.get_all_contracts().size()) == 0) {
        _number_free_room = room.get_list_of_room()[0].get_room_number();
    }
    vector<int> busy_rooms_number; // составить список занятых комнат, потом при проверки исключить все занятые комнаты,
    // а подходящие по типу номера комнта присвоить новому постояльцу

    for (int i = 0; i < int(current_book.get_all_contracts().size()); i++) {

        if (current_book.get_all_contracts()[i].get_end_date() >= date_start) {
            busy_rooms_number.push_back(current_book.get_all_contracts()[i].get_room_number());
        }
    }

    vector<int> all_rooms_number;
    for(int i = 0; i < int(room.get_list_of_room().size()); i++){
        all_rooms_number.push_back(room.get_list_of_room()[i].get_room_number());
    }
    for (int i=0; i<int(all_rooms_number.size()); i++){
        for(int j : busy_rooms_number){
            if(all_rooms_number[i] == j){
                all_rooms_number.erase(all_rooms_number.begin() + i); // все свободные комнаты
            }
        }
    }

    for(int i=0; i<int(room.get_list_of_room().size()); i++){
        for (int j : all_rooms_number){
            if(room.get_list_of_room()[i].get_room_number() == j &&
                    room.get_list_of_room()[i].get_type_room() == type_room){
                _number_free_room = room.get_list_of_room()[i].get_room_number();
            }
        }

    }

}

int Check_rooms::get_number_free_room() const {
    return _number_free_room;
}

Check_payment::Check_payment(int& start_date_living, int& end_date_living, Rooms& room, int& current_room, int& payment) {
    _number_of_days_living = end_date_living - start_date_living;
    _price = room.get_price_for_night_by_room_number(current_room)* _number_of_days_living;
    if (payment >= _price) {
        _status_of_payment = true;
    } else {
        _status_of_payment = false;
    }
}

bool Check_payment::get_status_payment() const {
    return _status_of_payment;
}