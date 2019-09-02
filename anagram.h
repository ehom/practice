#ifndef ANAGRAM_H_INCLUDED
#define ANAGRAM_H_INCLUDED

#include <string>
#include <vector>
#include <unordered_map>

namespace anagram {
  typedef std::unordered_map<char,int> CharFreqTable;

  class anagram {
    public:
      anagram(const std::string& word);
      std::vector<std::string> matches(const std::vector<std::string>& list);
    private:
      std::string m_subject;
      CharFreqTable m_charFreqTable;
  };
}

#endif
