#include <bits/stdc++.h>
using namespace std;
// final formula
double answer(double q, double total_probabilty_sum)
{

    double ans = (1 / (q - 1)) * (1 - total_probabilty_sum);
    return ans;
}

double tsallis_Entropy(string str, int start, int end, double window_size, double q)
{

    // to find total sum of probability
    double count1 = 0;
    double count0 = 0;
    double probability_of_0 ;
    double probability_of_1 = 0;
    double total_probabilty_sum = 0;

    for (int i = start; i < end; i++)
    {

        if (str[i] == '1')
        {
            count1++;
        }
        else
            count0++;
    }

    probability_of_0 = pow((count0 / window_size), q);
    probability_of_1 = pow((count1 / window_size), q);
    total_probabilty_sum = probability_of_0 + probability_of_1;

    return answer(q, total_probabilty_sum);
}

int main()
{
    string str = "";
    ifstream input_value;
    input_value.open("inp.csv");
    cout << endl<< endl;
    cout << " The string is"<< " ";

    double q = 2;
    // string input--------->
    while (input_value.eof() == 0)
    {
        getline(input_value, str);
        cout << str << endl;
        input_value.close();
    }
    ofstream output_value;
    output_value.open("out.csv");
    double window_size;
    cout << "enter window size ";
    cin >> window_size;

    // to find the no. of windows--->
    int no_ofWindows = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if ((i + window_size) > str.size())
            break;
        no_ofWindows++;
    }

    for (int i = 0; i < no_ofWindows; i++)
    {
        output_value << "Tsallis entropy for window " << i + 1 <<  "is "<<
                    tsallis_Entropy(str, i, window_size + i, window_size, q) << endl;
    }
    output_value.close();
    return 0;
}