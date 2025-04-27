#include "isogram.h"
#include <ctype.h>
#include <string.h>

bool is_isogram(const char phrase[]) {
  bool seen[26] = {false};
  char c;

  if (!phrase)
    return false;

  for (unsigned long i = 0; i < strlen(phrase); i++) {
    if (isalpha(phrase[i])) {
      c = tolower(phrase[i]);
      if (seen[c - 'a'])
        return false;
      seen[c - 'a'] = true;
    }
  }

  return true;
}
