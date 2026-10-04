class LFUCache {
    struct CacheInfo {
        int value;
        int frequency;
        std::list<int>::iterator position;
    };

    std::unordered_map<int, struct CacheInfo> cache;
    std::unordered_map<int, std::list<int>> freq_lists;

    int capacity;
    int minf;

    void update_freq_list(int key, struct CacheInfo &cache_info){
        freq_lists[cache_info.frequency].erase(cache_info.position);
        if (freq_lists[cache_info.frequency].empty()) {
            freq_lists.erase(cache_info.frequency);
            if (minf == cache_info.frequency) {
                ++minf;
            }
        }

        cache_info.frequency++;
        freq_lists[cache_info.frequency].push_back(key);
        cache_info.position = std::prev(freq_lists[cache_info.frequency].end());
    }

public:
    LFUCache(int capacity) : capacity(capacity), minf(0) {}

    int get(int key) {
        const auto it = cache.find(key);
        if (it == cache.end()) {
            return -1;
        }

        struct CacheInfo &cache_info = it->second; 
        update_freq_list(key, cache_info);
        return cache_info.value;
    }

    void put(int key, int value) {
        if (capacity <= 0) {
            return;
        }
        const auto it = cache.find(key);
        if (it != cache.end()) {
            struct CacheInfo &cache_info = it->second; 
            cache_info.value = value;
            update_freq_list(key, cache_info);
            return;
        }

        if (capacity == cache.size()) {
            // Erase minimun frequency node 
            int erace_key = freq_lists[minf].front();
            freq_lists[minf].pop_front();
            cache.erase(erace_key);

            if (freq_lists[minf].empty()) {
                freq_lists.erase(minf);
            }
        }

        minf = 1;
        freq_lists[1].push_back(key);
        cache.emplace(key, CacheInfo{value, 1, std::prev(freq_lists[1].end())});
    }
};