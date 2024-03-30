#include "binary_trees.h"

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
 * @heap: Pointer to the root node of the heap to convert
 * @size: Address to store the size of the array
 * Return: Pointer to the sorted array of integers
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    if (heap == NULL || size == NULL)
        return (NULL);

    size_t count = binary_tree_size(heap);
    int *sorted_array = malloc(sizeof(int) * count);

    if (sorted_array == NULL)
        return (NULL);

    size_t i = 0;

    while (heap != NULL)
    {
        sorted_array[i++] = heap->n;
        heap_extract(&heap);
    }

    *size = count;
    return (sorted_array);
}
