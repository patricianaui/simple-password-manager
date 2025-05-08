#include <stdio.h>
#include <string.h>

void addOrViewCredentials(){
    char cAddOrView[10];
    
    printf("Welcome to Patricia's simple password manager!\n\n");

    while (1) {
        printf("\nWould you like to add or view your credentials?\nADD | VIEW > ");
        scanf("%s", cAddOrView);

        if (strcmp(cAddOrView, "ADD") == 0 || strcmp(cAddOrView, "add") == 0 || strcmp(cAddOrView, "Add") == 0) {
            char cService[12];
            char cUsername[20];
            char cPassword[30];

            printf("\nTo start, please enter the service name (e.g. Gmail, Youtube, Tiktok, etc.): ");
            scanf("%s", cService);
            printf("Next, please enter your email/username: ");
            scanf("%s", cUsername);
            printf("Lastly, please enter your password: ");
            scanf("%s", cPassword);

            saveCredentials(cService, cUsername, cPassword);
        }
        else if (strcmp(cAddOrView, "VIEW") == 0 || strcmp(cAddOrView, "view") == 0 || strcmp(cAddOrView, "View") == 0) {
            FILE *fptr = fopen("credentials.txt", "r");

            if (fptr == NULL) {
                printf("\nNo credentials found or file could not be opened.\n");
            } else {
                char line[100];
                printf("\nSaved credentials:\n\n");
                while (fgets(line, sizeof(line), fptr)) {
                    printf("%s", line);
                }
                fclose(fptr);
            }
        } else {
            printf("\nInvalid option. Please type ADD or VIEW.\n");
            continue;
        }

        // Ask if the user wants to continue
        char cCheckQuit[4];
        printf("\nWould you like to continue?\n\nY | N > ");
        scanf("%s", cCheckQuit);

        if (strcmp(cCheckQuit, "N") == 0 || strcmp(cCheckQuit, "n") == 0) {
            printf("\nGoodbye!\n");
            break;
        }
    }
}

void saveCredentials(char cService[], char cUsername[], char cPassword[]){
	// Open file in append mode
	FILE *fptr = fopen("credentials.txt", "a");
	
	// Write the formatted data to the file
	fprintf(fptr, "Service: %s | Username: %s | Password: %s\n", cService, cUsername, cPassword);
	
	// Close the file
	fclose(fptr);
	
	// Show confirmation message
	printf("\nCredentials saved successfully!\n");
}

int main(){
	
	addOrViewCredentials();
	
	return 0;	
}