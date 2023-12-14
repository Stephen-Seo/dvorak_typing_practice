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
        DrawText(prev.c_str(), LEFT_OFFSET + offset, TOP_OFFSET, FONT_SIZE, GRAY);
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

    draw_overlay(word_center[0]);
}

void Screen::draw_overlay(char c) {
    switch (c) {
    case '`':
    case '~':
        DrawCircle(1 + KEY_HALF_SIZE, 1 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case '1':
    case '!':
        DrawCircle(61 + KEY_HALF_SIZE, 1 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case '2':
    case '@':
        DrawCircle(121 + KEY_HALF_SIZE, 1 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case '3':
    case '#':
        DrawCircle(181 + KEY_HALF_SIZE, 1 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case '4':
    case '$':
        DrawCircle(241 + KEY_HALF_SIZE, 1 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case '5':
    case '%':
        DrawCircle(301 + KEY_HALF_SIZE, 1 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case '6':
    case '^':
        DrawCircle(361 + KEY_HALF_SIZE, 1 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case '7':
    case '&':
        DrawCircle(421 + KEY_HALF_SIZE, 1 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case '8':
    case '*':
        DrawCircle(481 + KEY_HALF_SIZE, 1 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case '9':
    case '(':
        DrawCircle(541 + KEY_HALF_SIZE, 1 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case '0':
    case ')':
        DrawCircle(601 + KEY_HALF_SIZE, 1 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case '{':
    case '[':
        DrawCircle(661 + KEY_HALF_SIZE, 1 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case '}':
    case ']':
        DrawCircle(721 + KEY_HALF_SIZE, 1 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case '\'':
    case '"':
        DrawCircle(91 + KEY_HALF_SIZE, 61 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case '<':
    case ',':
        DrawCircle(151 + KEY_HALF_SIZE, 61 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case '>':
    case '.':
        DrawCircle(211 + KEY_HALF_SIZE, 61 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case 'P':
    case 'p':
        DrawCircle(271 + KEY_HALF_SIZE, 61 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case 'Y':
    case 'y':
        DrawCircle(331 + KEY_HALF_SIZE, 61 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case 'F':
    case 'f':
        DrawCircle(391 + KEY_HALF_SIZE, 61 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case 'G':
    case 'g':
        DrawCircle(451 + KEY_HALF_SIZE, 61 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case 'C':
    case 'c':
        DrawCircle(511 + KEY_HALF_SIZE, 61 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case 'R':
    case 'r':
        DrawCircle(571 + KEY_HALF_SIZE, 61 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case 'L':
    case 'l':
        DrawCircle(631 + KEY_HALF_SIZE, 61 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case '?':
    case '/':
        DrawCircle(691 + KEY_HALF_SIZE, 61 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case '+':
    case '=':
        DrawCircle(751 + KEY_HALF_SIZE, 61 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case '|':
    case '\\':
        DrawCircle(811 + KEY_HALF_SIZE, 61 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case 'A':
    case 'a':
        DrawCircle(106 + KEY_HALF_SIZE, 121 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case 'O':
    case 'o':
        DrawCircle(166 + KEY_HALF_SIZE, 121 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case 'E':
    case 'e':
        DrawCircle(226 + KEY_HALF_SIZE, 121 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case 'U':
    case 'u':
        DrawCircle(286 + KEY_HALF_SIZE, 121 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case 'I':
    case 'i':
        DrawCircle(346 + KEY_HALF_SIZE, 121 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case 'D':
    case 'd':
        DrawCircle(406 + KEY_HALF_SIZE, 121 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case 'H':
    case 'h':
        DrawCircle(466 + KEY_HALF_SIZE, 121 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case 'T':
    case 't':
        DrawCircle(526 + KEY_HALF_SIZE, 121 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case 'N':
    case 'n':
        DrawCircle(586 + KEY_HALF_SIZE, 121 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case 'S':
    case 's':
        DrawCircle(646 + KEY_HALF_SIZE, 121 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case '_':
    case '-':
        DrawCircle(706 + KEY_HALF_SIZE, 121 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case ':':
    case ';':
        DrawCircle(136 + KEY_HALF_SIZE, 181 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case 'Q':
    case 'q':
        DrawCircle(196 + KEY_HALF_SIZE, 181 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case 'J':
    case 'j':
        DrawCircle(256 + KEY_HALF_SIZE, 181 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case 'K':
    case 'k':
        DrawCircle(316 + KEY_HALF_SIZE, 181 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case 'X':
    case 'x':
        DrawCircle(376 + KEY_HALF_SIZE, 181 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case 'B':
    case 'b':
        DrawCircle(436 + KEY_HALF_SIZE, 181 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case 'M':
    case 'm':
        DrawCircle(496 + KEY_HALF_SIZE, 181 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case 'W':
    case 'w':
        DrawCircle(556 + KEY_HALF_SIZE, 181 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case 'V':
    case 'v':
        DrawCircle(616 + KEY_HALF_SIZE, 181 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    case 'Z':
    case 'z':
        DrawCircle(676 + KEY_HALF_SIZE, 181 + KEY_HALF_SIZE, KEY_HALF_SIZE, KEY_HIGHLIGHT_COLOR);
        break;
    default:
        break;
    }
}
