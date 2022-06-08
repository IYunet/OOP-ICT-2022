#include <gtest/gtest.h>

#include "hotel/Workers.h"
#include "hotel/Rooms.h"
#include "hotel/Clients.h"
#include "hotel/Book.h"
using namespace std;
#include <cstdlib>

TEST(CreateHotel, AllChecks) {
    Workers workers; // бд работников
    workers.add_workers(111,"Sveta Kulagina","+78708909776");
    workers.add_workers(222,"Natasha Rostova","+78708909777");
    workers.add_workers(333,"Stive Job","+78706909778");
    Rooms rooms; // бд комнат
    rooms.add_rooms(20,"one");
    rooms.add_rooms(70,"two");
    rooms.add_rooms(45, "one");
    rooms.add_rooms(15, "two");
    Clients spisok_clients; // бд клиентов
    spisok_clients.add_clients(3345678, "Ivan Kozlov", "123@mail.ru", "+78708909775");
    spisok_clients.add_clients(3345679, "Maria Markina", "test@mail.ru", "+7870890925");
    spisok_clients.add_clients(3345680, "Daria Baldina", "flop@mail.ru", "+78708909779");
    spisok_clients.add_clients(3345681, "Dania Kazantsev", "fu@mail.ru", "+7870890922");

    Book book;
    book.add_contract(1,2,10000,workers, rooms, spisok_clients.get_client_by_passport(3345678),"one", book);
    ASSERT_EQ(book.get_all_contracts()[0].get_contract_id_of_client(), 1); // проверка заселения в одноместный
    book.add_contract(1,2,20000,workers, rooms, spisok_clients.get_client_by_passport(3345681),"one", book);
    ASSERT_EQ(book.get_all_contracts()[1].get_contract_id_of_client(), 2); // проверка заселения в одноместный на те же даты и в тот же тип номера
    ASSERT_ANY_THROW(book.add_contract(1,2,2345,workers, rooms, spisok_clients.get_client_by_passport(3345681),"one", book)); // проверка, что нет свободного номера
    ASSERT_ANY_THROW(book.add_contract(1,10,20,workers, rooms, spisok_clients.get_client_by_passport(3345681),"two", book)); // проверка, что недостаточно денег для оплаты
    book.add_contract(3,8,234445,workers, rooms, spisok_clients.get_client_by_passport(3345679),"two", book);
    book.add_contract(5,10,2344445,workers, rooms, spisok_clients.get_client_by_passport(3345680),"two", book);
    ASSERT_EQ(book.get_all_contracts()[2].get_contract_id_of_client(), 3); // проверка заселения в двухместный
    ASSERT_EQ(book.get_all_contracts()[3].get_contract_id_of_client(), 4); // проверка заселения в двухместный на те же даты и в тот же тип номера
}


