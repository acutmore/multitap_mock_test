#ifndef MULTITAP_H
#define MULTITAP_H

// For a char 'character', determine the phone keypad strokes necessary
int encode_character(char character, char *multitap);

// Returns the position of character in lookup_position (recursively)
char* find_character(char character, char *lookup_position);

// Returns the relevant button to be pressed, e.g. '2', for character, with count
// the number of times the button needs to be pressed.
char find_button_for_character(char *character, int &count);

void add_character_to_string(char character, char* &string, int count);

void encode(const char* plaintext, char* multitap);

#endif /* MULTITAP_H */
