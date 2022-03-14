#include "serialization_helper.h"

#include "game.h"
#include "string_helper.h"

std::string json_from(Game *game) {
  auto p = "{\"balllocation\":\"" + game->ball_location +
           "\", \"gameId\": " + std::to_string(game->game_id) +
           ", \"version\": \"" + game->version +
           "\", \"metainformation\": " + json_from(&game->meta_information) +
           ", \"playerlocations\": [";
  std::list<std::string> pllist;
  for (const auto &sl : game->player_locations) {
    pllist.push_back(json_from(&sl));
  }
  p += join(pllist.begin(), pllist.end(), ",");
  p += "]}";
  return p;
}

std::string json_from(MetaInformation *meta_information) {
  auto p = "{\"size\": \"" + meta_information->size + "\", \"teams\": [";

  std::list<std::string> teams;
  for (const auto &team : meta_information->teams) {
    teams.push_back(json_from(&team));
  }
  p += join(teams.begin(), teams.end(), ",");

  p += "], \"speciallocations\": [";
  std::list<std::string> sllist;
  for (const auto &sl : meta_information->special_location) {
    sllist.push_back(json_from(&sl));
  }
  p += join(sllist.begin(), sllist.end(), ",");

  p += "]}";
  return p;
}

std::string json_from(Team const *team) {
  auto p = "{\"teamId\": " + std::to_string(team->team_id) +
           ", \"teamname\": \"" + team->team_name + "\", \"playerids\": [" +
           join(team->player_ids.begin(), team->player_ids.end(), ",") + "]}";
  return p;
}

std::string json_from(SpecialLocation const *special_location) {
  return "{\"kind\": \"" + special_location->kind + "\", \"location\": \"" +
         special_location->location +
         "\", \"team\": " + std::to_string(special_location->team) + "}";
}

std::string json_from(PlayerLocation const *playerLocation) {
  return "{\"location\": \"" + playerLocation->location +
         "\", \"playerid\": " + std::to_string(playerLocation->player_id) + "}";
}