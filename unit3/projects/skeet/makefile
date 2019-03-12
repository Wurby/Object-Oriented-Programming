###############################################################
# Program:
#     Milestone 09, Skeet
#     Brother Dudley, CS165
# Author:
#     Joshua Pearson
# Summary:
#     This is an absolute shell of a program, can't compile 
# Above and Beyond
#     When you submit your final project (not for milestones),
#     list anything here that you did to go above and beyond
#     the base requirements for your project.
###############################################################

LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o rifle.o 
	g++ driver.o game.o uiInteract.o uiDraw.o point.o rifle.o velocity.o
	flyingObject.o bird.o bullet.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
bullet.o: flyingObject.h bullet.cpp bullet.h
	g++ -c bullet.cpp

bird.o: flyingObject.h bird.h bird.cpp
	g++ -c birds.cpp

flyingObject.o: flyingObject.cpp flyingObject.h point.h velocity.h uiDraw.h
	g++ -c flyingObject.cpp

velocity.o: velocity.cpp velocity.h
	g++ -c velocity.cpp

uiDraw.o: uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

game.o: game.cpp uiDraw.h uiInteract.h point.h rifle.h bullet.h birds.h
	g++ -c game.cpp

driver.o: game.h uiInteract.h driver.cpp
	g++ -c driver.cpp

rifle.o: rifle.h point.h uiDraw.h rifle.cpp
	g++ -c rifle.cpp


###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
