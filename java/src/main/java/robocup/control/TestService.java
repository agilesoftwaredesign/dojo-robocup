package robocup.control;

import java.util.Arrays;

import javax.enterprise.context.ApplicationScoped;
import javax.inject.Inject;

@ApplicationScoped
public class TestService {
    @Inject
    GameService gameService;

    public void setup(int setupId) {
        assert (setupId == 1);

        var team1 = new Game.Team(1, "A Team", Arrays.asList(43, 44, 59));
        var team2 = new Game.Team(2, "Bee Team", Arrays.asList(661, 25, 79));

        var ballSpawnPoint = new Game.SpecialLocation("100x50", "ball-spawn-point");
        var goal1 = new Game.SpecialLocation("201x40 - 201x30", "goal", team1);
        var goal2 = new Game.SpecialLocation("1x40 - 1x30", "goal", team2);

        var meta = new Game.MetaInformation();
        meta.setSize("200x100");
        meta.getSpeciallocations()
            .addAll(Arrays.asList(ballSpawnPoint, goal1, goal2));
        meta.getTeams()
            .addAll(Arrays.asList(team1, team2));

        var playLocations = Arrays.asList(new Game.PlayerLocation(43, "5x6"), new Game.PlayerLocation(661, "55x6"));

        var game = new Game();
        game.setGameId(22);
        game.setVersion("0.1");
        game.setMetainformation(meta);
        game.setBalllocation("10x50");
        game.setPlayerlocations(playLocations);

        gameService.setGame(game);
    }
}
