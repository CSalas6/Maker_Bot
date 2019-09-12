#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<iostream>
#include<cctype>
#include<map>
#include<vector>
#include<string>

/*
// Base Structs to hold individual Char comparison
struct Comp_char {
  // the char characteriing this struct
  char char_compared_to;
  // numerical odds, greater than or equal to Zero
  unsigned int odds;
  // numerical odds in the form of a decimal, some value between 1 and 0
  unsigned float percent_odds;
}
*/

// Given an input int, return a random number between 0 and "size"
int mass_rand(int size);
// When called, return a random int between 1 and 100
int pert_rand();

// Base struct to hold letter
struct Indiv_char {
  // current char
  char designated_char;
  // map pair of char to num of occurances, for next following char
  std::map<char, unsigned int> suffix;
  // map pair of char to odds of appearce out of 100
  std::map<char, int> appearance_rate;
  // a list of chars corresponding to the number rolled; ie if 42 is rolled then pull 42nd char
  std::vector<char> odds;
  // total number of comaprisons made- confidence
  unsigned int total_comparisons;
  // Size of the map
  unsigned int links;
};

// Markov chain explicitly for the use of letters
class Markov_chain {

  private:

    // Series is a 101 length array, made in construct
    std::map<char, Indiv_char> prefix;
    // List chars, same order as prefixes
    std::vector<char> set_vector;

    // FN: determine odds of char; used in fn: read_set()
    unsigned int get_odds(char map_letter, char querry_char);
    void set_odds(char map_letter, char querry_char, unsigned int update);

    // FN: recurrsive support to "word_building" FN in public
    std::string build_word(char runner);

// Given a letter, make a vector of suffixes corresponding to the
//  percent chance * 100; if a certain char has a 26% chance of being
//  the suffix then, in the vector there will be 26 copies of that same
//  letter
void Make_odd_series(char in);

  public:
    // FN:
    Markov_chain();

    // FN: make a single word; end with a whitespace
    std::string word_building(char start_letter);
    // FN: provide a char, return the most likely char
    char return_char(char querry_letter);
    // FN: same as "return_char" but is random
/***************************/
// see Flur file
    // FN: populate data with saved data
//WIP    void read_saved_set;
// see Flur file
    // FN: recieve message from anther function
void recieve_mssg(int i_in, char c_in, int flags);
// FN: recieve request for map of data
std::map<char, unsigned int> write_request(char c_in)


};
