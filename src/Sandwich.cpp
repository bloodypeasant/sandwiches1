#include <math.h>
#include "Sandwich.hpp"

Sandwich::Sandwich(double posX, double posY, double dimX, double dimY, Color color)
    : posX(posX), posY(posY), dimX(dimX), dimY(dimY), color(color)
{
}

void Sandwich::Draw(SDL_Renderer *pRenderer)
{
  SDL_Rect rect{
      (int)round(400.0 + posX - 0.5 * dimX),
      (int)round(300.0 + posY - 0.5 * dimY),
      (int)round(dimX),
      (int)round(dimY)};
  SDL_SetRenderDrawColor(pRenderer, color.r, color.g, color.b, color.a);
  SDL_RenderFillRect(pRenderer, &rect);
}