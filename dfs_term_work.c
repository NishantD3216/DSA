#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LOCATIONS 100
#define INFINITY 999999

struct Location {
    int id;
    char name[100];
    struct Road* next;
};

struct Road {
    int distance;
    struct Location* destination;
    struct Road* next;
};

struct Location* CreateLocation(const char* name, int id) {
    struct Location* newLocation = (struct Location*)malloc(sizeof(struct Location));
    strcpy(newLocation->name, name);
    newLocation->id = id;
    newLocation->next = NULL;
    return newLocation;
}

struct Road* CreateRoad(struct Location* destination, int distance) {
    struct Road* newRoad = (struct Road*)malloc(sizeof(struct Road));
    newRoad->destination = destination;
    newRoad->distance = distance;
    newRoad->next = NULL;
    return newRoad;
}

void AddRoad(struct Location* location1, struct Location* location2, int distance) {
    struct Road* road1 = CreateRoad(location2, distance);
    struct Road* road2 = CreateRoad(location1, distance);
    road1->next = location1->next;
    location1->next = road1;
    road2->next = location2->next;
    location2->next = road2;
}

void DFS(struct Location* current, struct Location* end, bool* visited, struct Location** path, int* pathIndex, int* shortestDistance, int currentDistance) {
    visited[current->id] = true;
    path[(*pathIndex)++] = current;

    if (current == end) {
        if (currentDistance < *shortestDistance) {
            *shortestDistance = currentDistance;
            printf("Shortest Path Found: ");
            for (int i = 0; i < *pathIndex; i++) {
                printf("%s -> ", path[i]->name);
            }
            printf("End\n");
        }
    } else {
        struct Road* road = current->next;
        while (road != NULL) {
            if (!visited[road->destination->id]) {
                DFS(road->destination, end, visited, path, pathIndex, shortestDistance, currentDistance + road->distance);
            }
            road = road->next;
        }
    }

    visited[current->id] = false;
    (*pathIndex)--;
}

void FindShortestPath(struct Location* start, struct Location* end) {
    bool visited[MAX_LOCATIONS] = { false };
    struct Location* path[MAX_LOCATIONS];
    int pathIndex = 0;
    int shortestDistance = INFINITY;

    DFS(start, end, visited, path, &pathIndex, &shortestDistance, 0);

    if (shortestDistance == INFINITY) {
        printf("No path found between the locations.\n");
    }
}

int main() {
    struct Location* locations[MAX_LOCATIONS];
    int numLocations = 0;

    printf("Enter location details (name and identifier), type 'done' to stop:\n");
    char name[100];
    int id;
    while (1) {
        printf("Name: ");
        scanf("%s", name);
        if (strcmp(name, "done") == 0) {
            break;
        }
        printf("Identifier: ");
        scanf("%d", &id);

        locations[numLocations] = CreateLocation(name, id);
        numLocations++;
    }

    printf("\nEnter roads (start_location_id end_location_id distance), type '-1' to stop:\n");
    int startId, endId, distance;
    while (1) {
        printf("Start Location ID: ");
        scanf("%d", &startId);
        if (startId == -1) {
            break;
        }
        printf("End Location ID: ");
        scanf("%d", &endId);
        printf("Distance: ");
        scanf("%d", &distance);

        if (startId < numLocations && endId < numLocations) {
            AddRoad(locations[startId], locations[endId], distance);
        } else {
            printf("Invalid location identifiers.\n");
        }
    }

    printf("\nEnter the start and end location identifiers to find the shortest path:\n");
    printf("Start Location ID: ");
    scanf("%d", &startId);
    printf("End Location ID: ");
    scanf("%d", &endId);

    if (startId < numLocations && endId < numLocations) {
        FindShortestPath(locations[startId], locations[endId]);
    } else {
        printf("Invalid location identifiers.\n");
    }

    return 0;
}
