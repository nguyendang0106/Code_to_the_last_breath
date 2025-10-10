/*
Mô tả
Write a C program to perform some queries on a telco data (comming from stdin) with the following format:
The first block of data consists of lines (terminated by a line containing #), each line (number of lines can be up to 100000) is under the form:
        call <from_number> <to_number> <date> <from_time> <end_time>
which is a call from the phone number <from_number> to a phone number <to_number> on <date>, and starting at time-point <from_time>, terminating at time-point <end_time>
<from_number> and <to_number> are string of 10 characters (a phone number is correct if it contains only digits 0,1,...,9, otherwise, the phone number is incorrect)
<date> is under the form YYYY-MM-DD (for example 2022-10-21)
<from_time> and <to_time> are under the form hh:mm:ss (for example, 10:07:23)

The second block consists of queries (terminated by a line containing #), each query in a line (number of lines can be up to 100000) and belongs to one of the following types:
?check_phone_number: print to stdout (in a new line) value 1 if no phone number is incorrect
?number_calls_from <phone_number>: print to stdout (in a new line) the number of times a call is made from <phone_number>
?number_total_calls: print to stdout (in a new line) the total number of calls of the data
?count_time_calls_from <phone_number>: print to stdout (in a new line) the total time duration (in seconds) the calls are made from <phone_number>

Example
Input
call 0912345678 0132465789 2022-07-12 10:30:23 10:32:00
call 0912345678 0945324545 2022-07-13 11:30:10 11:35:11
call 0132465789 0945324545 2022-07-13 11:30:23 11:32:23
call 0945324545 0912345678 2022-07-13 07:30:23 07:48:30
#
?check_phone_number
?number_calls_from 0912345678
?number_total_calls
?count_time_calls_from 0912345678
?count_time_calls_from 0132465789
#

Output
1
2
4
398
120
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> fphone;
vector<string> tphone;
vector<string> date;
vector<string> ftime;
vector<string> ttime;

unordered_map<string, int> number_calls_from;
int total_calls = 0;
vector<int> compute_ftime;
vector<int> compute_ttime;

vector<int> out;

int checkPhoneNumber()
{
    // check fphone
    for (vector<string>::iterator it = fphone.begin(); it != fphone.end(); it++)
    {
        if ((*it).size() != 10)
        {
            return -1;
        }

        for (int i = 0; i < 10; i++)
        {
            if ((*it)[i] < '0' || (*it)[i] > '9')
            {
                return -1;
            }
        }
    }

    // check tphone
    for (vector<string>::iterator it = tphone.begin(); it != tphone.end(); it++)
    {
        if ((*it).size() != 10)
        {
            return -1;
        }

        for (int i = 0; i < 10; i++)
        {
            if ((*it)[i] < '0' || (*it)[i] > '9')
            {
                return -1;
            }
        }
    }

    return 1;
}

int numberCallsFrom(string p)
{
    return number_calls_from[p];
}

int countTimeCallsFrom(string p)
{
    int number_of_times = number_calls_from[p];
    int cnt = 0;
    int total_time = 0;

    for (int i = 0; i < fphone.size(); i++)
    {
        if (cnt == number_of_times)
        {
            break;
        }

        if (fphone[i] == p)
        {
            // compute "from time" - ftime
            for (int j = 0; j < ftime[i].size(); j++)
            {
                if (ftime[i][j] == ':')
                {
                    ftime[i][j] = ' ';
                }
            }
            stringstream s1(ftime[i]);
            string word1;

            while (s1 >> word1)
            {
                compute_ftime.push_back(stoi(word1));
            }

            // compute "to time" - ttime
            stringstream s2(ttime[i]);
            string word2;

            while (getline(s2, word2, ':'))
            {
                compute_ttime.push_back(stoi(word2));
            }

            // compute time
            total_time += (compute_ttime[0] * 3600 + compute_ttime[1] * 60 + compute_ttime[2]) -
                          (compute_ftime[0] * 3600 + compute_ftime[1] * 60 + compute_ftime[2]);

            compute_ftime.clear();
            compute_ttime.clear();

            cnt++;
        }
    }

    return total_time;
}

void input()
{
    string string1, string2, string3, string4, string5, string6;
    string query;
    string tmp;

    while (1)
    {
        cin >> string1;
        if (string1 == "#")
        {
            break;
        }

        cin >> string2;
        fphone.push_back(string2);
        number_calls_from[string2]++;

        cin >> string3;
        tphone.push_back(string3);

        cin >> string4;
        date.push_back(string4);

        cin >> string5;
        ftime.push_back(string5);

        cin >> string6;
        ttime.push_back(string6);

        total_calls++;
    }

    while (1)
    {
        cin >> query;
        if (query == "#")
        {
            break;
        }

        if (query == "?check_phone_number")
        {
            out.push_back(checkPhoneNumber());
        }
        else if (query == "?number_calls_from")
        {
            cin >> tmp;
            out.push_back(numberCallsFrom(tmp));
        }
        else if (query == "?number_total_calls")
        {
            out.push_back(total_calls);
        }
        else if (query == "?count_time_calls_from")
        {
            cin >> tmp;
            out.push_back(countTimeCallsFrom(tmp));
        }
    }
}

void output()
{
    for (vector<int>::iterator it = out.begin(); it != out.end(); it++)
    {
        cout << (*it) << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();

    output();

    return 0;
}