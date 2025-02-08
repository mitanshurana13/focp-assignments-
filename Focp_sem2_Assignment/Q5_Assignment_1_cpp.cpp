#include <iostream>
using namespace std;

// Function to rotate the matrix by 90 degrees clockwise
void rotateMatrix(int n, int matrix[][100]) {
    // First, transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Then, reverse each row
    for (int i = 0; i < n; i++) {
        for (int j = 0, k = n - 1; j < k; j++, k--) {
            swap(matrix[i][j], matrix[i][k]);
        }
    }
}

// Function to print the matrix
void printMatrix(int n, int matrix[][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;
    
    int matrix[100][100]; // Assuming max size is 100x100
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Original Matrix:\n";
    printMatrix(n, matrix);

    rotateMatrix(n, matrix);

    cout << "Rotated Matrix (90 degrees clockwise):\n";
    printMatrix(n, matrix);

    return 0;
}