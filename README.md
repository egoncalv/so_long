<h1 align=center>so_long</h1>

This project is a small 2D game.

Its purpose is to make you work with textures, sprites, and some other basic gameplay elements.

For this project we are going to use the school graphical library: the MiniLibX. This library was developed internally and includes basic necessary tools to open a window, create images and deal with keyboard and mouse events.

I have learned how to manage windows, images, keyboard events, as well as pathfinding algorithms and graphical programming.

The program takes a map, in .ber format, as argument. The map must be formatted as the following:
`
11111111111111111           1 = Walls
10000C00000000001           0 = Empty Space       
1C0000000000000C1           C = Collectables
11111110111111101           P = Player
100C0000100000001           E = Exit
1C00000E1C000P001
11111111111111111
`
If the map does not exist, or if it is invalid in any way (Not rectangular, not closed by walls, no player in the map, double exit, etc.) the program must return an Error and exit properly.



<p align=center>
  <img href=https://user-images.githubusercontent.com/37090738/201161987-efebf462-53b1-424e-9823-9894c37332be.gif>
</p>
