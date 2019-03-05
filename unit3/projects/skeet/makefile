###############################################################
# Program:
#     Milestone 08, Skeet
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

##############################
#	Well, here I am again. I really only have been able to put
# 	4 hours into this, and most of that time was spent trying to
#	understand the requirements. I am not sure what else to do,
# 	but turn in this basically shell of a program and comment
#	what I did do. I tried to make a skeleton for the rest of the
#	project, but I don't know if I was even able to do that.
#	
#	I've been spending more time working on other classes and
#	projects at work. Since I work full-time, I only have about
#	10 hours a week I can dedicated to this class, and that's
# 	showing to be insuffecient. Do you have any suggestions?
#	You're obviously not familiar with my situation, and that's
#	my fault, but I am struggling to both understand and work
#	these opengl prove projects. It's difficult to understand
#	what needs doing, and I am feeling a bit lost when I do
#	put the time into these, I try to break them down into
#	more managable pieces, but even those are daunting. 
#
#	What more can I do? I program in javascript at work, the
#	way I see it, that's mostly irrelevant. Thanks for reading
#	this novel, I hope I can recover from these, but I am unsure
#	what I can do with the time allotment I have available.
##############################

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

birds.o: flyingObject.h birds.h birds.cpp
	g++ -c birds.cpp

flyingObject.o: flyingObject.cpp flyingObject.h point.h velocity.h
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
