#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Node {
public:
    char data;
    float freq;
    Node *left, *right;

    Node(char d, float f) {
        data = d;
        freq = f;
        left = right = NULL;
    }
};

float totalCompressedBits = 0;

void findTwoMin(Node* arr[], int n, int &min1, int &min2) {
    min1 = -1;
    min2 = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == NULL) continue;
        if (min1 == -1 || arr[i]->freq < arr[min1]->freq) {
            min2 = min1;
            min1 = i;
        }
        else if (min2 == -1 || arr[i]->freq < arr[min2]->freq) {
            min2 = i;
        }
    }
}

Node* buildHuffman(Node* arr[], int n) {
    int currentSize = n;
    while (currentSize > 1) {
        int min1, min2;
        findTwoMin(arr, currentSize, min1, min2);

        Node* leftNode = arr[min1];
        Node* rightNode = arr[min2];

        Node* newNode = new Node('$', leftNode->freq + rightNode->freq);
        newNode->left = leftNode;
        newNode->right = rightNode;

        arr[min1] = newNode;

        for (int i = min2; i < currentSize - 1; i++) {
            arr[i] = arr[i + 1];
        }
        currentSize--;
    }
    return arr[0];
}

void printCodes(Node* root, int code[], int top) {
    if (root->left) {
        code[top] = 0;
        printCodes(root->left, code, top + 1);
    }
    if (root->right) {
        code[top] = 1;
        printCodes(root->right, code, top + 1);
    }
    if (!root->left && !root->right) {
        cout << root->data << " : ";
        for (int i = 0; i < top; i++) cout << code[i];
        cout << endl;

        // bits = frequency * length of the code
        totalCompressedBits += (root->freq * top);
    }
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    char ch[50];
    float freq[50];

    cout << "Enter characters:\n";
    for (int i = 0; i < n; i++) cin >> ch[i];

    cout << "Enter frequencies:\n";
    for (int i = 0; i < n; i++) cin >> freq[i];

    // Calculate fixed-length bits needed (e.g., for 5 chars, we need 3 bits)
    // Formula: ceil(log2(n))
    float fixedBitsPerChar = ceil(log2(n));
    float totalOriginalBits = fixedBitsPerChar;

    Node* arr[50];
    for (int i = 0; i < n; i++) {
        arr[i] = new Node(ch[i], freq[i]);
    }

    Node* root = buildHuffman(arr, n);

    int code[100];
    cout << "\nHuffman Codes:\n";
    printCodes(root, code, 0);

    // Results using your formula: cr = ((original - compressed) / original) * 100
    cout << fixed << setprecision(2);
    cout << "\n--- Compression Analysis ---" << endl;
    cout << "Original bits (Fixed-length): " << totalOriginalBits << endl;
    cout << "Compressed bits (Huffman):    " << totalCompressedBits << endl;

    float cr = ((totalOriginalBits - totalCompressedBits) / totalOriginalBits) * 100;

    cout << "Compression Ratio:            " << cr << "%" << endl;

    return 0;
}
