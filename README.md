**My first graphical project - Building a small 2D game in C**

In this project I learned how to use a graphical library "MiniLibx" to render images to the screen. 
I also learned about game logic to render movements of a player.

**How does it work**
- Clone the repository
- Make
- Run ./so_long with your map e.g. "./so_long "game_maps/validmap2.ber"
- Play using WASD keys to move the player, collect the fish and return to the treasure chest to win.
- The no of moves and collectable count is displayed in shell.

**Error handling** 
To check the map is valid, I use a flood fill function to screen the entire map.
-->It will return an error if you:
Test different line sizes - "map is not a rectangle"
Parse invalid characters
Create a map where exit (E) or collectables (C) are not reachable by the player (P)
The map is missing a complete set of walls around the outside (1)


