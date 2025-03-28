#include "temperature.h"
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// Function to convert Celsius to Kelvin
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

// Function to convert Kelvin to Celsius
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

// Function to categorize the temperature based on Celsius
void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Category: Freezing\n");
        display_advisory("Freezing");
    } else if (celsius >= 0 && celsius <= 10) {
        printf("Category: Cold\n");
        display_advisory("Cold");
    } else if (celsius > 10 && celsius <= 25) {
        printf("Category: Comfortable\n");
        display_advisory("Comfortable");
    } else if (celsius > 25 && celsius <= 35) {
        printf("Category: Hot\n");
        display_advisory("Hot");
    } else {
        printf("Category: Extreme Heat\n");
        display_advisory("Extreme Heat");
    }
}

// Function to display the advisory based on the temperature category
void display_advisory(const char *category) {
    if (category == "Freezing") {
        printf("Advisory: Wear a jacket.\n");
    } else if (category == "Cold") {
        printf("Advisory: Wear a sweater.\n");
    } else if (category == "Comfortable") {
        printf("Advisory: Enjoy the weather.\n");
    } else if (category == "Hot") {
        printf("Advisory: Stay hydrated.\n");
    } else if (category == "Extreme Heat") {
        printf("Advisory: Stay indoors.\n");
    }
}
