#include <stdio.h>

//  Categorize numerical input
const char* getLevelCategory(int value) {
    if (value >= 0 && value <= 30) return "low";
    else if (value >= 31 && value <= 70) return "medium";
    else if (value >= 71 && value <= 100) return "high";
    else return "invalid";
}

//  Decision based on battery & load categories
const char* getPowerMode(int batteryLevel, int loadLevel) {
    const char* battery = getLevelCategory(batteryLevel);
    const char* load = getLevelCategory(loadLevel);

    if (battery == "low") {
        if (load == "low") return "Economy";
        else if (load == "medium") return "Normal";
        else if (load == "high") return "Limit Output";
    } 
    else if (battery == "medium") {
        if (load == "high") return "Limit Output";
        else return "Normal";
    } 
    else if (battery == "high") {
        return "Normal";
    }

    return "Invalid Input";
}

int main() {
    int batteryLevel, loadLevel;
    printf("Enter Battery Level (0-100): ");
    scanf("%d", &batteryLevel);

    printf("Enter Load Demand (0-100): ");
    scanf("%d", &loadLevel);

    //  Convert numeric to category
    const char* batteryCategory = getLevelCategory(batteryLevel);
    const char* loadCategory = getLevelCategory(loadLevel);
    const char* mode = getPowerMode(batteryLevel, loadLevel);

    //  Output full system decision
    printf("\n=== Power Optimization Result ===\n");
    printf("Battery Level: %d -> %s\n", batteryLevel, batteryCategory);
    printf("Load Demand:  %d -> %s\n", loadLevel, loadCategory);
    printf("Recommended Power Mode: %s\n", mode);

    return 0;
}