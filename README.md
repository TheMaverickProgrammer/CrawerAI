# About
This project contains the AI to a basic crawler enemy for a platformer game. 
It was used in a late, undeveloped Allegro game.

# How It Works
The enemy crosses along a tiled world until an edge is reached.
It uses line geometry as sensors to determine if there is a close wall it can cling to.
It then crawls along the wall. 
If there is no wall to cling to it detects if there is an face on the same tile it
can wrap around. If so, it moves over to that face and crawls.

The end result is a like a [Greemer](http://metroid.wikia.com/wiki/Geemer) from the original 2D super metroid.
