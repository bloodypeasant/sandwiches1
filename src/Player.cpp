#include <math.h>
#include "Player.hpp"

Player::Player(double posX, double posY, double dimX, double dimY, Color color)
    : posX(posX), posY(posY), dimX(dimX), dimY(dimY), color(color)
{
}

void Player::Draw(SDL_Renderer *pRenderer)
{
  SDL_Rect rect{
      (int)round(400 + posX - 0.5 * dimX),
      (int)round(300 + posY - 0.5 * dimY),
      (int)round(dimX),
      (int)round(dimY)};
  SDL_SetRenderDrawColor(pRenderer, color.r, color.g, color.b, color.a);
  SDL_RenderFillRect(pRenderer, &rect);
}