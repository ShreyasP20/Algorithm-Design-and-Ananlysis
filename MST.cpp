#include<iostream>
using namespace std;

void mst(int gr[10][10], int n);

int main() {
    int gr[10][10];
    int n;
    
    cout << "Enter the number of Elements:" << endl;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cout << "Enter the Weight from " << i;
        for (int j = 0; j < n; j++) {
            cout << " to " << j << ": ";
            if (i == j) {
                gr[i][j] = 100000;
            } else {
                cin >> gr[i][j];
            }
            cout << endl;
        }
    }

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << gr[i][j] << "\t";
        }
        cout << endl;
    }  
    mst(gr, n);
    return 0;
}

void mst(int gr[10][10], int n) {
    int sum = 0;
    int visited[n];

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    while (true) {
        int min_val = 100000; 
        int min_vert = -1, min_verta = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && gr[i][j] < min_val) {
                        min_val = gr[i][j];
                        min_verta = j;
                        min_vert = i;
                    }
                }
            }
        }

        if (min_vert == -1 || min_verta == -1) {
            break;
        }

        
        sum += min_val;
        gr[min_vert][min_verta] = 100000;
        visited[min_verta] = 1;

        for (int i = 0; i < n; i++) {
            gr[min_verta][i] = 0;
        }

        cout << sum << endl;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << gr[i][j] << "\t";
            }
            cout << endl;
        }
    }
}
