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
  /**
   * Class construnctor
   * Permorm construnction of the intance of the main app class
   */
  shooting_stars(void);
  ~shooting_stars(void) = default;

  /**
   * Perfmorm main app loop
   *
   * @param[in] population Population size
   */
  void execute(unsigned population);

private:
  std::mt19937 random;

  sf::RenderWindow window;
  std::vector<std::pair<sf::CircleShape /*star*/, float /*speed*/>> stars;

  /**
   * Perfmorm logging the current drawn objects
   *
   * @param[in] out Stream for log
   */
  void log(std::ostream &out);

  /**
   * Perform drawing the current available scene objects
   */
  void draw(void);
  /**
   * Perform populating stars from a given count
   *
   * @param[in] population Population size
   */
  void populate(unsigned population);
};

#endif // !__SHOOTING_STARS_HPP__