#include <stdio.h>

// Function: getSensorSignal
// Description: Categorizes the sensor signal value into "Normal", "Irregular", or "Abnormal"
const char* getSensorSignal(int sensorValue) {
    if (sensorValue >= 0 && sensorValue <= 30)
        return "Normal";
    else if (sensorValue <= 70)
        return "Irregular";
    else if (sensorValue <= 100)
        return "Abnormal";
    else
        return "Invalid";  // Out of range
}

// Function: getDeviationLevel
// Description: Categorizes the deviation value into "Low", "Medium", or "High"
const char* getDeviationLevel(int deviationValue) {
    if (deviationValue >= 0 && deviationValue <= 30)
        return "Low";
    else if (deviationValue <= 70)
        return "Medium";
    else if (deviationValue <= 100)
        return "High";
    else
        return "Invalid";  // Out of range
}

// Function: getFaultRisk
// Description: Determines the fault risk based on the sensor signal and deviation level categories
const char* getFaultRisk(const char* signal, const char* deviation) {
    // Decision matrix based on documented table
    if (signal == "Normal") {
        if (deviation == "Low")
            return "None";
        else if (deviation == "Medium")
            return "Low";
        else if (deviation == "High")
            return "Medium";
    } else if (signal == "Irregular") {
        if (deviation == "Low")
            return "Medium";
        else if (deviation == "Medium")
            return "High";
        else if (deviation == "High")
            return "Critical";
    } else if (signal == "Abnormal") {
        if (deviation == "Low")
            return "High";
        else if (deviation == "Medium")
            return "Critical";
        else if (deviation == "High")
            return "Shutdown Alert";
    }

    // If input categories are invalid
    return "Invalid";
}

// Main function: Program entry point
int main() {
    int sensorValue, deviationValue;

    // Prompting user for sensor signal input (numeric 0–500)
    printf("Enter Sensor Signal value (0 - 100): ");
    scanf("%d", &sensorValue);

    // Prompting user for deviation level input (numeric 0–500)
    printf("Enter Deviation Level value (0 - 100): ");
    scanf("%d", &deviationValue);

    // Validate the input range
    if (sensorValue < 0 || sensorValue > 500 || deviationValue < 0 || deviationValue > 500) {
        printf("Invalid input! Values must be between 0 and 500.\n");
        return 1;
    }

    // Categorize the inputs
    const char* signal = getSensorSignal(sensorValue);
    const char* deviation = getDeviationLevel(deviationValue);

    // Determine the fault risk based on categories
    const char* risk = getFaultRisk(signal, deviation);

    // Display the result
    printf("\n--- Fault Diagnosis Result ---\n");
    printf("Sensor Signal     : %s\n", signal);
    printf("Deviation Level   : %s\n", deviation);
    printf("Fault Risk        : %s\n", risk);
    return 0;
}