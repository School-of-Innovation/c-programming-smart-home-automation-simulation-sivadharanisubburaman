/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */

 #include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initializeSystem(int rooms, int lights[], int locks[], int motion[], int temperature[]);
void displayMenu();
void toggleLight(int rooms, int lights[]);
void readTemperature(int rooms, int temperature[]);
void checkMotion(int rooms, int motion[]);
void securitySystem(int rooms, int locks[]);
void analyzeHouseStatus(int rooms, int lights[], int locks[], int motion[], int temperature[]);

int main() {
    int rooms;

    printf("Enter number of rooms: ");
    if (scanf("%d", &rooms) != 1 || rooms <= 0) {
        printf("Invalid input! Please enter a positive integer for the number of rooms.\n");
        return 1;  // Exit the program if the input is invalid.
    }

    int lights[rooms], locks[rooms], motion[rooms], temperature[rooms];

    initializeSystem(rooms, lights, locks, motion, temperature);

    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice! Try again.\n");
            while (getchar() != '\n'); // Clear the invalid input buffer
            continue;
        }

        switch (choice) {
            case 1: toggleLight(rooms, lights); break;
            case 2: readTemperature(rooms, temperature); break;
            case 3: checkMotion(rooms, motion); break;
            case 4: securitySystem(rooms, locks); break;
            case 5: analyzeHouseStatus(rooms, lights, locks, motion, temperature); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }

    } while (choice != 6);

    return 0;
}

void initializeSystem(int rooms, int lights[], int locks[], int motion[], int temperature[]) {
    srand(time(NULL));  // Initialize random seed

    for (int i = 0; i < rooms; i++) {
        lights[i] = 0;  // Light OFF by default
        locks[i] = 1;   // Locked by default
        motion[i] = 0;  // No motion detected by default
        temperature[i] = 22 + (rand() % 11);  // Temperature between 22°C and 32°C
    }
    printf("System Initialized.\n");
}

void displayMenu() {
    printf("\n===== Smart Home Menu =====\n");
    printf("1. Toggle Light\n");
    printf("2. Read Temperature\n");
    printf("3. Check Motion Sensor\n");
    printf("4. Lock/Unlock Security System\n");
    printf("5. House Status Summary\n");
    printf("6. Exit\n");
}

void toggleLight(int rooms, int lights[]) {
    int room;
    printf("Enter room number to toggle light (1-%d): ", rooms);
    if (scanf("%d", &room) != 1 || room < 1 || room > rooms) {
        printf("Invalid input or room number!\n");
        while (getchar() != '\n'); // Clear invalid input buffer
        return;
    }

    lights[room - 1] = !lights[room - 1];
    printf("Light in Room %d is now %s.\n", room, lights[room - 1] ? "ON" : "OFF");
}

void readTemperature(int rooms, int temperature[]) {
    int room;
    printf("Enter room number (1-%d): ", rooms);
    if (scanf("%d", &room) != 1 || room < 1 || room > rooms) {
        printf("Invalid input or room number!\n");
        while (getchar() != '\n'); // Clear invalid input buffer
        return;
    }

    printf("Temperature in Room %d: %d°C\n", room, temperature[room - 1]);
}

void checkMotion(int rooms, int motion[]) {
    int room;
    printf("Enter room number (1-%d): ", rooms);
    if (scanf("%d", &room) != 1 || room < 1 || room > rooms) {
        printf("Invalid input or room number!\n");
        while (getchar() != '\n'); // Clear invalid input buffer
        return;
    }

    motion[room - 1] = 1;  // Simulate motion detection
    printf("Motion detected in Room %d!\n", room);
}

void securitySystem(int rooms, int locks[]) {
    int room;
    printf("Enter room number to Lock/Unlock (1-%d): ", rooms);
    if (scanf("%d", &room) != 1 || room < 1 || room > rooms) {
        printf("Invalid input or room number!\n");
        while (getchar() != '\n'); // Clear invalid input buffer
        return;
    }

    locks[room - 1] = !locks[room - 1];  // Toggle lock state
    printf("Room %d is now %s.\n", room, locks[room - 1] ? "LOCKED" : "UNLOCKED");
}

void analyzeHouseStatus(int rooms, int lights[], int locks[], int motion[], int temperature[]) {
    printf("\nHouse Status:\n");
    for (int i = 0; i < rooms; i++) {
        printf("- Room %d: Light %s, Temp %d°C, %s, %s\n", 
               i + 1, lights[i] ? "ON" : "OFF", temperature[i], 
               motion[i] ? "Motion Detected" : "No Motion", 
               locks[i] ? "Locked" : "Unlocked");
    }
}