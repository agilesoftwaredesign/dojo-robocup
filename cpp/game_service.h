#ifndef GAME_SERVICE_H_
#define GAME_SERVICE_H_

#include <map>
#include <list>
#include <memory>

// forward-decl
struct Game;

class GameService {
private:
  std::map<int, std::shared_ptr<Game>> games_;

public:
  std::list<int> listGameIds();
  void setGame(std::unique_ptr<Game> game);
  Game *getGame(int game_id) noexcept;
};

#endif // GAME_SERVICE_H_