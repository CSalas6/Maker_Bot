#include"markov.h"

/**/
// provided some int, generate a random num between Zero and "size"
int mass_rand(int size) {
  return ( rand() % size );
}
/**/
int pert_rand() {
  return ( (rand() + 1) % 100 );
}
/*
 *************************
 */
Markov_chain::Markov_chain() {}

// Provided the letter in the map and the prefix's suffix, return the unsigned int "odds"
// contained in the map suffix
unsigned int Markov_chain::get_odds(char map_letter, char querry_char) {
  // if the desired obj exists(prefix's suffix), then return the int contained
  if ( (prefix[map_letter]).suffix[querry_char] ) {
    return ( ( (prefix[map_letter]).suffix[querry_char]).appearance_rate[querry_char]);
    // otherwise return zero, for "no" odds/ impossible
  } else {
    return 0;
  }
}

/**/

void Markov_chain::set_odds(char map_letter, char querry_char, unsigned int update) {
  // If the map prefix exists
  if(prefix.find(map_letter) != prefix.end() ) {
    Indiv_char temp = prefix[map_letter];

    // check to see if corresponding suffix exists; if so then change it to "update"
    if ( temp.suffix[querry_char] ) {
      int K = temp.suffix[querry_char];
      int J = temp.total_comparisons - K;
      temp.total_comparisons = J + update;

      // if the corresponding suffix does not exist; create and set it
    } else {
      (temp.suffix).insert(std::pair<char, unsigned int>(querry_char, update) );
      temp.total_comparisons = temp.total_comparisons + update;
      temp.links = temp.links + 1;
    }
    // update the changed Indiv_char struct into the "prefix" map
    prefix[map_letter] = temp;

    // if the map prefix does not exist, create and set it
  } else {

    // create Indiv_char struct for the new insert
    Indiv_char temp;
    (temp.suffix).insert(std::pair<char, unsigned int>(querry_char, update) );
    temp.designated_char = map_letter;
    temp.total_comparisons = update;
    temp.links = 1;

    // insert the new pair into the "prefix" map & update the "set_vector"
    prefix.insert(std::pair<char, Indiv_char>(map_letter, temp) );
    set_vector.push_back(map_letter);
  }

}

/**/
// Given a letter, make a vector of suffixes corresponding to the
//  percent chance * 100; if a certain char has a 26% chance of being
//  the suffix then, in the vector there will be 26 copies of that same
//  letter
void Markov_chain::Make_odd_series(char in) {
  // create/ assign objs as needed
  Indiv_char temp = prefix[in];
  std::vector<char> return_obj;
  // Clear the appearance rate map to be reset
  temp.appearance_rate.clear();
  temp.odds.clear();
  // make a map.iterator then go through the suffix map one by one
  for (std::map<char, unsigned int>::iterator it = temp.suffix.begin();
      it != temp.suffix.end(); it++) {
    // determine perecnt chance of occurance by dividing suffix's numerical occurance
    //  count by the total # occurances; then multiply by 100
    float K = it->second / temp.total_comparisons;
    int J = K * 100;
   // assign appropriate set to appearance_rate
   temp.appearance_rate.insert(std::pair<char, int>(it->first, J));
   // populate the temp.odds vector with a temp vector
    while(J > 0) {
      return_obj.push_back( it->first );
      J--;
    }
  }
  // set the temp vector to the temp.odds one
  temp.odds = return_obj;
}


/**/
//  FN: begin recursive FN "build_word", ends on a whitespace
std::string Markov_chain::word_building(char start_letter) {
  return build_word(start_letter);
}

/**/
//  FN: recursive fn to start making a word letter by letter
std::string Markov_chain::build_word(char runner) {
std::string return_obj = "";
Indiv_char temp = prefix[runner];

  // if the runner is a whitespace, then pass the "runner" as is
  if ( std::isspace(runner) ) {
    return_obj = return_obj + runner;
    // end recurssion

    // If the runner is not a whitespace, then find the next one and recurrse
  } else {
    // return a random number between 0 and size of the vector "V" as "T"
    int T = mass_rand(temp.odds.size() );
    // using the random number, pull it's "odds" vector to pull from
    char R = temp.odds[T]
    // Build the string "return_obj" wih the randomly chosen letter and call
    //    the function recurssively to get the next letter;
    return_obj = R + build_word(temp.odds[T]);
    // recurse
  }
  return return_obj;
}
/**/
// Provide a char and return the most likely char
char return_char(char querry_letter) {
// if the char exists in Markov's stored data
if (prefix.find(querry_letter) != prefix.end) {
  // temp variables
  Indiv_char temp = prefix[querry_letter];
  char current; // check moment by moment
  char largest; // last char
  int check = 0; // char with greatest liekely hood
  // for length of odds, count number of same char
  for (std::map<char, int>::iterator it = temp.appearance_rate.begin(); it !=
      temp.appearance_rate.end(); i++) {
    if (temp.appearance_rate[it]->second > check) {
      largest = temp.appearance_rate[it]->first;
      check = temp.appearance_rate[it]->second;
    }
  }
}
return check;
}else {
// error; desired char not in saved data
// unreliable error response, but it is one
return '0';
}
}
// public FN, to take in inputs to add to data collection
void markov::recieve_mssg(int i_in, char c_in, char check, int flags) {
  switch (flags) {
    case 0: // new input, put into class accordingly
        Indiv_char temp = prefix[check];
        (temp.suffix).insert(std::pair<char, int>(c_in, i_in));
        break;
    case 1: // Update required, check.suffix[c_in] != i_in
        set_odds(check, c_in, i_in);
        Make_odd_series(check)
        break;
    case 2: // temp
        break;
    default:
        break;
  }
}
void Markov::recieve_mssg(char c_in, Indiv_char IC_in) {
  // if prefix does not exist, fill it with the Indiv_str
  if (prefix[c_in].find() == prefix.end() ) {
    prefix.insert(std::pair<char, Indiv_char>(c_in, IC_in) );
    Make_odd_series(c_in);
  } else {
    // If the prefix does exist then add all the new values to the prefix map
    in_indiv_char_fix(IC_in);
    Make_odd_series(c_in);
  }
}
// recieve_mssg(string, Indiv_str) Helper function. Progressively move through
// the Indiv_str to update each Indiv_str.suffix set
void Markov::in_indiv_char_fix(Indiv_char IC_in) {
  for (std::map<char, unsigned int>::iterator it = IC_in.suffix.begin();
      it != IC_in.suffix.end(); it++) {
        set_odds(IC_in.designated_str, it.first(), it.second());
      }
}
// public FN, recieves a char that is used to pull the corresponding suffic
// list from
std::map<char, unsigned int> write_request(char c_in) {
  return prefix[c_in].suffix;
}










/*

//The main method
int main(void)
{
int nwords = MAXGEN;
Prefix prefix; // current input prefix
for (int i = 0; i < NPREF; i++)
add(prefix, NONWORD);
build(prefix, cin);
add(prefix, NONWORD);
generate(nwords);
return 0;
}

//The build function
// build: read input words, build state table
void build(Prefix& prefix, istream& in)
{
string buf;
while (in >> buf)
add(prefix, buf);
}

//The add function
// add: add word to suffix deque, update prefix
void add(Prefix& prefix, const string& s)
{
if (prefix.size() == NPREF) {
statetab[prefix].push_back(s);
prefix.pop_front();
}
prefix.push_back(s);
}

//The generate function
// generate: produce output, one word per line
void generate(int nwords)
{
Prefix prefix;
int i;
for (i = 0; i < NPREF; i++)
add(prefix, NONWORD);
for (i = 0; i < nwords; i++) {
vector<string>& suf = statetab[prefix];
const string& w = suf[rand() % suf.size()];
if (w == NONWORD)
break;
cout << w << "\n";
prefix.pop_front(); // advance
prefix.push_back(w);
}
}

 */
