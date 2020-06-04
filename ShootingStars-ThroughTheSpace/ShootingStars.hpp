#pragma once
#ifndef __SHOOTING_STARS__
#define __SHOOTING_STARS__

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <random>
#include <vector>
#include <iostream>

#include "MSingleton.hpp"

class ShootingStars
{
private:
#ifdef _WIN64 
	std::mt19937_64 random;
#else 
	std::mt19937 random; 
#endif

	sf::RenderWindow window;
	std::vector<std::pair<sf::CircleShape /*star*/, float /*speed*/>> stars;

	ShootingStars(void);
	ShootingStars(unsigned width, unsigned height);

	void __draw(void);
	void __log(std::ostream& out) noexcept;
	void __generate(unsigned generation_count);
	void __start(unsigned generation_count);

	friend class MeyersSingleton<ShootingStars>;
public:
	~ShootingStars() = default;

	static void start(unsigned generation_count);
	static void start(unsigned width, unsigned height, unsigned generation_count);
};

#endif // !__SHOOTING_STARS__