#include <bits/stdc++.h>
#include <time.h>
using namespace std;
clock_t begin, end;
double time_;
int ** matrix_allocate(int n, int m) {
        int i, j;
        int ** mat = (int ** ) malloc(n * sizeof(int * ));
        for (i = 0; i < n; ++i) {
                mat[i] = (int * ) malloc(m * sizeof(int));
        }
        return mat;
}
int Peak(int ** mat, int r, int c) {
        if (r == 1 && c == 1) {
                return mat[0][0];
        }
        for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                        if (j == 0 && i == 0) {//corner top left side
                                if (mat[i][j] >= mat[i + 1][j] && mat[i][j] >= mat[i][j + 1]) {
                                        return mat[i][j];
                                }
                        } else if (i == 0 && j > 0 && j < c - 1) {//corner top middle elements
                                if (mat[i][j] >= mat[i + 1][j] && mat[i][j] >= mat[i][j - 1] && mat[i][j] >= mat[i][j + 1]) {
                                        return mat[i][j];
                                }
                        } else if (j == 0 && i > 0 && i < r - 1) {//corner left side elements
                                if (mat[i][j] >= mat[i - 1][j] && mat[i][j] >= mat[i + 1][j] && mat[i][j] >= mat[i][j + 1]) {
                                        return mat[i][j];
                                }
                        } else if (i == r - 1 && j == 0) {//corner bottom left side
                                if (mat[i][j] >= mat[i - 1][j] && mat[i][j] >= mat[i][j + 1]) {
                                        return mat[i][j];
                                }
                        } else if (i == r - 1 && j > 0 && j < c - 1) {//corner bottom elements
                                if (mat[i][j] >= mat[i - 1][j] && mat[i][j] >= mat[i][j - 1] && mat[i][j] >= mat[i][j + 1]) {
                                        return mat[i][j];
                                }
                        } else if (i == r - 1 && j == c - 1) {//bottom right side
                                if (mat[i][j] >= mat[i - 1][j] && mat[i][j] >= mat[i][j - 1]) {
                                        return mat[i][j];
                                }
                        } else if (j == c - 1 && i == 0) {//top right side
                                if (mat[i][j] >= mat[i + 1][j] && mat[i][j] >= mat[i][j - 1]) {
                                        return mat[i][j];
                                }
                        } else if (j == c - 1 && i > 0 && i < r - 1) {//corner right side elements
                                if (mat[i][j] >= mat[i - 1][j] && mat[i][j] >= mat[i + 1][j] && mat[i][j] >= mat[i][j - 1]) {
                                        return mat[i][j];
                                }
                        } else {//for middle elements
                                if (mat[i][j] >= mat[i - 1][j] && mat[i][j] >= mat[i + 1][j] && mat[i][j] >= mat[i][j - 1] && mat[i][j] >= mat[i][j + 1]) {
                                        return mat[i][j];
                                }
                        }
                }
        }
}
int main() {
        int r, c;
        printf("Enter rows and columns:");
        cin >> r >> c;
        int ** mat = matrix_allocate(r, c);
        printf("\nEnter matrix elements:");
        for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                        cin >> mat[i][j];
                        cout << mat[i][j];
                }
        }
        int mid = c / 2;
        begin = clock();
        cout << "\n\nFirst Peak element is : " << Peak(mat, r, c);
        end = clock();
        time_ = ((double)(end - begin)) / CLOCKS_PER_SEC;
        cout << "\nTime taken :" << time_;
        return 0;
}
