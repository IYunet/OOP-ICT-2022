#include "Workers.h"

#include <utility>

Worker_tab::Worker_tab(int id, string full_name_worker, string phone_worker) {
    _id_worker = id;
    _full_name_worker = std::move(full_name_worker);
    _phone_worker = std::move(phone_worker);
}

int Worker_tab::get_id_worker() const {
    return _id_worker;
}

string Worker_tab::get_full_name_worker() {
    return _full_name_worker;
}

string Worker_tab::get_phone_worker() {
    return _phone_worker;
}

void Workers::add_workers(int id, string full_name_worker, string phone_worker) {
    Worker_tab employee(id, std::move(full_name_worker), std::move(phone_worker));
    _list_of_worker.push_back(employee);
}

int Workers::get_id_worker(int n) {
    if( _list_of_worker[n].get_id_worker() != 0) {return _list_of_worker[n].get_id_worker();}
    else{throw std::invalid_argument( "this worker doesn't exist" );}
}

string Workers::get_full_name_worker(int n) {
    if( _list_of_worker[n].get_id_worker() != 0) {return _list_of_worker[n].get_full_name_worker();}
    else{throw std::invalid_argument( "this worker doesn't exist" );}
}

string Workers::get_phone_worker(int n) {
    if( _list_of_worker[n].get_id_worker() != 0) {return _list_of_worker[n].get_phone_worker();}
    else{throw std::invalid_argument( "this worker doesn't exist" );}
}

vector<Worker_tab> Workers::get_list_of_worker() {
    return _list_of_worker;
}

int Workers::get_number_of_workers() {
    return int(_list_of_worker.size());
}


