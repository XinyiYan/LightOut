# LightOut
[Lights Out](https://en.wikipedia.org/wiki/Lights_Out_(game)) is a one-player game.  

The game consists of a n by n grid of lights, each of which can be either on or off.
When the game begins, players specify an initial configuration of on and off cells.  
Once the cells are configured, the player chooses a cell and toggle it. In response,
the adjacent lights will all switch configurations between off and on as well.

The goal of the game is to switch all the lights off within a certain number of moves.

To run this program, you need to use graphical applications.  
For Mac users, install [XQuartz](http://xquartz.macosforge.org/). 
Once installed, you might need to modify Makefile to tell g++ where X11 is located.  
Browse through your Mac’s file system looking for a directory X11 that contains directories 'lib' and 'include'. Then specify the lib directory using the -L option and the include directory using the -I (uppercase i) option in Makefile.  
For example, on my Mac, I used `-L/opt/X11/lib -I/opt/X11/include`  

To start this game:  
1) Clone this repo to a fresh folder  
2) Open Terminal and change the current working directory to your local project  
3) Run `make`  
4) If it builds successfully, then do `./lightout.exe`  
5) Enter `new n` , which creates a new n × n grid  
6) Enter `init` . Enters initialization mode. Subsequently, read pairs of integers r c and set the cell at row r, column c as on. The top-left corner is row 0, column 0. The coordinates -1 -1 end initialization mode.  
7) Enter `game g`. Once the board has been initialized, this command starts a new game, with a commitment to solve the game in g moves or fewer.  
8) Toggle a light by using `switch r c`, which switches the light at row r, column c on or off  

The program ends when the input stream is exhausted or when the game is won or lost. The game is lost if the board is not cleared within g moves.

A sample interaction follows:  
`new 5`       Create a 5 x 5 grid  
`init`        Enter initialization mode   
`1 2`         Switches the light at row 1, column 2 on  
`2 2`         Switches the light at row 2, column 2 on  
`3 2`         Switches the light at row 3, column 2 on  
`-1 -1`       End initialization mode   
`game 3`      Commit to solve the game in 3 moves or fewer  
`switch 2 2`  Toggle the light at row 2, column 2  
`switch 3 2`  Toggle the light at row 3, column 2  
etc...  

Enjoy the game!

