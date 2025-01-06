#include <string>
#include <list>
#include <vector>
#include <functional>
#include <memory>

template<typename K, typename T>
class HashTable
{
  public:
    HashTable(size_t size)
      : _t(size)
    {
    }

    T* put(const K& key, const T& value) {
      const auto i = idx(key);
      bucket_ptr_t& p = _t.at(i);

      // initialize bucket
      if (!p) {
        p = std::make_unique<bucket_t>();
      }

      // find existing element
      for (auto it = p->begin(); it != p->end(); it++) {
        if (it->first == key) {
          it->second = value;
          return &it->second;
        }
      }

      // if element not found, create it
      p->push_back(std::make_pair(key, value));
      return &p->back().second;
    }

    T* get(const K& key) const {
      const auto i = idx(key);
      const bucket_ptr_t& p = _t.at(i);
      if (!p) {
        return nullptr;
      }

      for (auto it = p->begin(); it != p->end(); it++) {
        if (it->first == key) {
          return &it->second;
        }
      }

      return nullptr;
    }

    T& operator[](const K& key) {
      const auto e = get(key);
      if (e) {
        return *e;
      }
      return *put(key, T());
    }

    size_t size() const { return _t.size(); }

  private:
    using bucket_element_t = std::pair<K,T>;
    using bucket_t = std::list<bucket_element_t>;
    using bucket_ptr_t = std::unique_ptr<bucket_t>;
    using table_t = std::vector<bucket_ptr_t>;
    table_t _t;

    inline size_t idx(const T& key) const { return std::hash<T>{}(key) % size(); }
};
