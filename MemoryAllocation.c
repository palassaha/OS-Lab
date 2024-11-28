//check code

#include <stdio.h>
#include <stdlib.h>

#define MAX_PARTITIONS 10
#define MAX_PROCESSES 10

void printTable(int processSize[], int m, int allocation[], const char* title) {
    printf("\n%s Allocation:\n", title);
    printf("+-----------+--------------+--------------+\n");
    printf("| Process | Process Size | Block Number |\n");
    printf("+-----------+--------------+--------------+\n");
    for (int i = 0; i < m; i++) {
        if (allocation[i] != -1)
            printf("| %-9d | %-12d | %-12d |\n", i + 1, processSize[i], allocation[i] + 1);
        else
            printf("| %-9d | %-12d | %-12s |\n", i + 1, processSize[i], "Not Allocated");
    }
    printf("+-----------+--------------+--------------+\n");
}

void bestFit(int processSize[], int m, int blockSize[], int n) {
    int allocation[MAX_PROCESSES];
    for (int i = 0; i < m; i++)
        allocation[i] = -1;

    for (int i = 0; i < m; i++) {
        int bestIdx = -1;
        for (int j = 0; j < n; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }
    printTable(processSize, m, allocation, "Best Fit");
}

void firstFit(int processSize[], int m, int blockSize[], int n) {
    int allocation[MAX_PROCESSES];
    for (int i = 0; i < m; i++)
        allocation[i] = -1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
    printTable(processSize, m, allocation, "First Fit");
}

void worstFit(int processSize[], int m, int blockSize[], int n) {
    int allocation[MAX_PROCESSES];
    for (int i = 0; i < m; i++)
        allocation[i] = -1;

    for (int i = 0; i < m; i++) {
        int worstIdx = -1;
        for (int j = 0; j < n; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                    worstIdx = j;
            }
        }
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }
    printTable(processSize, m, allocation, "Worst Fit");
}

int main() {
    int processSize[MAX_PROCESSES], blockSize[MAX_PARTITIONS], blockSize2[MAX_PARTITIONS], blockSize3[MAX_PARTITIONS];
    int m, n;

    printf("Enter number of processes: ");
    scanf("%d", &m);
    printf("Enter the size of each process:\n");
    for (int i = 0; i < m; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    printf("Enter number of memory blocks: ");
    scanf("%d", &n);
    printf("Enter the size of each block:\n");
    for (int i = 0; i < n; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
        blockSize2[i] = blockSize[i];
        blockSize3[i] = blockSize[i];
    }

    bestFit(processSize, m, blockSize, n);
    firstFit(processSize, m, blockSize2, n);
    worstFit(processSize, m, blockSize3, n);

    return 0;
}