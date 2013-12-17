#include "multitap.h"
#include <cctype>

char lookup[] = "1.,!?2abc3def4ghi5jkl6mno7pqrs8tuv9wxyz0 ";

int encode_character(char character, char *multitap){
  int keystrokes = 0;

  if (isdigit(character)){
    *(multitap++) = '*';
    *(multitap++) = character;
    keystrokes = 2;
  }
  else {
    character = tolower(character);
    char* char_position = find_character(character, lookup);
    if (*char_position){
      int taps = 0;
      char button = find_button_for_character(char_position, taps);
      add_character_to_string(button, multitap, taps);
      keystrokes = taps;
    }
  }
  *(multitap) = '\0';
  return keystrokes;
}

char* find_character(char character, char *lookup_position){
  return ((*lookup_position == character) || !*lookup_position)?
    lookup_position : find_character(character, ++lookup_position);
}

char find_button_for_character(char *character, int &count){
  return (isdigit(*character))?
    *character : find_button_for_character(--character, ++count);
}

void add_character_to_string(char character, char* &string, int count){
  while (count-- > 0){
    *string = character;
    ++string;
  }
}

void encode(const char* plaintext, char* multitap){
  bool uppercase = false;
  for (;*plaintext;plaintext++){
    if (isalpha(*plaintext)){
      if (static_cast<bool>(isupper(*plaintext)) == !uppercase){
	  *(multitap++) = '#';
	  uppercase = !uppercase;
	}
    }
    char test[10];
    encode_character(*plaintext, test);
    if (*test == *(--multitap))
      *(++multitap) = '|';
    multitap++;
    int taps = encode_character(*plaintext, multitap);
    multitap = &multitap[taps];
  }
}
