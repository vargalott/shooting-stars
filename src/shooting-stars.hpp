#pragma once
#ifndef __SHOOTING_STARS_HPP__
#define __SHOOTING_STARS_HPP__

#include <iostream>
#include <random>
#include <vector>

#include <SFML/Graphics.hpp>

#include "m_singleton.hpp"

/**
 * Main app class
 *
 * ...
 *
 * Implements stars animation, debug loggins etc
 */
class shooting_stars {
public:
  ~shooting_stars() = default;

  /**
   * Perform application start from a given stars count
   *
   * @param[in] generation_count Count of starting stars
   */
  static void start(unsigned generation_count);
  /**
   * Perform application start in window from a given size
   * from a given stars count
   *
   * @param[in] width Window width
   * @param[in] height Window height
   * @param[in] generation_count Count of starting stars
   */
  static void start(unsigned width, unsigned height, unsigned generation_count);

private:
  std::mt19937 random;

  sf::RenderWindow window;
  std::vector<std::pair<sf::CircleShape /*star*/, float /*speed*/>> stars;

  /**
   * Class construnctor
   * Permorm construnction of the intance of the main app class
   */
  shooting_stars(void);
  /**
   * Class construnctor
   * Permorm construnction of the intance of the main app class
   * from a given size
   *
   * @param[in] width Window width
   * @param[in] height Window height
   */
  shooting_stars(unsigned width, unsigned height);

  /**
   * Perform drawing the current available scene objects
   */
  void __draw(void);
  /**
   * Perfmorm logging the current drawn objects
   */
  void __log(std::ostream &out);
  /**
   * Perform populating stars from a given count
   */
  void __generate(unsigned generation_count);
  /**
   * Perfmorm main app loop
   */
  void __start(unsigned generation_count);

  friend class meyers_singleton<shooting_stars>;
};

#endif // !__SHOOTING_STARS_HPP__