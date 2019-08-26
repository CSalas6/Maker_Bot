  1 #include"markov.h"
  2
  3 struct File {
  4   std::string file_name;
  5   int x_axis;
  6   int y_axis;
  7   bool uploaded;
  8   time_t up_clock;
  9   bool downloaded;
 10   time_t down_clock;
 11   File();
 12 };
 13
 14   File::File() {
 15   file_name = "";
 16   x_axis = 0;
 17   y_axis = 0;
 18   uploaded = false;
 19   downloaded = false;
 20
 21   }
 22
 23 class File_Worker {
 24   public:
 25     std::string get_working_file() {return working_file;}
 26     void set_working_file(std::string);
 27     void access_markov();
 28
 29   private:
 30     void upload_to_markov(/*probably a char? or more?*/);
 31     void download_from_markov(/*pull data from markov and save it*/);
 32
 33
 34
 35 };
