#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long total{0} ;
    for (int ii{0}; ii < s.size() ;ii++)
        {
            if (s[ii] == 'a') total++ ;
        }
    total *= n/s.size() ;

    for (int ii{0}; ii < n%s.size(); ii++)
        {
            if(s[ii] == 'a') total++ ;
        }

    return total ;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
