package robocup.control;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

import javax.enterprise.context.ApplicationScoped;

@ApplicationScoped
public class GameService {
    private Map<Integer, Game> games = new HashMap<>();

    public Set<Integer> listGameIds() {
        return new HashSet<Integer>(games.keySet());
    }

    public void setGame(Game game) {
        games.put(game.getGameId(), game);
    }

    public Game getGame(int gameId) {
        return games.get(gameId);
    }
}
