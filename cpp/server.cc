#include <cstdlib>
#include <iostream>
#include <memory>
#include <restbed>

#include "game.h"
#include "game_service.h"
#include "serialization_helper.h"
#include "string_helper.h"
#include "test_service.h"

GameService *game_service = nullptr;
TestService *test_service = nullptr;

constexpr int listeningOnPort = 9852;

using namespace std;
using namespace restbed;

void replyWithJson(std::string body, const shared_ptr<Session> session) {
  const multimap<string, string> headers{
      {"Content-Type", "application/json"},
      {"Access-Control-Allow-Origin", "*"},
      {"Content-Length", ::to_string(body.length())}};

  session->close(OK, body, headers);
}

void replyWithPlain(std::string body, const shared_ptr<Session> session) {
  const multimap<string, string> headers{
      {"Connection", "close"},
      {"Access-Control-Allow-Origin", "*"},
      {"Content-Length", ::to_string(body.length())}};

  session->close(OK, body, headers);
}

void post_method_handler(const shared_ptr<Session> session) {
  const auto request = session->get_request();

  size_t content_length = request->get_header("Content-Length", 0);

  session->fetch(content_length, [request](const shared_ptr<Session> session,
                                           const Bytes &body) {
    std::cout << "Size: " << body.size() << "; Data: " << body.data()
              << std::endl;
    replyWithPlain("Hello World!", session);
  });
}

void post_test_setup_handler(const shared_ptr<Session> session) {
  const auto request = session->get_request();
  const string setupIdStr = request->get_path_parameter("setupId");
  const int setupId = std::stoi(setupIdStr);

  test_service->setup(setupId);

  const string body = "{\"success\": \"true\"}";
  replyWithJson(body, session);
}

void get_games_method_handler(const shared_ptr<Session> session) {
  const auto request = session->get_request();
  const string gameIdStr = request->get_path_parameter("gameId");
  const int gameId = std::stoi(gameIdStr);

  auto game = game_service->getGame(gameId);
  if (game == nullptr) {
    replyWithJson("{\"error\": \"could not find game\"}", session);
    return;
  }

  auto body = json_from(game);
  replyWithJson(body, session);
}

void get_list_games_handler(const shared_ptr<Session> session) {
  auto ids = game_service->listGameIds();

  auto idsStr = join(ids.begin(), ids.end(), ", ");
  const string body = "[" + idsStr + "]";

  replyWithJson(body, session);
}

void step_game_method_handler(const shared_ptr<Session> session) {
  const auto request = session->get_request();
  const string gameIdStr = request->get_path_parameter("gameId");
  const int gameId = std::stoi(gameIdStr);

  auto game = game_service->getGame(gameId);
  if (game == nullptr) {
    const auto fail =
        "{\"success\": false, \"error-message\": \"could find game\"}";
    replyWithJson(fail, session);
    return;
  }

  game->step();

  const string body = "{\"success\": true, \"numberOfStepsSinceStart\": 4321}";
  replyWithJson(body, session);
}

void service_ready_handler(Service &) {
  std::cout << "listening on port " << listeningOnPort << " ..." << std::endl;
}

void setupAndRegisterResources(Service &service) {
  const auto POST = "POST";
  const auto GET = "GET";

  auto testSetupResource = make_shared<Resource>();
  testSetupResource->set_path("/api/test-setup/{setupId: [0-9]+}");
  testSetupResource->set_method_handler(POST, post_test_setup_handler);
  service.publish(testSetupResource);

  auto listGamesResource = make_shared<Resource>();
  listGamesResource->set_path("/api/games");
  listGamesResource->set_method_handler(GET, get_list_games_handler);
  service.publish(listGamesResource);

  auto gamesResource = make_shared<Resource>();
  gamesResource->set_path("/api/games/{gameId: [0-9]+}");
  gamesResource->set_method_handler(GET, get_games_method_handler);
  service.publish(gamesResource);

  auto stepResource = make_shared<Resource>();
  stepResource->set_path("/api/games/{gameId: [0-9]+}/step");
  stepResource->set_method_handler(POST, step_game_method_handler);
  service.publish(stepResource);
}

auto createSettings() {
  auto settings = make_shared<Settings>();
  settings->set_port(listeningOnPort);
  settings->set_bind_address("127.0.0.1");
  settings->set_default_header("Connection", "close");
  return settings;
}

int main(const int, const char **) {
  auto game_service_uniq = std::make_unique<GameService>();
  game_service = game_service_uniq.get();
  auto test_service_uniq = std::make_unique<TestService>(game_service);
  test_service = test_service_uniq.get();

  Service service;
  setupAndRegisterResources(service);

  auto settings = createSettings();

  service.set_ready_handler(service_ready_handler);
  service.start(settings);

  std::cout << "- bye -" << std::endl;
  return EXIT_SUCCESS;
}