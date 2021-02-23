// Написать программу которая переворачивает строку

#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    string greeting = "Hello";
    reverse(greeting.begin(), greeting.end());
    cout << greeting << endl;
}