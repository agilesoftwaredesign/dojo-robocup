#ifndef TEST_SERVICE_H_
#define TEST_SERVICE_H_

// forward-decl
class GameService;

class TestService {
private:
  GameService *game_service_;

public:
  TestService(GameService *game_service);
  void setup(int setupId);
};

#endif // TEST_SERVICE_H_