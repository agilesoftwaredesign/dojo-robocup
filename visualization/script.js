const teamColors = {
    1: 'red',
    2: 'green'
};

function log_info(msg) {
    console.log(msg);
}

function log_error(msg) {
    console.log(msg);
    alert(msg);
}

function update_display() {
    const gameid = document.getElementById('gameid').value;
    if (gameid === '') {
        alert('you need to select a game');
        return;
    }

    const url = `http://localhost:9852/api/games/${gameid}`
    const option = {}
    console.log(`fetching ${url}`);
    fetch(url, option)
        .then(response => Promise.all([response.ok, response.json()]))
        .then(([responseOk, json]) => {
            if (!responseOk) {
                log_error('request failed')
                return;
            }

            if ('error' in json) {
                log_error('"error" in response');
                return;
            }

            try {
                display(json);
            }
            catch (error) {
                console.error(`error while processing`, error);
            }
        })
        .catch(error => {
            log_error(`could not parse response ${error}`);
        });
}

function display(json) {
    // console.log(json);

    const canvas = document.getElementById('playground');
    clearCanvas(canvas);

    let ctx = canvas.getContext('2d');
    const teams = json.metainformation.teams;

    const ball = locationFrom(json.balllocation);
    drawBall(ctx, ball);

    json.playerlocations.forEach(player => {
        const loc = locationFrom(player.location);
        const playerId = player.playerid;
        const team = teamOfPlayer(playerId, teams);
        const color = teamColors[team.teamId];

        drawPlayer(ctx, loc, color);
    })
}

function teamOfPlayer(playerId, teams) {
    for (var t in teams) {
        if (teams[t].playerids.includes(playerId)) {
            return teams[t];
        }
    }

    return { teamId: 0 };
}

function locationFrom(txt) {
    return txt.split("x").map(x => parseInt(x));
}

function clearCanvas(canvas) {
    // https://developer.mozilla.org/en-US/docs/Web/API/CanvasRenderingContext2D/clearRect
    const ctx = canvas.getContext('2d');
    ctx.clearRect(0, 0, canvas.width, canvas.height);
}

function drawBall(ctx, loc) {
    // https://developer.mozilla.org/en-US/docs/Web/API/CanvasRenderingContext2D/ellipse
    log_info(`drawBall at ${loc}`);
    const radius = 1;
    ctx.beginPath();
    ctx.fillStyle = '#F0DB4F';
    ctx.strokeStyle = 'black';
    ctx.ellipse(loc[0], loc[1], radius, radius, 0, 0, 2 * Math.PI);
    ctx.stroke();
}

function drawPlayer(ctx, loc, color) {
    // https://developer.mozilla.org/en-US/docs/Web/API/CanvasRenderingContext2D/ellipse
    log_info(`drawPlayer at ${loc} with color ${color}`);
    const radius = 1;
    ctx.beginPath();
    ctx.fillStyle = color;
    ctx.strokeStyle = color;
    ctx.ellipse(loc[0], loc[1], radius, radius, 0, 0, 2 * Math.PI);
    ctx.stroke();
}

function next_step() {
    const gameid = document.getElementById('gameid').value;
    if (gameid === '') {
        alert('you need to select a game');
        return;
    }

    log_error('step not implemented');
}