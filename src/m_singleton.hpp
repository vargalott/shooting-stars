#pragma once
#ifndef __M_SINGLETON_HPP__
#define __M_SINGLETON_HPP__

template <typename single_instance> class meyers_singleton {
public:
  meyers_singleton() = delete;
  meyers_singleton(meyers_singleton<single_instance> const &) = delete;
  meyers_singleton(meyers_singleton<single_instance> &&) = delete;
  meyers_singleton<single_instance> const &operator=(meyers_singleton<single_instance> const &) = delete;
  meyers_singleton<single_instance> const &operator=(meyers_singleton<single_instance> &&) = delete;

  [[nodiscard]] static single_instance &get_instance(void) {
    static single_instance currentInstance;
    return currentInstance;
  };
  template <typename... Args>
  [[nodiscard]] static single_instance &get_instance(Args... args) {
    static single_instance currentInstance(args...);
    return currentInstance;
  };
};

#endif // !__M_SINGLETON_HPP__