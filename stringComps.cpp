#include "stringComps.h"

namespace stringComps {

double stringComps::levDist(const std::string& s1, const std::string& s2){
    // Levenstein Distance
    int distance;
    
    const size_t len1 = s1.size(), len2 = s2.size();
    std::vector<std::vector<int>> dp(2, std::vector<int>(len2 + 1));
    
    for (size_t j = 0; j <= len2; ++j) {
        dp[0][j] = j;
    }

    for (size_t i = 1; i <= len1; ++i) {
        dp[i % 2][0] = i;
        int minVal = dp[i % 2][0];

        for (size_t j = 1; j <= len2; ++j) {
            dp[i % 2][j] = std::min({
                dp[(i - 1) % 2][j] + 1,
                dp[i % 2][j - 1] + 1,
                dp[(i - 1) % 2][j - 1] + (s1[i - 1] != s2[j - 1])
            });
            minVal = std::min(minVal, dp[i % 2][j]);
        }
    }
    distance = dp[len1 % 2][len2];
    int maxLength = std::max(s1.length(), s2.length());
    return (1.0 - double(distance) / maxLength);
}   

double stringComps::jaroWinkler(const std::string& s1, const std::string& s2){
    double distance = 0.0;
    int s1_len = s1.length();
    int s2_len = s2.length();
    int match_distance = std::max(s1_len, s2_len) / 2 - 1;
    int matches = 0;

    for (int i = 0; i < s1_len; i++) {
        for (int j = std::max(0, i - match_distance); j < std::min(s2_len, i + match_distance + 1); j++) {
            if (s1[i] == s2[j]) {
                matches++;
                break;
            }
        }
    }

    if (matches == 0) {
        return 0.0;
    }

    double t = 0.0;
    int k = 0;
    for (int i = 0; i < s1_len; i++) {
        if (s1[i] == s2[i]) {
            t++;
        }
        if (s1[i] != s2[i]) {
            break;
        }
    }

    for (int i = 0; i < s1_len; i++) {
        if (s1[i] == s2[i]) {
            k++;
        }
        if (s1[i] != s2[i]) {
            break;
        }
    }

    distance = (matches / s1_len + matches / s2_len + (matches - t) / matches) / 3.0;
    distance += k * 0.1 * (1 - distance);
    

    return distance;
}

std::map<char, int> calculateFrequencyVector(const std::string& str) {
    std::map<char, int> freqVector;
    for (char ch : str) {
        freqVector[ch]++;
    }
    return freqVector;
}

int dotProduct(const std::map<char, int>& vec1, const std::map<char, int>& vec2) {
    int dot = 0;
    for (const auto& pair : vec1) {
        char key = pair.first;
        if (vec2.find(key) != vec2.end()) {
            dot += pair.second * vec2.at(key);
        }
    }
    return dot;
}

double magnitude(const std::map<char, int>& vec) {
    double mag = 0.0;
    for (const auto& pair : vec) {
        mag += pair.second * pair.second;
    }
    return sqrt(mag);
}

double cosineSimilarity(const std::string& str1, const std::string& str2) {
    auto vec1 = calculateFrequencyVector(str1);
    auto vec2 = calculateFrequencyVector(str2);

    int dot = dotProduct(vec1, vec2);
    double mag1 = magnitude(vec1);
    double mag2 = magnitude(vec2);

    if (mag1 == 0 || mag2 == 0) {
        return 0; // To avoid division by zero
    }

    return static_cast<double>(dot) / (mag1 * mag2);
}

double stringComps::jaccardSim(const std::string& s1, const std::string& s2){
    // Jaccard Similarity
    double sim = 0.0;
    std::set<char> set1(s1.begin(), s1.end());
    std::set<char> set2(s2.begin(), s2.end());
    std::set<char> intersection;
    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(intersection, intersection.begin()));
    sim = static_cast<double>(intersection.size()) / (set1.size() + set2.size() - intersection.size());
    return sim;
}

std::string soundex(const std::string& s) {

    if (s.empty()) return "";

    std::string soundexStr;
    soundexStr += std::toupper(s[0]);
    std::map<char, char> soundexMap = {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };

    for (size_t i = 1; i < s.size(); ++i) {
        if (soundexMap.find(s[i]) != soundexMap.end()) {
            soundexStr += soundexMap[s[i]];
        }
    }

    return soundexStr;
}

int stringComps::soundexSim(const std::string& s1, const std::string& s2){
    // Soundex Similarity
    double sim = 0.0;
    std::string soundex1 = soundex(s1);
    std::string soundex2 = soundex(s2);
    sim = soundex1 == soundex2 ? 1 : 0;
    return sim;
}
}
