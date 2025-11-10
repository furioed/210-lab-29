#include <iostream>
#include <fstream>
#include <map>
#include <array>
#include <list>
#include <string>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <windows.h>
#include <ctime>

// Define a struct to represent a patient
    // Name, hours in a certain stage, hours in the hospital, total hours

struct Patient {
    std::string name;
    int hoursInStage;
    int totalHours;
};

std::map<std::string, int> totalTreated;
std::map<std::string, int> totalEmergencies;

// Define a function to simulate a hospital time interval
    // Parameters: map of hospital departments, number of intervals

const int MAX_WAITING = 5;
const int MAX_TREATMENT = 3;

    void simulateHospital(std::map<std::string, std::array<std::list<Patient>, 3>>& hospital, int intervals) {
for (int i = 0; i < intervals; ++i) {
for (auto& dept : hospital) {
        std::string departmentName = dept.first;
        auto& stages = dept.second;

        for (auto& stage : stages) {
            for (auto& p : stage) {
                if (&stage != &stages[2]) {
                p.hoursInStage++;
                p.totalHours++;
            }
        }
    }
bool delay = rand() % 100 < 30;
            if (delay) {
                std::cout << "Delay in " << departmentName << " this hour (no patient movement).\n";
                continue;
            }

bool emergency = rand() % 100 < 10;
             if (emergency && stages[1].size() < MAX_TREATMENT) {
                Patient emergencyPatient{"Emergency_" + departmentName, 0, 0};
                stages[1].push_back(emergencyPatient);
                std::cout << "Emergency patient added to Treatment in " << departmentName << ".\n";
                totalEmergencies[departmentName]++;
            }

// For departments or areas of the hosital
    // Access array of lists
    // Move patients through stages
    // Print if they changed stages

            // Move one patient from waiting to treatment (if any)
             while (!stages[0].empty() && stages[1].size() < MAX_TREATMENT)
            Patient p = stages[0].front();
            stages[0].pop_front();
            stages[1].push_back(p);
            std::cout << "Moved patient " << p.name << " from Waiting to Treatment in " << departmentName << "\n";

        }

        // Move one patient from treatment to discharge (if any)
        while (!stages[1].empty()) {
            Patient p = stages[1].front();
            stages[1].pop_front();
            stages[2].push_back(p);
            std::cout << "Moved patient " << p.name << " from Treatment to Discharge in " << departmentName << "\n";
            totalTreated[departmentName]++;
        }
    }
}

    }
    // If a delay occurs, print that too next to the department
    // Have a small but actual chance for a emergency president 


// Main function
int main() {
        srand(static_cast<unsigned int>(time(nullptr))); 
    // Initialize map to store hospital department info
        // Initialize map to store hospital department info
    std::map<std::string, std::array<std::list<Patient>, 3>> hospital;
    hospital["ER"];      
    hospital["ICU"];
    hospital["Surgery"];
    hospital["Radiology"];
    hospital["Pediatrics"];

    for (auto& dept : hospital) {
    totalTreated[dept.first] = 0;
    totalEmergencies[dept.first] = 0;
}
    // Each department will have an array with three list
    // Index 0: waiting
    // Index 1: treatment
    // Index 2: discharge

// Open an external file to read hospital data
    std::ifstream file("patients.txt");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open patients.txt\n";
        return 1;
    }

        std::string department, name;
    while (file >> department >> name ) {
        std::getline(file, name);
        Patient p{name, 0, 0};

        if (hospital.find(department) != hospital.end()) {
            if (hospital[department][0].size() < MAX_WAITING) {
            hospital[department][0].push_back(p); // All patients start in Waiting
       } else {
                std::cout << "Waiting area full in " << department << ". Patient " << name << " cannot enter.\n";
            }
        } else {
            std::cout << "Warning: department " << department << " not recognized for patient " << name << "\n";
        }
    
    }
    file.close();

    std::cout << "Initial hospital data loaded.\n";



    // If file does not open, print an error message and exit program
// Close the file

    // Begin a time-based simulation of hospital flow

int totalIntervals = 20;  // 20 time intervals
for (int i = 0; i < totalIntervals; ++i) {
    std::cout << "\n=== Time Interval " << i + 1 << " ===\n";

    simulateHospital(hospital, 1); // THIS WILL BE CHANGED IN BETA

    std::cout << "\n=== FINAL REPORT ===\n";
for (auto& dept : hospital) {
    std::cout << dept.first
              << " | Treated: " << totalTreated[dept.first]
              << " | Emergencies: " << totalEmergencies[dept.first]
              << " | Waiting: " << dept.second[0].size()
              << " | Treatment: " << dept.second[1].size()
              << " | Discharged: " << dept.second[2].size()
              << "\n";
}
Sleep(1000);

}
    return 0;

}
        // For 20 time intervals 
            // Iterate through each department in the map
                // Call the simulation function to update patient stages
                // Print hospital status summary for this time interval
                  // Example output: "ER — Waiting: 2 | Treatment: 3 | Discharged: 1"

            // Randomly simulate events such as:
                // Max capacity (stop adding new patients)
                // Emergency arrivals (add patient to treatment immediately)
                // Delays (patients spend extra time in stage)



            // Wait or pause briefly to simulate passage of time between intervals

    // End of simulation // WORKING ON THIS
        // Write final hospital data (e.g., total patients treated) to output file
        // Print summary report


// End of main function