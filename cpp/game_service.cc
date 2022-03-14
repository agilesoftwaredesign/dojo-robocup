#include "game_service.h"

#include <iostream>

#include "game.h"

std::list<int> GameService::listGameIds() {
  std::list<int> ids;
  for (const auto &[key, value] : games_) {
    ids.push_back(key);
  }
  return ids;
}

void GameService::setGame(std::unique_ptr<Game> game) {
  games_[game->game_id] = std::move(game);
}

Game *GameService::getGame(int game_id) noexcept {
  auto idx = games_.find(game_id);
  if (idx != games_.end()) {
    return idx->second.get();
  } else {
    return nullptr;
  }
}