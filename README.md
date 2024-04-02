# C++ stringComps Library

The `stringComps` library provides functions for calculating various string comparison metrics in C++. Below are the main functions available in this library.

## Functions

### `levDist(const std::string& s1, const std::string& s2)`

Calculates the Levenshtein distance between two strings, which measures the difference between them as the number of edits needed to transform one string into the other.

- **Parameters**
  - `s1`: The first string.
  - `s2`: The second string.
- **Returns**: The Levenshtein distance as a percentage where 100% is a perfect match.

### `jaroWinkler(const std::string& s1, const std::string& s2)`

Calculates the Jaro-Winkler similarity between two strings, which is a measure of similarity between two strings.

- **Parameters**
  - `s1`: The first string.
  - `s2`: The second string.
- **Returns**: A similarity score between 0.0 and 1.0, where 1.0 means an exact match.

### `cosineSimilarity(const std::string& s1, const std::string& s2)`

Calculates the cosine similarity between two strings based on the count of each character.

- **Parameters**
  - `s1`: The first string, represented as a vector of character frequencies.
  - `s2`: The second string, represented as a vector of character frequencies.
- **Returns**: The cosine similarity between the two strings as a double.

### `jaccardSim(const std::string& s1, const std::string& s2)`

Calculates the Jaccard similarity between two strings, which is the size of the intersection divided by the size of the union of the character sets.

- **Parameters**
  - `s1`: The first string.
  - `s2`: The second string.
- **Returns**: The Jaccard similarity score.

### `soundexSim(const std::string& s1, const std::string& s2)`

Compares two strings based on the Soundex algorithm.

- **Parameters**
  - `s1`: The first string.
  - `s2`: The second string.
- **Returns**: `1` if the Soundex codes of the two strings are equal, `0` otherwise.

## Usage

Include the `stringComps.h` header in your C++ project to use the functions:

```cpp
#include "stringComps.h"
```

Then call the functions as needed, for example:

```cpp
double sim = stringComps::levDist("hello", "hallo");
```

## Building

This library is written in standard C++ and can be built using any standard C++ compiler, such as g++, clang++, or MSVC.

## Contributions

Contributions to this library are welcome. Please submit pull requests to the repository or open issues for bugs and feature requests.

## License

Specify the license under which the library is released.

## Author

- **Author:** Nick Smith
- **Date:** 4.2.2024
