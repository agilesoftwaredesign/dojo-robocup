# Dojo Robocup
**Dojo vision**: You play robocup (soccer) with two or more teams on a field. You design and implement players (agent). You adjust the server to host your players. In order to do that you need to re-design, refactor, and verify operations.

> This code base is intentionally very smelly! Otherwise you as coachee couldn't discuss, re-design, fixing, and improving!

## Orientation
* You start the server on port 9852.
  * The server adheres to the tests in ```test/```.
* With ```GET http://localhost:9852/api/games``` you get the current games.
* With ```GET http://localhost:9852/api/games/<game-id>``` you get the game state.
* With ```POST http://localhost:9852/api/games/<game-id>/step``` you progress the game.

# Suggested dojo excercise
* Make a ```step``` happen.
* Provide different players.
* What can the player see? (Hint: avoid feature-envy, consider rough player)
* Let the player move on the field.
* Improve the data representation of the players.
* Inter-player collaboration.
* Three or more teams playing.
* Improve the visualization, e.g. with SVG, sprite, or 3D.
* 3D movement (locations are not 2D anymore).
* Check for exception-safety, and copy-, move-semantic.
* Defensive programming.
* Stream the game to an outside sink.
* Complex tatical move with predication and pre-planning.