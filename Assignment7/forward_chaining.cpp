#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// Structure for rule representation
struct Rule
{
    string condition;
    string conclusion;
};

int main()
{
    // Step 1: Define rules
    vector<Rule> rules = {
        {"it is raining", "the ground is wet"},
        {"the ground is wet", "the road is slippery"},
        {"the road is slippery", "drive carefully"}};

    // Step 2: Known facts
    unordered_set<string> facts = {"it is raining"};

    // Step 3: Forward chaining loop
    bool newFactAdded = true;

    while (newFactAdded)
    {
        newFactAdded = false;

        for (auto &rule : rules)
        {
            // If condition matches and conclusion not already known
            if (facts.find(rule.condition) != facts.end() &&
                facts.find(rule.conclusion) == facts.end())
            {

                facts.insert(rule.conclusion);
                cout << "Derived new fact: " << rule.conclusion << endl;
                newFactAdded = true;
            }
        }
    }

    // Step 4: Final facts
    cout << "\nFinal set of facts:\n";
    for (auto &f : facts)
        cout << "- " << f << endl;

    return 0;
}
