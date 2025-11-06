#include <iostream>
#include <map>
#include <array>
#include <list>
#include <string>
#include <array>
#include <stdlib>
#include <time>

// Define a struct to represent a patient
    // Name, hours in a certain stage, hours in the hospital, total hours

// Define a function to simulate a hospital time interval
    // Parameters: map of hospital departments, number of intervals
// For departments or areas of the hosital
    // Access array of lists
    // Move patients through stages
    // Print if they changed stages
    // If a delay occurs, print that too next to the department
    // Have a small but actual chance for a emergency president 


// Main function
    // Initialize map to store hospital department info
    // Each department will have an array with three list
    // Index 0: waiting
    // Index 1: treatment
    // Index 2: discharge

// Open an external file to read hospital data
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