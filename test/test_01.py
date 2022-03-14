import requests
api_base = "http://localhost:9852/api"

expected_game = {"balllocation":"10x50","gameId":22,"metainformation":{"size":"200x100","speciallocations":[{"kind":"ball-spawn-point","location":"100x50","team":0},{"kind":"goal","location":"201x40 - 201x30","team":1},{"kind":"goal","location":"1x40 - 1x30","team":2}],"teams":[{"playerids":[43,44,59],"teamId":1,"teamname":"A Team"},{"playerids":[661,25,79],"teamId":2,"teamname":"Bee Team"}]},"playerlocations":[{"location":"5x6","playerid":43},{"location":"55x6","playerid":661}],"version":"0.1"}

setup_url = '%s/test-setup/1' % api_base
setup_result = requests.post(setup_url)
assert setup_result.status_code == 200, "setup not okay"

game_url = '%s/games/22' % api_base
response = requests.get(game_url)
assert response.status_code == 200, "game request not okay"
game_result = response.json()

# in future this needs to be softened in order to allow extensions
assert sorted(expected_game.items()) == sorted(game_result.items())
print("-- okay -- (all asserts are okay)")