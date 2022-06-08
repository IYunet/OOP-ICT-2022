#pragma once
#include <iostream>
#include <vector>


using std::string;
using std::vector;

class Client_tab{
private:
    int _id_passport;
    string _full_name_client;
    string _email;
    string _phone_client;
public:
    Client_tab(int &id_passport, string &full_name_client, string &email, string &phone_client);
    Client_tab();
    [[nodiscard]] int get_id_passport() const; //функции для получения информации о клиенте
    [[nodiscard]] string get_full_name_client() const;
    [[nodiscard]] string get_email() const;
    [[nodiscard]] string get_phone_client() const;
    Client_tab& operator=(const Client_tab &client);
};

class Clients {
private:
    vector<Client_tab> _list_of_clients;
public:
    void add_clients(int id_passport, string full_name_client, string email, string phone_client);
    Client_tab get_client_by_passport(int n);
    //неиспользуемые функции в лабе, но по логике они нужны
    int get_id_passport(int n);
    string get_full_name_client(int n);
    string get_email(int n);
    string get_phone_client(int n);
    vector<Client_tab> get_list_of_clients();
};
