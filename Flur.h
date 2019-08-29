// Flur will be tasked with explicitly reading from the save file and sending it off to Markov's save file

// include files, idk what will be here yet, but there will be a lot of them

/*****************************************/
class Flur {
// a class should contain:
  // variables: the file name; a step counter(and/or line counter?); a runner for the file; runing string line holder?;
  // functions: Get the File; Parse the File(into lines?); Parse the Lines; Decode the Lines(ASCII into Char); Send to Markov;
        // open the file; primary activation FN; notify Markov of actions;

 public:
 void FlurSaveFile(std::string); // the outside's connection to save the input file for Markov; Markov and Flur are a thing
 void contactFlur(); // start the primary activation function

 private:
 std::string file_name; // name of the file
 int line_counter; // the corresponding line number to the file that the program is working on
 int step_counter; // the corresponding ASCII 'block' that the program is working on
 std::ifstream file_in; // the opened and readable file
 std::string line_holder; // the line of the file being worked through

 Flur(); Flur(int); // constructors, the INT is for any special start conditions
/*
  file_name = "";
  line_counter = 0;
  step_counter = 0;
  line_holder = "":
  */
 void FlursAffection(); // activate all the helper functions until the file has been read through
/*
  while (ifstream != EOF) {
    MessageMarkov(1); // tell markov there is a new line
    ParseFile();
    ParseLine(); // sperate the line into an array & send it to markov
    }
    */
 void ParseFile(); // use the 'file_in' variable to get one line of the file and save it into 'line_holder'
/*
  std::getline(file_in, line_holder);
  */
 void ParseLine(); // use 'line_holder' to chop it up into a series of characters. have "send-to-markov" contained within?
                     // must be able to send/ decode only the stuff correctly; in csv some are numbers others are characters
/*
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
    i = 1;
  for( //i to end of block) {
    k = i % 2; // check if position 'i' is even
    if (k == 0) { // if even, bc even in the line should be an char
      SendToMarkov(Decode(block[i]));
    } else { // if odd, bc odd will be integers
      SendToMarkov(std::stoi(block[i]));
      }
      }

*/
 char Decode(std::string); char Decode(int) // input as ASCII to return a character; even nessessary?
 void SendToMarkov(char); void SendToMarkov(int); // send a variable to Markov
 void MessageMarkov(int); void MessageMarkov(int, char) // systematically send messages
                     //to Markov; ie: inform Markov the start of a new line or new char
}
