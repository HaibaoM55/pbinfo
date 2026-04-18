#include <iostream>
#include <string_view>
#include <string>
#include <vector>

using namespace std;

const string WHITESPACES = " ";                                            // DO NOT MODIFY
                                                                           // DO NOT MODIFY
struct Heading {                                                           // DO NOT MODIFY
    int level;                                                             // DO NOT MODIFY
    string title;                                                          // DO NOT MODIFY
    // -1 if the heading is not an example                                 // DO NOT MODIFY
    int example_number = -1;                                               // DO NOT MODIFY
    string codeblock;                                                      // DO NOT MODIFY
};                                                                         // DO NOT MODIFY
                                                                           // DO NOT MODIFY
string_view substring(string_view s, int p, size_t n = string_view::npos) {// DO NOT MODIFY
    return s.substr(p, n);                                                 // DO NOT MODIFY
}                                                                          // DO NOT MODIFY
                                                                           // DO NOT MODIFY
int line_count(const string &str) {                                        // DO NOT MODIFY
    if (str.length() == 0) {                                               // DO NOT MODIFY
        return 0;                                                          // DO NOT MODIFY
    }                                                                      // DO NOT MODIFY
    int count = 1;                                                         // DO NOT MODIFY
    for (char c : str) {                                                   // DO NOT MODIFY
        if (c == '\n') {                                                   // DO NOT MODIFY
            count++;                                                       // DO NOT MODIFY
        }                                                                  // DO NOT MODIFY
    }                                                                      // DO NOT MODIFY
                                                                           // DO NOT MODIFY
    return count;                                                          // DO NOT MODIFY
}                                                                          // DO NOT MODIFY
                                                                           // DO NOT MODIFY
bool is_heading(string &line) {                                            // DO NOT MODIFY
    return line[0] == '#';                                                 // DO NOT MODIFY
}                                                                          // DO NOT MODIFY
                                                                           // DO NOT MODIFY
bool is_codeblock_start(string line) {                                     // DO NOT MODIFY
    // Delete first preceeding 3 spaces                                    // DO NOT MODIFY
    for (int i = 0; i < 3; i++) {                                          // DO NOT MODIFY
        if (line.length() && line[0] == ' ') {                             // DO NOT MODIFY
            line = line.substr(1);                                         // DO NOT MODIFY
        }                                                                  // DO NOT MODIFY
    }                                                                      // DO NOT MODIFY
    if (line.find("```") == 0) {                                           // DO NOT MODIFY
        return true;                                                       // DO NOT MODIFY
    }                                                                      // DO NOT MODIFY
                                                                           // DO NOT MODIFY
    return false;                                                          // DO NOT MODIFY
}                                                                          // DO NOT MODIFY
                                                                           // DO NOT MODIFY
int codeblock_separator_length(string line) {                              // DO NOT MODIFY
    int index = line.find("`");                                            // DO NOT MODIFY
                                                                           // DO NOT MODIFY
    if (index == line.npos) {                                              // DO NOT MODIFY
        return -1;                                                         // DO NOT MODIFY
    }                                                                      // DO NOT MODIFY
                                                                           // DO NOT MODIFY
    int count = 0;                                                         // DO NOT MODIFY
    // Counts the backticks                                                // DO NOT MODIFY
    for (auto c : line.substr(index)) {                                    // DO NOT MODIFY
        if (c == '`') {                                                    // DO NOT MODIFY
            count++;                                                       // DO NOT MODIFY
        } else {                                                           // DO NOT MODIFY
            break;                                                         // DO NOT MODIFY
        }                                                                  // DO NOT MODIFY
    }                                                                      // DO NOT MODIFY
                                                                           // DO NOT MODIFY
    return count;                                                          // DO NOT MODIFY
}                                                                          // DO NOT MODIFY
                                                                           // DO NOT MODIFY
bool is_codeblock_end(string line, int n = 3) {                            // DO NOT MODIFY
    // Delete first preceeding 3 spaces                                    // DO NOT MODIFY
    for (int i = 0; i < 3; i++) {                                          // DO NOT MODIFY
        if (line.length() && line[0] == ' ') {                             // DO NOT MODIFY
            line = line.substr(1);                                         // DO NOT MODIFY
        }                                                                  // DO NOT MODIFY
    }                                                                      // DO NOT MODIFY
    // Delete the spaces at the end                                        // DO NOT MODIFY
    while (line.length()) {                                                // DO NOT MODIFY
        if (line[line.length() - 1] == ' ') {                              // DO NOT MODIFY
            line = line.substr(0, line.length() - 1);                      // DO NOT MODIFY
        } else {                                                           // DO NOT MODIFY
            break;                                                         // DO NOT MODIFY
        }                                                                  // DO NOT MODIFY
    }                                                                      // DO NOT MODIFY
                                                                           // DO NOT MODIFY
    // Delete the backticks at the end (not all of them)                   // DO NOT MODIFY
    while (line.length() > n) {                                            // DO NOT MODIFY
        if (line[line.length() - 1] == '`') {                              // DO NOT MODIFY
            line = line.substr(0, line.length() - 1);                      // DO NOT MODIFY
        } else {                                                           // DO NOT MODIFY
            break;                                                         // DO NOT MODIFY
        }                                                                  // DO NOT MODIFY
    }                                                                      // DO NOT MODIFY
                                                                           // DO NOT MODIFY
    // Generates the string with n backticks                               // DO NOT MODIFY
    string end_str = string(n, '`');                                       // DO NOT MODIFY
                                                                           // DO NOT MODIFY
    if (line == end_str) {                                                 // DO NOT MODIFY
        return true;                                                       // DO NOT MODIFY
    }                                                                      // DO NOT MODIFY
                                                                           // DO NOT MODIFY
    return false;                                                          // DO NOT MODIFY
}                                                                          // DO NOT MODIFY
                                                                           // DO NOT MODIFY
int heading_level(string &line) {                                          // DO NOT MODIFY
    int level = 0;                                                         // DO NOT MODIFY
    for (char c : line) {                                                  // DO NOT MODIFY
        if (c == '#') {                                                    // DO NOT MODIFY
            level++;                                                       // DO NOT MODIFY
        } else {                                                           // DO NOT MODIFY
            break;                                                         // DO NOT MODIFY
        }                                                                  // DO NOT MODIFY
                                                                           // DO NOT MODIFY
        if (level == 6) {                                                  // DO NOT MODIFY
            break;                                                         // DO NOT MODIFY
        }                                                                  // DO NOT MODIFY
    }                                                                      // DO NOT MODIFY
                                                                           // DO NOT MODIFY
    return level;                                                          // DO NOT MODIFY
}                                                                          // DO NOT MODIFY
                                                                           // DO NOT MODIFY
string_view str_from_next_word(const string &str) {                        // DO NOT MODIFY
    int index = str.find_first_not_of(WHITESPACES);                        // DO NOT MODIFY
    if (index == str.npos) {                                               // DO NOT MODIFY
        return "";                                                         // DO NOT MODIFY
    }                                                                      // DO NOT MODIFY
                                                                           // DO NOT MODIFY
    return substring(str, index);                                          // DO NOT MODIFY
}                                                                          // DO NOT MODIFY
                                                                           // DO NOT MODIFY
vector<string> get_words(const string &str) {                              // DO NOT MODIFY
    int start_word = 0;                                                    // DO NOT MODIFY
    vector<string> words;                                                  // DO NOT MODIFY
                                                                           // DO NOT MODIFY
    for (int i = 0; i < str.length(); i++) {                               // DO NOT MODIFY
        int index = WHITESPACES.find_first_of(str[i]);                     // DO NOT MODIFY
        // If whitespace found                                             // DO NOT MODIFY
        if (index != WHITESPACES.npos) {                                   // DO NOT MODIFY
            if (start_word < i) {                                          // DO NOT MODIFY
                auto word = str.substr(start_word, i - start_word);        // DO NOT MODIFY
                words.push_back(word);                                     // DO NOT MODIFY
            }                                                              // DO NOT MODIFY
            start_word = i + 1;                                            // DO NOT MODIFY
        }                                                                  // DO NOT MODIFY
    }                                                                      // DO NOT MODIFY
                                                                           // DO NOT MODIFY
    if (start_word < str.length()) {                                       // DO NOT MODIFY
        auto word = str.substr(start_word);                                // DO NOT MODIFY
        words.push_back(word);                                             // DO NOT MODIFY
    }                                                                      // DO NOT MODIFY
                                                                           // DO NOT MODIFY
    return words;                                                          // DO NOT MODIFY
}                                                                          // DO NOT MODIFY
                                                                           // DO NOT MODIFY
Heading parse_heading_line(string &line) {                                 // DO NOT MODIFY
    int level = heading_level(line);                                       // DO NOT MODIFY
    string title = "";                                                     // DO NOT MODIFY
                                                                           // DO NOT MODIFY
    line = line.substr(level);                                             // DO NOT MODIFY
                                                                           // DO NOT MODIFY
    for (const auto &word : get_words(line)) {                             // DO NOT MODIFY
        if (title.length() > 0) {                                          // DO NOT MODIFY
            title += " ";                                                  // DO NOT MODIFY
        }                                                                  // DO NOT MODIFY
        title += word;                                                     // DO NOT MODIFY
    }                                                                      // DO NOT MODIFY
                                                                           // DO NOT MODIFY
    return Heading{level, title};                                          // DO NOT MODIFY
}                                                                          // DO NOT MODIFY

vector<Heading> headings;
bool code_context = false;
int separator_length = 3;
string codeblock;
Heading last_heading;

void parse_line(string &line) {
    if(code_context && is_codeblock_end(line, separator_length)){
        code_context = false;
        headings.back().codeblock = codeblock;
        codeblock = "";
    }
    else if (is_codeblock_start(line)) {
        code_context = true;
        separator_length = codeblock_separator_length(line);
    }else if (code_context) {
        if (codeblock.length() > 0) {
            codeblock += "\n";
        }
        codeblock += line;
    } else if (is_heading(line)) {
        auto heading = parse_heading_line(line);

        if (heading.title.find("Exemplul") == 0 && heading.level == 2) {
            // strlen("Exemplul") == 8
            string possible_number = heading.title.substr(8);
            try {
                // stoi == string to integer
                heading.example_number = stoi(possible_number);
            }
            catch (invalid_argument const &ex) {}
        }

        headings.push_back(heading);
    }
 }

int main() {                                                               // DO NOT MODIFY
    int n_lines;                                                           // DO NOT MODIFY
    string line;                                                           // DO NOT MODIFY
                                                                           // DO NOT MODIFY
    cin >> n_lines;                                                        // DO NOT MODIFY
                                                                           // DO NOT MODIFY
    for (int i = 0; i < n_lines; i++) {                                    // DO NOT MODIFY
        getline(cin, line);                                                // DO NOT MODIFY
        parse_line(line);                                                  // DO NOT MODIFY
    }                                                                      // DO NOT MODIFY
                                                                           // DO NOT MODIFY
    for (auto &heading : headings) {                                       // DO NOT MODIFY
        if (heading.example_number != -1) {                                // DO NOT MODIFY
            cout << "Exemplul " << heading.example_number << '\n';         // DO NOT MODIFY
        } else if (heading.title == "Intrare" and heading.level == 3) {    // DO NOT MODIFY
            cout << "n: " << line_count(heading.codeblock) << '\n';        // DO NOT MODIFY
            cout << heading.codeblock << '\n';                             // DO NOT MODIFY
        } else if (heading.title == "Iesire" and heading.level == 3) {     // DO NOT MODIFY
            cout << "m: " << line_count(heading.codeblock) << '\n';        // DO NOT MODIFY
            cout << heading.codeblock << '\n';                             // DO NOT MODIFY
        }                                                                  // DO NOT MODIFY
    }                                                                      // DO NOT MODIFY
                                                                           // DO NOT MODIFY
    return 0;                                                              // DO NOT MODIFY
}                                                                          // DO NOT MODIFY
