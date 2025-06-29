#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <unordered_set>

// https://algo.monster/problems/amazon-oa-recent-items

using namespace std;

vector<string> getRecentItems(const vector<string> &logs)
{
    list<string> recent;
    unordered_set<string> seen;
    for (string log : logs)
    {
        if (seen.count(log))
            recent.remove(log);
        seen.insert(log);
        recent.push_front(log);
    }
    return vector<string>(recent.begin(), recent.end());
}

void runTest(const vector<string> &logs, const vector<string> &expected)
{
    vector<string> result = getRecentItems(logs);

    cout << "Input: ";
    for (const auto &log : logs)
        cout << "\"" << log << "\", ";
    cout << "\n";

    cout << "Output: ";
    for (const auto &item : result)
        cout << "\"" << item << "\", ";
    cout << "\n";

    cout << "Expected: ";
    for (const auto &item : expected)
        cout << "\"" << item << "\", ";
    cout << "\n";

    cout << (result == expected ? "✅ Passed\n\n" : "❌ Failed\n\n");
}

int main()
{
    runTest({"Echo Show 8", "Kindle Oasis", "Fire TV Stick", "Echo Show 8"},
            {"Echo Show 8", "Fire TV Stick", "Kindle Oasis"});

    runTest({"A", "B", "C", "B", "D", "A"},
            {"A", "D", "B", "C"});

    runTest({"Laptop"},
            {"Laptop"});

    runTest({}, {}); // Edge case: empty input

    return 0;
}
