#include <stdio.h>

// Function to map value to category
const char* getCategory(int value) {
    if (value >= 0 && value <= 30)
        return "Low";
    else if (value <= 70)
        return "Medium";
    else if (value <= 100)
        return "High";
    else
        return "Invalid";  // Out of range
}

// Function to determine temperature based on distance and speed
const char* getTemperature(const char* distance, const char* speed) {
    // Decision table logic
    if (distance == "Low") {
        if (speed == "Low")
            return "Low";
        else if (speed == "Medium")
            return "Medium";
        else if (speed == "High")
            return "High";
    } 
    else if (distance == "Medium") {
        if (speed == "Low")
            return "Low";
        else if (speed == "Medium")
            return "Medium";
        else if (speed == "High")
            return "High";
    }
    else if (distance == "High") {
        if (speed == "Low")
            return "Low";
        else if (speed == "Medium")
            return "Medium";
        else if (speed == "High")
            return "High";
    }

    return "Invalid";
}

int main() {
    int distanceValue, speedValue;

    // User input
    printf("Enter Distance value (0 - 100): ");
    scanf("%d", &distanceValue);

    printf("Enter Speed value (0 - 100): ");
    scanf("%d", &speedValue);

    // Validate inputs
    if (distanceValue < 0 || distanceValue > 500 || speedValue < 0 || speedValue > 500) {
        printf("Invalid input! Values must be between 0 and 500.\n");
        return 1;
    }

    // Map numeric inputs to categories
    const char* distance = getCategory(distanceValue);
    const char* speed = getCategory(speedValue);

    // Determine temperature from category logic
    const char* temperature = getTemperature(distance, speed);

    // Output result
    printf("\n--- Temperature Prediction Result ---\n");
    printf("Distance     : %s\n", distance);
    printf("Speed        : %s\n", speed);
    printf("Temperature  : %s\n", temperature);
    return 0;
}