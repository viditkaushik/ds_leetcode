int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int* stack = (int*)malloc(asteroidsSize * sizeof(int)); 
    int top = -1; 

    for (int i = 0; i < asteroidsSize; i++) {
        int current = asteroids[i];
        int exploded = 0;

        while (top >= 0 && stack[top] > 0 && current < 0) {
            if (abs(stack[top]) < abs(current)) {
                top--; 
            } else if (abs(stack[top]) == abs(current)) {
                top--; 
                exploded = 1;
                break;
            } else {
                exploded = 1;
                break;
            }
        }

        if (!exploded) {
            stack[++top] = current;
        }
    }

    *returnSize = top + 1; 
    return stack;
}
