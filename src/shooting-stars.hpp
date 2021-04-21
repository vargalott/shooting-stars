#pragma once
#ifndef __SHOOTING_STARS_HPP__
#define __SHOOTING_STARS_HPP__

#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <vector>

#include "m_singleton.hpp"

class shooting_stars {
public:
  ~shooting_stars() = default;

  static void start(unsigned generation_count);
  static void start(unsigned width, unsigned height, unsigned generation_count);

private:
  std::mt19937 random;

  sf::RenderWindow window;
  std::vector<std::pair<sf::CircleShape /*star*/, float /*speed*/>> stars;

  shooting_stars(void);
  shooting_stars(unsigned width, unsigned height);

  void __draw(void);
  void __log(std::ostream &out) noexcept;
  void __generate(unsigned generation_count);
  void __start(unsigned generation_count);

  friend class meyers_singleton<shooting_stars>;
};

#endif // !__SHOOTING_STARS_HPP__