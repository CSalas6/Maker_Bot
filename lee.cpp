
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
  // FN: Read in from the file and generate an occurance rate in map form
  //  for use by Markov, letter comparisons to one-another
  void Lee::populate_m_pre() {
    char pre = file_access.get();
    for (char suf = file_access.get(); file_access.good(); suf = file_access.get()) {
      { // seperate zone
        m_fill(pre, suf);
        pre = suf;
      }
    }
  }
  // Fn poulate_m_pre() helper function. Take inputs of "pre" and "suf" to
  // fill in the Markov prefix map accordingly
  void Lee::m_fill(char pre, char suf) {
    if (markov_prefixes[pre].find() != markov_prefixes.end() ){
      Indiv_char temp = markov_prefixes[pre];
      if (temp.suffix[suf].find() != temp.suffix.end() ) {
        temp.suffix[suf] += 1;
      } else {
        temp.suffix.insert(std::pair<char, unsigned int>(suf, 1) );
      }
    } else {
      Indiv_str temp;
      temp.designated_char = pre;
      temp.suffix.insert(std::pair<char, unsigned int>(suf, 1));
      markov_prefixes.insert(std::pair<char, Indiv_char>(pre, temp));
    }
  }
  // FN: Read in from the file and generate an occurance rate in map form
  //  for use by Warkov, word by word comparisons
  void Lee::populate_w_pre() {
    std::string pre = "", suf = "";
    for (char LetterA = file_access.get(); file_access.good(); suf = file_access.get()) {
      suf = suf + LetterA;
      if (std::isspace(LetterA) ) {
        if (pre != "") {
          w_fill(pre, suf);
        }
        pre = suf;
        suf = "";
      }
    } // end of For loop
  }
  // Fn poulate_w_pre() helper function. Take inputs of "pre" and "suf" to
  // fill in the Warkov prefix map accordingly
  void Lee::w_fill(std::string pre, std::string suf) {
    if (warkov_prefixes[pre].find() != warkov_prefixes.end() ){
      Indiv_str temp = warkov_prefixes[pre];
      if (temp.suffix[suf].find() != temp.suffix.end() ) {
        temp.suffix[suf] += 1;
      } else {
        temp.suffix.insert(std::pair<std::string, unsigned int>(suf, 1) );
      }
    } else {
      Indiv_str temp;
      temp.designated_str = pre;
      temp.suffix.insert(std::pair<std::string, unsigned int>(suf, 1));
      markov_prefixes.insert(std::pair<char, Indiv_str>(pre, temp));
    }
  }
  // a private access to set the file_access variable
  void Lee::set_file_access(std::string in) {
    if ( file_access.open(in, std::ifstream::in) )
  }

  // Send the refrence of the markov_prefixes map to Markov
  void Lee::send_to_markov();
  // Send the refrence of the warkov_prefixes map to Markov
  void Lee::send_to_warkov();

  // constructors
  Lee::Lee() {}
  Lee::Lee(Markov_chain * a, Warkov_chain * b) {
    recieve_markov_obj(a);
    recieve_warkov_obj(b);
  }
  Lee::Lee(std::string a) {
    recieve_file(a);
  }
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
