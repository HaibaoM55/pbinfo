#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

struct Package {
    std::string name;
    std::string author;
    std::string version;

public:
    Package(std::string name, std::string author, std::string version) :
        name(name), author(author), version(version) {}

    bool operator==(const Package& other) const {
        return name == other.name && author == other.author && version == other.version;
    }
};

// Read installed packages from a CSV file
std::vector<Package> list_installed_packages(const std::string& filename) {
    std::vector<Package> installed;
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Failed to open installed packages file: " << filename << "\n";
        return installed;
    }

    std::string line;
    std::getline(file, line); // skip header
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, author, version;
        std::getline(ss, name, ',');
        name.erase(remove_if(name.begin(), name.end(), ::isspace), name.end());
        std::getline(ss, author, ',');
        author.erase(remove_if(author.begin(), author.end(), ::isspace), author.end());
        std::getline(ss, version, ',');
        version.erase(remove_if(version.begin(), version.end(), ::isspace), version.end());
        installed.emplace_back(name, author, version);
    }

    return installed;
}
std::vector<Package> list_allowed_packages(const std::string& filename){
    std::vector<Package> allowed;
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Failed to open installed packages file: " << filename << "\n";
        return allowed;
    }
    std::string line;
    std::getline(file, line); // skip header
    std::string namef, authorf, versionf;
    while (std::getline(file, line)) {
        if(line[4] == '}' && line[0] != ']'){
            //std::cout << namef << '\n' << authorf <<'\n' << versionf << '\n';
            allowed.emplace_back(namef, authorf, versionf);
        }else{
            char firstLetter = 0;
            int firstLetterAp = 0;
            for(int i = 0; i < line.size(); i++){
                if('a' <= line[i] && line[i] <= 'z'){
                    firstLetter = line[i];
                    firstLetterAp = i;
                    break;
                }
            }
            if(firstLetter == 'n'){
                namef = line.substr(17, line.size()-19);
            }else if(firstLetter == 'a'){
                authorf = line.substr(19, line.size()-21);
            }else if(firstLetter == 'v'){
                versionf = line.substr(20, line.size()-21);
            }
        }
    }
    return allowed;
}
int main() {
    auto installed = list_installed_packages("installed.csv");
    auto allowed = list_allowed_packages("allowlist.json");
    for (const auto& installedPackage: installed) {
        bool ok = false;
        for(const auto& allowedPackage: allowed){
            if(installedPackage == allowedPackage){
                ok = true;
                break;
            }
        }
        if(!ok){
            std::cout << installedPackage.name << ',' << installedPackage.author << ',' << installedPackage.version <<'\n';
        }
    }
    return 0;
}
