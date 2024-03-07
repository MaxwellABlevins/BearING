#include <string>

/*
 * is_vowel
 *
 * Checks if the current character under the reading head is a vowel.
 *
 * input: Character
 * output: True if it is a vowel, false if it is not.
 */

bool is_vowel(char p) {
	if (p == 'a' || p == 'e' || p == 'i' || p == 'o' || p == 'u') {
		return true;
	}
	else {
		return false;
	}
}

/*
 * is_consonant
 *
 * Checks if the current character under the reading head is a consonant.
 *
 * input: Character
 * output: True if it is a consonant, false if it is not.
 */

bool is_consonant(char p) {
	if (p == 'a' || p == 'e' || p == 'i' || p == 'o' || p == 'u') {
		return false;
	}
	else {
		return true;
	}
}

/*
 * ends_with_double_consonant
 *
 * Check if the word ends with a double consonant.
 *
 * input: String
 * output: True if it ends with a double consonant, false if it does not.
 *
 * If the string is shorter than 2 characters, the function returns false.
 */

bool ends_with_double_consonant(std::string str) {
	if (str.length() < 2) {
		return false;
	}
	else {
		if (is_consonant(str[str.length() - 1]) && str[str.length() - 1] == str[str.length() - 2]) {
			return true;
		}
		else {
			return false;
		}
	}
}

/*
 * ends_with_cvc
 *
 * Check if the word ends with a consonant-vowel-consonant pattern.
 *
 * input: String
 * output: True if it ends with a consonant-vowel-consonant pattern, false if it does not.
 * 
 * If the string is shorter than 3 characters, the function returns false.
 */

bool ends_with_cvc(std::string str) {
	if (str.length() < 3) {
		return false;
	}
	else {
		if (is_consonant(str[str.length() - 1]) && is_vowel(str[str.length() - 2]) && is_consonant(str[str.length() - 3])) {
			return true;
		}
		else {
			return false;
		}
	}
}

/*
 * contains_vowel
 *
 * Check if the word contains a vowel.
 *
 * input: String
 * output: True if it contains a vowel, false if it does not.
 */

bool contains_vowel(std::string str) {
	for (int i = 0; i < str.length(); i++) {
		if (is_vowel(str[i])) {
			return true;
		}
	}
	return false;
}

/*
 * count_consonants_at_front
 *
 * Count the number of consecutive consonants at the start of the string.
 *
 * input: string
 * output: Number of consecutive consonants at the start of the string.
 * 
 * Uses is_consonant to determine whether a character is a consonant.
 */

int count_consonants_at_front(std::string str) {
	int count = 0;
	for (int i = 0; i < str.length(); i++) {
		if (is_consonant(str[i])) {
			count++;
		}
		else {
			break;
		}
	}
	return count;
}

/*
 * count_vowels_at_back
 *
 * Count the number of consecutive vowels at the end of the string.
 *
 * input: String
 * output: Number of consecutive vowels at the end of the string.
 * 
 * Uses is_vowel to determine whether a character is a vowel. If the string is shorter than 1 character, the function returns 0.
 */

int count_vowels_at_back(std::string str) {
	int count = 0;
	for (int i = str.length() - 1; i >= 0; i--) {
		if (is_vowel(str[i])) {
			count++;
		}
		else {
			break;
		}
	}
	return count;
}

/*
 * ends_with
 *
 * Checks if a word's and a suffix's strings are empty, and if not, checks if the word is empty and if the suffix is not empty. Finally, checks if the word ends with the suffix.
 *
 * input: Two strings. The word and the suffix.
 * output: Firstly, returns false if suffix is longer than word. True if both strings are empty, false if the word is empty and the suffix is not, and true if the word ends with the suffix.
 * 
 * False if none of the conditions are met.
 */


bool ends_with(std::string candidate, std::string suffix) {
	if (suffix.length() > candidate.length()) {
		return false;
	}
	else if (candidate.length() == 0 && !suffix.length() == 0) {
		return false;
	}
	else if (candidate.length() == 0 && suffix.length() == 0) {
		return true;
	}
	else {
		for (int i = 0; i < suffix.length(); i++) {
			if (candidate[candidate.length() - suffix.length() + i] != suffix[i]) {
				return false;
			}
		}
		return true;
	}
}


/*
 * new_ending
 *
 * Creates a new string from the candidate string by removing the last suffix.length() characters and appending the new suffix.
 *
 * input: A string, a number, a string named candidate, the suffix length, and replacement in that order.
 * output: Returns the new word.
 * 
 * Assume suffix length is always less than or equal to the length of the candidate. If the candidate is empty, the function returns an empty string.
 */

std::string new_ending(std::string word, int num, std::string candidate, int suffix_length, std::string replacement) {
	if (candidate.length() == 0) {
		return "";
	}
	else {
		std::string new_word = candidate.substr(0, candidate.length() - suffix_length);
		new_word += replacement;
		return new_word;
	}
}


