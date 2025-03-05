#include <iostream>
#include <string>
#include <algorithm> // For sorting
using namespace std;

class Queue {
private:
    static const int MAX_SIZE = 100; // Maximum size of the queue
    int array[MAX_SIZE];             // Array to store patient IDs
    int front_idx, rear_idx;         // Indices for front and rear of the queue

public:
    // Constructor to initialize the queue
    Queue() : front_idx(-1), rear_idx(-1) {}

    // Function to check if the queue is empty
    bool isEmpty() const {
        return front_idx == -1 && rear_idx == -1;
    }

    // Function to check if the queue is full
    bool isFull() const {
        return rear_idx == MAX_SIZE - 1;
    }

    // Enqueue operation: Add an element at the rear end of the queue
    void Enqueue(int element) {
        if (isFull()) {
            cout << "Queue overflow! Cannot enqueue more patients." << endl;
            return;
        }
        if (isEmpty()) {
            front_idx = rear_idx = 0; // Initialize both indices for the first element
        } else {
            rear_idx++; // Increment rear index
        }
        array[rear_idx] = element;
        cout << "Patient with ID " << element << " registered." << endl;
    }

    // Dequeue operation: Remove and display the element from the front end of the queue
    int Dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow! No patients to serve." << endl;
            return -1; // Return -1 to indicate failure
        }
        int servedPatient = array[front_idx];
        cout << "Serving patient with ID " << servedPatient << "." << endl;

        if (front_idx == rear_idx) {
            front_idx = rear_idx = -1; // Reset indices if the queue becomes empty
        } else {
            front_idx++; // Move the front index forward
        }
        return servedPatient;
    }

    // FirstElement operation: Display the contents of the first element of the queue
    void FirstElement() const {
        if (isEmpty()) {
            cout << "No patients in the queue." << endl;
            return;
        }
        cout << "First patient in the queue has ID " << array[front_idx] << "." << endl;
    }

    // Clear operation: Release the memory allocated by the queue
    void Clear() {
        front_idx = rear_idx = -1; // Reset indices to clear the queue
        cout << "All appointments canceled. The doctor can go to lunch." << endl;
    }

    // ShowAllPatients operation: Show all patient IDs in sorted order
    void ShowAllPatients() const {
        if (isEmpty()) {
            cout << "No patients in the queue." << endl;
            return;
        }

        // Create a temporary array to sort the patient IDs
        int tempArray[MAX_SIZE];
        int size = rear_idx - front_idx + 1;
        for (int i = 0; i < size; ++i) {
            tempArray[i] = array[front_idx + i];
        }

        // Sort the temporary array
        sort(tempArray, tempArray + size);

        // Display the sorted patient IDs
        cout << "Patients in sorted order: ";
        for (int i = 0; i < size; ++i) {
            cout << tempArray[i] << " ";
        }
        cout << endl;
    }
};

// Waiting Room Management System
class WaitingRoom {
private:
    Queue patientQueue; // Queue to manage patients
    int nextId;         // Auto-generated ID for patients

public:
    // Constructor to initialize the system
    WaitingRoom() : nextId(1) {}

    // RegisterPatient: Assigns an auto-generated ID to a patient and enqueues them
    void RegisterPatient() {
        patientQueue.Enqueue(nextId);
        nextId++; // Increment the ID for the next patient
    }

    // ServePatient: Calls a patient to provide hospital service
    void ServePatient() {
        patientQueue.Dequeue();
    }

    // CancelAll: Cancels all appointments so the doctor can go to lunch
    void CancelAll() {
        patientQueue.Clear();
    }

    // CanDoctorGoHome: Checks if no one is waiting
    bool CanDoctorGoHome() const {
        return patientQueue.isEmpty();
    }

    // ShowAllPatients: Shows all patient IDs in sorted order
    void ShowAllPatients() const {
        patientQueue.ShowAllPatients();
    }
};

int main() {
    WaitingRoom waitingRoom;
    int choice;

    while (true) {
        cout << "\n--- Waiting Room Management System ---" << endl;
        cout << "1. Register Patient" << endl;
        cout << "2. Serve Patient" << endl;
        cout << "3. Cancel All Appointments" << endl;
        cout << "4. Can Doctor Go Home?" << endl;
        cout << "5. Show All Patients (Sorted)" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                waitingRoom.RegisterPatient();
                break;
            case 2:
                waitingRoom.ServePatient();
                break;
            case 3:
                waitingRoom.CancelAll();
                break;
            case 4:
                if (waitingRoom.CanDoctorGoHome()) {
                    cout << "Yes, the doctor can go home." << endl;
                } else {
                    cout << "No, there are still patients waiting." << endl;
                }
                break;
            case 5:
                waitingRoom.ShowAllPatients();
                break;
            case 6:
                cout << "Exiting the system. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}