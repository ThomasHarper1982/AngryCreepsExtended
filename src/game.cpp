#include "game.h"
#include <iostream>
#include "SDL.h"




Game::Game(std::size_t grid_width, std::size_t grid_height) {
   gameState = std::make_unique< GameState>(static_cast<int>(grid_width), static_cast<int>(grid_height));
   gameState.get()->init();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;
  //renderer.Render(gameState.get());
  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    
    controller.HandleInput(running, gameState.get());
    if (gameState->hasEnded()){
        int grid_width = gameState->getMapX();
        int grid_height = gameState->getMapY();
        gameState  = std::make_unique< GameState>(static_cast<int>(grid_width), static_cast<int>(grid_height));
        gameState->init();
        frame_start = SDL_GetTicks();
        renderer.Render(gameState.get());
        controller.HandleInput(running, gameState.get());
    }
    gameState.get()->Update();
    std::cout << "here1" <<std::endl;
    renderer.Render(gameState.get());
    std::cout << "here3" <<std::endl;
    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;
     renderer.UpdateWindowTitle(gameState.get());
    // After every second, update the window title.
    if (frame_end - title_timestamp >= 10000) {
      renderer.UpdateWindowTitle(gameState.get());
 //     renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

/*void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::Update() {
  if (!snake.alive) return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }*/