#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <random>
#include <vector>
#include <iostream>

#pragma region ShootingStars
class ShootingStars
{
private:
	std::vector<std::pair<sf::CircleShape, float>> stars;
	std::mt19937_64 random;
public:
	ShootingStars();
	~ShootingStars() = default;

	void start();
	void draw(sf::RenderWindow& window);
};
ShootingStars::ShootingStars()
{
	this->random.seed(std::random_device().operator()());
}
void ShootingStars::start()
{
	std::uniform_real_distribution<float> position(1, 720);
	std::uniform_real_distribution<float> speed(4, 10);
	std::uniform_int_distribution<int> color(0, 255);
	std::uniform_real_distribution<float> size(0.5, 3);
	for (size_t t = 0; t < 25; ++t)
	{
		this->stars.push_back(std::make_pair(sf::CircleShape(size(this->random)), speed(this->random)));
		this->stars[this->stars.size() - 1].first.setFillColor(sf::Color(color(this->random), color(this->random), color(this->random)));
		this->stars[this->stars.size() - 1].first.setPosition(-50, position(this->random));
	}
}
void ShootingStars::draw(sf::RenderWindow& window)
{
	for (size_t t = 0; t < this->stars.size(); ++t)
	{
		if (this->stars[t].first.getPosition().x >= 1280)
		{
			this->stars.erase(this->stars.begin() + t);
			--t;
			continue;
		}
		this->stars[t].first.setPosition(this->stars[t].first.getPosition().x + this->stars[t].second, this->stars[t].first.getPosition().y);
		window.draw(this->stars[t].first);
	}
	std::cout << "current count: " << this->stars.size() << "\n";
	if (this->stars.size() == 0)
		window.close();
}
#pragma endregion



int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Shooting Stars");
	ShootingStars stars; sf::Clock clock;
	stars.start();

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		if (time >= 0.5)
		{
			clock.restart();
			stars.start();
		}
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed)
				window.close();

		window.clear();
		stars.draw(window);
		window.display();
		sf::sleep(sf::milliseconds(50));
	}
	return 0;
}