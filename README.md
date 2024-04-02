# C++ stringComps Library

The `stringComps` library provides functions for calculating various string comparison metrics in C++. Below are the main functions available in this library.

## Functions

### `levDist(string s1, string s2)`

Calculates the Levenshtein distance between two strings, which measures the difference between them as the number of edits needed to transform one string into the other.

**Function:** ```cpp
levDist(const std::string& s1, const std::string& s2)```
- **Parameters**
  - `s1`: The first string.
  - `s2`: The second string.
- **Returns**: The Levenshtein distance as a percentage where 100% is a perfect match.

### `jaroWinkler(string s1, string s2)`

Calculates the Jaro-Winkler similarity between two strings, which is a measure of similarity between two strings.

**Function:** ```cpp
jaroWinkler(const std::string& s1, const std::string& s2)```
- **Parameters**
  - `s1`: The first string.
  - `s2`: The second string.
- **Returns**: A similarity score between 0.0 and 1.0, where 1.0 means an exact match.

### `cosineSimilarity(string s1, string s2)`

Calculates the cosine similarity between two strings based on the count of each character.

**Function:** ```cpp
cosineSimilarity(const std::string& s1, const std::string& s2)```
- **Parameters**
  - `s1`: The first string, represented as a vector of character frequencies.
  - `s2`: The second string, represented as a vector of character frequencies.
- **Returns**: The cosine similarity between the two strings as a double.

### `jaccardSim(string s1, string s2)`

Calculates the Jaccard similarity between two strings, which is the size of the intersection divided by the size of the union of the character sets.

**Function:** ```cpp
jaccardSim(const std::string& s1, const std::string& s2)```
- **Parameters**
  - `s1`: The first string.
  - `s2`: The second string.
- **Returns**: The Jaccard similarity score.

### `soundexSim(string s1, string s2)`

**Function:** ```cpp
soundexSim(const std::string& s1, const std::string& s2)```
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

## Mathematics Behind `stringComps` Functions

### Levenshtein Distance (`levDist`)
Levenshtein distance measures the minimum number of single-character edits (insertions, deletions, or substitutions) required to change one string into the other.

Mathematically, it can be represented as:
- Let `s1` and `s2` be two strings with lengths `n` and `m`.
- `levDist(i, j)` is the Levenshtein distance between the first `i` characters of `s1` and the first `j` characters of `s2`.
- The distance can be calculated using the following recursive formula:

  ```
  levDist(i, j) = 
      | 0                           if i = 0 and j = 0
      | i                           if j = 0
      | j                           if i = 0
      | levDist(i - 1, j - 1)       if s1[i] = s2[j]
      | 1 + min(levDist(i - 1, j),  // Deletion
               levDist(i, j - 1),  // Insertion
               levDist(i - 1, j - 1))  // Substitution otherwise
  ```

### Jaro-Winkler Similarity (`jaroWinkler`)
The Jaro-Winkler similarity is a measure of similarity between two strings, giving more favor to strings that match from the beginning.

For two strings `s1` and `s2`, the Jaro similarity `jaro(s1, s2)` is defined as:

```
jaro(s1, s2) = 1 / 3 * (m / |s1| + m / |s2| + (m - t) / m)
```
where:
- `|s1|` and `|s2|` are the lengths of `s1` and `s2`,
- `m` is the number of matching characters,
- `t` is the number of transpositions (half the number of matching characters that are in a different order).

Jaro-Winkler similarity introduces a prefix scale `p` for a common prefix length `l` up to a maximum of 4 characters:
```
jaroWinkler(s1, s2) = jaro(s1, s2) + l * p * (1 - jaro(s1, s2))
```

### Cosine Similarity (`cosineSimilarity`)
Cosine similarity measures the cosine of the angle between two vectors. In the context of strings, each character's frequency can represent vector dimensions.

For strings `s1` and `s2` represented as vectors `v1` and `v2`:

```
cosineSimilarity(s1, s2) = dot(v1, v2) / (||v1|| * ||v2||)
```
where:
- `dot(v1, v2)` is the dot product of `v1` and `v2`,
- `||v1||` and `||v2||` are the magnitudes (Euclidean norms) of `v1` and `v2`.

### Jaccard Similarity (`jaccardSim`)
Jaccard similarity is a measure of how similar two sets are, defined as the size of their intersection divided by the size of their union.

For two strings `s1` and `s2`:

```
jaccardSim(s1, s2) = |s1 ∩ s2| / |s1 ∪ s2|
```
where `|s1 ∩ s2|` is the count of unique common characters, and `|s1 ∪ s2|` is the count of unique characters in both strings.

### Soundex Similarity (`soundexSim`)
Soundex is a phonetic algorithm that indexes words by their sound when pronounced in English. The similarity is binary, typically considered 1 if the Soundex codes of both strings are the same and 0 otherwise.

For two strings `s1` and `s2`:
```
soundexSim(s1, s2) = 1 if soundex(s1) = soundex(s2)
                   = 0 otherwise
```
where `soundex(s)` is the Soundex code of string `s`.

Each of these functions encapsulates a different approach to measuring how strings relate to each other, be it through literal character edits, phonetic similarity, or statistical representation as vectors.

## Building

This library is written in standard C++ and can be built using any standard C++ compiler, such as g++, clang++, or MSVC.

## Contributions

Contributions to this library are welcome. Please submit pull requests to the repository or open issues for bugs and feature requests.

## Author

- **Author:** Nick Smith
- **Date:** April 2<sup>nd</sup>, 2024
