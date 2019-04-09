###############################################################
# Program:
#     Prove 13, Asteroids
#     Brother Dudley, CS165
# Author:
#     Joshua Pearson
# Summary:
#     I unfortunately only had between 2-4 hours a week to work
#     on this project, I couldn't get it to do anything and
#    	could not continue before it was due. I laid a good
#     ground-work and added todos and bugs to fix while working
#		so at least I have that going for me.
#		theoretically, the game should allow the user to blow up
#		asteroids.
# Above and Beyond
#    	Laid the ground work to add extras in the form of
#     a shield and bullet splitting/spread, along with a plan
#     to add random colosions between asteroids to make it a 
#b		bit more random.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o velocity.o flyingObject.o ship.o bullet.o rocks.o powerUp.o
	g++ driver.o game.o uiInteract.o uiDraw.o point.o velocity.o flyingObject.o ship.o bullet.o rocks.o powerUp.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o       Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o   Handles input events
#    point.o        The position on the screen
#    game.o         Handles the game interaction
#    velocity.o     Velocity (speed and direction)
#    flyingObject.o Base class for all flying objects
#    ship.o         The player's ship
#    bullet.o       The bullets fired from the ship
#    rocks.o        Contains all of the Rock classes
#	  powerUp.o	     Contains powerups (bullet spread, shield)
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

driver.o: driver.cpp game.h
	g++ -c driver.cpp

game.o: game.cpp game.h uiDraw.h uiInteract.h point.h velocity.h flyingObject.h bullet.h rocks.h ship.h powerUp.h
	g++ -c game.cpp

velocity.o: velocity.cpp velocity.h point.h
	g++ -c velocity.cpp

flyingObject.o: flyingObject.cpp flyingObject.h point.h velocity.h uiDraw.h
	g++ -c flyingObject.cpp

ship.o: ship.cpp ship.h flyingObject.h point.h velocity.h uiDraw.h
	g++ -c ship.cpp

bullet.o: bullet.cpp bullet.h flyingObject.h point.h velocity.h uiDraw.h
	g++ -c bullet.cpp

rocks.o: rocks.cpp rocks.h flyingObject.h point.h velocity.h uiDraw.h
	g++ -c rocks.cpp

powerUp.o: flyingObject.h point.h velocity.h powerUp.h
	g++ -c powerUp.cpp

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
