package robocup.control;

import java.util.ArrayList;
import java.util.List;

public class Game {
    static public class PlayerLocation {
        private int playerid;
        private String location;

        public PlayerLocation() {
        }

        public PlayerLocation(int id, String location) {
            this.setPlayerid(id);
            this.setLocation(location);
        }

        public int getPlayerid() {
            return playerid;
        }

        public void setPlayerid(int playerid) {
            this.playerid = playerid;
        }

        public String getLocation() {
            return location;
        }

        public void setLocation(String location) {
            this.location = location;
        }
    }

    static public class Team {
        private int teamId;
        private String teamname;
        private List<Integer> playerids = new ArrayList<>();

        public Team() {
        }

        public Team(int teamId, String name, List<Integer> playerIds) {
            this.teamId = teamId;
            this.teamname = name;
            this.playerids = playerIds;
        }

        public int getTeamId() {
            return teamId;
        }

        public void setTeamId(int teamId) {
            this.teamId = teamId;
        }

        public String getTeamname() {
            return teamname;
        }

        public void setTeamname(String teamname) {
            this.teamname = teamname;
        }

        public List<Integer> getPlayerids() {
            return playerids;
        }

        public void setPlayerids(List<Integer> playerids) {
            this.playerids = playerids;
        }
    }

    static public class SpecialLocation {
        private String location;
        private String kind;
        private int team;

        public SpecialLocation() {
        }

        public SpecialLocation(String location, String kind) {
            this.location = location;
            this.kind = kind;
        }

        public SpecialLocation(String location, String kind, Team team) {
            this.location = location;
            this.kind = kind;
            this.setTeam(team.teamId);
        }

        public String getLocation() {
            return location;
        }

        public void setLocation(String location) {
            this.location = location;
        }

        public String getKind() {
            return kind;
        }

        public void setKind(String kind) {
            this.kind = kind;
        }

        public int getTeam() {
            return team;
        }

        public void setTeam(int team) {
            this.team = team;
        }
    }

    static public class MetaInformation {
        private String size;
        private List<Team> teams = new ArrayList<>();
        private List<SpecialLocation> speciallocations = new ArrayList<>();

        public String getSize() {
            return size;
        }

        public void setSize(String size) {
            this.size = size;
        }

        public List<Team> getTeams() {
            return teams;
        }

        public void setTeams(List<Team> teams) {
            this.teams = teams;
        }

        public List<SpecialLocation> getSpeciallocations() {
            return speciallocations;
        }

        public void setSpeciallocations(List<SpecialLocation> speciallocations) {
            this.speciallocations = speciallocations;
        }
    }

    private int gameId;
    private String version;
    private String balllocation;
    private MetaInformation metainformation = new MetaInformation();
    private List<PlayerLocation> playerlocations = new ArrayList<>();

    public int getGameId() {
        return gameId;
    }

    public void setGameId(int gameId) {
        this.gameId = gameId;
    }

    public String getVersion() {
        return version;
    }

    public void setVersion(String version) {
        this.version = version;
    }

    public String getBalllocation() {
        return balllocation;
    }

    public void setBalllocation(String balllocation) {
        this.balllocation = balllocation;
    }

    public MetaInformation getMetainformation() {
        return metainformation;
    }

    public void setMetainformation(MetaInformation metainformation) {
        this.metainformation = metainformation;
    }

    public List<PlayerLocation> getPlayerlocations() {
        return playerlocations;
    }

    public void setPlayerlocations(List<PlayerLocation> playerlocations) {
        this.playerlocations = playerlocations;
    }

    public void step() {
        // TODO Auto-generated method stub
    }
}
