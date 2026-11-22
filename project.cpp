
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct Patient {
    int id;
    string name;
    int priority;
    string emergency;
};

struct Compare {
    bool operator()(Patient a, Patient b) {
        if (a.priority == b.priority)
            return a.id > b.id;

        return a.priority < b.priority;
    }
};

class HospitalQueue {
private:
    priority_queue<Patient, vector<Patient>, Compare> pq;
    int nextId = 1;

public:
    void addPatient() {
        Patient p;
        p.id = nextId++;

        cout << "\nEnter patient name: ";
        cin.ignore();
        getline(cin, p.name);

        cout << "\nSelect Emergency Level:\n";
        cout << "1. Low\n";
        cout << "2. Medium\n";
        cout << "3. High\n";
        cout << "4. Critical\n";
        cout << "Enter choice: ";
        cin >> p.priority;

        if (p.priority < 1 || p.priority > 4) {
            cout << "\nInvalid priority!\n";
            nextId--;
            return;
        }

        switch (p.priority) {
            case 1: p.emergency = "Low"; break;
            case 2: p.emergency = "Medium"; break;
            case 3: p.emergency = "High"; break;
            case 4: p.emergency = "Critical"; break;
        }

        pq.push(p);

        cout << "\nPatient added successfully!";
        cout << "\nPatient ID: " << p.id << endl;
    }

    void treatPatient() {
        if (pq.empty()) {
            cout << "\nNo patients waiting!\n";
            return;
        }

        Patient p = pq.top();
        pq.pop();

        cout << "\n===== TREATING PATIENT =====\n";
        cout << "Patient ID: " << p.id << endl;
        cout << "Name: " << p.name << endl;
        cout << "Emergency: " << p.emergency << endl;
        cout << "Patient treated successfully!\n";
    }

    void displayPatients() {
        if (pq.empty()) {
            cout << "\nNo patients in queue!\n";
            return;
        }

        priority_queue<Patient, vector<Patient>, Compare> temp = pq;

        cout << "\n===== WAITING PATIENTS =====\n";

        while (!temp.empty()) {
            Patient p = temp.top();

            cout << "\nID: " << p.id;
            cout << "\nName: " << p.name;
            cout << "\nEmergency: " << p.emergency;
            cout << "\n--------------------------\n";

            temp.pop();
        }
    }

    void showNextPatient() {
        if (pq.empty()) {
            cout << "\nNo patients waiting!\n";
            return;
        }

        Patient p = pq.top();

        cout << "\n===== NEXT PATIENT =====\n";
        cout << "ID: " << p.id << endl;
        cout << "Name: " << p.name << endl;
        cout << "Emergency: " << p.emergency << endl;
    }

    void totalPatients() {
        cout << "\nTotal waiting patients: " << pq.size() << endl;
    }
};

int main() {
    HospitalQueue hospital;
    int choice;

    do {
        cout << "\n\n====================================";
        cout << "\n     SMART HOSPITAL MANAGEMENT";
        cout << "\n====================================";
        cout << "\n1. Add Patient";
        cout << "\n2. Treat Next Patient";
        cout << "\n3. Display Waiting Patients";
        cout << "\n4. Show Next Patient";
        cout << "\n5. Total Waiting Patients";
        cout << "\n6. Exit";
        cout << "\n====================================";
        cout << "\nEnter your choice: ";

        if (!(cin >> choice)) {
            cout << "\nInvalid input. Exiting.\n";
            break;
        }

        switch (choice) {
            case 1:
                hospital.addPatient();
                break;

            case 2:
                hospital.treatPatient();
                break;

            case 3:
                hospital.displayPatients();
                break;

            case 4:
                hospital.showNextPatient();
                break;

            case 5:
                hospital.totalPatients();
                break;

            case 6:
                cout << "\nThank you for using Smart Hospital Management!\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
