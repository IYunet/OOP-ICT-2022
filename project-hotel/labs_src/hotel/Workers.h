#pragma once
#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Worker_tab{
private:
    int _id_worker;
    string _full_name_worker;
    string _phone_worker;
public:
    Worker_tab(int id, string full_name_worker, string phone_worker);
    [[nodiscard]] int get_id_worker() const;
    string get_full_name_worker();
    string get_phone_worker();
};

class Workers{
private:
    vector<Worker_tab> _list_of_worker;
public:
    void add_workers(int id, string full_name_worker, string phone_worker);
    int get_id_worker(int n);
    int get_number_of_workers();
    //неиспользуемые функции в лабе, но по логике они нужны
    string get_full_name_worker(int n);
    string get_phone_worker(int n);
    vector<Worker_tab> get_list_of_worker();
};