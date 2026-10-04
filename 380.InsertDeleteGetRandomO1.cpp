#include <cstddef>
#include <unordered_map>
#include <vector>

class RandomizedSet {

private:
    std::vector<int> values;
    std::unordered_map<int, int> indices;

public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if(indices.find(val) != indices.end()){
            return false;
        }

        indices[val] = static_cast<int>(values.size()); 
        values.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        const auto it = indices.find(val);
        if(it == indices.end()){
            return false;
        }

        const int index = it->second;

        // Move last value in vector to remove value's positon, and remove last item in vector.
        const int values_last = values.back();
        values[index] = values_last;
        indices[values_last] = index;
        
        values.pop_back();
        indices.erase(it);
        return true;
    }
    
    int getRandom() {
        return values[std::rand()%static_cast<int>(values.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */