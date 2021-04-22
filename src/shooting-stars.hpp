#pragma once
#ifndef __SHOOTING_STARS_HPP__
#define __SHOOTING_STARS_HPP__

#include <iostream>
#include <random>
#include <vector>

#include <SFML/Graphics.hpp>

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
   * @param[in] population Count of starting stars
   */
  static void run(unsigned population);
  /**
   * Perform application start in window from a given size
   * from a given stars count
   *
   * @param[in] population Count of starting stars
   * @param[in] width Window width
   * @param[in] height Window height
   */
  static void run(unsigned population, unsigned width, unsigned height);

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
  void draw(void);
  /**
   * Perfmorm logging the current drawn objects
   *
   * @param[in] out Stream for log
   */
  void log(std::ostream &out);
  /**
   * Perform populating stars from a given count
   *
   * @param[in] population Population size
   */
  void populate(unsigned population);
  /**
   * Perfmorm main app loop
   */
  void execute(unsigned population);
};

#endif // !__SHOOTING_STARS_HPP__