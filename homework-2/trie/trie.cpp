#include "trie.h"
trie_t::trie_t() = default;
trie_t::~trie_t() = default;
trie_t::trie_t(const trie_t &other) = default;
trie_t &trie_t::operator=(const trie_t &other) = default;

void trie_t::insert(const std::string &str) {
  count_in_all_key+=1;
  if (str.length() == 0) {
    count_in_current_key+=1;
    return;
  }
  ply[str[0]].insert(str.substr(1));
}
bool trie_t::erase(const std::string &str) {
  if (str.length() == 0) {
    if (count_in_current_key > 0) {
      count_in_all_key-=1;
      count_in_current_key-=1;
      return true;
    } else {
      return false;
    }
  }
  if (ply.end() == ply.find(str[0])) {
    return false;
  }
  if (ply[str[0]].erase(str.substr(1))) {
    count_in_all_key-=1;
    return true;
  }
  return false;
}

void trie_t::clear() {
  ply.clear();
  count_in_current_key = 0;
  count_in_all_key = 0;
}

bool trie_t::find(const std::string &str) const {
  if (str.length() == 0) {
    return true;
  }
  if (ply.end() == ply.find(str[0])) {
    return false;
  }
  return ply.at(str[0]).find(str.substr(1));
}

size_t trie_t::count_with_prefix(const std::string &prefix) const {
  if (prefix.length() == 0) {
    return count_in_all_key;
  }
  if (ply.end() == ply.find(prefix[0])) {
    return 0;
  }
  return ply.at(prefix[0]).count_with_prefix(prefix.substr(1));
}

std::string trie_t::operator[](size_t index) const {
  if (count_in_current_key > index) {
    return "";
  }
  index = index - count_in_current_key;
  for (const auto &cell : ply) {
    if (cell.second.count_in_all_key > index) {
      return cell.first + cell.second[index];
    } else {
      index = index - cell.second.count_in_all_key;
    }
  }
}

std::vector<std::string> trie_t::to_vector() const {
  std::vector<std::string> v_str;
  v_str.reserve(count_in_current_key);
for (int i = 0; i < count_in_current_key; ++i) {
    v_str.emplace_back("");
  }
  for (const auto &cell : ply) {
    std::vector<std::string> v_temp = cell.second.to_vector();
    for (std::string &str : v_temp) {
      str = cell.first + str;
    }
    v_str.insert(v_str.end(), v_temp.begin(),
                         v_temp.end());
  }
  return v_str;
}

size_t trie_t::size() const {
  return count_in_all_key;
}

bool trie_t::empty() const {
  return count_in_all_key == 0;
}

void trie_t::swap(trie_t &other) {
  std::swap(*this, other);
}
