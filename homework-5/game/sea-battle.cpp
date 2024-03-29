#include "game/sea-battle.h"

#include <utility>

sea_battle_t::turn_t sea_battle_t::change_turn(turn_t current_turn) {
  return current_turn == FIRST_PLAYER ? SECOND_PLAYER : FIRST_PLAYER;
}

std::string sea_battle_t::get_player_name(turn_t turn) {
  return turn == FIRST_PLAYER ? "First" : "Second";
}

sea_battle_t::sea_battle_t(std::shared_ptr<player_interface_t> player1, field_t field1,
                           std::shared_ptr<player_interface_t> player2, field_t field2)
    : f1(std::move(field1)), f2(std::move(field2)), my_player(std::move(player1)), enemy_player(std::move(player2)), my_field(&f1),
      enemy_field(&f2) {}

void sea_battle_t::play() {
  while (true) {
    std::pair<int, int> move = my_player->make_move(*my_field, delete_ships(*enemy_field));
    int i = move.first;
    int j = move.second;

    if (field_t::is_cell_valid(i, j)) {
      switch ((*enemy_field)[i][j]) {
      case field_t::MISS_CELL:
      case field_t::HIT_CELL:
        my_player->on_duplicate_move(i, j);
        break;
      case field_t::EMPTY_CELL:
        (*enemy_field)[i][j] = field_t::MISS_CELL;
        my_player->on_miss(i, j);
        std::swap(my_player, enemy_player);
        std::swap(my_field, enemy_field);
        break;
      case field_t::SHIP_CELL:
        (*enemy_field)[i][j] = field_t::HIT_CELL;
        if (check_kill(*enemy_field, i, j)) {
          my_player->on_kill(i, j);
          if (check_win(*enemy_field)) {
            my_player->on_win();
            enemy_player->on_lose();
            return;
          }
        } else {
          my_player->on_hit(i, j);
        }
        break;
      }
    } else {
      my_player->on_incorrect_move(i, j);
    }
  }
}

field_t sea_battle_t::delete_ships(field_t f) {
  for (int i = 0; i < field_t::FIELD_SIZE; i++) {
    for (int j = 0; j < field_t::FIELD_SIZE; j++) {
      if (f[i][j] == field_t::SHIP_CELL) {
        f[i][j] = field_t::EMPTY_CELL;
      }
    }
  }
  return f;
}

bool sea_battle_t::check_kill(field_t &f, int i, int j) {
  for (auto direction : field_t::DIRECTIONS) {
    int i_offset = direction.first;
    int j_offset = direction.second;
    while (field_t::is_cell_valid(i + i_offset, j + j_offset) && f[i + i_offset][j + j_offset] == field_t::HIT_CELL) {
      i_offset += direction.first;
      j_offset += direction.second;
    }
    if (field_t::is_cell_valid(i + i_offset, j + j_offset) && f[i + i_offset][j + j_offset] == field_t::SHIP_CELL) {
      return false;
    }
  }
  return true;
}

bool sea_battle_t::check_win(field_t &f) {
  for (int i = 0; i < field_t::FIELD_SIZE; i++) {
    for (int j = 0; j < field_t::FIELD_SIZE; j++) {
      if (f[i][j] == field_t::SHIP_CELL) {
        return false;
      }
    }
  }
  return true;
}