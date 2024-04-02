#pragma once
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <cctype> 

namespace stringComps {
    double levDist(const std::string&, const std::string&);
    double jaroWinkler(const std::string&, const std::string&);
    double cosineSimilarity(const std::string&, const std::string&);
    double jaccardSim(const std::string&, const std::string&);
    int soundexSim(const std::string&, const std::string&);
}