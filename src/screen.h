#ifndef DVORAK_TYPING_PRACTICE_SCREEN_H_
#define DVORAK_TYPING_PRACTICE_SCREEN_H_

// Standard library includes
#include <array>
#include <bitset>
#include <string>

// Third party includes
#include <raylib.h>

// Constants
constexpr int LEFT_OFFSET = 20;
constexpr int TOP_OFFSET = 320;
constexpr int FONT_SIZE = 40;
constexpr int CENTER_X_OFFSET = FONT_SIZE / 2;
constexpr int PREV_OFFSET = FONT_SIZE * 2;

constexpr int KEY_HALF_SIZE = 29;
constexpr Color KEY_HIGHLIGHT_COLOR = Color{255, 255, 0, 127};

class Screen {
 public:
  Screen();
  ~Screen();

  void set_word(std::string s);

  // True if finished with word.
  bool update();
  void draw();

 private:
  std::string prev;
  std::string word;
  std::string word_pre;
  std::string word_post;
  std::array<char, 2> word_center;
  Texture2D keyboard;
  unsigned int idx;
  /*
   * 0 - cached word data is dirty
   */
  std::bitset<32> flags;

  void draw_overlay(char c);
};

#endif
