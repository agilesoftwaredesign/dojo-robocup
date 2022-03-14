package robocup.boundary;

import javax.inject.Inject;
import javax.ws.rs.POST;
import javax.ws.rs.Path;
import javax.ws.rs.Produces;
import javax.ws.rs.core.MediaType;

import org.jboss.logging.Logger;

import robocup.control.TestService;

@Path("/api/test-setup")
public class TestSetupResource {
    @Inject
    TestService testService;

    @Inject
    Logger log;

    @Inject
    GamesResource gamesResouce;

    @POST
    @Path("1")
    @Produces(MediaType.TEXT_PLAIN)
    public String setup01() {
        testService.setup(1);
        log.info("added game for test-setup");
        return "setup complete";
    }
}
