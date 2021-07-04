
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>

using namespace std;

vector<int> tosort;

int partition(int min_index, int max_index) {
    srand(time(NULL));

    //this is the index of randomly selected pivot
    int random = rand()%(max_index-min_index+1);
    int pivot;
    int temp;

    //swap pivot to the end of the list
    temp = tosort[max_index];
    tosort[max_index] = tosort[min_index + random];
    tosort[min_index + random] = temp;
    pivot = tosort[max_index];

    int j = min_index;
    
    for (int i = min_index; i < max_index; i++) {
        if (tosort[i] > pivot) {
            temp = tosort[j];
            tosort[j] = tosort[i];
            tosort[i] = temp;
            j++;
        }
    }

    temp = tosort[j];
    tosort[j] = tosort[max_index];
    tosort[max_index] = temp;
    return j;
}
void quicksort(int min_index, int max_index) {
    //if size = 1
    if (max_index - min_index == 0) {
        return;
    }
    //if size = 2
    if (max_index - min_index == 1) {
        if (tosort[max_index] > tosort[min_index]) {
            int temp = tosort[max_index];
            tosort[max_index] = tosort[min_index];
            tosort[min_index] = temp;
            return;
        }
    }
    if (min_index < max_index) {
        int pivot = partition(min_index, max_index);
        quicksort(min_index, pivot - 1);
        quicksort(pivot + 1, max_index);
    }
}

int main()
{
    string input;
    char token;
    int token_int;
    int temp = 0;
    bool negative = false;

    //please dont enter any spaces!!
    cout << "Please enter the list: ";
    cin >> input;

    auto i = input.begin();
    token = *i;

    while (token != '*') {
        token_int = (int)token - '0';
        if (token_int >= 0 && token_int <= 9) {
            temp = temp * 10 + token_int;

        }
        else if (token == '-') {
            negative = true;
        }
        else {
            if (negative == true) {
                tosort.push_back(temp * -1);
            }
            else {
                tosort.push_back(temp);
            }

            temp = 0;
            negative = false;
        }
        token = *(++i);
        if (token == '*') {
            if (negative == true) {
                tosort.push_back(temp * -1);
            }
            else {
                tosort.push_back(temp);
            }

        }
    }

    quicksort(0, tosort.size() - 1);

    for (int i = 0; i < tosort.size() - 1; i++) {
        cout << tosort[i] << ", ";
    }
    cout << tosort[tosort.size() - 1];
}
