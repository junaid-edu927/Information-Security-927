#include <iostream>

using namespace std;

int main() {
    char text[100];
    int nums[100];
    int len = 0;
    int K[2][2] = {{2, 1}, {1, 1}};

    cout << "Enter text (uppercase letters only): ";
    cin >> text;

    cout << "\n--- Step 1: Grouping Preparation ---\n";
    for (int i = 0; text[i] != '\0'; i++) {
        nums[len++] = text[i] - 'A';
    }
    if (len % 2 != 0) {
        nums[len++] = 23;
    }
    cout << "Converted Numbers (A=0, B=1...): ";
    for(int i = 0; i < len; i++) cout << nums[i] << " ";
    cout << "\n";

    cout << "\n--- Step 2: Hill Cipher Application ---\n";
    for (int i = 0; i < len; i += 2) {
        int p1 = nums[i];
        int p2 = nums[i + 1];
        nums[i] = (K[0][0] * p1 + K[0][1] * p2) % 26;
        nums[i + 1] = (K[1][0] * p1 + K[1][1] * p2) % 26;
    }
    cout << "Hill Cipher Transformed Numbers: ";
    for(int i = 0; i < len; i++) cout << nums[i] << " ";
    cout << "\n";

    cout << "\n--- Step 3: AES-like Shifting Method ---\n";
    for (int i = 0; i < len; i += 4) {
        if (i + 3 < len) {
            int temp = nums[i + 1];
            nums[i + 1] = nums[i + 3];
            nums[i + 3] = nums[i + 2];
            nums[i + 2] = temp;
        }
    }
    cout << "Shifted Numbers: ";
    for(int i = 0; i < len; i++) cout << nums[i] << " ";
    cout << "\n";

    cout << "\n--- Final Output ---\n";
    cout << "Encrypted Text: ";
    for (int i = 0; i < len; i++) {
        cout << (char)(nums[i] + 'A');
    }
    cout << "\n";

    return 0;
}