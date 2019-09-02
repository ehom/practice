#include "anagram.h"

#include <cctype>
#include <algorithm>

namespace anagram {

  // private namespace
  // not publicized in the header

  namespace {
    CharFreqTable createCharFreqTable(const std::string& word)
    {
      CharFreqTable charFreqTable;

      for (char ch: word) {
        auto search_iterator = charFreqTable.find(ch);
        if (search_iterator == charFreqTable.end()) {
          charFreqTable[ch] = 1; 
        } else {
          search_iterator->second++; 
        }
      }
      return charFreqTable;
    }

    std::string strToUpper(std::string input)
    {
      std::transform(input.begin(), input.end(), 
        input.begin(), 
        [](unsigned char c){ return std::toupper(c); });

      return input;
    }
  } // end-namespace

  anagram::anagram(const std::string& word)
  {
    m_subject       = strToUpper(word);
    m_charFreqTable = createCharFreqTable(m_subject); 
  }

  std::vector<std::string> anagram::matches(const std::vector<std::string>& word_list)
  {
    std::vector<std::string> results;
    CharFreqTable charFreqTable;

    for (auto& word: word_list) {
      std::string upperCasedString = strToUpper(word);

      if (m_subject.compare(upperCasedString) == 0) continue;

      charFreqTable = createCharFreqTable(upperCasedString);

      if (m_charFreqTable == charFreqTable) {
        results.push_back(word);
      }
    }
    return results;
  }
}
