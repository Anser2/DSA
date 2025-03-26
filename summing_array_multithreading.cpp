#include <iostream>
#include <pthread.h>
#include <ctime>
using namespace std;

#define NUM_THREADS 2
#define rows 10000
#define columns 10000

pthread_mutex_t mutex;

struct ThreadData{
    int start;
    int end;
};

long long int array[rows][columns];
long long int sum = 0;

void* sumArray(void* arg){
    ThreadData* data = (ThreadData*)arg;
    for(int i=data->start; i<data->end; i++){
        for (int j = 0; j < columns; j++) {
            pthread_mutex_lock(&mutex);
            sum += array[i][j];
            pthread_mutex_unlock(&mutex);
        }    
    }
    return NULL;
}


int main(){
    
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
        array[i][j]= (i+1)*(j+1);
        }
    }
    
    pthread_mutex_init(&mutex, NULL);
    pthread_t thread[NUM_THREADS];
    ThreadData data[NUM_THREADS];

    clock_t start_time = clock();  // Start time

    for(int i=0; i<NUM_THREADS; i++){
        data[i].start = (rows * i)/NUM_THREADS;
        data[i].end = (i == NUM_THREADS - 1) ? rows : (rows * (i + 1)) / NUM_THREADS;  
        pthread_create(&thread[i], NULL, sumArray, (void*)&data);
        
    }
    for(int i=0; i<NUM_THREADS; i++){
        pthread_join(thread[i], NULL);
    }
    
    clock_t end_time = clock();  // End time
    double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;

    pthread_mutex_destroy(&mutex);
    
    // for(int i=0; i<rows; i++){
    //     for(int j=0; j<columns; j++){
    //         cout << array[i][j] << " " ;
    //     }
    // }
    cout << endl << "Total sum: " << sum << endl;
    cout << "Execution Time: " << elapsed_time << " seconds" << endl;


    
    return 0;
    
}