#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/* Function to print binary tree */
void binary_tree_print(const binary_tree_t *tree)
{
    char **s;
    size_t height, i, j;

    if (!tree)
        return;

    height = _height(tree);
    s = malloc(sizeof(*s) * (height + 1));
    if (!s)
        return;

    for (i = 0; i < height + 1; i++)
    {
        s[i] = malloc(sizeof(**s) * 255);
        if (!s[i])
        {
            // Free previously allocated memory on failure
            while (i > 0)
            {
                --i;
                free(s[i]);
            }
            free(s);
            return;
        }
        memset(s[i], ' ', 254);  // Use ' ' for clarity
        s[i][254] = '\0';        // Ensure null termination
    }

    print_t(tree, 0, 0, s);

    for (i = 0; i < height + 1; i++)
    {
        // Safely iterate and handle trailing spaces
        for (j = 253; j != (size_t)-1; --j) 
        {
            if (s[i][j] != ' ')
                break;
            s[i][j] = '\0';  // Safely truncate trailing spaces
        }
        printf("%s\n", s[i]);
        free(s[i]);
    }
    free(s);
}
