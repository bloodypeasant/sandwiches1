#pragma once

#include "Color.hpp"
#include "SDL.h"

class Player
{
public:
  Player(double posX, double posY, double dimX, double dimY, Color color);
  void Draw(SDL_Renderer *pRenderer);

private:
  double posX;
  double posY;
  double dimX;
  double dimY;
  Color color;
};