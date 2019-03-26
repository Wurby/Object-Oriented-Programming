/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/

#ifndef GAME_H
#define GAME_H

class Game
{
 protected:
 public:
   void advance();
   void handleInput();
   void draw();
};

#endif /* GAME_H */
