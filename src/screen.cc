#include "screen.h"
#include <raylib.h>

Screen::Screen() :
prev(),
word(),
word_center{0, 0},
keyboard(LoadTexture("dvorak_keyboard.png")),
idx(0)
{
    flags.set(0);
}

Screen::~Screen() {
    UnloadTexture(keyboard);
}

void Screen::set_word(std::string s) {
    prev = word;
    word = s;
    idx = 0;
    word_pre.clear();
    word_post.clear();
    word_center[0] = s.at(0);
    flags.set(0);
}

bool Screen::update() {
    int input = GetCharPressed();
    if (input == word_center[0]) {
        ++idx;
        flags.set(0);
        if (idx >= word.size()) {
            return true;
        }
    }

    return false;
}

void Screen::draw() {
    DrawTexture(keyboard, 0, 0, WHITE);
    if (flags.test(0)) {
        flags.reset(0);

        if (idx > 0) {
            word_pre = word.substr(0, idx);
        } else {
            word_pre.clear();
        }

        if (idx < word.size()) {
            word_post = word.substr(idx + 1, word.size() - idx - 1);
        } else {
            word_post.clear();
        }

        word_center[0] = word.at(idx);
    }

    int offset = 0;
    if (!prev.empty()) {
        DrawText(prev.c_str(), LEFT_OFFSET + offset, TOP_OFFSET, FONT_SIZE, Color{127, 127, 127, 255});
        offset += MeasureText(prev.c_str(), FONT_SIZE) + PREV_OFFSET;
    }

    if (!word_pre.empty()) {
        DrawText(word_pre.c_str(), LEFT_OFFSET + offset, TOP_OFFSET, FONT_SIZE, WHITE);
        offset += MeasureText(word_pre.c_str(), FONT_SIZE) + CENTER_X_OFFSET;
    }

    DrawText(word_center.data(), LEFT_OFFSET + offset, TOP_OFFSET, FONT_SIZE, GREEN);
    offset += MeasureText(word_center.data(), FONT_SIZE) + CENTER_X_OFFSET;

    if (!word_post.empty()) {
        DrawText(word_post.c_str(), LEFT_OFFSET + offset, TOP_OFFSET, FONT_SIZE, WHITE);
    }
}
