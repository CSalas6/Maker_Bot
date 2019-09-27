
#include"lee.h"

/*
class Lee {
private:
  std::ifstream file_access;
  std::map<char, Indiv_char> markov_prefixes;
  std::map<std::string, Indiv_str> warkov_prefixes;
  Markov_chain Markov;
  Warkov_chain Warkov;
*/
  // FN: Read in from the file and generate an map<char, int> for Makrov's
  //  occurance_rate variable. (letter to letter comparisons)
  void Lee::populate_m_pre() {
    char pre = file_access.get();
    for (char suf = file_access.get(); file_access.good(); suf = file_access.get()) {
        m_fill(pre, suf);
        pre = suf;
    }
  }
  // Fn poulate_m_pre() helper function. Take inputs of "pre" and "suf" to
  // fill in the Markov prefix map accordingly
  void Lee::m_fill(char pre, char suf) {
      // If "pre" exists in the markov_prefixes map, else create and add it
    if (markov_prefixes[pre].find() != markov_prefixes.end() ){
      Indiv_char temp = markov_prefixes[pre];
      // If "suf" in the Indiv_char's "suffix" map then add one, else
      // create and add one it
      if (temp.suffix[suf].find() != temp.suffix.end() ) {
        temp.suffix[suf] += 1;
      } else {
        temp.suffix.insert(std::pair<char, unsigned int>(suf, 1) );
      }
      // Else continuation of line_26 If
    } else {
      Indiv_str temp;
      temp.designated_char = pre;
      temp.suffix.insert(std::pair<char, unsigned int>(suf, 1));
      markov_prefixes.insert(std::pair<char, Indiv_char>(pre, temp));
    }
  }
  // FN: Read in from the file and generate an map<string, int> for Wakrov's
  //  occurance_rate variable. (Word to word comparisons)
  void Lee::populate_w_pre() {
    std::string pre = "", suf = "";
    for (char LetterA = file_access.get(); file_access.good(); suf = file_access.get()) {
      suf = suf + LetterA;
      // If letter at file_access.get is a space then run w_fill
      if (std::isspace(LetterA) ) {
        // If "pre" has been set, run w_fill
        if (pre != "") {
          w_fill(pre, suf);
        }
        pre = suf;
        suf = "";
      }
    }
  }
  // Fn poulate_w_pre() helper function. Take inputs of "pre" and "suf" to
  // fill in the Warkov prefix map accordingly
  void Lee::w_fill(std::string pre, std::string suf) {
     // If "pre" exists in the markov_prefixes map, else create and add it
    if (warkov_prefixes[pre].find() != warkov_prefixes.end() ){
      Indiv_str temp = warkov_prefixes[pre];
      // If "suf" in the Indiv_str's "suffix" map then add one, else
      // create and add one it
      if (temp.suffix[suf].find() != temp.suffix.end() ) {
        temp.suffix[suf] += 1;
      } else {
        temp.suffix.insert(std::pair<std::string, unsigned int>(suf, 1) );
      }
    } else {  // Else continuation of line_64 If
      Indiv_str temp;
      temp.designated_str = pre;
      temp.suffix.insert(std::pair<std::string, unsigned int>(suf, 1));
      markov_prefixes.insert(std::pair<char, Indiv_str>(pre, temp));
    }
  }
  // a private access to set the "file_access" variable
  void Lee::set_file_access(std::string in) {
    if ( file_access.open(in, std::ifstream::in) )
  }

  // Send the refrence of the markov_prefixes map to Markov
  void Lee::send_to_markov();
  // Send the refrence of the warkov_prefixes map to Markov
  void Lee::send_to_warkov();

  // constructors:
  // Default - does nothing
  Lee::Lee() {}
  // Populate Markov and Warkov obj in class with given "a" and "b"
  Lee::Lee(Markov_chain * a, Warkov_chain * b) {
    recieve_markov_obj(a);
    recieve_warkov_obj(b);
  }
  // Populate "file_access" variable with given "a"
  Lee::Lee(std::string a) {
    recieve_file(a);
  }
  // Populate "file_access" with "a"; Populate Markov and Warkov obj
  // with "b" and "c" respectively
  Lee::Lee(std::string a, Markov_chain * b, Warkov_chain * c) {
    recieve_file(a);
    recieve_markov_obj(b);
    recieve_warkov_obj(c);
  }
  // FN: public access to set the file_access variable
  void Lee::recieve_file(std::string in) {
    set_file_access(in);
  }
  // FN: set the object of Lee::Markov to the input
  void Lee::recieve_markov_obj(Markov_chain * in) {
    &Markov = in;
    &markov_prefixes = * (Markov.prefix);
  }
  // FN: set the object of Lee::Warkov to the input
  void Lee::recieve_warkov_obj(Warkov_chain * in) {
    &Warkov = in;
    &warkov_prefixes = * (Warkov.prefix);
  }
