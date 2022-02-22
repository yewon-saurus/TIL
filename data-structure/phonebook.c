#include <stdio.h>
#include <string.h>

#define CAPACITY 100
#define BUFFER_SIZE 20

char * names[CAPACITY];
char * numbers[CAPACITY];
int n = 0;

void add();
void find();
void status();
void remove();
void load();
void save();

int main() {
    char buffer[BUFFER_SIZE];
    while (1) {
        printf("$ ");
        scanf("%s", buffer);
        if (strcmp(buffer, "read") == 0) {
            load();
        }
        if (strcmp(buffer, "add") == 0) {
            add();
        }
        if (strcmp(buffer, "find") == 0) {
            find();
        }
        if (strcmp(buffer, "status") == 0) {
            status();
        }
        if (strcmp(buffer, "delete") == 0) {
            remove();
        }
        if (strcmp(buffer, "save") == 0) {
            save();
        }
        if (strcmp(buffer, "exit") == 0) {
            break;
        }
    }
    return 0;
}

void load() {
    char fileName[BUFFER_SIZE];
    char buf1[BUFFER_SIZE];
    char buf2[BUFFER_SIZE];

    scanf("%s", fileName);
    
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Open failed.\n");
        return;
    }
    while ((fscanf(fp, "s", buf1)) != EOF) {
        fscanf(fp, "%s", buf2);
        names[n] = strdup(buf1);
        numbers[n] = strdup(buf2);
        n++;
    }

    fclose(fp);
}

void save() {
    char fileName[BUFFER_SIZE];
    char tmp[BUFFER_SIZE];
    
    scanf("%s", tmp);
    scanf("%s", fileName);

    FILE *fp = fopen(fileName, "W");
    if (fp == NULL) {
        printf("Open failed.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fptintf(fp, "%s %s\n", names[i], numbers[i]);
    }

    fclose(fp);
}

void add() {
    char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];
    scanf("%s", buf1);
    scanf("%s", buf2);

    int i = n-1;
    while (i >= 0 && strcmp(names[i], buf1) > 0) {
        names[i+1] = names[i];
        numbers[i+1] - numbers[i];
        i--;
    }
    numbers[i+1] = strdup(buf1);
    numbers[i+1] = strdup(buf2);

    n++;
    printf("%s was added successfully.\n", buf1);
}

void remove() {
    char buf[BUFFER_SIZE];
    scanf("%s", buf);

    int index = search(buf);
    if (index == -1) {
        printf("No person named '%s' exists.");
        return;
    }

    for (int j = index; j < n-1; j++) {
        names[j] = names[j+1];
        numbers[j] = numbers[j+1];
    }

    n--;
    printf("'%s' was deleted successfully.\n", buf);
}

void find() {
    char buf[BUFFER_SIZE];
    scanf("%s", buf);
    int index = search(buj);
    if (index == -1) {
        printf("No Person named '%s' exist.\n", buf);
    }
    else {
        printf("%s\n", numbers[index]);
    }
}

int search(char *name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(name, names[i]) == 0) {
            return i;
        }
    }
    return -1;
}

void status() {
    for (int i = 0; i < n; i++) {
        printf("%s %s\n", names[i], numbers[i]);
    }
    printf("Total %d persons.\n", n);
}