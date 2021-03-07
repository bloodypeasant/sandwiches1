#include "Game.hpp"

Game::Game()
{
  if (Initialize())
  {
    Run();
  }
  Finalize();
}

void Game::Finalize()
{
  SDL_Log("Finalizing Game.");
  SDL_DestroyRenderer(pRenderer);
  SDL_DestroyWindow(pWindow);
  SDL_Quit();
}

bool Game::Initialize()
{
  if (InitializeView())
  {
    InitializeModel();
    SDL_Log("Initialized Game.");
    return true;
  }
  return false;
}

void Game::InitializeModel()
{
  sandwiches.emplace_back(Sandwich{-200, -200, 25, 25, Color{255, 0, 0, 255}});
  sandwiches.emplace_back(Sandwich{200, 200, 25, 25, Color{255, 255, 0, 255}});
}

bool Game::InitializeView()
{
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
  {
    SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    return false;
  }
  pWindow = SDL_CreateWindow(
      "Sandwiches",
      SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
      800, 600,
      0);
  if (!pWindow)
  {
    SDL_Log("Failed to create window: %s", SDL_GetError());
    return false;
  }
  pRenderer = SDL_CreateRenderer(
      pWindow,
      -1,
      SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!pRenderer)
  {
    SDL_Log("Failed to create renderer: %s", SDL_GetError());
    return false;
  }
  return true;
}

void Game::Run()
{
  SDL_Log("Running Game.");
  while (isRunning)
  {
    RunController();
    RunModel();
    RunView();
  }
}

void Game::RunController()
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
    case SDL_QUIT:
      isRunning = false;
      break;
    case SDL_MOUSEBUTTONDOWN:
      SDL_Log("Mouse down");
      break;
    case SDL_MOUSEBUTTONUP:
      SDL_Log("Mouse up");
      break;
    case SDL_MOUSEMOTION:
      SDL_Log("Mouse motion");
      break;
    }
  }
  const Uint8 *state = SDL_GetKeyboardState(NULL);
  if (state[SDL_SCANCODE_ESCAPE])
  {
    isRunning = false;
  }
  // TODO: process other keys here
}

void Game::RunModel()
{
  while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksCount + 16))
    ;
  float deltaTime = (SDL_GetTicks() - ticksCount) / 1000.0f;
  if (deltaTime > 0.05f)
  {
    deltaTime = 0.05f;
  }
  ticksCount = SDL_GetTicks();
  // TODO: move things, etc.
}

void Game::RunView()
{
  world.Draw(pRenderer);
  for (Sandwich &sandwich : sandwiches)
  {
    sandwich.Draw(pRenderer);
  }
  player.Draw(pRenderer);
  SDL_RenderPresent(pRenderer);
}