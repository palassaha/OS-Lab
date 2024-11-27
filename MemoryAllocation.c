// Evaluate the memory allocation methods for fixed partition using First fit/ Best fit/ Worst fit

#include <stdio.h>

#define MAX_HOLES 10
#define MAX_REQUESTS 10

void bestFit(int holes[], int numHoles[], int requests[], int numRequests);
void worstFit(int holes[], int numHoles[], int requests[], int numRequests);
void firstFit(int holes[], int numHoles[], int requests[], int numRequests);
void printTable(int requests[], int selectedHoles[], int leftover, int numRequests);
void printLeftOverHoles(int originalHoles[], int holes[], int numHoles);

int main() {
    int holes[MAX_HOLES], originalHoles[MAX_HOLES], requests[MAX_REQUESTS];
    int numHoles, numRequests;

    printf("Enter no of memory holes:\n");
    scanf("%d", &numHoles);
    for(int i=0; i<numHoles; i++) {
        printf("Hole %d:", i+1);
        scanf("%d", &holes[i]);
        originalHoles[i] = holes[i];
    }

    printf("Enter no of memory requests:\n");
    scanf("%d", &numRequests);
    for(int i=0; i<numRequests; i++) {
        printf("Request %d:", i+1);
        scanf("%d", &holes[i]);
    }

    

}
