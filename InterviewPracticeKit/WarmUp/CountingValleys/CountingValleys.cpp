#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the sockMerchant function below.
int sockMerchant(int n, vector<int> ar) {
    // n: Number of socks in the pile.
    // ar: The colors of each sock.
    // Output: integer representing the number of matching pairs of socks that are available.

    std::map<int,int> m ; // Key is digit/color and value is count/frequency.
    int total{0} ;         // Total number of pairs

    for (std::vector<int>::size_type ii{0}; ii < (unsigned)n; ii++)     // Traverse array of socks.
    {
        if (m.find(ar[ii]) == m.end()) // Does not exist.
            m[ar[ii]] = 1 ;            // Insert in map.
        else
            m[ar[ii]] += 1 ;           // Incremenet frequency.
    }

    for ( const auto &myPair : m )  // Traverse map
    {
        total += myPair.second / 2 ; // Increase total by total/2.
    }

    return total ;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split_string(ar_temp_temp);

    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
        int ar_item = stoi(ar_temp[i]);

        ar[i] = ar_item;
    }

    int result = sockMerchant(n, ar);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
