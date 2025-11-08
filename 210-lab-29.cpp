#include <iostream>
#include <fstream>
#include <map>
#include <array>
#include <list>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>

// Define a struct to represent a patient
    // Name, hours in a certain stage, hours in the hospital, total hours

struct Patient {
    std::string name;
    int hoursInStage;
    int totalHours;
};

// Define a function to simulate a hospital time interval
    // Parameters: map of hospital departments, number of intervals

    void simulateHospital(std::map<std::string, std::array<std::list<Patient>, 3>>& hospital, int intervals) {
for (auto& dept : hospital) {
        std::string departmentName = dept.first;
        auto& stages = dept.second;


// For departments or areas of the hosital
    // Access array of lists
    // Move patients through stages
    // Print if they changed stages

            // Move one patient from waiting to treatment (if any)
        if (!stages[0].empty()) {
            Patient p = stages[0].front();
            stages[0].pop_front();
            stages[1].push_back(p);
            std::cout << "Moved patient " << p.name << " from Waiting to Treatment in " << departmentName << "\n";
        }

        // Move one patient from treatment to discharge (if any)
        if (!stages[1].empty()) {
            Patient p = stages[1].front();
            stages[1].pop_front();
            stages[2].push_back(p);
            std::cout << "Moved patient " << p.name << " from Treatment to Discharge in " << departmentName << "\n";
        }
    }
}
    // If a delay occurs, print that too next to the department
    // Have a small but actual chance for a emergency president 


// Main function
int main() {
    // Initialize map to store hospital department info
        // Initialize map to store hospital department info
    std::map<std::string, std::array<std::list<Patient>, 3>> hospital;
    hospital["ER"];      
    hospital["ICU"];
    hospital["Surgery"];
    hospital["Radiology"];
    hospital["Pediatrics"];
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

        std::string name, department;
    while (file >> name >> department ) {
        Patient p{name, 0, 0};
        hospital[department][0].push_back(p); // Initially all in waiting
    }
    file.close();

    std::cout << "Initial hospital data loaded.\n";



    // If file does not open, print an error message and exit program
// Close the file

    // Begin a time-based simulation of hospital flow

        simulateHospital(hospital, 5);

        // Print summary for this interval
    for (auto& dept : hospital) {
        std::cout << dept.first << " — Waiting: " << dept.second[0].size()
                  << " | Treatment: " << dept.second[1].size()
                  << " | Discharge: " << dept.second[2].size() << "\n";
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

    // End of simulation
        // Write final hospital data (e.g., total patients treated) to output file
        // Print summary report

// End of main function