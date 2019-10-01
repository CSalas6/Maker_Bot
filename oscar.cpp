

#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<iostream>
#include<cctype>
#include<map>
#include<vector>
#include<string>
#include"lee.h"
#include"Flur.h"
#include"markov.h"
#include"warkov.h"

int main() {

char user_in_c = '0';
bool run_loop = true;

Markov_chain Mark;
Warkov_chain Wark;
Lee lee(&Mark, &Wark);

while(run_loop) {

  std::cout << "Welcome to Makerbot V 0.1\n"
    << "I am Oscar, how may I help you today?\n\n"
    << "1) Give Flur a file to read\n"
    << "2) Give Lee a file to read\n"
    << "3) Have Markov return a randomly constructed word\n"
    << "4) Have Warkov return a randomly written line\n"
    << "q) quit\n";

    std::cin >> user_in_c;

  switch (user_in_c) {
    case '1': std::cout << "Flur is not accessable right now" << '\n';
      break;
    case '2': std::cout << "Contacting Lee\n"
                        << "Please input the desired file now" << '\n';
              std::string file = "";
              std::getline(std::cin, file);
              lee.recieve_file(file);
              std::cout << "Lee has been called and completed\n";
      break;
    case '3': std::cout << "Markov is not accessable right now" << '\n';
      break;
    case '4': std::cout << "Contacting Warkov\n"
                        << "Please input a random number less than:"
                        Wark.prefix_size() << '\n';
              int r_val = 99999999;
              std::cin >> r_val;
              std::string temp = "";
              temp = Wark.R_line_building(r_val);
              std::cout << "Wark has been called and completed\n"
                        << "the random line is: \n"
                        << temp << '\n';
      break;
    case 'q': run_loop = false; break;
    case 'Q': run_loop = false; break;
    default: std::cout << "I didn't get that, can you repeat?" << '\n';
      break;
  }
}



  return 0;
}
