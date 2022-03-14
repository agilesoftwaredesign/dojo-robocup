#ifndef GAME_H_
#define GAME_H_

#include <list>
#include <string>

struct Team {
  int team_id;
  std::string team_name;
  std::list<int> player_ids;
};

struct SpecialLocation {
  std::string location;
  std::string kind;
  int team;
};

struct MetaInformation {
  std::string size;
  std::list<Team> teams;
  std::list<SpecialLocation> special_location;
};

struct PlayerLocation {
  int player_id;
  std::string location;
};

struct Game {
  int game_id;
  std::string version;
  std::string ball_location;
  MetaInformation meta_information;
  std::list<PlayerLocation> player_locations;

  void step() {}
};

#endif // GAME_H_