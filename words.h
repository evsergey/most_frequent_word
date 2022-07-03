#pragma once

#include <string>
#include <string_view>

std::string load();
std::pair<std::string, size_t> count_words_0(const std::string& text);
std::pair<std::string, size_t> count_words_1(const std::string& text);
std::pair<std::string, size_t> count_words_2(const std::string& text);
std::pair<std::string_view, size_t> count_words_3(const std::string& text);
std::pair<std::string_view, size_t> count_words_4(const std::string& text);
