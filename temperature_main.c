#include "temperature.h"

int main(int argc, char *argv[]) {
    float temperature, converted_temp;
    int input_scale, target_scale;
    char retry;

    do {
        // Display input options
        printf("Enter the temperature value: ");
        while (scanf("%f", &temperature) != 1) {
            printf("Invalid input. Please enter a valid temperature value: ");
            while(getchar() != '\n');  // Clear the buffer
        }

        printf("Choose the input scale:\n");
        printf("1. Fahrenheit\n");
        printf("2. Celsius\n");
        printf("3. Kelvin\n");
        printf("Enter the scale number (1-3): ");
        while (scanf("%d", &input_scale) != 1 || input_scale < 1 || input_scale > 3) {
            printf("Invalid choice. Please enter a valid scale number (1-3): ");
            while(getchar() != '\n');  // Clear the buffer
        }

        printf("Choose the target scale for conversion:\n");
        printf("1. Fahrenheit\n");
        printf("2. Celsius\n");
        printf("3. Kelvin\n");
        printf("Enter the scale number (1-3): ");
        while (scanf("%d", &target_scale) != 1 || target_scale < 1 || target_scale > 3) {
            printf("Invalid choice. Please enter a valid scale number (1-3): ");
            while(getchar() != '\n');  // Clear the buffer
        }

        // Conversion logic
        if (input_scale == target_scale) {
            printf("No conversion needed. The temperature is already in the target scale.\n");
            converted_temp = temperature;
        } else {
            switch (input_scale) {
                case 1: // Fahrenheit
                    if (target_scale == 2) {
                        converted_temp = fahrenheit_to_celsius(temperature);
                    } else if (target_scale == 3) {
                        converted_temp = fahrenheit_to_celsius(temperature);
                        converted_temp = celsius_to_kelvin(converted_temp);
                    }
                    break;
                case 2: // Celsius
                    if (target_scale == 1) {
                        converted_temp = celsius_to_fahrenheit(temperature);
                    } else if (target_scale == 3) {
                        converted_temp = celsius_to_kelvin(temperature);
                    }
                    break;
                case 3: // Kelvin
                    if (target_scale == 1) {
                        converted_temp = kelvin_to_celsius(temperature);
                        converted_temp = celsius_to_fahrenheit(converted_temp);
                    } else if (target_scale == 2) {
                        converted_temp = kelvin_to_celsius(temperature);
                    }
                    break;
            }
        }

        // Display converted temperature
        printf("Converted temperature: %.2f\n", converted_temp);

        // Categorize and give advisory
        categorize_temperature(converted_temp);

        // Ask if the user wants to convert again
        printf("\nDo you want to perform another conversion? (y/n): ");
        while (scanf(" %c", &retry) != 1 || (retry != 'y' && retry != 'n')) {
            printf("Invalid input. Please enter 'y' or 'n': ");
            while(getchar() != '\n');  // Clear the buffer
        }

    } while (retry == 'y');

    printf("Goodbye!\n");
    return 0;
}
