// Flur will be tasked with explicitly reading from the save file and sending it off to Markov's save file
#include"Flur.h"
// include files, idk what will be here yet, but there will be a lot of them

/*****************************************/
#include"Flur.h"

 Flur::Flur() {  // constructors, the INT is for any special start conditions
  file_name = "";
  line_counter = 0;
  step_counter = 0;
  line_holder = "":
}

Flur::Flur(int a) {
  file_name = "";
  line_counter = a;
  step_counter = 0;
  line_holder = "":
}

 void FLur::FlursAffection() { // activate all the helper functions until the file has been read through

  while (file_in != EOF) {
    MessageMarkov(1); // tell markov there is a new line
    ParseFile();
    ParseLine(); // sperate the line into an array & send it to markov
    }
  }

 void FLur::ParseFile() { // use the 'file_in' variable to get one line of the file and save it into 'line_holder'
  std::getline(file_in, line_holder);
}

 void Flur::ParseLine() { // use 'line_holder' to chop it up into a series of characters. have "send-to-markov" contained within?
                     // must be able to send/ decode only the stuff correctly; in csv some are numbers others are characters
  int i = 0, k = 0;
  std::vector<std::string> block; // a vector of the string in the csv line
  while(line_holder[i] != '\n') {
    std::string temp = "";
    if (line_holder[i] != ',') { // if the position is not a comma
      temp += lineholder[i]; // add it to temp
      } else {
      block.push_back(temp); // the current temp to block if a comma is found
      }
      i++;
    }
    i = 0;
    SendToMarkov(Decode(block[i])); // send Markov the very 1st element of the block
  for(i = 1; block.size() > i; i++) {
    k = i % 2; // check if position 'i' is even
    if (k == 0) { // if even, bc even in the line should be an char
      SendToMarkov(Decode(block[i]), 1);
    } else { // if odd, bc odd will be integers
    SendToMarkov(Decode(block[i]);
      }
}
  }

int Flur::Decode(std::string a) { // Input a string to get an Int in return
  return std::stoi(a);
}
// Input a string to get back a char *; runs other Decode Fn
// the int b will be changed to a 1 if it is an array; 0 if it is a single char
char * Flur::Decode(std::string a, int * b) {
  return Decode( std::stoi(a) );
}
// Input an int; namely a ASCII integer; return the corresponding character to
char Decode(int a) { // input as ASCII to return a character; even nessessary?
   char c = '0' + a;
   return c;
 }

 void SendToMarkov(char, int); // send a variable to Markov
 void MessageMarkov(int); void MessageMarkov(int, char); // systematically send messages
                     //to Markov; ie: inform Markov the start of a new line or new char
