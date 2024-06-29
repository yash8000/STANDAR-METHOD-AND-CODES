#include <iostream>
#include <set>
#include <string>

using namespace std;

// Recursive function to generate combinations
void generate(int n, const string &open, const string &close, string current, set<string> &result) {
    // Base case: when n is 0, add the current string to the result
    if (n == 0) {
        result.insert(current);
        return;
    }

    // Generate combinations with the remaining pairs
    for (size_t i = 0; i < open.size(); ++i) {
        // Adding pair before
        generate(n - 1, open, close, string(1, open[i]) + string(1, close[i]) + current, result);

        // Adding pair around
        generate(n - 1, open, close, string(1, open[i]) + current + string(1, close[i]), result);

        // Adding pair after
        generate(n - 1, open, close, current + string(1, open[i]) + string(1, close[i]), result);
    }
}

int main() {
    int n = 2; // Number of pairs to generate
    cin>>n;
    // string open = "([<{"; // Opening characters
    // string close = ")]>}"; // Closing characters
    string open = "("; // Opening characters
    string close = ")"; // Closing characters

    set<string> result; // Set to store unique combinations

    // Generate all combinations
    generate(n, open, close, "", result);

    // Output the results
    for (const string &s : result) {
        cout << s << endl;
    }

    return 0;
}
