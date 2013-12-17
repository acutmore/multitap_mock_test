#ifndef MULTITAP_H
#define MULTITAP_H

int encode_character(char character, char *multitap);

char* find_character(char character, char *lookup_position);

char find_button_for_character(char *character, int &count);

void add_character_to_string(char character, char* &string, int count);

void encode(const char* plaintext, char* multitap);

#endif /* MULTITAP_H */
