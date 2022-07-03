#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>

std::string load()
{
    FILE* f = fopen("ClarissaHarlowe.txt", "rt");
    fseek(f, 0, SEEK_END);
    size_t size = ftell(f);
    fseek(f, 0, SEEK_SET);
    std::string text(size, 0);
    size = fread(text.data(), 1, size, f);
    text.resize(size);
    fclose(f);
    return text;
}

#include <map>
#include <regex>
std::pair<std::string, size_t> count_words_0(const std::string& text)
{
    std::map<std::string, size_t> d;
    const std::regex re("[^a-xzA-Z]+");
    for (std::sregex_token_iterator it(text.begin(), text.end(), re, -1), end; it != end; ++it)
        if (auto word = it->str(); word.size() > 3)
        {
            if (auto dit = d.find(word); dit != d.end())
                ++dit->second;
            else
                d.emplace(std::move(word), 1);
        }
    auto best = d.cbegin();
    for (auto dit = d.cbegin(); dit != d.cend(); ++dit)
        if (dit->second > best->second)
            best = dit;
    return *best;
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
bool is_latin_alpha(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
std::pair<std::string, size_t> count_words_1(const std::string& text)
{
    auto next_word = [&text, pos = size_t(0)]() mutable
    {
        for (; pos < text.size() && !is_latin_alpha(text[pos]); ++pos);
        size_t start = pos;
        for (; pos < text.size() && is_latin_alpha(text[pos]); ++pos);
        return text.substr(start, pos - start);
    };
    std::map<std::string, size_t> d;
    for (;;)
        if (auto word = next_word(); word.empty())
            break;
        else if (word.size() > 3)
        {
            if (auto dit = d.find(word); dit != d.end())
                ++dit->second;
            else
                d.emplace(word, 1);
        }
    auto best = d.cbegin();
    for (auto dit = d.cbegin(); dit != d.cend(); ++dit)
        if (dit->second > best->second)
            best = dit;
    return *best;
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
#include <unordered_map>
std::pair<std::string, size_t> count_words_2(const std::string& text)
{
    auto next_word = [&text, pos = size_t(0)]() mutable
    {
        for (; pos < text.size() && !is_latin_alpha(text[pos]); ++pos);
        size_t start = pos;
        for (; pos < text.size() && is_latin_alpha(text[pos]); ++pos);
        return text.substr(start, pos - start);
    };
    std::unordered_map<std::string, size_t> d;
    d.reserve(20000);
    for (;;)
        if (auto word = next_word(); word.empty())
            break;
        else if (word.size() > 3)
        {
            if (auto dit = d.find(word); dit != d.end())
                ++dit->second;
            else
                d.emplace(word, 1);
        }
    auto best = d.cbegin();
    for (auto dit = d.cbegin(); dit != d.cend(); ++dit)
        if (dit->second > best->second)
            best = dit;
    return *best;
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
#include <string_view>
struct string_hash : std::hash<std::string_view> {
    using is_transparent = void;
};
std::pair<std::string_view, size_t> count_words_3(const std::string& text)
{
    auto next_word = [&text, pos = size_t(0)]() mutable
    {
        for (; pos < text.size() && !is_latin_alpha(text[pos]); ++pos);
        size_t start = pos;
        for (; pos < text.size() && is_latin_alpha(text[pos]); ++pos);
        return std::string_view(text.data() + start, pos - start);
    };
    std::unordered_map<std::string_view, size_t, string_hash, std::equal_to<>> d;
    d.reserve(20000);
    for (;;)
        if (auto word = next_word(); word.empty())
            break;
        else if (word.size() > 3)
        {
            if (auto dit = d.find(word); dit != d.end())
                ++dit->second;
            else
                d.emplace(word, 1);
        }
    auto best = d.cbegin();
    for (auto dit = d.cbegin(); dit != d.cend(); ++dit)
        if (dit->second > best->second)
            best = dit;
    return *best;
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
#include <memory_resource>
std::pair<std::string_view, size_t> count_words_4(const std::string& text)
{
    auto next_word = [&text, pos = size_t(0)]() mutable
    {
        for (; pos < text.size() && !is_latin_alpha(text[pos]); ++pos);
        size_t start = pos;
        for (; pos < text.size() && is_latin_alpha(text[pos]); ++pos);
        return std::string_view(text.data() + start, pos - start);
    };
    using map = std::pmr::unordered_map<std::string_view, size_t, string_hash, std::equal_to<>>;
    std::pmr::monotonic_buffer_resource res{ 100000 };
    map d{ &res };
    d.reserve(20000);
    for (;;)
        if (auto word = next_word(); word.empty())
            break;
        else if (word.size() > 3)
        {
            if (auto dit = d.find(word); dit != d.end())
                ++dit->second;
            else
                d.emplace(word, 1);
        }
    auto best = d.cbegin();
    for (auto dit = d.cbegin(); dit != d.cend(); ++dit)
        if (dit->second > best->second)
            best = dit;
    return *best;
}
