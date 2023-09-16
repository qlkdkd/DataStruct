#include <stdio.h>
#include <string.h>

#define N_STUDENTS  4

typedef struct student_info {
    char    name[10];
    int     height;
    float   weight;
} student_info;

student_info students[N_STUDENTS] = {
    {"�̼���", 172, 83.4},
    {"ȫ�浿", 167, 72.5},
    {"������", 159, 70.8},
    {"������", 163, 58.4}
};

void selectionSort(student_info arr[], int n, char key) {//key�˻� �˰����� Ȱ���Ͽ� ������ ��� ã��
    int i, j, min_idx;
    student_info tmp;
   
    //���� ��� �˻��ϱ�
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (key == 'n' && strcmp(arr[j].name, arr[min_idx].name) < 0) {
                min_idx = j;//�̸������� �����ϴ� ����̹Ƿ� strcmp �Լ� ���
            }
            else if (key == 'h' && arr[j].height < arr[min_idx].height) {
                min_idx = j;
            }
            else if (key == 'w' && arr[j].weight < arr[min_idx].weight) {
                min_idx = j;
            }
        }

        //�����ϱ�
        tmp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = tmp;
    }
}

void printStudents(student_info arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("�̸�: %s, Ű: %d, ������: %.1f\n", arr[i].name, arr[i].height, arr[i].weight);
    }
}

int main() {
    printf("���� ������:\n");
    printStudents(students, N_STUDENTS);

    printf("\n�л� �̸����� ����:\n");
    selectionSort(students, N_STUDENTS, 'n');//key���� n(�̸�)���� �����Ͽ� �̸������� �����ϱ�
    printStudents(students, N_STUDENTS);

    printf("\nŰ�� ����:\n");
    selectionSort(students, N_STUDENTS, 'h');//key���� h(Ű)�� �����Ͽ� Ű������ �����ϱ�
    printStudents(students, N_STUDENTS);

    printf("\n�����Է� ����:\n");
    selectionSort(students, N_STUDENTS, 'w');//key���� w(������)�� �����Ͽ� �����Լ����� �����ϱ�
    printStudents(students, N_STUDENTS);

    return 0;
}