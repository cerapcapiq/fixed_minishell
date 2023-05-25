#include "../include/minishell.h"
#include <string.h>

#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>


char **var_ft_getenv(MyNode *envList)
{
    int count = 0;
    MyNode *current = envList;
    char **variable = NULL;

    // Count the number of nodes in the linked list
    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    // Allocate memory for an array of char pointers (plus one extra for NULL termination)
    variable = (char **)malloc((count + 1) * sizeof(char *));
    if (variable == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    // Traverse the linked list and copy the environment variables to the array
    current = envList;
    int i = 0;
    while (current != NULL)
    {
        // Concatenate name and value with '=' separator
        int len = strlen(current->name) + strlen(current->value) + 2;
        variable[i] = (char *)malloc(len * sizeof(char));
        snprintf(variable[i], len, "%s=%s", current->name, current->value);

        if (it_works(variable[i])) {
            // The command exists and is executable
            break;
        }

        current = current->next;
        i++;
    }

    // Terminate the array with NULL
    variable[i] = NULL;

    return variable;
}



char* var_getEnvValue(MyNode *envListHead, char* name) {
    MyNode* current = envListHead;
    while (current != NULL) {
        if (ft_strcmp(current->name, name)== 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL; // Environment variable not found
}

MyNode* var_createNode(char* name, char* value) {
    MyNode* newNode = (MyNode*)malloc(sizeof(MyNode));
    newNode->name = strdup(name);
    newNode->value = strdup(value);
    newNode->next = NULL;
    return newNode;
}

void var_deleteNode(MyNode** head, char** name)
{
    int i = 1;
    printf("here is unset %s", name[i]);
    if (*head == NULL) {
        // List is empty, nothing to delete
        printf("nono\n");;
    }
    if (name[i] == NULL)
        printf("nothing\n");
    MyNode* current = *head;
    MyNode* previous = NULL;
    
    // Iterate through the list to find the node with the given name
    while (current != NULL)
    {
        if (strcmp(current->name, name[i]) == 0)
        {
            // Node found, delete it
            
            if (previous == NULL)
            {
                *head = current->next;
            }
            else
            {
                // The node to be deleted is not the head
                previous->next = current->next;
            }
            free(current->name);
            free(current->value);
            free(current);
            
            return;
        }
        
        // Move to the next node
        previous = current;
        current = current->next;
    
    }
printf("Node with name '%s' not found in the list.\n", name[i]);
}

void var_insertNode(MyNode** head, char* name, char* value) {
    MyNode* newNode = var_createNode(name, value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        MyNode* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}



void var_freeList(MyNode* head) {
    MyNode* current = head;
    while (current != NULL) {
       MyNode* next = current->next;
        free(current->name);
        free(current->value);
        free(current);
        current = next;
    }
}

void var_printList(MyNode* head) {
    MyNode* current = head;
    if (current == NULL)
        printf("booba\n");
    while (current != NULL) {
        printf("%s=%s\n", current->name, current->value);
        current = current->next;
    }
    if (current == NULL)
        printf("booba\n");
}

MyNode* var_getTerminalEnvList(char* env[]) {
    MyNode* envList = NULL;

    // Iterate over the environment variables
    for (int i = 0; env[i] != NULL; i++) {
        char* variable = env[i];
        char* name = strtok(variable, "=");
        char* value = strtok(NULL, "=");

        var_insertNode(&envList, name, value);
    }

    return envList;
}