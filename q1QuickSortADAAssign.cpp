// Question1
#include <iostream>
using namespace std;

int partition(int arr[], int size){
    int starting_element = arr[0], count = 0; // starting element pivot element man liya

    // ab hum pivot element ke right mei check karenge
    // usse chotte element ko uske sath swap kar denge
    for (int i = 1; i < size; i++){ // i = 1 isliye liya kyunki i = 0 pe toh already pivot element pada hai
        if (arr[i] < starting_element){
            count++;
        }
    }
    arr[0] = arr[count];
    arr[count] = starting_element;
    return count;
}

void quickSort(int arr[], int size){
    // base case
    if (size <= 1) return;

    int c = partition(arr, size); // yahan c = pivot element
    int i = 0, j = size - 1;

    while (i < c && j > c){
        if (arr[i] >= arr[c]){
            if (arr[j] < arr[c]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
            else{
                j--;
            }
        }
        else i++;
    }

    quickSort(arr, c);
    quickSort(arr + (c + 1), size - c - 1);
}

int main(){
    int n; 
    cout<<"enter the value of n"<<endl;
    cin >> n;

    int *arr = new int[n];
    cout<<"enter the values "<<endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    quickSort(arr, n);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    delete [] arr;
}
