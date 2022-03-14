package robocup.boundary;

import java.util.Set;

import javax.inject.Inject;
import javax.ws.rs.GET;
import javax.ws.rs.POST;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;
import javax.ws.rs.Produces;
import javax.ws.rs.core.MediaType;

import org.jboss.logging.Logger;

import robocup.control.Game;
import robocup.control.GameService;

@Path("/api/games")
public class GamesResource {
    @Inject
    GameService gameService;

    @Inject
    Logger log;

    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public Set<Integer> listAllGames() {
        var gameIds = gameService.listGameIds();
        return gameIds;
    }

    @GET
    @Path("{gameId}")
    @Produces(MediaType.APPLICATION_JSON)
    public Game getGame(@PathParam("gameId") int gameId) {
        var game = gameService.getGame(gameId);

        if (game == null) {
            log.warn("no game found for gameId " + gameId);
        } else {
            log.info("retrieved game for gameId " + gameId + "; version: " + game.getVersion());
        }

        return game;
    }

    static public class StepResult {
        private boolean success;
        private int numberOfStepsSinceStart;

        public boolean isSuccess() {
            return success;
        }

        public void setSuccess(boolean success) {
            this.success = success;
        }

        public int getNumberOfStepsSinceStart() {
            return numberOfStepsSinceStart;
        }

        public void setNumberOfStepsSinceStart(int numberOfStepsSinceStart) {
            this.numberOfStepsSinceStart = numberOfStepsSinceStart;
        }
    }

    @POST
    @Path("{gameId}/step")
    @Produces(MediaType.APPLICATION_JSON)
    public StepResult step(@PathParam("gameId") int gameId) {
        var game = gameService.getGame(gameId);

        var stepResult = new StepResult();
        if (game == null) {
            log.warn("no game found for gameId " + gameId);
            stepResult.setSuccess(false);
            stepResult.setNumberOfStepsSinceStart(2);

        } else {
            log.info("step for gameId " + gameId);
            game.step();
            stepResult.setSuccess(true);
            stepResult.setNumberOfStepsSinceStart(1234);
        }

        return stepResult;
    }
}
