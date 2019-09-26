#include"warkov.h"

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
Warkov_chain::Warkov_chain() {}

// Provided the letter in the map and the prefix's suffix, return the unsigned int "odds"
// contained in the map suffix
unsigned int Warkov_chain::get_odds(std::string map_str, std::string querry_str) {
  // if the desired obj exists(prefix's suffix), then return the int contained
  if ( (prefix[map_str]).suffix[querry_str] ) {
    return ( ( (prefix[map_str]).suffix[querry_str]).appearance_rate[querry_str]);
    // otherwise return zero, for "no" odds/ impossible
  } else {
    return 0;
  }
}

/**/

void Warkov_chain::set_odds(std::string map_str, std::string querry_str, unsigned int update) {
  // If the map prefix exists
  if(prefix.find(map_str) != prefix.end() ) {
    Indiv_str temp = prefix[map_str];

    // check to see if corresponding suffix exists; if so then change it to "update"
    if ( temp.suffix[querry_str] ) {
      int K = temp.suffix[querry_str];
      int J = temp.total_comparisons - K;
      temp.total_comparisons = J + update;

      // if the corresponding suffix does not exist; create and set it
    } else {
      (temp.suffix).insert(std::pair<std::string, unsigned int>(querry_str, update) );
      temp.total_comparisons = temp.total_comparisons + update;
      temp.links = temp.links + 1;
    }
    // update the changed Indiv_str struct into the "prefix" map
    prefix[map_str] = temp;

    // if the map prefix does not exist, create and set it
  } else {

    // create Indiv_str struct for the new insert
    Indiv_str temp;
    (temp.suffix).insert(std::pair<char, unsigned int>(querry_str, update) );
    temp.designated_str = map_str;
    temp.total_comparisons = update;
    temp.links = 1;
    if (querry_str[querry_str.length() - 1] == '\n') {
      temp.is_endcard = true;
    }

    // insert the new pair into the "prefix" map & update the "set_vector"
    prefix.insert(std::pair<std::string, Indiv_str>(map_str, temp) );
    set_vector.push_back(map_str);
  }

}

/**/
// Given a letter, make a vector of suffixes corresponding to the
//  percent chance * 100; if a certain char has a 26% chance of being
//  the suffix then, in the vector there will be 26 copies of that same
//  letter
void Warkov_chain::Make_odd_series(std::string in) {
// only run FN if in the prefix[]
if (prefix[in].find() != prefix.end() ) {
  // create/ assign objs as needed
  Indiv_str temp = prefix[in];
  std::vector<std::string> return_obj;
  // Clear the appearance rate map to be reset
  temp.appearance_rate.clear();
  temp.odds.clear();
  // make a map.iterator then go through the suffix map one by one
  for (std::map<std::string, unsigned int>::iterator it = temp.suffix.begin();
      it != temp.suffix.end(); it++) {
    // determine perecnt chance of occurance by dividing suffix's numerical occurance
    //  count by the total # occurances; then multiply by 100
    float K = it->second / temp.total_comparisons;
    int J = K * 100;
   // assign appropriate set to appearance_rate
   temp.appearance_rate.insert(std::pair<std::string, int>(it->first, J));
   // populate the temp.odds vector with a temp vector
    while(J > 0) {
      return_obj.push_back( it->first );
      J--;
    }
  }
  // set the temp vector to the temp.odds one
  temp.odds = return_obj;
  }
}

/**/
//  FN: begin recursive FN "build_word", ends on a whitespace
std::string Warkov_chain::line_building(std::string start_str) {
  return build_word(start_str);
}

/**/
//  FN: recursive fn to start making a word letter by letter
std::string Warkov_chain::build_line(std::string runner) {
std::string return_obj = "";
Indiv_str temp = prefix[runner]

  // if the runner is a whitespace, then pass the "runner" as is
  if ( temp.is_endcard ) {
    return_obj = return_obj + runner;
    // end recurssion

    // If the runner is not a whitespace, then find the next one and recurrse
  } else {
    // return a random number between 0 and size of the vector "V" as "T"
    int T = mass_rand(temp.odds.size() );
    // using the random number, pull it's "odds" vector to pull from
    std::string R = temp.odds[T]
    // Build the string "return_obj" wih the randomly chosen letter and call
    //    the function recurssively to get the next letter;
    return_obj = R + build_line(temp.odds[T]);
    // recurse
  }
  return return_obj;
}
/**/
// Provide a string and return the most likely string
std::string return_str(std::string querry_str) {
// if the char exists in Warkov's stored data
if (prefix.find(querry_str) != prefix.end) {
  // temp variables
  // for length of odds, count number of same char
  Indiv_str temp = prefix[querry_letter];
  std::string current; // check moment by moment
  std::string largest; // last char
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
}
return check;
}else {
// error; desired char not in saved data
// unreliable error response, but it is one
return "0";
}
}
// public FN, to take in inputs to add to data collection
void Warkov::recieve_mssg(int i_in, std::string s_in, str::string check, int flags) {
  switch (flags) {
    case 0: // new input, put into class accordingly; only ever at starting up
      // check is not in the prefix map
        if(prefix.find(map_str) == prefix.end() ) {
            Indiv_str temp;
            temp.designated_str = check;
            (temp.suffix).insert(std::pair<std::string, unsigned int>(c_in, i_in));
            prefix.insert(std::pair<std::string, Indiv_str>(check, s_in) );
            // Check is already in the prfix map
          } else {
        Indiv_str temp = prefix[check];
        (temp.suffix).insert(std::pair<std::string, unsigned int>(c_in, i_in));
        }
        break;
    case 1: // Update required, check.suffix[c_in] != i_in or add to map after
            // staring up
        set_odds(check, s_in, i_in);
        break;
        case 2: // Update required, check.suffix[c_in] != i_in or add to map after
                // staring up AND remake the odd_series
            set_odds(check, s_in, i_in);
            recieve_mssg(0, "", check, 3);
            break;
                case 3:
        Make_odd_series(check);
        break;
    default:
        break;
  }
}
// other recieve_mssg function to insted take in a prefix[] object
void Warkov::recieve_mssg(std::string s_in, Indiv_str IS_in) {
  // if prefix does not exist, fill it with the Indiv_str
  if (prefix[s_in].find() == prefix.end() ) {
    prefix.insert(std::pair<std::string, Indiv_str>(s_in, IS_in) );
    Make_odd_series(s_in);
  } else {
    // If the prefix does exist then add all the new values to the prefix map
    in_indiv_str_fix(IS_in);
    Make_odd_series(s_in);
  }
}
// recieve_mssg(string, Indiv_str) Helper function. Progressively move through
// the Indiv_str to update each Indiv_str.suffix set
void Warkov::in_indiv_str_fix(Indiv_str IS_in) {
  for (std::map<std::string, unsigned int>::iterator it = IS_in.suffix.begin();
      it != IS_in.suffix.end(); it++) {
        set_odds(IS_in.designated_str, it.first(), it.second());
      }
}
// public FN, recieves a char that is used to pull the corresponding suffic
// list from
std::map<char, unsigned int> write_request(std::string s_in) {
  return prefix[s_in].suffix;
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
