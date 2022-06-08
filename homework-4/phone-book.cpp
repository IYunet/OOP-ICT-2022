#include "phone-book.h"
bool phone_book_t::create_user(const std::string &number, const std::string &name) {
  size_before = unique_number.size();
  unique_number.insert(number);
  size_after = unique_number.size();
  if (size_before == size_after){
    return false;
  }
  else{
    names.push_back(name);
    numbers.push_back(number);
    total_duration.push_back(0);
    return true;
  }
}

bool phone_book_t::add_call(const call_t &call) {
  if (unique_number.find(call.number) != unique_number.end()){
    number_history.push_back(call.number);
    duration_history.push_back(call.duration_s);
    for  (int i=0; i< numbers.size(); i++) {
      if (numbers[i] == call.number) {
        total_duration[i] += call.duration_s;
      };
    };
    return true;
  }
  else{
    return false;
  }
}

std::vector<call_t> phone_book_t::get_calls(size_t start_pos, size_t count) const {
  int start_pos_int = static_cast<int>(start_pos);
  int count_int = static_cast<int>(count);
  if(count == 0){
    vector<call_t> history_call;
    return history_call;
  }
  if(count > number_history.size()){
    vector<call_t> history_call;
    for(int i = start_pos_int; i < number_history.size(); i++){
      call_t temp;
      temp.number = number_history[i];
      temp.duration_s = duration_history[i];
      history_call.push_back(temp);
    }
    return history_call;
  }
  else{
    vector<call_t> history_call;
    int up_limit = 0;
    int size = static_cast<int>(number_history.size());
    if (start_pos_int + count_int < size){ up_limit = start_pos_int + count_int;}
    else { up_limit = size;}
    for(int i = start_pos_int; i < up_limit; i++){
      call_t temp;
      temp.number = number_history[i];
      temp.duration_s = duration_history[i];
      history_call.push_back(temp);
    }
    return history_call;
  }
}

std::vector<user_info_t> phone_book_t::search_users_by_name(const std::string &name_prefix, size_t count) const {
  std::multimap<string, std::map<string,double>> sub_book;
  vector<user_info_t> user_info;
  for (int i=0; i < unique_number.size(); i++){
    if(names[i].find(name_prefix) == 0){
      std::map<string,double> book_name_durection;
      book_name_durection.insert({numbers[i], total_duration[i]});
      sub_book.insert({names[i],book_name_durection});
    }
  }
  vector<std::pair<string, std::map<string,double>>> vec;
  std::multimap<string, std::map<string,double>> :: iterator it2;
  for (it2=sub_book.begin(); it2!=sub_book.end(); it2++)
  {
    vec.emplace_back(it2->first, it2->second);
  }
  sort(vec.begin(), vec.end(), sortByVal);
  for(it2=sub_book.begin(); it2!=sub_book.end(); it2++){
    user_info_t temp_user_info;
    std::map<string,double> temp_info_name_dur;
    temp_user_info.user.name = it2->first;
    temp_info_name_dur = it2->second;
    std::map<string,double>:: iterator it3;
    it3=temp_info_name_dur.begin();
    temp_user_info.user.number = it3->first;
    temp_user_info.total_call_duration_s = it3->second;
    user_info.push_back(temp_user_info);
  }
  struct sort_for_name
  {
    inline bool operator() (const user_info_t& info1, const user_info_t& info2)
    {
      return (info1.user.name < info2.user.name) ||
             ((info1.user.name == info2.user.name) && (info1.total_call_duration_s > info2.total_call_duration_s)) ||
             ((info1.total_call_duration_s == info2.total_call_duration_s) && (info1.user.name == info2.user.name) &&
              (info1.user.number < info2.user.number));
    }
  };
  sort(user_info.begin(), user_info.end(), sort_for_name());
  if(user_info.size() <= count){
    return user_info;
  }
  else {return {user_info.begin(),user_info.begin()+int(count)};}
}

std::vector<user_info_t> phone_book_t::search_users_by_number(const std::string &number_prefix, size_t count) const {
  std::multimap<string, std::map<string,double>> sub_book;
  vector<user_info_t> user_info;
  for (int i=0; i < unique_number.size(); i++){
    if(numbers[i].find(number_prefix) == 0){
      std::map<string,double> book_name_durection;
      book_name_durection.insert({numbers[i], total_duration[i]});
      sub_book.insert({names[i],book_name_durection});
    }
  }
  vector<std::pair<string, std::map<string,double>>> vec;
  std::multimap<string, std::map<string,double>> :: iterator it2;
  for (it2=sub_book.begin(); it2!=sub_book.end(); it2++)
  {
    vec.emplace_back(it2->first, it2->second);
  }
  sort(vec.begin(), vec.end(), sortByVal);
  for(it2=sub_book.begin(); it2!=sub_book.end(); it2++){
    user_info_t temp_user_info;
    std::map<string,double> temp_info_name_dur;
    temp_user_info.user.name = it2->first;
    temp_info_name_dur = it2->second;
    std::map<string,double>:: iterator it3;
    it3=temp_info_name_dur.begin();
    temp_user_info.user.number = it3->first;
    temp_user_info.total_call_duration_s = it3->second;
    user_info.push_back(temp_user_info);
  }
  struct sort_for_number
  {
    inline bool operator() (const user_info_t& info1, const user_info_t& info2)
    {
      return (info1.total_call_duration_s > info2.total_call_duration_s) ||
             ((info1.total_call_duration_s == info2.total_call_duration_s) && (info1.user.name < info2.user.name)) ||
             ((info1.total_call_duration_s == info2.total_call_duration_s) && (info1.user.name == info2.user.name) &&
              (info1.user.number < info2.user.number));
    }
  };
  sort(user_info.begin(), user_info.end(), sort_for_number());
  if(user_info.size() <= count){
    return user_info;
  }
  else {return {user_info.begin(),user_info.begin()+int(count)};}
}

void phone_book_t::clear(){
  unique_number.clear();
  names.clear();
  numbers.clear();
  number_history.clear();
  duration_history.clear();
  all_calls.clear();
  total_duration.clear();
}

size_t phone_book_t::size() const {
  return unique_number.size();
}
bool phone_book_t::empty() const {
  return unique_number.empty();
}
bool phone_book_t::sortByVal(const std::pair<string, std::map<string,double>> &a, const std::pair<string, std::map<string,double>> &b) {
  std::map<string,double>:: iterator it3;
  return (a.second < b.second);
}

