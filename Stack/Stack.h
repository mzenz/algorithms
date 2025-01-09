#pragma once

#include <vector>

template<typename T>
class Stack {
  public:
    Stack() {
    }

    T pop() {
      const T v(_s.back());
      _s.pop_back();
      return v;
    }

    void push(const T& v) {
      _s.push_back(v);
    }

    size_t size() const { return _s.size(); }

  private:
    std::vector<T> _s;
};
