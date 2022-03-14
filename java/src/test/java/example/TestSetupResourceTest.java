package example;

import static io.restassured.RestAssured.given;
import static org.hamcrest.CoreMatchers.is;

import org.junit.jupiter.api.Test;

import io.quarkus.test.junit.QuarkusTest;

@QuarkusTest
public class TestSetupResourceTest {

    @Test
    public void testSetup01() {
        given().when()
               .post("/api/test-setup/1")
               .then()
               .statusCode(200)
               .body(is("setup complete"));

        given().when()
               .get("/api/games")
               .then()
               .statusCode(200)
               .body(is("[22]"));
    }

    @Test
    public void testSetup01_content() {
        given().when()
               .post("/api/test-setup/1")
               .then()
               .statusCode(200)
               .body(is("setup complete"));

        final var expected =
                "{\"balllocation\":\"10x50\",\"gameId\":22,\"metainformation\":{\"size\":\"200x100\",\"speciallocations\":[{\"kind\":\"ball-spawn-point\",\"location\":\"100x50\",\"team\":0},{\"kind\":\"goal\",\"location\":\"201x40 - 201x30\",\"team\":1},{\"kind\":\"goal\",\"location\":\"1x40 - 1x30\",\"team\":2}],\"teams\":[{\"playerids\":[43,44,59],\"teamId\":1,\"teamname\":\"A Team\"},{\"playerids\":[661,25,79],\"teamId\":2,\"teamname\":\"Bee Team\"}]},\"playerlocations\":[{\"location\":\"5x6\",\"playerid\":43},{\"location\":\"55x6\",\"playerid\":661}],\"version\":\"0.1\"}";
        given().when()
               .get("/api/games/22")
               .then()
               .statusCode(200)
               .body(is(expected));
    }
}
