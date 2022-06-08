#include "Clients.h"

Client_tab::Client_tab(int &id_passport, string &full_name_client, string &email, string &phone_client) {
    _id_passport = id_passport;
    _full_name_client = full_name_client;
    _email = email;
    _phone_client = phone_client;
}

int Client_tab::get_id_passport() const {
    return _id_passport;
}

string Client_tab::get_full_name_client() const {
    return _full_name_client;
}

string Client_tab::get_email() const {
    return _email;
}

string Client_tab::get_phone_client() const {
    return _phone_client;
}

Client_tab &Client_tab::operator=(const Client_tab &client) {
    _id_passport = client.get_id_passport();
    _full_name_client = client.get_full_name_client();
    _email = client.get_email();
    _phone_client = client.get_phone_client();
    return *this;
}

Client_tab::Client_tab() {
    _id_passport = 0;
    _full_name_client = "temp";
    _email = "temp";
    _phone_client = "temp";
}


void Clients::add_clients(int id_passport, string full_name_client, string email, string phone_client) {
    Client_tab temp_client(id_passport, full_name_client, email, phone_client);
    _list_of_clients.push_back(temp_client);
}

int Clients::get_id_passport(int n) {
    if( _list_of_clients[n].get_id_passport() != 0) {return _list_of_clients[n].get_id_passport();}
    else{throw std::invalid_argument( "this client doesn't exist" );}
}

string Clients::get_full_name_client(int n) {
    if( _list_of_clients[n].get_id_passport() != 0) {return _list_of_clients[n].get_full_name_client();}
    else{throw std::invalid_argument( "this client doesn't exist" );}
}

string Clients::get_email(int n) {
    if( _list_of_clients[n].get_id_passport() != 0) {return _list_of_clients[n].get_email();}
    else{throw std::invalid_argument( "this client doesn't exist" );}
}

string Clients::get_phone_client(int n) {
    if( _list_of_clients[n].get_id_passport() != 0) {return _list_of_clients[n].get_phone_client();}
    else{throw std::invalid_argument( "this client doesn't exist" );}
}

vector<Client_tab> Clients::get_list_of_clients() {
    return _list_of_clients;
}

Client_tab Clients::get_client_by_passport(int n) {
    for(auto & _list_of_client : _list_of_clients){
        if (_list_of_client.get_id_passport() == n){
            return _list_of_client;
        }
    }
    throw std::invalid_argument( "this client doesn't exist");
}


