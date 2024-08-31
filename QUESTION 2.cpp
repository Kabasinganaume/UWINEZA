#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printDivisors(int n) {
    vector<int> divisors;
    
    // Finding divisors
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
        }
    }
    
    // Sorting divisors in decreasing order
    sort(divisors.rbegin(), divisors.rend());
    
    cout << "Divisors of " << n << " in decreasing order:" << endl;
    
    // Using a traditional for loop to iterate over the divisors
    for (size_t i = 0; i < divisors.size(); ++i) {
        cout << divisors[i] << endl;
    }
}

int main() {
    cout << "\t\t\t Welcome to the executing machine  \n" << endl;
    cout << "This is the execiting designed to exhibit the positive divisors of positive integers supplied by you." << endl;
    cout << "You'll be able to enter a positive integer." << endl;
    cout << "Each time you enter a positive integer,the executing machine will print all the divisors of your integer in a column and in decreasing order." << endl;
    cout << "You may terminate the executing machni by entering a negative integer." << endl;

    while (true) {
        int num;
        cout << "\nPlease enter a positive integer (or enter a negative integer to quit): ";
        cin >> num;

        if (num <= 0) {
            cout << "the executing machine terminated. Thank you!" << endl;
            break;
        }
        
        printDivisors(num);

        char choice;
        cout << "Would you like to enter another integer? (Y/N): ";
        cin >> choice;

        // Validate the user's choice
        while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
            cout << "Please respond with Y (or y) for yes and N (or n) for no." << endl;
            cout << "Would you like to enter another integer? (Y/N): ";
            cin >> choice;
        }

        if (choice == 'n' || choice == 'N') {
            cout << "the executing machine terminated. Thank you!" << endl;
            break;
        }
    }

    return 0;
}

