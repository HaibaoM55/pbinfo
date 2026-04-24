#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int extract_year(const string& date) {
    return stoi(date.substr(0, 4));
}

set<string> get_more_severe_family(const string& hcc, const map<string, vector<string>>& hcc_graph) {
    set<string> visited;
    vector<string> stack = {hcc};
    while (!stack.empty()) {
        string current = stack.back();
        if (visited.count(current)) break;
        visited.insert(current);
        if (hcc_graph.count(current)) {
            for (const auto& neighbor : hcc_graph.at(current)) {
                stack.push_back(neighbor);
            }
        }
    }
    return visited;
}

int main() {
    int H, P, D, N;
    map<string, string> hcc_names;
    map<string, vector<string>> hcc_severity_graph;
    map<string, string> diagnosis_to_hcc;

	// Reading HCC -> description
    cin >> H;
    for (int i = 0; i < H; ++i) {
        string hcc, name;
        cin >> hcc;
        getline(cin, name); // Read the rest of the line
        if (!name.empty() && name[0] == ' ') name = name.substr(1);
        hcc_names[hcc] = name;
    }

	// Reading HCC -> more severe HCC
    cin >> P;
    for (int i = 0; i < P; ++i) {
        string from, to;
        cin >> from >> to;
        hcc_severity_graph[from].push_back(to);
    }

	// Reading diagnosis -> HCC
    cin >> D;
    for (int i = 0; i < D; ++i) {
        string diag, hcc;
        cin >> diag >> hcc;
        diagnosis_to_hcc[diag] = hcc;
    }

	// Reading patient history
    cin >> N;
    map<int, set<string>> year_to_hccs;
    map<int, set<string>> year_to_diagnoses;  // New map to store diagnoses by year
    map<string, int> first_seen;
    for (int i = 0; i < N; ++i) {
        string date, diag;
        cin >> date >> diag;
        int year = extract_year(date);
        year_to_diagnoses[year].insert(diag);  // Store diagnosis by year
        if (diagnosis_to_hcc.count(diag)) {
            string hcc = diagnosis_to_hcc[diag];
            year_to_hccs[year].insert(hcc);
            if (!first_seen.count(hcc) || year < first_seen[hcc]) {
                first_seen[hcc] = year;
            }
        }
    }

	// Set to store all years
    set<int> all_years;
    int min_year = 9999;
    int max_year = 0;
    for (const auto& [year, _] : year_to_hccs) {
        all_years.insert(year);
        min_year = min(min_year, year);
        max_year = max(max_year, year);
    }
    // Add all years from min_year to 2024
    for (int year = min_year; year <= 2024; ++year) {
        all_years.insert(year);
    }

	// For each HCC seen initially, check if it was monitored in the following years
    vector<pair<int, string>> reported;
    for (const auto& [hcc, first_year] : first_seen) {
        set<string> family = get_more_severe_family(hcc, hcc_severity_graph);
        for (int year : all_years) {
            if (year <= first_year) continue;
            bool found = false;
            // Check all diagnoses for this year
            for (const string& diag : year_to_diagnoses[year]) {
                if (diagnosis_to_hcc.count(diag)) {
                    string diag_hcc = diagnosis_to_hcc[diag];
                    if (family.count(diag_hcc)) {
                        found = true;
                        break;
                    }
                }
            }
            if (!found) {
                reported.push_back({year, hcc});
            }
        }
    }

    // Clean up reported data - keep only the most severe HCC from each family per year
    set<pair<int, string>> cleaned_reported;
    bool modified;
    do {
        modified = false;
        cleaned_reported.clear();

        // For every HCC in reported
        for (int i = 0; i < reported.size(); ++i) {
            bool should_keep = true;
            int current_year = reported[i].first;
            string current_hcc = reported[i].second;
            set<string> current_family = get_more_severe_family(current_hcc, hcc_severity_graph);

            // Check against all other HCCs from the same year
            for (int j = 0; j < reported.size(); ++j) {
                if (i == j) continue;
                if (reported[j].first != current_year) continue;

                string other_hcc = reported[j].second;

                // Other_hcc is in current_hcc's family (other_hcc is more severe)
                if (current_family.count(other_hcc)) {
                    should_keep = false;
                    break;
                }
            }

            if (should_keep) {
                cleaned_reported.insert(reported[i]);
            } else {
                modified = true;
            }
        }

        // Update reported for next iteration if needed
        if (modified) {
            reported = vector<pair<int, string>>(cleaned_reported.begin(), cleaned_reported.end());
        }
    } while (modified);

    // Sort by year ascending and HCC code descending
    sort(reported.begin(), reported.end(),
        [](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        });

    // Output sorted results
    for (const auto& [year, hcc] : reported) {
        cout << year << " " << hcc_names[hcc] << endl;
    }

    return 0;
}
