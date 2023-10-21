#include <iostream>
#include <string>

using namespace std;

string changeLightColors(string S, int K) {
    string colors = "RGB";

    for (int i = 0; i < K; i++) {
        string new_S = "";

        for (char c : S) {
            int current_color_index = colors.find(c);
            int next_color_index = (current_color_index + 1) % 3;
            new_S += colors[next_color_index];
        }

        S = new_S;
    }

    return S;
}

int main() {
    string S = "RBRG";
    int K = 2;
    string result = changeLightColors(S, K);
    cout << result << endl;
    return 0;
}
