class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        std::stable_sort(logs.begin(), logs.end(),
            [](const std::string &a, const std::string &b){
                auto delimiter_a = a.find(' ');
                auto delimiter_b = b.find(' ');

                std::string_view id_a(a.data(), delimiter_a);
                std::string_view id_b(b.data(), delimiter_b);
                std::string_view contents_a(a.data() + delimiter_a + 1, a.size() - delimiter_a - 1);
                std::string_view contents_b(b.data() + delimiter_b + 1, b.size() - delimiter_b - 1);

                bool digit_a = std::isdigit(contents_a[0]);
                bool digit_b = std::isdigit(contents_b[0]);

                if (digit_a != digit_b) {
                    return !digit_a;
                }

                if(digit_a){
                    return false;
                }

                if(contents_a != contents_b){
                    return contents_a < contents_b;
                }

                return id_a < id_b;
            }
        );
    
        return logs;
    }
}
