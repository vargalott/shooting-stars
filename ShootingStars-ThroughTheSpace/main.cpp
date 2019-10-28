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
	#ifdef _WIN64
		std::mt19937_64 random;
	#else
		std::mt19937 random;
	#endif
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
	std::uniform_real_distribution<float> position(-480, 1200);
	std::uniform_real_distribution<float> speed(4, 10);
	std::uniform_int_distribution<int> color(0, 255);
	std::uniform_real_distribution<float> size(0.5, 3);
	for (size_t t = 0; t < 25; ++t)
	{
		this->stars.emplace_back(sf::CircleShape(size(this->random)), speed(this->random));
		this->stars[this->stars.size() - 1].first.setFillColor(sf::Color(color(this->random), color(this->random), color(this->random)));
		this->stars[this->stars.size() - 1].first.setPosition(-50, position(this->random));
	}
}
void ShootingStars::draw(sf::RenderWindow& window)
{
	for (size_t t = 0; t < this->stars.size(); ++t)
	{
		if (
			this->stars[t].first.getPosition().x >= 1280 ||
			this->stars[t].first.getPosition().x <= -100 ||
			this->stars[t].first.getPosition().y <= -580 ||
			this->stars[t].first.getPosition().y >= 1300
			)
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
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Shooting Stars", sf::Style::Titlebar | sf::Style::Close);
	sf::View view(sf::FloatRect(0.f, 0.f, 1280.f, 720.f));

	ShootingStars stars; sf::Clock clock;
	stars.start();

	bool is_auto_rotated_r = false,
		is_auto_rotated_l = false;

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
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					view.rotate(0.5);
					window.setView(view);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					view.rotate(-0.5);
					window.setView(view);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
				{
					is_auto_rotated_r = !is_auto_rotated_r;
					is_auto_rotated_l = false;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
				{
					is_auto_rotated_l = !is_auto_rotated_l;
					is_auto_rotated_r = false;
				}
				break;
			default:
				break;
			};

		if (is_auto_rotated_r)
		{
			view.rotate(0.5);
			window.setView(view);
		};
		if (is_auto_rotated_l)
		{
			view.rotate(-0.5);
			window.setView(view);
		};

		window.clear();
		stars.draw(window);
		window.display();

		sf::sleep(sf::milliseconds(50));
	}
	return 0;
}