#pragma once
#include <iostream>
#include <vector>
#include "Clients.h"
#include "Workers.h"
#include "Rooms.h"
#include <unistd.h>

using std::string;
using std::vector;


class Book_tab {
private:
    int _current_id_contract;
    int _start_date_living;
    int _end_date_living;//дни отсчитываются от 1 января 2020 года(т.е 822 день = 1 января + 822)
    int _payment; //необходимо для проверки оплаты
    int _id_worker;
    int _room_number;
    Client_tab _current_client;
public:
    Book_tab(int& id_contract, int &start_date_living, int &end_date_living, int &payment,
             Workers &list_of_workers,Rooms &rooms, Client_tab &current_client, int& room_number);
    void add_room_number(int n);
    [[nodiscard]] int get_contract_id_of_client() const;
    [[nodiscard]] int get_worker_id() const;
    [[nodiscard]] int get_start_date() const;
    [[nodiscard]] int get_end_date() const;
    [[nodiscard]] int get_room_number() const;
};


class Book {
private:
    vector <Book_tab> _all_contracts;
public:
    void add_contract(int start_date_living, int end_date_living, int payment,
                      Workers list_of_workers, Rooms rooms,
                      Client_tab current_client, const string& type_room, Book &current_book);
    vector <Book_tab> get_all_contracts();
    int get_numbers_of_all_contracts();
    int get_contract_of_client(int n);
    int get_worker_id(int n);
    int get_start_date(int n);
    int get_end_date(int n);
};


class Check_rooms {
private:
    int _number_free_room = 0;
public:
    Check_rooms(Rooms& room, int date_start, int date_end, const string& type_room, Book &current_book);
    [[nodiscard]] int get_number_free_room() const;
};

class Check_payment {
private:
    int _number_of_days_living;
    int _price;
    bool _status_of_payment;
public:
    Check_payment(int& start_date_living, int& end_date_living, Rooms& room, int& current_check, int& payment);
    [[nodiscard]] bool get_status_payment() const;
};
