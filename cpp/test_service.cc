#include "test_service.h"

#include "game.h"
#include "game_service.h"

#include <cassert>
#include <iostream>

TestService::TestService(GameService *game_service)
    : game_service_(game_service) {
  // empty
}

void TestService::setup(int setupId) {
  assert(setupId == 1);
  std::cout << "TestService::setup = " + std::to_string(setupId) << std::endl;

  auto team1 = Team{1, "A Team", {43, 44, 59}};
  auto team2 = Team{2, "Bee Team", {661, 25, 79}};

  auto ballSpawnPoint = SpecialLocation{"100x50", "ball-spawn-point", 0};
  auto goal1 = SpecialLocation{"201x40 - 201x30", "goal", 1};
  auto goal2 = SpecialLocation{"1x40 - 1x30", "goal", 2};

  auto meta = MetaInformation{
      "200x100", {team1, team2}, {ballSpawnPoint, goal1, goal2}};

  auto game = std::make_unique<Game>();
  game->game_id = 22;
  game->version = "0.1";
  game->ball_location = "10x50";
  game->meta_information = meta;
  game->player_locations = {PlayerLocation{43, "5x6"},
                            PlayerLocation{661, "55x6"}};

  game_service_->setGame(std::move(game));
}