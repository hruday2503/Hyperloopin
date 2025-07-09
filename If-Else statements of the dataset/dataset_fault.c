#include <stdio.h>

/*
 * Function: getSensorSignal
 * --------------------------
 * Classifies the numeric sensor signal value into one of the following operational states:
 * - "Nominal"      : indicates stable readings (0–30)
 * - "Fluctuating"  : indicates variation outside baseline (31–70)
 * - "Unstable"     : indicates dangerous or erratic behavior (71–100)
 *
 * Returns a string representing the signal category.
 */
const char* getSensorSignal(int sensorValue) {
    if (sensorValue >= 0 && sensorValue <= 30)
        return "Nominal";
    else if (sensorValue <= 70)
        return "Fluctuating";
    else if (sensorValue <= 100)
        return "Unstable";
    else
        return "Invalid";  // Out of expected input range
}

/*
 * Function: getDeviationLevel
 * ----------------------------
 * Converts a deviation value into its respective impact category:
 * - "Minimal"   : acceptable fluctuation (0–30)
 * - "Moderate"  : cautionary deviation (31–70)
 * - "Severe"    : high-risk deviation (71–100)
 *
 * Returns a string indicating the deviation severity level.
 */
const char* getDeviationLevel(int deviationValue) {
    if (deviationValue >= 0 && deviationValue <= 30)
        return "Minimal";
    else if (deviationValue <= 70)
        return "Moderate";
    else if (deviationValue <= 100)
        return "Severe";
    else
        return "Invalid";  // Out of expected input range
}

/*
 * Function: getFaultRisk
 * -----------------------
 * Uses the signal state and deviation level to infer the system's fault risk status.
 * The logic mimics a decision matrix based on predefined operational risk levels.
 *
 * Categories include:
 * - "No Risk"
 * - "Low Risk"
 * - "Moderate Risk"
 * - "High Risk"
 * - "Critical Risk"
 * - "System Halt"  (shutdown recommended)
 *
 * Returns a string indicating the resulting fault risk category.
 */
const char* getFaultRisk(const char* signal, const char* deviation) {
    if (signal == "Nominal") {
        if (deviation == "Minimal")
            return "No Risk";
        else if (deviation == "Moderate")
            return "Low Risk";
        else if (deviation == "Severe")
            return "Moderate Risk";
    } else if (signal == "Fluctuating") {
        if (deviation == "Minimal")
            return "Moderate Risk";
        else if (deviation == "Moderate")
            return "High Risk";
        else if (deviation == "Severe")
            return "Critical Risk";
    } else if (signal == "Unstable") {
        if (deviation == "Minimal")
            return "High Risk";
        else if (deviation == "Moderate")
            return "Critical Risk";
        else if (deviation == "Severe")
            return "System Halt";
    }

    return "Invalid";  // If either input is unrecognized
}

/*
 * Function: main
 * ---------------
 * Entry point of the program. Accepts user input, performs classification using
 * signal and deviation functions, then derives the risk level.
 */
int main() {
    int sensorValue, deviationValue;

    // Prompting user for the sensor signal reading (0 to 100 expected)
    printf("Enter Sensor Signal value (0 - 100): ");
    scanf("%d", &sensorValue);

    // Prompting user for the deviation level reading (0 to 100 expected)
    printf("Enter Deviation Level value (0 - 100): ");
    scanf("%d", &deviationValue);

    // Input validation to ensure both values are within allowed range
    if (sensorValue < 0 || sensorValue > 100 || deviationValue < 0 || deviationValue > 100) {
        printf("Invalid input! Values must be between 0 and 100.\n");
        return 1;  // Exit with error
    }

    // Classify each input into descriptive categories
    const char* signal = getSensorSignal(sensorValue);
    const char* deviation = getDeviationLevel(deviationValue);

    // Use categories to determine the fault risk
    const char* risk = getFaultRisk(signal, deviation);

    // Output the final evaluation result
    printf("\n--- Fault Diagnosis Result ---\n");
    printf("Sensor Signal     : %s\n", signal);
    printf("Deviation Level   : %s\n", deviation);
    printf("Fault Risk        : %s\n", risk);

    return 0;  // Exit successfully
}

