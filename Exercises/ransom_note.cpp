/*
Hackerrank exercise:

Suppose you want to write a ransom note by using individual letters cut out from a magazine. Your task is to write a function, where you are given two strings as input, one representing the magazine, and one representing the note. The function would return either True if it’s possible to create the note out of the content of the magazine, or False if not.

Example
Say you’re given the following magazine and note:

Magazine: "hello world"
Note: "role"
Returns: True
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool shouldExcludeCharacter(char c) {
  return c == ' ' && c == '\t' && c == '\n';
}

// O(N) + O(M)
bool canCreateNoteOptimized(const string& source, const string& target)
{
  unordered_map<char, uint> characters;
  for (auto it = target.begin(); it != target.end(); ++it) {
    const char c = *it;
    if (!shouldExcludeCharacter(c)) {
      ++characters[tolower(c)]; // initialized as 0 if not present
    }
  }

  for (auto it = source.begin(); it != source.end(); ++it) {
    const char c = *it;
    if (shouldExcludeCharacter(c)) {
      continue;
    }

    auto characterIt = characters.find(tolower(c));
    if (characterIt == characters.end()) {
      continue;
    }

    --characterIt->second;
    if (characterIt->second == 0) {
      characters.erase(characterIt);
      if (characters.empty()) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  const string magazine = "hello world";
  const string note = "rolex";
  // const string note = "role";

  const bool canBuildNote = canCreateNoteOptimized(magazine, note);

  cout << "source string: " << magazine << endl;
  cout << "target string: " << note << endl;
  cout << "can we build our ransom note?: " << (canBuildNote ? "YES!" : "no :(") << endl;

  return 0;
}
