#include "assetManager.hpp"

namespace Sonar {
void AssetManager::LoadTexture(std::string name, std::string filename) {
  sf::Texture texture;
  if (texture.loadFromFile(filename)) {
    this->_textures[name] = texture;
  }
}

sf::Texture &AssetManager::GetTexture(std::string name) {
  return this->_textures.at(name);
}

void AssetManager::LoadFont(std::string name, std::string filename) {
  sf::Font font;
  if (font.openFromFile(filename)) {
    this->_fonts[name] = font;
  }
}

sf::Font &AssetManager::GetFont(std::string name) {
  return this->_fonts.at(name);
}

} // namespace Sonar
