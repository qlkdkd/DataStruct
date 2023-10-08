#include <stdio.h>
#define  MAX_TERMS 100

typedef struct {
    int row;
    int col;
    int value;
} element;
typedef struct SparseMatrix {
    element data[MAX_TERMS];
    int rows; // ���� ����
    int cols; // ���� ����
    int terms; // ���� ����
} SparseMatrix;

SparseMatrix x1 = { {{1,1,5},{2,2,9}}, 3, 3, 2 };//(1, 1)�� 5 ��ġ, (2, 2)�� 9 ��ġ(�������� ���� 0)
SparseMatrix y1 = { {{0,0,5},{2,2,9}}, 3, 3, 2 };

SparseMatrix x2 = { {{0,0,1},{0,1,2},{0,2,3},{1,0,1},{1,1,2},{1,2,3},{2,0,1},{2,1,2},{2,2,3}}, 3, 3, 9 };
SparseMatrix y2 = { {{0,0,1},{0,1,1},{0,2,1},{1,0,1},{1,1,1},{1,2,1},{2,0,1},{2,1,1},{2,2,1}}, 3, 3, 9 };

SparseMatrix x3 = { {{0,0,7},{0,2,2},{1,2,3},{2,0,7}}, 3, 3, 4 };
SparseMatrix y3 = { {{0,1,5},{0,2,8},{1,2,4},{2,0,4},{2,2,1}}, 3, 3, 5 };


//��� ����� �Ϲ� ��ķ� ��ȯ�ϴ� �Լ�
void sparseToDense(SparseMatrix sparse, int dense[][MAX_TERMS]) {
    for (int i = 0; i < sparse.rows; i++) {
        for (int j = 0; j < sparse.cols; j++) {
            dense[i][j] = 0; // �ϴ� ��� ��Ҹ� 0���� �ʱ�ȭ
        }
    }

    for (int i = 0; i < sparse.terms; i++) {
        dense[sparse.data[i].row][sparse.data[i].col] = sparse.data[i].value;
    }
}


//��ĵ��� �����ִ� �Լ�
void matrixMultiply(int a[][MAX_TERMS], int b[][MAX_TERMS], int result[][MAX_TERMS], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}



//����� ����ϴ� �Լ�
void printMatrix(int mat[][MAX_TERMS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("------------------------------------\n");
}


int main() {
    int result[MAX_TERMS][MAX_TERMS];

    // x1�� y1�� ��� ����� �Ϲ� ��ķ� ��ȯ
    int dense_x1[3][3];
    int dense_y1[3][3];
    sparseToDense(x1, dense_x1);
    printf("x1: \n");
    printMatrix(dense_x1, x1.rows, x1.cols);
    printf("\n");
    sparseToDense(y1, dense_y1);
    printf("y1: \n");
    printMatrix(dense_y1, y1.rows, y1.cols);
    printf("\n");

    // �� ����� ���ϰ� ����� ���
    matrixMultiply(dense_x1, dense_y1, result, x1.rows, x1.cols, y1.cols);
    printf("x1 * y1 ���:\n");
    printMatrix(result, x1.rows, y1.cols);

    // x2�� y2�� ��� ����� �Ϲ� ��ķ� ��ȯ
    int dense_x2[3][3];
    int dense_y2[3][3];
    sparseToDense(x2, dense_x2);
    printf("x2: \n");
    printMatrix(dense_x2, x2.rows, x2.cols);
    sparseToDense(y2, dense_y2);
    printf("y2: \n");
    printMatrix(dense_y2, y2.rows, y2.cols);


    // �� ����� ���ϰ� ����� ���
    matrixMultiply(dense_x2, dense_y2, result, x2.rows, x2.cols, y2.cols);
    printf("\nx2 * y2 ���:\n");
    printMatrix(result, x2.rows, y2.cols);

    // x3�� y3�� ��� ����� �Ϲ� ��ķ� ��ȯ
    int dense_x3[3][3];
    int dense_y3[3][3];
    sparseToDense(x3, dense_x3);
    printf("x3: \n");
    printMatrix(dense_x3, x3.rows, x3.cols);
    sparseToDense(y3, dense_y3);
    printf("y3: \n");
    printMatrix(dense_y3, y3.rows, y3.cols);

    // �� ����� ���ϰ� ����� ���
    matrixMultiply(dense_x3, dense_y3, result, x3.rows, x3.cols, y3.cols);
    printf("\nx3 * y3 ���:\n");
    printMatrix(result, x3.rows, y3.cols);

    return 0;
}