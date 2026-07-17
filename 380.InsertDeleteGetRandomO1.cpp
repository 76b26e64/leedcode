#include <cstddef>
#include <random>
#include <unordered_map>
#include <vector>

class RandomizedSet {
    std::vector<int> values;
    std::unordered_map<int, std::size_t> indices;
    std::mt19937 generator;

public:
    RandomizedSet() : generator(std::random_device{}()) {}

    bool insert(int val) {
        if (indices.find(val) != indices.end()) {
            return false;
        }

        indices[val] = values.size();
        values.push_back(val);
        return true;
    }

    bool remove(int val) {
        const auto it = indices.find(val);
        if (it == indices.end()) {
            return false;
        }

        const std::size_t index = it->second;
        const int lastValue = values.back();

        values[index] = lastValue;
        indices[lastValue] = index;
        values.pop_back();
        indices.erase(it);
        return true;
    }

    int getRandom() {
        std::uniform_int_distribution<std::size_t> distribution(
            0, values.size() - 1);
        return values[distribution(generator)];
    }
};
