<h1 align=center>so_long</h1>

This project is a small 2D game.

Its purpose is to make you work with textures, sprites, and some other basic gameplay elements. I have learned how to manage windows, images, keyboard events, as well as pathfinding algorithms and graphical programming.

The program takes a map, in .ber format, as argument. The map must be formatted as the following:

```
11111111111111111           1 = Walls
10000C00000000001           0 = Empty Space       
1C0000000000000C1           C = Collectables
11111110111111101           P = Player
100C0000100000001           E = Exit
1C00000E1C000P001
11111111111111111
```

If the map does not exist, or if it is invalid in any way (Not rectangular, not closed by walls, no player in the map, double exit, etc.) the program must return an Error and exit properly.

![Errors screenshot](https://user-images.githubusercontent.com/37090738/201168380-2bd91aa9-82b3-47d8-b8be-9b2f4653dcaa.png)

Another challenge was to check if the map had a valid path (Player being able to reach all collectables and the exit). For that, I wrote a pathfinding algorithm called dfs. If it verifies that there is no valid path, the program exits properly.

![Error screenshot](https://user-images.githubusercontent.com/37090738/201168868-47c3e9f6-3442-469d-8d34-ca30b76984d8.png)

Once everything is checked, the game starts and we are able to play it:

![Gameplay gif](https://user-images.githubusercontent.com/37090738/201161987-efebf462-53b1-424e-9823-9894c37332be.gif)

To run it (Linux Only), you can use the following command in the root of the repository:
`make`
