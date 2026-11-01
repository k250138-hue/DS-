#include <iostream>
using namespace std;

int recursiveArraySum(int* arr[], int sizes[], int dim) {
    int sum = 0;
    
    if (dim == 1) {
        for (int i = 0; i < sizes[0]; ++i) {
            if (arr[i] != nullptr) {
                sum += *arr[i]; 
            }
        }
        return sum;
    }

    for (int i = 0; i < sizes[0]; ++i) {
        if (arr[i] != nullptr) {
            sum += recursiveArraySum((int**)arr[i], sizes + 1, dim - 1);
        }
    }

    return sum;
}

int** createJaggedArray(int sizes[], int dim) {
    int** arr = new int*[sizes[0]];

    if (dim == 1) {
        for (int i = 0; i < sizes[0]; ++i) {
            cout << "Enter value for element " << i + 1 << ": ";
            int val;
            cin >> val;
            arr[i] = new int(val);
        }
    } else {
        for (int i = 0; i < sizes[0]; ++i) {
            cout << "Level " << dim << ", index " << i << endl;
            arr[i] = (int*)createJaggedArray(sizes + 1, dim - 1);
        }
    }

    return arr;
}

void deleteJaggedArray(int* arr[], int sizes[], int dim) {
    if (dim == 1) {
        for (int i = 0; i < sizes[0]; ++i) {
            delete (int*)arr[i];
        }
    } else {
        for (int i = 0; i < sizes[0]; ++i) {
            if (arr[i] != nullptr) {
                deleteJaggedArray((int**)arr[i], sizes + 1, dim - 1);
            }
        }
    }
    delete[] arr;
}

int main() {
    int dim;
    cout << "Enter dimensions: ";
    cin >> dim;

    if (dim <= 0) {
        return 0;
    }

    int* sizes = new int[dim];
    cout << "Enter size of each dimension:\n";
    for (int i = 0; i < dim; ++i) {
        cin >> sizes[i];
    }

    int** root = createJaggedArray(sizes, dim);

    int totalSum = recursiveArraySum(root, sizes, dim);
    cout << "Sum: " << totalSum << endl;

    deleteJaggedArray(root, sizes, dim);
    delete[] sizes;

    return 0;
}