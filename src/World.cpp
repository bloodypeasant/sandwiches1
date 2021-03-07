#include "World.hpp"

World::World(double dimX, double dimY, Color color)
    : dimX(dimX), dimY(dimY), color(color)
{
}

void World::Draw(SDL_Renderer *pRenderer)
{
  SDL_SetRenderDrawColor(pRenderer, color.r, color.g, color.b, color.a);
  SDL_RenderClear(pRenderer);
}