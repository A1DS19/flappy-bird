#include "main.hpp"

#include <stdlib.h>

#include <optional>

int main() {
  sf::RenderWindow window(sf::VideoMode(ScreenDims), "Flappy Bird");

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }
  }

  return EXIT_SUCCESS;
}
