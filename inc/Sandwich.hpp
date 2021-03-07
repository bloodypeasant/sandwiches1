#pragma once

#include "Color.hpp"
#include "SDL.h"

class Sandwich
{
public:
  Sandwich(double posX, double posY, double dimX, double dimY, Color color);
  void Draw(SDL_Renderer *pRenderer);

private:
  double posX;
  double posY;
  double dimX;
  double dimY;
  Color color;
};