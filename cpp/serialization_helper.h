#ifndef SERIALIZATION_HELPER_H_
#define SERIALIZATION_HELPER_H_

#include <string>

// forward-decl
class Game;
class Team;
class MetaInformation;
class PlayerLocation;
class SpecialLocation;

std::string json_from(Game *game);
std::string json_from(MetaInformation *meta_information);
std::string json_from(Team const *team);
std::string json_from(PlayerLocation const *team);
std::string json_from(SpecialLocation const *special_location);

#endif