#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

string dayOfProgrammer(int year)
{
    ostringstream x;
    x << year;
    string y = x.str();
    string z = "12.09.";
    string z1 = "13.09.";
    string l = z + y;
    string nl = z1 + y;

    if (year < 1918)
    {
        return ((year % 4 == 0) ? l : nl);
    }
    if (year > 1918)
    {
        return(year % 400 == 0) ? l : (year % 4 == 0)&&(year % 100!=0) ? l : nl ;
    }
    if(year==1918)
    {
        return "26.09.1918";
    }
    return "0";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
