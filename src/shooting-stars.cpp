#include "shooting-stars.hpp"

shooting_stars::shooting_stars(void) : shooting_stars(1280, 720){};
shooting_stars::shooting_stars(unsigned width, unsigned height)
    : window(sf::VideoMode(width, height), "Shooting Stars",
             sf::Style::Titlebar | sf::Style::Close),
      random(std::random_device().operator()()) {}

void shooting_stars::__draw(void) {
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
                              current_star->getPosition().y); // moving left
    this->window.draw(*current_star);
  };

  #ifndef NDEBUG
    this->__log(std::cerr);
  #endif

  if (this->stars.size() == 0) {
    this->window.close();
  }
};
void shooting_stars::__log(std::ostream &out) {
  out << "current count:\t" << this->stars.size() << "\n";
};
void shooting_stars::__generate(unsigned generation_count) {
  static std::uniform_real_distribution<float> position(
      -50, this->window.getSize().y + 50);
  static std::uniform_real_distribution<float> speed(4, 10);
  static std::uniform_int_distribution<int> color(0, 255);
  static std::uniform_real_distribution<float> size(0.5, 3);

  for (std::size_t t = 0; t < generation_count; ++t) {
    this->stars.emplace_back(sf::CircleShape(size(this->random)),
                             speed(this->random));
    this->stars.at(this->stars.size() - 1)
        .first.setFillColor(sf::Color(color(this->random), color(this->random),
                                      color(this->random)));
    this->stars.at(this->stars.size() - 1)
        .first.setPosition(-50, position(this->random));
  };
};
void shooting_stars::__start(unsigned generation_count) {
  sf::Clock clock;
  this->__generate(25);

  while (this->window.isOpen()) {
    float current_time = clock.getElapsedTime().asSeconds();
    if (current_time >= 0.5f) {
      clock.restart();
      this->__generate(generation_count);
    };

    sf::Event event;
    while (this->window.pollEvent(event))
      switch (event.type) {
      case sf::Event::Closed: {
        this->window.close();
        break;
      };
      default:
        break;
      };

    this->window.clear();
    this->__draw();
    this->window.display();

    sf::sleep(sf::milliseconds(50));
  };
};

void shooting_stars::start(unsigned generation_count) {
  meyers_singleton<shooting_stars>::get_instance().__start(generation_count);
};
void shooting_stars::start(unsigned width, unsigned height,
                           unsigned generation_count) {
  meyers_singleton<shooting_stars>::get_instance(width, height)
      .__start(generation_count);
};