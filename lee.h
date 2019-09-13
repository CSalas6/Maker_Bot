// Lee will work on the decoding of other code files to create a database for
// use by Markov and Warkov respectively.

class Lee {
private:
  std::ifstream file_access;
  std::map<char, Indiv_char> markov_prefixes;
  std::map<std::string, Indiv_str> warkov_prefixes;
  Markov_chain Markov;
  Warkov_chain Warkov;

  // FN: Read in from the file and generate an occurance rate in map form
  //  for use by Markov, letter comparisons to one-another
  void populate_m_pre();
  // FN: Read in from the file and generate an occurance rate in map form
  //  for use by Warkov, word by word comparisons
  void populate_w_pre();
  // a private access to set the file_access variable
  void set_file_access(std::string in);

  // Send the refrence of the markov_prefixes map to Markov
  void send_to_markov();
  // Send the refrence of the warkov_prefixes map to Markov
  void send_to_warkov();

public:
  // constructors
  Lee(); Lee(Markov_chain * a, Warkov_chain * b);
  Lee(std::string a); Lee(std::string a, Markov_chain * a, Warkov_chain * b);
  // FN: public access to set the file_access variable
  void recieve_file(std::string in) {set_file_access(in);}
  // FN: set the object of Lee::Markov to the input
  void recieve_markov_obj(Markov_chain * in);
  // FN: set the object of Lee::Warkov to the input
  void recieve_warkov_obj(Warkov_chain * in);
};
