#include "shooting-stars.hpp"

shooting_stars::shooting_stars(void) : shooting_stars(1280, 720){};
shooting_stars::shooting_stars(unsigned width, unsigned height)
    : window(sf::VideoMode(width, height), "Shooting Stars",
             sf::Style::Titlebar | sf::Style::Close),
      random(std::random_device().operator()()){};

void shooting_stars::draw(void) {
  for (std::size_t t = 0; t < this->stars.size(); ++t) {
    sf::CircleShape *current_star = &this->stars[t].first;
    float current_speed = this->stars[t].second;

    if (current_star->getPosition().x >= this->window.getSize().x ||
        current_star->getPosition().y >= this->window.getSize().y) {
      this->stars.erase(this->stars.begin() + t);
      --t;
      continue;
    };

    current_star->setPosition(current_star->getPosition().x + current_speed,
                              current_star->getPosition().y);
    this->window.draw(*current_star);
  };

  if (this->stars.size() == 0) {
    this->window.close();
  }
};
void shooting_stars::log(std::ostream &out) {
  out << "current count:\t" << this->stars.size() << "\n";
};
void shooting_stars::populate(unsigned population) {
  static std::uniform_real_distribution<float> speed(4, 10);
  static std::uniform_int_distribution<int> color(0, 255);
  static std::uniform_real_distribution<float> size(0.5, 3);

  static std::uniform_real_distribution<float> position(
      0, this->window.getSize().y);

  // populating
  for (std::size_t t = 0; t < population; ++t) {
    sf::CircleShape star = sf::CircleShape(size(this->random));
    star.setFillColor(sf::Color(color(this->random), color(this->random),
                                color(this->random)));
    star.setPosition(-50, position(this->random));

    this->stars.emplace_back(star, speed(this->random));
  };
};
void shooting_stars::execute(unsigned population) {
  sf::Clock clock;

  this->populate(population);

  while (this->window.isOpen()) {
    float current_time = clock.getElapsedTime().asSeconds();
    if (current_time >= 0.5f) {
      clock.restart();
      this->populate(population);
    };

    sf::Event event;
    while (this->window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed: {
        this->window.close();
        break;
      };
      default: {
        break;
      };
      };
    }

#ifndef NDEBUG
    this->log(std::cerr);
#endif

    this->window.clear();
    this->draw();
    this->window.display();

    sf::sleep(sf::milliseconds(50));
  };
};

void shooting_stars::run(unsigned population) {
  shooting_stars().execute(population);
};
void shooting_stars::run(unsigned population, unsigned width, unsigned height) {
  shooting_stars(width, height).execute(population);
};