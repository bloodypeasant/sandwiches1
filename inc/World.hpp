#pragma once

#include "Color.hpp"
#include "SDL.h"

class World
{
public:
  World(double dimX, double dimY, Color color);
  void Draw(SDL_Renderer *pRenderer);

  double dimX;
  double dimY;

private:
  Color color;
};