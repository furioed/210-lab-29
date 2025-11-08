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
    // Placeholder
    std::cout << "Simulation function called for " << intervals << " intervals.\n";
}

// For departments or areas of the hosital
    // Access array of lists
    // Move patients through stages
    // Print if they changed stages
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
    int stageHours;
    while (file >> name >> department >> stageHours) {
        Patient p{name, stageHours, stageHours};
        hospital[department][0].push_back(p); // Initially all in waiting
    }
    file.close();

    std::cout << "Initial hospital data loaded.\n";

    return 0;
}
    // If file does not open, print an error message and exit program
// Close the file

    // Begin a time-based simulation of hospital flow
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