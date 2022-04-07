#include <iostream>
#include <string>
#include <vector>
using namespace std;

void NEXT (int& n, const vector<int>& days, vector<vector<string>>& tasks) {
    ++n;
    if (n > 11) {
        n = 0;
    }
    vector<vector<string>> New = tasks;
    int a = tasks.size();
    int b = days[n];
    tasks.resize(b);
    const int c = b - 1;
    if (a > b) {
        for (b; b < a; ++b) {
            tasks[c].insert(end(tasks[c]), begin(New[b]), end(New[b]));
        }
    }
    New.clear();
}

void DUMP (int& day, const vector<vector<string>>& tasks) {
    cout << tasks[day - 1].size();
    for (auto i : tasks[day - 1]) {
        cout << " " << i;
    }
    cout << '\n';
}


int main () {
    int Q;
    cin >> Q;
    vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};
    vector<vector<string>> tasks;
    int n = 0;
    tasks.resize(days[n], {});
    for (int i = 0; i < Q; ++i) {
        string COM;
        int day;
        string TAS;
        cin >> COM;
        if (COM == "ADD") {
            cin >> day >> TAS;
            tasks[day - 1].push_back(TAS);
        }
        else if (COM == "NEXT") {
            NEXT (n, days, tasks);
        }
        else if (COM == "DUMP") {
            cin >> day;
            DUMP (day, tasks);
        }
    }
    
    
    
    return 0;
}