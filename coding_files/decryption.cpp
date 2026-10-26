#include <iostream>

using namespace std;

int main() {
    char text[100];
    int nums[100];
    int len = 0;
    int K_inv[2][2] = {{1, 25}, {25, 2}};

    cout << "Enter encrypted text (uppercase letters only): ";
    cin >> text;

    for (int i = 0; text[i] != '\0'; i++) {
        nums[len++] = text[i] - 'A';
    }

    cout << "\n--- Step 1: Reverse AES-like Shifting ---\n";
    for (int i = 0; i < len; i += 4) {
        if (i + 3 < len) {
            int temp = nums[i + 3];
            nums[i + 3] = nums[i + 1];
            nums[i + 1] = nums[i + 2];
            nums[i + 2] = temp;
        }
    }
    cout << "Reversed Shift Numbers: ";
    for(int i = 0; i < len; i++) cout << nums[i] << " ";
    cout << "\n";

    cout << "\n--- Step 2: Reverse Hill Cipher ---\n";
    for (int i = 0; i < len; i += 2) {
        int p1 = nums[i];
        int p2 = nums[i + 1];
        nums[i] = (K_inv[0][0] * p1 + K_inv[0][1] * p2) % 26;
        nums[i + 1] = (K_inv[1][0] * p1 + K_inv[1][1] * p2) % 26;
    }
    cout << "Original Numbers: ";
    for(int i = 0; i < len; i++) cout << nums[i] << " ";
    cout << "\n";

    cout << "\n--- Step 3: Combine The Text ---\n";
    cout << "Decrypted Text: ";
    for (int i = 0; i < len; i++) {
        if (nums[i] == 23 && i == len - 1) {
            continue;
        }
        cout << (char)(nums[i] + 'A');
    }
    cout << "\n";

    return 0;
}