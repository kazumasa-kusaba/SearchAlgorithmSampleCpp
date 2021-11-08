#include <iostream>
#include <string>
#include <unordered_map>

int bm_search(const std::string& text, const std::string& pattern)
{
  std::unordered_map<char, int> skip_table;
  int i = 0;
  int j = 0;
  
  for (int i = 0; i < pattern.size(); i++) {
    skip_table[pattern[i]] = pattern.size() - i - 1;
  }

  i = pattern.size() - 1;

  while (i < text.size()) {
    j = pattern.size() - 1;

    while (text[i] == pattern[j]) {
      if (j == 0) {
        return i;
      }
      i--;
      j--;
    }

    int skip = skip_table.find(text[i]) != skip_table.end() ? skip_table.at(text[i]) : pattern.size();
    i += std::max(skip, (int)(pattern.size() - j));
  } 

  return -1;
}

int main(void)
{
  int ret = 0;
  std::string text;
  std::string pattern;

  std::cout << "Enter the text: ";
  std::cin >> text;

  std::cout << "Enter the pattern: ";
  std::cin >> pattern;

  ret = bm_search(text, pattern);
  if (ret == -1) {
    std::cout << "\"" << pattern << "\"" << " was not found in " << "\"" << text << "\"" << std::endl;
  } else {
    std::cout << "\"" << pattern << "\"" << " was found in the " << ret + 1 << "th letter of " << text << std::endl;
  }

  return 0;
}

