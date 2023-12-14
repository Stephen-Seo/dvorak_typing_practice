// Standard library includes
#include <fstream>
#include <iostream>
#include <string>

// Third party includes
#include <raylib.h>

// Local includes
#include "screen.h"

std::string get_next_word(std::istream *i) {
  std::string word;
  while (i->good()) {
    int in = i->get();
    if (in != std::char_traits<char>::eof() && in != ' ' && in != '\n' &&
        in != '\r') {
      word.push_back((char)in);
    } else if (in == ' ' || in == '\n' || in == '\r' || in == '\t') {
      if (!word.empty()) {
        break;
      } else {
        continue;
      }
    }
  }

  return word;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Expected 1 arg input filename!\n";
    return 1;
  }

  std::ifstream ifs(argv[1]);

  if (!ifs.good()) {
    std::cout << "ERROR: Failed to open file \"" << argv[1] << "\"!\n";
    return 2;
  }

  InitWindow(900, 400, "Dvorak Typing Practice");
  SetTargetFPS(15);

  {
    Screen screen{};

    std::string word;

    do {
      word = get_next_word(&ifs);
      if (!word.empty()) {
        screen.set_word(word);
        while (!screen.update() && !WindowShouldClose()) {
          BeginDrawing();
          ClearBackground(BLACK);
          screen.draw();
          EndDrawing();
        }
      }
    } while (!ifs.eof() && !WindowShouldClose());
  }

  CloseWindow();
  return 0;
}
